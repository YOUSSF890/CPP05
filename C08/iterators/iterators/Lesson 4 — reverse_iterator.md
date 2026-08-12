Sure! 😄 Let's continue with **Lesson 4 — Reverse Iterators**.

# Lesson 4 — `reverse_iterator`

So far, we moved through a container like this:

```text
10 → 20 → 30 → 40
```

A **reverse iterator** lets us move in the opposite direction:

```text
40 → 30 → 20 → 10
```

---

## 1. Normal iterator

With a normal iterator:

```cpp
std::vector<int>::iterator it = numbers.begin();
```

we start at the first element:

```text
       it
        ↓
[10] [20] [30] [40]
```

Then:

```cpp
++it;
```

moves us:

```text
[10] [20] [30] [40]
       ↑
       it
```

So:

```text
begin() → 10 → 20 → 30 → 40 → end()
```

---

# 2. Reverse iterator

Now we use:

```cpp
std::vector<int>::reverse_iterator it;
```

And instead of:

```cpp
begin()
```

we use:

```cpp
rbegin()
```

Example:

```cpp
std::vector<int>::reverse_iterator it = numbers.rbegin();
```

Now the iterator starts at the **last element**:

```text
[10] [20] [30] [40]
                 ↑
                 it
               rbegin()
```

So:

```cpp
std::cout << *it;
```

prints:

```text
40
```

---

# 3. `++it` now moves backwards

This is the interesting part.

With a normal iterator:

```cpp
++it;
```

means:

```text
10 → 20 → 30 → 40
```

With a reverse iterator:

```cpp
++it;
```

means:

```text
40 → 30 → 20 → 10
```

So `++it` always means:

> Move to the next position **for this iterator**.

A reverse iterator defines "next" as moving backwards through the container.

---

# 4. Example

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
numbers.push_back(40);

std::vector<int>::reverse_iterator it = numbers.rbegin();

while (it != numbers.rend())
{
    std::cout << *it << std::endl;
    ++it;
}
```

Output:

```text
40
30
20
10
```

---

# 5. `rbegin()` and `rend()`

You already know:

```cpp
begin()
end()
```

Now we have:

```cpp
rbegin()
rend()
```

Think about it like this:

```text
Normal:

begin()
   ↓
[10] [20] [30] [40]
                    ↑
                   end()


Reverse:

rend()
   ↓
[10] [20] [30] [40]
                    ↑
                  rbegin()
```

So:

```text
begin()  → first element
end()    → after last element

rbegin() → last element
rend()   → before first element
```

---

# 6. Important: `rend()` is not an element

Just like:

```cpp
end()
```

doesn't point to a real element,

```cpp
rend()
```

doesn't point to a real element either.

So don't do:

```cpp
std::cout << *numbers.rend();
```

❌ Wrong.

Instead:

```cpp
while (it != numbers.rend())
{
    std::cout << *it;
    ++it;
}
```

---

# 7. Normal vs reverse

This is worth memorizing:

| Normal           | Reverse           |
| ---------------- | ----------------- |
| `begin()`        | `rbegin()`        |
| `end()`          | `rend()`          |
| starts at first  | starts at last    |
| `++it` → forward | `++it` → backward |

Example:

```text
Normal:

begin()
  ↓
10 → 20 → 30 → 40
                  ↓
                 end()


Reverse:

rbegin()
   ↓
40 → 30 → 20 → 10
                  ↓
                 rend()
```

---

# 8. Exercise 1 🧠

What will this print?

```cpp
std::vector<int> numbers;

numbers.push_back(5);
numbers.push_back(10);
numbers.push_back(15);

std::vector<int>::reverse_iterator it = numbers.rbegin();

std::cout << *it << std::endl;

++it;

std::cout << *it << std::endl;
```

Think:

```text
rbegin()
   ↓
[5] [10] [15]
```

Then:

```cpp
++it;
```

Where does it go?

---

# 9. Exercise 2

Complete this code:

```cpp
std::vector<int>::reverse_iterator it = numbers.________();

while (it != numbers.________())
{
    std::cout << ______ << std::endl;
    ______it;
}
```

The output should be:

```text
40
30
20
10
```

There are four blanks.

---

# 10. Exercise 3 — Modify elements

A normal `reverse_iterator` can modify elements.

For example:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);

std::vector<int>::reverse_iterator it = numbers.rbegin();

*it = 999;
```

Remember:

```text
rbegin()
   ↓
[10] [20] [30]
             ↑
```

So which element becomes `999`?

The vector becomes:

```text
[10] [20] [999]
```

Why?

Because `rbegin()` starts at the **last element**.

---

# 11. `const_reverse_iterator`

Just like normal iterators have:

```cpp
iterator
const_iterator
```

reverse iterators have:

```cpp
reverse_iterator
const_reverse_iterator
```

Example:

```cpp
std::vector<int>::const_reverse_iterator it;

it = numbers.rbegin();
```

You can read:

```cpp
std::cout << *it;
```

But you cannot do:

```cpp
*it = 500;
```

So:

```text
reverse_iterator
    ↓
read + write


const_reverse_iterator
    ↓
read only
```

---

# 12. `crbegin()` and `crend()`

There are also:

```cpp
numbers.crbegin()
numbers.crend()
```

These give const reverse iterators.

So now you have:

```text
Normal:
begin()
end()

Const:
cbegin()
cend()

Reverse:
rbegin()
rend()

Const reverse:
crbegin()
crend()
```

Don't try to memorize everything at once. The important pattern is:

```text
begin       → first
rbegin      → last

end         → after last
rend        → before first
```

---

# 13. A useful mental picture

Imagine people standing in a line:

```text
Ali   Bob   Sara   John
 ↑
begin
```

A normal iterator walks:

```text
Ali → Bob → Sara → John
```

A reverse iterator starts from John:

```text
John → Sara → Bob → Ali
```

But the code still says:

```cpp
++it;
```

because you're moving to the **next position of the iterator**.

---

# 🎯 Lesson 4 challenge

Look at this code:

```cpp
std::vector<int> numbers;

numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);
numbers.push_back(40);

std::vector<int>::reverse_iterator it = numbers.rbegin();

while (it != numbers.rend())
{
    std::cout << *it << std::endl;
    ++it;
}
```

Answer these **three questions**:

1. What is `*it` the first time?
2. What does `++it` do?
3. What is the final output?

Once this is clear, the next lesson will be **Lesson 5 — iterator types/categories**, where we'll understand why a `vector` iterator can do things that a `list` iterator cannot.
