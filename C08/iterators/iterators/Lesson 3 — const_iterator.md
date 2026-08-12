Absolutely. 👍 Let's continue.

# Lesson 3 — `const_iterator`

This lesson is very important because it teaches you the difference between:

* an iterator that can **read and change**
* an iterator that can **only read**

---

## 1. Normal iterator

Start with:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
```

We can create a normal iterator:

```cpp
std::vector<int>::iterator it = numbers.begin();
```

Now:

```cpp
std::cout << *it << std::endl;
```

prints:

```text
10
```

But we can also change the value:

```cpp
*it = 100;
```

Now the vector is:

```text
[100] [20] [30]
```

So a normal iterator gives us **read + write** access.

```text
iterator
   │
   ├── read  ✓
   │
   └── write ✓
```

---

# 2. `const_iterator`

Now look at this:

```cpp
std::vector<int>::const_iterator it = numbers.begin();
```

The name gives you a clue:

```text
const_iterator
      ↓
   constant
```

It means:

> You can look at the element, but you cannot change it through this iterator.

So this is okay:

```cpp
std::cout << *it << std::endl;
```

But this is **not allowed**:

```cpp
*it = 100;
```

The compiler will complain.

Think:

```text
const_iterator
      │
      ├── read  ✓
      │
      └── write ✗
```

---

# 3. Why do we need this?

Imagine you have a function:

```cpp
void printNumbers(std::vector<int>& numbers)
{
    // ...
}
```

The function is only supposed to **print** the numbers.

It doesn't need to change anything.

You can use:

```cpp
std::vector<int>::const_iterator it;
```

This helps protect your data from accidental modification.

Example:

```cpp
void printNumbers(const std::vector<int>& numbers)
{
    std::vector<int>::const_iterator it = numbers.begin();

    while (it != numbers.end())
    {
        std::cout << *it << std::endl;
        ++it;
    }
}
```

Notice something important:

```cpp
const std::vector<int>& numbers
```

The vector itself is `const`.

Therefore, we use:

```cpp
const_iterator
```

to read it.

---

# 4. Why can't we use a normal iterator?

Suppose:

```cpp
void printNumbers(const std::vector<int>& numbers)
{
    std::vector<int>::iterator it = numbers.begin();
}
```

This will not work.

Why?

Because `numbers` is constant.

The function promises:

> "I won't modify this vector."

But a normal iterator could potentially do:

```cpp
*it = 999;
```

That would break the promise.

So C++ gives you:

```cpp
const_iterator
```

which prevents that.

---

# 5. A very useful rule

Remember:

### Normal vector

```cpp
std::vector<int> numbers;
```

You can use:

```cpp
std::vector<int>::iterator
```

### Const vector

```cpp
const std::vector<int> numbers;
```

You should use:

```cpp
std::vector<int>::const_iterator
```

---

# 6. Compare them

### Normal iterator

```cpp
std::vector<int>::iterator it = numbers.begin();

*it = 500;
```

Allowed.

### Const iterator

```cpp
std::vector<int>::const_iterator it = numbers.begin();

*it = 500;
```

Not allowed.

But both can do:

```cpp
std::cout << *it;
```

and:

```cpp
++it;
```

So:

```text
                    iterator
                       │
             ┌─────────┴─────────┐
             ▼                   ▼
        normal iterator     const_iterator
             │                   │
         read + write          read only
```

---

# 7. Important: `const_iterator` can still move

Some beginners think:

> "const iterator means the iterator cannot move."

No.

You can still do:

```cpp
++it;
```

and:

```cpp
--it;
```

when supported.

The `const` here means:

> You cannot modify the **element through the iterator**.

It does **not** mean the iterator itself cannot move.

For example:

```cpp
std::vector<int>::const_iterator it = numbers.begin();

std::cout << *it << std::endl;

++it;

std::cout << *it << std::endl;
```

Perfectly valid.

---

# 8. Exercise 1 🧠

Look at this:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);

std::vector<int>::const_iterator it = numbers.begin();

std::cout << *it << std::endl;

++it;

std::cout << *it << std::endl;
```

What does it print?

And answer:

**Can `++it` work with a `const_iterator`?**

---

# 9. Exercise 2 — Find the error

What's wrong here?

```cpp
std::vector<int>::const_iterator it = numbers.begin();

*it = 100;
```

Explain **why** the compiler doesn't allow it.

Try to answer in simple English:

> "`const_iterator` allows me to ________, but doesn't allow me to ________."

---

# 10. Exercise 3 — Write a read-only function

Write:

```cpp
void printNumbers(const std::vector<int>& numbers)
```

The function should print every element.

Example:

```text
10
20
30
40
```

You must use:

```cpp
std::vector<int>::const_iterator
```

and:

```cpp
begin()
end()
*it
++it
```

---

# 11. One more important detail: `cbegin()` and `cend()`

C++ also gives us:

```cpp
numbers.cbegin()
numbers.cend()
```

These return const iterators.

For example:

```cpp
std::vector<int>::const_iterator it = numbers.cbegin();

while (it != numbers.cend())
{
    std::cout << *it << std::endl;
    ++it;
}
```

Think:

```text
begin()  → normal iterator
cbegin() → const iterator

end()    → normal end iterator
cend()   → const end iterator
```

For now, don't worry too much about `cbegin()` and `cend()`. Just recognize them.

---

# 12. A common mistake

Don't confuse these two:

```cpp
const std::vector<int> numbers;
```

and:

```cpp
std::vector<int>::const_iterator it;
```

They are related, but they are **not the same thing**.

### `const vector`

Means:

> The vector cannot be modified.

### `const_iterator`

Means:

> You cannot modify the element through this iterator.

---

# 13. The big picture so far

You've now learned:

```text
                 ITERATOR
                    │
        ┌───────────┴───────────┐
        ▼                       ▼
   normal iterator        const_iterator
        │                       │
    read/write                read only
        │                       │
        └───────────┬───────────┘
                    ▼
                  *it
                    │
                    ▼
              current element

              ++it
                │
                ▼
          next position
```

And:

```cpp
numbers.begin()
```

starts at the first element.

```cpp
numbers.end()
```

marks the position after the last element.

```cpp
numbers.cbegin()
```

starts with a const iterator.

```cpp
numbers.cend()
```

marks the const end position.

