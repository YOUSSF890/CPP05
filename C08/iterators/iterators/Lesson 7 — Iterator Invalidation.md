Absolutely. 👍 Let's continue with **Lesson 7 — Iterator Invalidation**.

This is one of the most important iterator topics because it teaches you **when an iterator stops being safe to use**.

# Lesson 7 — Iterator Invalidation

## 1. What does "invalid iterator" mean?

Suppose:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);

std::vector<int>::iterator it = numbers.begin();
```

We have:

```text
it
 ↓
[10] [20] [30]
```

`it` points to `10`.

Now imagine the vector changes.

Sometimes the iterator can still be used.

Sometimes it becomes **invalid**.

An invalid iterator is an iterator that you should **not use anymore**.

---

# 2. Why can an iterator become invalid?

The easiest container to understand is `std::vector`.

A vector stores its elements in a continuous block of memory:

```text
[10][20][30][40]
```

But a vector has a limited amount of memory reserved for its elements.

You can see this with:

```cpp
numbers.size()
```

and:

```cpp
numbers.capacity()
```

### `size()`

How many elements are currently inside?

### `capacity()`

How many elements can fit in the currently allocated memory?

Example:

```text
size     = 3
capacity = 4
```

The vector has:

```text
[10][20][30][ empty ]
```

So it can add one more element without needing a bigger memory block.

---

# 3. What happens when capacity is full?

Suppose:

```text
size     = 4
capacity = 4
```

We have:

```text
[10][20][30][40]
```

Now:

```cpp
numbers.push_back(50);
```

There isn't enough space.

The vector may need to allocate a **new, larger memory block**.

Conceptually:

```text
OLD MEMORY

[10][20][30][40]
 ↑
 it
```

The vector creates something like:

```text
NEW MEMORY

[10][20][30][40][50]
```

Then it moves/copies the elements to the new location.

The old memory is no longer the vector's storage.

So your old iterator:

```text
it
 ↓
OLD [10]
```

is no longer valid.

---

# 4. The important rule for `vector`

A `vector` can invalidate iterators when its storage changes.

The most important situation to remember is:

```cpp
numbers.push_back(...);
```

If the `push_back()` causes a **reallocation**, iterators to the old elements become invalid.

So don't assume:

```cpp
it = numbers.begin();

numbers.push_back(50);

std::cout << *it;
```

is always safe.

It depends on whether reallocation happened.

---

# 5. Why does this matter?

Consider:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);

std::vector<int>::iterator it = numbers.begin();

numbers.push_back(40);

std::cout << *it << std::endl;
```

A beginner might think:

> "It still points to the first element, so it should print 10."

But that's not something you should rely on.

If the vector reallocated, `it` is invalid.

The safe approach is to get a new iterator after the modification:

```cpp
numbers.push_back(40);

std::vector<int>::iterator it = numbers.begin();

std::cout << *it << std::endl;
```

Now `it` belongs to the vector's current storage.

---

# 6. `reserve()` helps us understand this

You can ask a vector to reserve memory:

```cpp
numbers.reserve(100);
```

This means:

> Try to allocate enough storage for at least 100 elements.

For example:

```cpp
std::vector<int> numbers;

numbers.reserve(100);
```

Then we add:

```cpp
numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
```

The vector already has enough capacity.

So adding elements up to that capacity doesn't require the same kind of reallocation.

This can be useful for performance too.

---

# 7. `size()` vs `capacity()`

This is important enough to practice.

```cpp
std::vector<int> numbers;

numbers.reserve(10);

numbers.push_back(100);
numbers.push_back(200);
numbers.push_back(300);
```

You might have:

```text
size     = 3
capacity = 10
```

The exact capacity can depend on how the vector grows, but after `reserve(10)`, the capacity is at least 10.

Think:

```text
capacity
┌─────────────────────────────┐
│ 100 │ 200 │ 300 │ empty... │
└─────────────────────────────┘
     ↑
    size = 3
```

`size` counts actual elements.

`capacity` describes available storage for elements before another allocation is needed.

---

# 8. What about `std::list`?

Now compare a vector with a list.

A list looks conceptually like:

```text
[10] → [20] → [30] → [40]
```

The elements don't need to be stored next to each other.

So adding an element:

```cpp
numbers.push_back(50);
```

doesn't require moving the whole list into a new continuous memory block.

Therefore, iterators to existing list elements are generally much more stable when adding/removing other elements.

