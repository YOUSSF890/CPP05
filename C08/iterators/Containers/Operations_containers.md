Absolutely. In C++, **STL containers** share many common operations, but each container also has operations specific to its data structure.

Here is a useful **STL Containers operation map**.

## 1. Common operations

Most STL containers provide these:

| Operation  | Meaning                     | Example      |
| ---------- | --------------------------- | ------------ |
| `size()`   | Number of elements          | `v.size()`   |
| `empty()`  | Check if container is empty | `v.empty()`  |
| `clear()`  | Remove everything           | `v.clear()`  |
| `begin()`  | Iterator to first element   | `v.begin()`  |
| `end()`    | Iterator past last element  | `v.end()`    |
| `cbegin()` | Const iterator to first     | `v.cbegin()` |
| `cend()`   | Const iterator past last    | `v.cend()`   |
| `rbegin()` | Reverse iterator            | `v.rbegin()` |
| `rend()`   | Reverse end iterator        | `v.rend()`   |
| `front()`  | First element               | `v.front()`  |
| `back()`   | Last element                | `v.back()`   |

Example:

```cpp
std::vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);

std::cout << v.size() << std::endl;
std::cout << v.front() << std::endl;
std::cout << v.back() << std::endl;

if (!v.empty())
    std::cout << "Not empty" << std::endl;
```

---

# 2. Sequence Containers

The main sequence containers are:

```text
vector
deque
list
forward_list
array
```

---

## `std::vector`

Dynamic contiguous array.

```cpp
std::vector<int> v;
```

### Add

```cpp
v.push_back(10);
v.emplace_back(20);
```

### Remove

```cpp
v.pop_back();
```

### Access

```cpp
v[0];
v.at(0);
v.front();
v.back();
```

### Insert

```cpp
v.insert(v.begin(), 100);
```

### Erase

```cpp
v.erase(v.begin());
```

### Resize

```cpp
v.resize(10);
```

### Capacity

```cpp
v.capacity();
v.reserve(100);
v.shrink_to_fit();
```

### Swap

```cpp
v.swap(other);
```

---

# 3. `std::deque`

Double-ended queue.

```cpp
std::deque<int> d;
```

Can efficiently add/remove from **both ends**.

### Add

```cpp
d.push_back(10);
d.push_front(20);

d.emplace_back(30);
d.emplace_front(40);
```

### Remove

```cpp
d.pop_back();
d.pop_front();
```

### Access

```cpp
d[0];
d.at(0);
d.front();
d.back();
```

### Insert / erase

```cpp
d.insert(d.begin(), 100);
d.erase(d.begin());
```

---

# 4. `std::list`

Doubly linked list.

```cpp
std::list<int> l;
```

### Add

```cpp
l.push_back(10);
l.push_front(20);

l.emplace_back(30);
l.emplace_front(40);
```

### Remove

```cpp
l.pop_back();
l.pop_front();
```

### Insert

```cpp
l.insert(l.begin(), 100);
```

### Erase

```cpp
l.erase(l.begin());
```

### Special operations

```cpp
l.sort();
l.reverse();
l.unique();
l.remove(10);
```

### Splice

Move elements from one list to another:

```cpp
l.splice(l.begin(), other);
```

---

# 5. `std::forward_list`

Singly linked list.

```cpp
std::forward_list<int> fl;
```

It only moves **forward**.

```text
10 → 20 → 30 → NULL
```

### Add

```cpp
fl.push_front(10);
fl.emplace_front(20);
```

### Remove

```cpp
fl.pop_front();
```

### Insert

Because there is no `push_back()`, insertion is usually done **after** an iterator:

```cpp
fl.insert_after(fl.before_begin(), 10);
```

### Erase

```cpp
fl.erase_after(fl.before_begin());
```

### Special

```cpp
fl.sort();
fl.reverse();
fl.unique();
fl.remove(10);
```

---

# 6. `std::array`

Fixed-size array.

```cpp
std::array<int, 5> a;
```

Size is known at compile time.

```cpp
std::array<int, 5> a = {1, 2, 3, 4, 5};
```

### Access

```cpp
a[0];
a.at(0);
a.front();
a.back();
```

### Size

```cpp
a.size();
a.empty();
```

### Fill

```cpp
a.fill(42);
```

### Swap

```cpp
a.swap(other);
```

There is **no**:

```cpp
push_back()
pop_back()
insert()
erase()
```

because its size is fixed.

---

# 7. Associative Containers

These store elements according to a **key/order**.

```text
set
multiset
map
multimap
```

---

# 8. `std::set`

Stores **unique values**, sorted.

```cpp
std::set<int> s;

s.insert(30);
s.insert(10);
s.insert(20);
s.insert(10);
```

Result:

```text
10 20 30
```

The second `10` is ignored.

### Insert

```cpp
s.insert(10);
```

### Remove

```cpp
s.erase(10);
```

or:

```cpp
s.erase(s.begin());
```

### Search

```cpp
s.find(20);
```

