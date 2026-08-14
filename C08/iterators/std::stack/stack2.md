Great question. The key is:

**`stack` and `deque` have different purposes, even if `stack` uses a `deque` internally.**

### Think about it like this

A `deque` gives you **many operations**:

```cpp
d.push_front(10);
d.push_back(20);

d.pop_front();
d.pop_back();

d.front();
d.back();

d[0];
d[1];
```

So you have a lot of freedom.

A `stack` gives you only the operations needed for a **LIFO** structure:

```cpp
s.push(10);
s.push(20);

s.top();
s.pop();
```

Conceptually:

```text
deque:
 ┌──────────────────────────┐
 │ push_front()             │
 │ push_back()              │
 │ pop_front()              │
 │ pop_back()               │
 │ front()                  │
 │ back()                   │
 │ operator[]               │
 │ iterators                │
 └──────────────────────────┘

stack:
 ┌──────────────────────────┐
 │ push()                   │
 │ pop()                    │
 │ top()                    │
 │ empty()                  │
 │ size()                   │
 └──────────────────────────┘
```

### So why use `stack`?

Because **you don't always want to give yourself access to everything**.

Suppose your algorithm needs a stack:

```text
Last In → First Out
```

If you use a `deque` directly, someone could accidentally do:

```cpp
d.pop_front();
```

or:

```cpp
d.push_front(100);
```

Now your "stack" behavior can be broken.

With:

```cpp
std::stack<int> s;
```

the interface prevents those operations.

You can only work through the stack interface.

### Example

Imagine a function:

```cpp
void process(std::stack<int>& s)
{
    // This function knows:
    // "I am working with a LIFO structure."
}
```

The function doesn't care whether the stack internally uses:

```text
deque
vector
list
```

That's an important idea behind **container adaptors**.

```text
                 stack
                   │
          hides the implementation
                   │
          ┌────────┼────────┐
          ↓        ↓        ↓
        deque    vector    list
```

### The simplest way to remember

**`deque` = "Give me a double-ended container."**

**`stack` = "Give me a LIFO interface."**

So yes, you *could* use a `deque` directly. But `stack` is useful when you specifically want to enforce and express **stack behavior**.

This is exactly why `std::stack` is called a **container adaptor**: it takes an existing container and gives it a restricted interface specialized for a particular data structure.
