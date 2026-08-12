Great! 🚀 Let's go to **Lesson 2**.

# Lesson 2 — `begin()`, `end()`, and Iterator Movement

In Lesson 1, you learned:

```cpp
*it      // get the current value
++it     // move forward
begin()  // first element
end()    // after the last element
```

Now we're going to understand these ideas **much more deeply**.

---

## 1. Let's start with a simple vector

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
numbers.push_back(40);
```

Imagine:

```text
        begin()
           ↓
       ┌────┬────┬────┬────┐
       │ 10 │ 20 │ 30 │ 40 │
       └────┴────┴────┴────┘
                           ↑
                          end()
```

There are **4 elements**.

But there are actually **5 important positions**:

```text
       begin()
          ↓
       ┌────┬────┬────┬────┐
       │ 10 │ 20 │ 30 │ 40 │
       └────┴────┴────┴────┘
          ↑    ↑    ↑    ↑    ↑
          0    1    2    3   end
```

`end()` is a position, but **not an element**.

---

# 2. `begin()` gives you an iterator

```cpp
std::vector<int>::iterator it = numbers.begin();
```

Now:

```text
       it
       ↓
      [10] [20] [30] [40]
```

Therefore:

```cpp
*it
```

is:

```text
10
```

---

# 3. `++it` moves the iterator

```cpp
++it;
```

Now:

```text
             it
             ↓
      [10] [20] [30] [40]
```

So:

```cpp
*it
```

is now:

```text
20
```

Again:

```cpp
++it;
```

Now:

```text
                   it
                   ↓
      [10] [20] [30] [40]
```

And:

```cpp
*it
```

is:

```text
30
```

---

# 4. `it++` vs `++it`

You will see both:

```cpp
++it;
```

and:

```cpp
it++;
```

For basic movement, both move the iterator forward.

So:

```cpp
++it;
```

and:

```cpp
it++;
```

both eventually do:

```text
current → next
```

But they are not exactly the same operation.

### `++it`

Increment first.

### `it++`

Use the old value first, then increment.

For iterators, **prefer `++it`** when you simply want to move forward.

So write:

```cpp
++it;
```

This is also the usual style in iterator loops.

---

# 5. Very important: don't dereference `end()`

Look at this:

```cpp
std::vector<int>::iterator it = numbers.end();
```

The iterator is here:

```text
      [10] [20] [30] [40]
                         ↑
                        end
```

There is no element there.

So this is invalid:

```cpp
std::cout << *it;
```

because `it` is `end()`.

The safe pattern is:

```cpp
while (it != numbers.end())
{
    std::cout << *it << std::endl;
    ++it;
}
```

Notice the order:

```text
1. Check it != end()
2. Use *it
3. Move ++it
```

---

# 6. Why `!=` instead of `<`?

With a vector, you might see:

```cpp
it < numbers.end()
```

But the normal iterator pattern is:

```cpp
it != numbers.end()
```

Why?

Because **not every iterator supports `<`**.

For example, a `std::list` iterator can move forward and backward, but it doesn't support random-access comparisons like:

```cpp
it < other;
```

But this works:

```cpp
it != other;
```

So this is the general iterator pattern:

```cpp
it != end
```

Remember it.

---

# 7. Iterator + container

Here's something important.

The iterator belongs to a particular container.

For example:

```cpp
std::vector<int> a;
std::vector<int> b;
```

You get:

```cpp
std::vector<int>::iterator it = a.begin();
```

That iterator belongs to `a`.

You should not think of it as:

> "An iterator that points anywhere."

Think:

> "An iterator that is currently navigating this container."

---

# 8. Exercise 1 — Follow the iterator

Consider:

```cpp
std::vector<int> numbers;

numbers.push_back(100);
numbers.push_back(200);
numbers.push_back(300);
numbers.push_back(400);

std::vector<int>::iterator it = numbers.begin();

std::cout << *it << std::endl;

++it;

std::cout << *it << std::endl;

++it;

std::cout << *it << std::endl;
```

What is the output?

Think carefully:

```text
it → 100

++it

it → ?

++it

it → ?
```

---

# 9. Exercise 2 — Count the movements

Suppose:

```cpp
std::vector<int> numbers;

numbers.push_back(5);
numbers.push_back(10);
numbers.push_back(15);
numbers.push_back(20);
numbers.push_back(25);
```

And:

```cpp
std::vector<int>::iterator it = numbers.begin();

++it;
++it;
++it;
```

Where is `it`?

And what does:

```cpp
*it
```

give us?

---

# 10. Exercise 3 — Find the mistake

What's wrong with this code?

```cpp
std::vector<int>::iterator it = numbers.end();

std::cout << *it << std::endl;
```

Don't just say "it's wrong."

Try to explain:

> `end()` points to ________, not ________.

That's an important concept.

---

# 11. Exercise 4 — Write the loop

Write a program that prints:

```text
10
20
30
40
50
```

using:

```cpp
std::vector<int>::iterator
```

You must use:

```cpp
begin()
end()
*it
++it
```

Don't use:

```cpp
numbers[i]
```

or:

```cpp
range-based for
```

---

# 12. A small challenge 🧠

What will this print?

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
numbers.push_back(40);

std::vector<int>::iterator it = numbers.begin();

++it;

*it = 999;

++it;

std::cout << *it << std::endl;
```

Think step by step.

Initially:

```text
[10] [20] [30] [40]
  ↑
 it
```

After:

```cpp
++it;
```

Where is it?

Then:

```cpp
*it = 999;
```

What changed?

Then another:

```cpp
++it;
```

Where is it now?

---

## 🎯 Lesson 2 goal

By the end of this lesson, you should understand this picture:

```text
                vector
     ┌────┬────┬────┬────┐
     │ 10 │ 20 │ 30 │ 40 │
     └────┴────┴────┴────┘
       ↑              ↑
     begin()         end()
       │
       ↓
      iterator

*it  → current element
++it → next position
end  → stop position
```

**Your turn:** solve Exercises **1–4**, especially Exercise 3 in your own words. Then we can move to **Lesson 3: `const_iterator` and why it matters**.