### Count

```cpp
s.count(20);
```

For `set`, `count()` is normally:

```text
0 → doesn't exist
1 → exists
```

### Bounds

```cpp
s.lower_bound(20);
s.upper_bound(20);
```

---

# 9. `std::multiset`

Like `set`, but duplicates are allowed.

```cpp
std::multiset<int> ms;

ms.insert(10);
ms.insert(10);
ms.insert(20);
```

Result:

```text
10 10 20
```

Useful operations:

```cpp
ms.insert(10);
ms.erase(10);
ms.find(10);
ms.count(10);
ms.lower_bound(10);
ms.upper_bound(10);
```

---

# 10. `std::map`

Stores:

```text
key → value
```

Example:

```cpp
std::map<std::string, int> ages;

ages["Ali"] = 20;
ages["Bob"] = 25;
```

Conceptually:

```text
Ali → 20
Bob → 25
```

### Insert

```cpp
ages.insert(std::make_pair("John", 30));
```

Modern C++:

```cpp
ages.emplace("John", 30);
```

### Access

```cpp
ages["Ali"];
ages.at("Ali");
```

### Search

```cpp
ages.find("Ali");
```

### Check existence

```cpp
ages.count("Ali");
```

### Remove

```cpp
ages.erase("Ali");
```

### Bounds

```cpp
ages.lower_bound("Ali");
ages.upper_bound("Ali");
```

---

# 11. `std::multimap`

Like `map`, but **multiple elements can have the same key**.

```cpp
std::multimap<std::string, int> grades;

grades.insert({"Ali", 15});
grades.insert({"Ali", 18});
grades.insert({"Bob", 12});
```

Result:

```text
Ali → 15
Ali → 18
Bob → 12
```

Useful:

```cpp
grades.insert(...);
grades.emplace(...);

grades.find("Ali");
grades.count("Ali");

grades.erase("Ali");

grades.lower_bound("Ali");
grades.upper_bound("Ali");
```

---

# 12. Unordered Containers

These use **hash tables** instead of ordered trees.

```text
unordered_set
unordered_multiset
unordered_map
unordered_multimap
```

---

# 13. `std::unordered_set`

Unique values, no sorted order.

```cpp
std::unordered_set<int> us;

us.insert(10);
us.insert(20);
us.insert(10);
```

Operations:

```cpp
us.insert(10);
us.emplace(20);

us.find(10);
us.count(10);

us.erase(10);

us.size();
us.empty();
us.clear();
```

Hash-specific operations:

```cpp
us.bucket_count();
us.bucket(10);
us.load_factor();
us.max_load_factor();
us.rehash(100);
us.reserve(100);
```

---

# 14. `std::unordered_map`

Key → value using hashing.

```cpp
std::unordered_map<std::string, int> m;

m["Ali"] = 20;
m["Bob"] = 25;
```

Common:

```cpp
m.insert({"John", 30});
m.emplace("Sara", 22);

m["Ali"];
m.at("Ali");

m.find("Ali");
m.count("Ali");

m.erase("Ali");

m.size();
m.empty();
m.clear();
```

Hash-specific:

```cpp
m.bucket_count();
m.load_factor();
m.max_load_factor();
m.rehash(100);
m.reserve(100);
```

---

# 15. `std::stack`

A **container adaptor**.

It follows:

```text
LIFO
Last In → First Out
```

```text
     30 ← top
     20
     10
```

```cpp
std::stack<int> s;
```

### Add

```cpp
s.push(10);
s.push(20);
s.emplace(30);
```

### Remove

```cpp
s.pop();
```

### Access

```cpp
s.top();
```

### Other

```cpp
s.empty();
s.size();
```

There is **no iterator** for `std::stack`.

---

# 16. `std::queue`

FIFO:

```text
First In → First Out
```

```text
10 → 20 → 30
↑          ↑
front      back
```

```cpp
std::queue<int> q;
```

### Add

```cpp
q.push(10);
q.emplace(20);
```

### Remove

```cpp
q.pop();
```

### Access

```cpp
q.front();
q.back();
```

### Other

```cpp
q.empty();
q.size();
```

---

# 17. `std::priority_queue`

The largest element is normally at the top.

```cpp
std::priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(20);
```

Top:

```cpp
pq.top(); // 50
```

Operations:

```cpp
pq.push(100);
pq.emplace(200);

pq.top();

pq.pop();

pq.empty();
pq.size();
```

---

# 18. Iterator Operations

This is **very important** for STL.

Almost all normal containers support:

```cpp
begin()
end()
```

Example:

```cpp
std::vector<int> v = {10, 20, 30};

std::vector<int>::iterator it;

for (it = v.begin(); it != v.end(); ++it)
{
    std::cout << *it << std::endl;
}
```

You can also use:

```cpp
cbegin()
cend()

rbegin()
rend()

crbegin()
crend()
```

### Iterator modification

```cpp
*it = 100;
```

if the iterator is not const.

---

# 19. `insert()` vs `emplace()`

