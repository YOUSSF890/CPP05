# Lesson 8 — Custom Iterators

Now we move from **using iterators** to **building our own iterator**.

The goal is to understand what an iterator actually needs to do.

---

## 1. The basic idea

Suppose we have a simple container:

```cpp
class Numbers
{
private:
    int data[3] = {10, 20, 30};
};
```

We want this to work:

```cpp
Numbers nums;

for (auto it = nums.begin(); it != nums.end(); ++it)
{
    std::cout << *it << '\n';
}
```

For that to work, our iterator needs to understand three main operations:

```text
*it       → access the current element
++it      → move forward
it != end → check whether we're finished
```

That's the core of an iterator.

---

# 2. Building the iterator

We can create a small iterator class:

```cpp
class Iterator
{
private:
    int* ptr;

public:
    Iterator(int* p) : ptr(p) {}

    int& operator*()
    {
        return *ptr;
    }

    Iterator& operator++()
    {
        ++ptr;
        return *this;
    }

    bool operator!=(const Iterator& other) const
    {
        return ptr != other.ptr;
    }
};
```

Don't worry about every detail yet.

Focus on these three operators.

---

## 3. `operator*()`

When we write:

```cpp
*it
```

C++ calls:

```cpp
it.operator*()
```

Our implementation:

```cpp
int& operator*()
{
    return *ptr;
}
```

So if:

```text
ptr
 ↓
[10] [20] [30]
```

then:

```cpp
*it
```

returns `10`.

---

## 4. `operator++()`

When we write:

```cpp
++it;
```

C++ calls:

```cpp
it.operator++()
```

Our implementation:

```cpp
Iterator& operator++()
{
    ++ptr;
    return *this;
}
```

The internal pointer moves:

```text
Before:

ptr
 ↓
[10] [20] [30]


After ++it:

      ptr
       ↓
[10] [20] [30]
```

So the iterator moves from `10` to `20`.

---

## 5. `operator!=()`

A loop needs to know when to stop:

```cpp
it != end
```

So we define:

```cpp
bool operator!=(const Iterator& other) const
{
    return ptr != other.ptr;
}
```

Conceptually:

```text
it                    end
 ↓                     ↓
[10] [20] [30] [END]
```

As long as:

```cpp
it != end
```

we continue.

When:

```cpp
it == end
```

we stop.

---

# 6. Putting it into a container

Now let's give `Numbers` `begin()` and `end()`:

```cpp
class Numbers
{
private:
    int data[3] = {10, 20, 30};

public:
    Iterator begin()
    {
        return Iterator(data);
    }

    Iterator end()
    {
        return Iterator(data + 3);
    }
};
```

Notice:

```cpp
data
```

points to the first element.

And:

```cpp
data + 3
```

points **one past the last element**.

So:

```text
data
 ↓
[10] [20] [30] [END]
                    ↑
                 data + 3
```

---

# 7. Now the iterator works

We can do:

```cpp
Numbers nums;

for (auto it = nums.begin(); it != nums.end(); ++it)
{
    std::cout << *it << '\n';
}
```

The sequence is:

```text
begin()
  ↓
*it → 10
  ↓
++it
  ↓
*it → 20
  ↓
++it
  ↓
*it → 30
  ↓
++it
  ↓
it == end()
  ↓
stop
```

### The big picture

A custom iterator is basically an object that provides the operations needed to behave like a position in a sequence:

```text
              Custom Iterator
                    │
       ┌────────────┼────────────┐
       ↓            ↓            ↓
     *it          ++it         it != end
       │            │            │
       ↓            ↓            ↓
    access        move        compare
   element       forward      position
```

---

## Your first challenge 🧠

Look at this:

```cpp
Iterator& operator++()
{
    ++ptr;
    return *this;
}
```

Why do you think it returns:

```cpp
return *this;
```

instead of simply returning nothing?

Think about it before answering.

//////
Iterator(int* p) : ptr(p) {}
why type p int 
//////

Because in our example, the container stores **`int` values**:

```cpp
int data[3] = {10, 20, 30};
```

So `data` is an array of `int`.

When we use:

```cpp
Iterator(data);
```

the value passed to the constructor is essentially a pointer to an `int`:

```cpp
data
 ↓
int
```

Therefore the constructor accepts:

```cpp
Iterator(int* p)
```

Here:

* `int*` = pointer to an `int`
* `p` = parameter name
* `ptr` = member variable storing that pointer

So:

```cpp
Iterator(int* p) : ptr(p) {}
```

means:

> "Create an iterator from a pointer to an `int`, and store that pointer in `ptr`."

### Why not `double*`?

If our container stored `double`:

```cpp
double data[3] = {1.5, 2.5, 3.5};
```

then we'd need:

```cpp
Iterator(double* p)
```

If it stored `std::string`:

```cpp
std::string data[3];
```

we'd need a pointer to `std::string`.

### This reveals something important

Our current iterator is **specifically an iterator for `int`**.

Later, we'll make it **generic** using templates:

```cpp
template <typename T>
class Iterator
{
    T* ptr;
};
```

Then the same iterator can work with:

```text
int*       → int
double*    → double
string*    → string
```

That's the next important step after you fully understand this simple version.
