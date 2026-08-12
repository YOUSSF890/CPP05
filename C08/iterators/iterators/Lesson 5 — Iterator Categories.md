Absolutely 👍

# Lesson 5 — Iterator Categories

Now we're going one level deeper.

So far, you've learned how to **use** iterators.

Now we'll learn that **not all iterators can do the same things**.

The main idea is:

> Some iterators are more powerful than others.

---

# 1. Why do we have different iterator types?

Imagine two containers:

```cpp
std::vector<int> numbers;
std::list<int> numbers;
```

Both can contain:

```text
10 20 30 40 50
```

But internally, they work differently.

A `vector` is like a row:

```text
[10] [20] [30] [40] [50]
```

The elements are stored next to each other.

A `list` is more like connected nodes:

```text
[10] → [20] → [30] → [40] → [50]
```

Because of this, their iterators have different abilities.

---

# 2. The iterator hierarchy

Think of iterator abilities like levels:

```text
                 Contiguous
                     ↑
               Random Access
                     ↑
                Bidirectional
                     ↑
                  Forward
                     ↑
                   Input
```

There is also an **Output iterator** category for writing output sequences.

Don't worry about memorizing all of this yet.

The important idea is:

```text
higher level
    ↓
more operations available
```

---

# 3. Input iterator

An input iterator can basically:

* read values
* move forward

For example:

```cpp
++it;
*it;
```

You can think:

```text
READ
  +
MOVE FORWARD
```

It is one of the more limited iterator categories.

---

# 4. Forward iterator

A forward iterator can move forward:

```cpp
++it;
```

and read values.

It can also be used multiple times through the same range.

Think:

```text
10 → 20 → 30 → 40
```

It moves:

```text
→
→
→
```

but not:

```text
←
```

---

# 5. Bidirectional iterator

Now we get something more powerful.

A bidirectional iterator supports:

```cpp
++it;
```

and:

```cpp
--it;
```

So it can move both ways:

```text
10 → 20 → 30 → 40
     ←    ←    ←
```

For example, `std::list` provides bidirectional iterators.

Example:

```cpp
std::list<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);

std::list<int>::iterator it = numbers.begin();

++it;   // 20
++it;   // 30

--it;   // back to 20
```

This works because a list iterator is bidirectional.

---

# 6. Random-access iterator

This is where things become more interesting.

A random-access iterator can move much further.

For example:

```cpp
it + 3
```

means:

> Jump three positions forward.

And:

```cpp
it - 2
```

means:

> Jump two positions backward.

You can also do:

```cpp
it += 5;
it -= 2;
```

And compare positions:

```cpp
it < other;
it > other;
```

You can even use:

```cpp
it[3]
```

with a random-access iterator.

---

# 7. Vector has random-access iterators

For:

```cpp
std::vector<int> numbers;
```

we can do:

```cpp
std::vector<int>::iterator it = numbers.begin();
```

Then:

```cpp
it + 3
```

is valid.

Example:

```text
[10] [20] [30] [40] [50]
 ↑
it
```

After:

```cpp
it + 3
```

we reach:

```text
[10] [20] [30] [40] [50]
                 ↑
                 position 3
```

So:

```cpp
std::cout << *(it + 3);
```

prints:

```text
40
```

---

# 8. But list cannot do this

With:

```cpp
std::list<int> numbers;
```

this is not allowed:

```cpp
it + 3;
```

Why?

Because a list iterator doesn't have random access.

It can move:

```cpp
++it;
--it;
```

but not:

```cpp
it + 3;
```

You would move three times:

```cpp
++it;
++it;
++it;
```

This is an important difference.

---

# 9. Why is this important?

Imagine you write:

```cpp
template <typename Iterator>
void test(Iterator it)
{
    it + 5;
}
```

This function won't work with every iterator.

It requires an iterator that supports random access.

This is why understanding iterator categories becomes important when writing **generic C++ code**.

---

# 10. Contiguous iterator

Now we reach the strongest category:

```text
Contiguous
```

A contiguous iterator guarantees that the elements are stored directly next to each other in memory.

For example:

```cpp
std::vector<int>
std::array<int, 5>
```

Conceptually:

```text
memory:

[10][20][30][40][50]
```

The elements are contiguous.

This is stronger than just random access.

---

# 11. Compare the containers

Here's a useful table:

| Container     | Iterator ability           |
| ------------- | -------------------------- |
| `std::vector` | Random Access + Contiguous |
| `std::array`  | Random Access + Contiguous |
| `std::deque`  | Random Access              |
| `std::list`   | Bidirectional              |
| `std::map`    | Bidirectional              |
| `std::set`    | Bidirectional              |

For now, don't worry about every detail.

Just remember:

```text
vector → very powerful
list   → move forward/backward
```

---

# 12. Let's compare `vector` and `list`

### Vector

```cpp
std::vector<int> numbers;

std::vector<int>::iterator it = numbers.begin();

it + 5;
```

✅ Works.

### List

```cpp
std::list<int> numbers;

std::list<int>::iterator it = numbers.begin();

it + 5;
```

❌ Doesn't work.

But:

```cpp
++it;
```

works for both.

And for a list:

```cpp
--it;
```

also works.

---

# 13. The key idea

Don't think:

> "An iterator is just a pointer."

That's useful when you're starting, but it's not completely true.

A better mental model is:

> **An iterator is an object that provides a certain set of operations for moving through a range.**

Different iterators provide different operations.

For example:

```text
Input
 └── read + forward

Forward
 └── forward + repeated traversal

Bidirectional
 └── forward + backward

Random Access
 └── forward + backward + jumping

Contiguous
 └── random access + contiguous memory
```

---

# 14. Exercise 1 🧠

Which operations are valid for a `std::list` iterator?

```cpp
++it;
```

```cpp
--it;
```

```cpp
it + 3;
```

```cpp
*it;
```

Try to identify which are valid and which aren't.

---

# 15. Exercise 2

Which iterator is more powerful?

```text
A: std::list<int>::iterator
B: std::vector<int>::iterator
```

And why?

---

# 16. Exercise 3 — predict

Suppose:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
numbers.push_back(40);
numbers.push_back(50);

std::vector<int>::iterator it = numbers.begin();
```

What does this print?

```cpp
std::cout << *(it + 2) << std::endl;
```

Think about the positions:

```text
position:
   0     1     2     3     4
 [10]  [20]  [30]  [40]  [50]
   ↑
  it
```

---

# 17. Exercise 4 — important challenge

Look at:

```cpp
std::list<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
numbers.push_back(40);

std::list<int>::iterator it = numbers.begin();

++it;
++it;

std::cout << *it << std::endl;
```

What does it print?

And why does this work even though:

```cpp
it + 2
```

doesn't work?

---

# 18. What you need to remember today

Don't try to memorize every technical definition yet.

Remember this:

```text
                ITERATORS
                    │
        ┌───────────┴───────────┐
        │                       │
    less powerful          more powerful
        │                       │
     Forward               Random Access
        ↓                       ↓
 Bidirectional             vector
        ↓
      list
```

The most useful comparison for now:

```text
vector iterator:
++it
--it
it + n
it - n
it[n]

list iterator:
++it
--it
```

So when you see an iterator operation, always ask:

> **Does this iterator category support that operation?**

---

## 🎯 Next lesson

Next we'll connect iterators to **STL algorithms**, which is where iterators become really useful:

```cpp
std::find()
std::count()
std::for_each()
std::sort()
```

You'll see why algorithms take:

```cpp
begin()
end()
```

instead of simply taking a container.