This is an important distinction.

### `insert`

You give the container an already-created object/value.

```cpp
std::vector<std::pair<int, std::string> > v;

v.insert(v.begin(), std::make_pair(1, "Hello"));
```

### `emplace`

The container constructs the object directly.

```cpp
v.emplace(v.begin(), 1, "Hello");
```

For maps:

```cpp
m.insert(std::make_pair("Ali", 20));

m.emplace("Ali", 20);
```

---

# 20. `erase()`

There are several forms.

### By iterator

```cpp
v.erase(v.begin());
```

### By range

```cpp
v.erase(v.begin(), v.begin() + 3);
```

### By key

For associative containers:

```cpp
s.erase(10);
m.erase("Ali");
```

---

# 21. `find()`

Very important with associative containers.

```cpp
std::set<int> s;

s.insert(10);
s.insert(20);

std::set<int>::iterator it = s.find(20);
```

If found:

```cpp
if (it != s.end())
    std::cout << "Found";
```

If not found:

```cpp
it == s.end()
```

---

# 22. `count()`

Checks how many matching elements exist.

```cpp
s.count(20);
```

For `set`:

```text
0 or 1
```

For `multiset`:

```text
0, 1, 2, 3, ...
```

For `map`:

```text
0 or 1
```

For `multimap`:

```text
0, 1, 2, 3, ...
```

---

# 23. `lower_bound()` and `upper_bound()`

Very important for ordered containers.

Suppose:

```cpp
std::set<int> s = {10, 20, 30, 40};
```

### `lower_bound(25)`

Returns first element **>= 25**:

```text
30
```

### `upper_bound(20)`

Returns first element **> 20**:

```text
30
```

So:

```text
lower_bound(x) → >= x

upper_bound(x) → > x
```

---

# 24. `swap()`

Exchange two containers.

```cpp
std::vector<int> a = {1, 2, 3};
std::vector<int> b = {4, 5};

a.swap(b);
```

Now:

```text
a → 4 5
b → 1 2 3
```

There is also:

```cpp
std::swap(a, b);
```

---

# 25. `size()` vs `capacity()`

Very important with `vector`.

```cpp
std::vector<int> v;

v.push_back(10);
v.push_back(20);
```

### `size()`

Number of actual elements:

```cpp
v.size();
```

Result:

```text
2
```

### `capacity()`

Amount of allocated storage:

```cpp
v.capacity();
```

Could be:

```text
2
4
...
```

So:

```text
size     = elements currently stored
capacity = allocated space
```

---

# 26. `reserve()` vs `resize()`

### `reserve()`

Changes **capacity**, not the number of elements.

```cpp
v.reserve(100);
```

Afterward:

```text
size     = unchanged
capacity >= 100
```

### `resize()`

Changes the **number of elements**.

```cpp
v.resize(100);
```

Now:

```text
size = 100
```

---

# 27. Quick Cheat Sheet

| Container        | Add               | Remove           | Access       | Search | Special               |
| ---------------- | ----------------- | ---------------- | ------------ | ------ | --------------------- |
| `vector`         | `push_back`       | `pop_back`       | `[]`, `at`   | —      | `reserve`, `capacity` |
| `deque`          | `push_front/back` | `pop_front/back` | `[]`, `at`   | —      | double-ended          |
| `list`           | `push_front/back` | `pop_front/back` | `front/back` | —      | `sort`, `splice`      |
| `forward_list`   | `push_front`      | `pop_front`      | —            | —      | singly linked         |
| `array`          | —                 | —                | `[]`, `at`   | —      | `fill`                |
| `set`            | `insert`          | `erase`          | —            | `find` | sorted + unique       |
| `multiset`       | `insert`          | `erase`          | —            | `find` | sorted + duplicates   |
| `map`            | `insert/emplace`  | `erase`          | `[]`, `at`   | `find` | key/value             |
| `multimap`       | `insert/emplace`  | `erase`          | —            | `find` | duplicate keys        |
| `unordered_set`  | `insert`          | `erase`          | —            | `find` | hash                  |
| `unordered_map`  | `insert/emplace`  | `erase`          | `[]`, `at`   | `find` | hash                  |
| `stack`          | `push`            | `pop`            | `top`        | —      | LIFO                  |
| `queue`          | `push`            | `pop`            | `front/back` | —      | FIFO                  |
| `priority_queue` | `push`            | `pop`            | `top`        | —      | priority              |

## The most important operations to learn first

Since you're learning **C++ iterators/STL**, I'd learn them in this order:

```text
1. begin() / end()
2. size() / empty()
3. insert()
4. erase()
5. find()
6. push_back()
7. push_front()
8. pop_back()
9. pop_front()
10. front() / back()
11. [] / at()
12. lower_bound() / upper_bound()
13. emplace()
14. clear()
15. swap()
```

Then learn **iterator invalidation**, because understanding when `insert()`, `erase()`, and `push_back()` invalidate iterators is one of the most important parts of working correctly with STL containers.
