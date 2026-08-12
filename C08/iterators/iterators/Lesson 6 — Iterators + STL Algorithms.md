Absolutely 👍 Let's continue.

# Lesson 6 — Iterators + STL Algorithms

This is where iterators start to become **really useful**.

You already know how to manually walk through a vector:

```cpp
for (std::vector<int>::iterator it = numbers.begin();
     it != numbers.end();
     ++it)
{
    std::cout << *it << std::endl;
}
```

But C++ gives us algorithms that can do common operations for us.

The basic idea is:

```text
Container
   ↓
begin() ───────── end()
   ↓               ↓
   └──── range ────┘
          ↓
       algorithm
```

---

# 1. What is an algorithm?

An algorithm is a ready-made function that performs an operation.

For example:

```cpp
std::find()
```

can search for something.

```cpp
std::count()
```

can count something.

```cpp
std::for_each()
```

can perform a function on every element.

```cpp
std::sort()
```

can sort a range.

---

# 2. `std::find`

Let's say:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
numbers.push_back(40);
```

We want to find `30`.

We can write:

```cpp
#include <algorithm>

std::vector<int>::iterator it;

it = std::find(numbers.begin(), numbers.end(), 30);
```

Think about what we're giving `find()`:

```text
numbers.begin()
      ↓
[10] [20] [30] [40]
                        ↑
                  numbers.end()
```

We're saying:

> Search from `begin()` until `end()` for `30`.

---

# 3. What does `find()` return?

This is very important.

`std::find()` returns an **iterator**.

If it finds `30`:

```text
[10] [20] [30] [40]
            ↑
            it
```

Then:

```cpp
std::cout << *it;
```

prints:

```text
30
```

---

# 4. What if it doesn't find the value?

Suppose:

```cpp
std::find(numbers.begin(), numbers.end(), 99);
```

There is no `99`.

What does `find()` return?

It returns:

```cpp
numbers.end()
```

So we normally write:

```cpp
std::vector<int>::iterator it;

it = std::find(numbers.begin(), numbers.end(), 99);

if (it != numbers.end())
{
    std::cout << "Found!" << std::endl;
}
else
{
    std::cout << "Not found!" << std::endl;
}
```

The important pattern is:

```cpp
if (it != numbers.end())
```

means:

> We found something.

And:

```cpp
if (it == numbers.end())
```

means:

> We didn't find it.

---

# 5. Why does `find()` use iterators?

Because `find()` doesn't need to care about the container.

You can use:

```cpp
std::find(numbers.begin(), numbers.end(), 30);
```

with a vector.

You can also use it with a list:

```cpp
std::find(numbers.begin(), numbers.end(), 30);
```

The algorithm works with a **range**.

The range is:

```text
[begin, end)
```

That means:

> Start at `begin` and stop before `end`.

---

# 6. Understand `[begin, end)`

This notation is very common in C++:

```text
[begin, end)
```

The square bracket means:

> Include `begin`.

The round bracket means:

> Don't include `end`.

Example:

```text
begin                       end
 ↓                           ↓
[10] [20] [30] [40] [END]
 ↑___________________________↑
          range
```

The range contains:

```text
10, 20, 30, 40
```

but not `end`.

This is why C++ algorithms normally use:

```cpp
begin()
end()
```

---

# 7. `std::count`

Now suppose we have:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(10);
numbers.push_back(30);
numbers.push_back(10);
```

We want to know how many times `10` appears.

Use:

```cpp
int count = std::count(numbers.begin(), numbers.end(), 10);
```

Now:

```cpp
std::cout << count;
```

prints:

```text
3
```

Notice that `count()` doesn't return an iterator.

It returns a number.

So:

```text
find()
  ↓
iterator

count()
  ↓
number
```

---

# 8. `std::for_each`

This one is especially interesting for you because you're learning the `iter` exercise.

Suppose:

```cpp
void print(int n)
{
    std::cout << n << std::endl;
}
```

We can do:

```cpp
std::for_each(numbers.begin(), numbers.end(), print);
```

This means:

> Call `print()` for every element in this range.

Conceptually:

```text
10 → print(10)
20 → print(20)
30 → print(30)
40 → print(40)
```

This is closely related to your `iter` exercise.

---

# 9. Connection to your `iter` exercise

Your exercise looks like:

```cpp
template <typename T>
void iter(T *array, size_t length, void (*f)(T&))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}
```

The idea is:

```text
array
 ↓
element 1 → f()
element 2 → f()
element 3 → f()
element 4 → f()
```

`std::for_each()` has a similar idea:

```text
begin()
 ↓
element 1 → f()
element 2 → f()
element 3 → f()
element 4 → f()
 ↓
end()
```

So your `iter` exercise is helping you understand the idea behind algorithms that work on ranges.

---

# 10. `std::sort`

Now we get to a very useful algorithm.

Suppose:

```cpp
std::vector<int> numbers;

numbers.push_back(40);
numbers.push_back(10);
numbers.push_back(30);
numbers.push_back(20);
```

We can write:

```cpp
std::sort(numbers.begin(), numbers.end());
```

Before:

```text
40  10  30  20
```

After:

```text
10  20  30  40
```

Notice again:

```cpp
numbers.begin()
numbers.end()
```

We give the algorithm a range.

---

# 11. Why can `sort()` work with vector?

Remember Lesson 5?

`std::vector` has a **random-access iterator**.

`std::sort()` requires a random-access range.

So this works:

```cpp
std::sort(numbers.begin(), numbers.end());
```

But you can't simply use `std::sort()` with a `std::list`.

Why?

Because list iterators are only bidirectional.

For lists, use the list's own:

```cpp
numbers.sort();
```

This is a good example of why iterator categories matter.

---

# 12. Very important pattern

When you see:

```cpp
some_algorithm(container.begin(), container.end(), ...);
```

read it as:

> "Apply this algorithm to every element in this range."

For example:

```cpp
std::find(numbers.begin(), numbers.end(), 20);
```

means:

> Search this range for 20.

```cpp
std::count(numbers.begin(), numbers.end(), 20);
```

means:

> Count 20 in this range.

```cpp
std::sort(numbers.begin(), numbers.end());
```

means:

> Sort this range.

---

# 13. Exercise 1 — `find`

Given:

```cpp
std::vector<int> numbers;

numbers.push_back(5);
numbers.push_back(10);
numbers.push_back(15);
numbers.push_back(20);
```

Write code that finds `15`.

Then answer:

> What type does `std::find()` return?

---

# 14. Exercise 2 — check if found

Complete this:

```cpp
std::vector<int>::iterator it;

it = std::find(numbers.begin(), numbers.end(), 100);

if (________________)
{
    std::cout << "Found" << std::endl;
}
else
{
    std::cout << "Not found" << std::endl;
}
```

What should go inside the `if`?

Hint:

```text
What does find() return when it doesn't find anything?
```

---

# 15. Exercise 3 — count

Given:

```cpp
std::vector<int> numbers;

numbers.push_back(5);
numbers.push_back(10);
numbers.push_back(5);
numbers.push_back(20);
numbers.push_back(5);
```

What does this give?

```cpp
int result = std::count(numbers.begin(), numbers.end(), 5);
```

What is:

```text
result = ?
```

---

# 16. Exercise 4 — sort

What will the vector contain after:

```cpp
std::sort(numbers.begin(), numbers.end());
```

if initially:

```text
30  5  100  20  10
```

?

---

# 17. Exercise 5 — connect it to `iter`

You have:

```cpp
void print(int& n)
{
    std::cout << n << std::endl;
}
```

And:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
```

Write one line using `std::for_each()` to call `print()` for every element.

Think:

```text
for_each(
    ______,
    ______,
    ______
);
```

---

# 🎯 The big picture

You've now reached an important point:

```text
                 CONTAINER
                     │
             begin() │ end()
                     ▼
                   RANGE
                     │
                     ▼
                ALGORITHM
                     │
        ┌────────────┼────────────┐
        ▼            ▼            ▼
      find         count       for_each
        │            │            │
    iterator       number       function
```

And your `iter` exercise fits here:

```text
                 iter()
                   │
        array + length + function
                   │
                   ▼
          visit every element
                   │
                   ▼
              for_each()
                   │
          begin() + end() + function
```

### Next lesson

We'll study **iterator invalidation**.

This is very important in real C++:

```cpp
std::vector<int>::iterator it = numbers.begin();

numbers.push_back(100);
```

What happens to `it`?

Can you still use it?

Why can adding an element sometimes make an iterator invalid?

That's the next big concept.