This is one reason different containers have different characteristics.

---

# 9. Important comparison

For now, remember this simplified picture:

### `vector`

```text
[10][20][30][40]
```

Adding elements **can** invalidate iterators if reallocation happens.

### `list`

```text
[10] → [20] → [30] → [40]
```

Adding an element generally doesn't invalidate iterators to existing elements.

---

# 10. Erasing is another important case

Suppose:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
numbers.push_back(40);
```

We get:

```text
[10] [20] [30] [40]
```

Suppose we want to remove `20`.

We can find it:

```cpp
std::vector<int>::iterator it;

it = std::find(numbers.begin(), numbers.end(), 20);
```

Now:

```text
[10] [20] [30] [40]
      ↑
      it
```

Then:

```cpp
numbers.erase(it);
```

The vector becomes:

```text
[10] [30] [40]
```

But here's the important part:

> The iterator `it` should not be used as if it still points to the erased element.

That element no longer exists.

---

# 11. `erase()` can return an iterator

This is very useful.

For many containers, `erase()` returns an iterator to the element after the erased one.

For example:

```cpp
std::vector<int>::iterator it;

it = std::find(numbers.begin(), numbers.end(), 20);

if (it != numbers.end())
{
    it = numbers.erase(it);
}
```

Suppose we started with:

```text
[10] [20] [30] [40]
       ↑
       it
```

After:

```cpp
it = numbers.erase(it);
```

we have:

```text
[10] [30] [40]
       ↑
       it
```

So `it` now points to `30`.

This pattern is very useful.

---

# 12. Erasing while looping

Here's a common pattern:

```cpp
std::vector<int>::iterator it = numbers.begin();

while (it != numbers.end())
{
    if (*it == 20)
        it = numbers.erase(it);
    else
        ++it;
}
```

Why don't we always do:

```cpp
++it;
```

after `erase()`?

Because `erase()` already gives us the next valid iterator.

So:

```cpp
it = numbers.erase(it);
```

means:

> Remove this element and give me the next valid position.

But:

```cpp
++it;
```

means:

> Move to the next position without erasing.

---

# 13. A common beginner mistake

Don't do this:

```cpp
if (*it == 20)
{
    numbers.erase(it);
    ++it;
}
```

Why?

Because after:

```cpp
numbers.erase(it);
```

the iterator may no longer be valid.

Instead:

```cpp
it = numbers.erase(it);
```

This gives you a valid iterator to continue with.

---

# 14. Exercise 1 🧠

Suppose:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);

std::vector<int>::iterator it = numbers.begin();
```

Then:

```cpp
numbers.push_back(40);
```

Question:

**Can you always safely assume that `it` is still valid?**

Think about:

```text
vector
  ↓
reallocation?
  ↓
iterator validity
```

---

# 15. Exercise 2

What's wrong with this?

```cpp
std::vector<int>::iterator it = numbers.begin();

numbers.erase(it);

std::cout << *it << std::endl;
```

Why shouldn't we use `it` after erasing the element it referred to?

---

# 16. Exercise 3 — understand `erase`

Suppose:

```text
[10] [20] [30] [40]
       ↑
       it
```

Then:

```cpp
it = numbers.erase(it);
```

What should the vector look like?

And where should `it` point?

---

# 17. Exercise 4 — fix the loop

This code is wrong:

```cpp
std::vector<int>::iterator it = numbers.begin();

while (it != numbers.end())
{
    if (*it == 20)
    {
        numbers.erase(it);
        ++it;
    }
    else
    {
        ++it;
    }
}
```

Rewrite the `if` part correctly.

Hint:

```cpp
it = numbers.erase(???);
```

---

# 18. The big picture

You now have an important set of concepts:

```text
ITERATOR
   │
   ├── points to an element
   │
   ├── can move
   │
   ├── can read/write depending on type
   │
   └── can become invalid
             │
             ├── container modification
             ├── reallocation
             └── erase
```

And one pattern you should remember:

```cpp
it = container.erase(it);
```

This is especially useful when removing elements while iterating.

---

## 🎯 What comes next

Next we'll study **iterator traits**.

This is a little more advanced, but it connects directly to **templates and generic programming**:

```cpp
template <typename Iterator>
void print(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        std::cout << *begin << std::endl;
        ++begin;
    }
}
```

We'll learn how C++ can discover information about an iterator's type and why that matters when writing generic functions.
