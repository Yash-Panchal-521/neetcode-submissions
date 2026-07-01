# Design HashMap

**NeetCode:** [Design HashMap](https://neetcode.io/problems/design-hashmap)
**Difficulty:** Easy | **Pattern:** Design / Arrays

---

## Problem

Design a HashMap without using any built-in hash table libraries. Implement `put(key, value)`, `get(key)`, and `remove(key)`.

---

## Solution — Linear Scan (`solution_linear_scan.cpp`)

### Approach
Store `(key, value)` pairs in a plain `vector<pair<int,int>>`. Every operation does a linear scan with `find_if` to locate the entry matching the key.

### Algorithm
1. `put`: scan for an existing pair with the given key. If found, overwrite its value; otherwise append a new pair.
2. `get`: scan for the key; return its value if found, else `-1`.
3. `remove`: scan for the key; erase the pair if found.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) per operation (linear scan) |
| **Space** | O(n) for stored pairs |

### Key Insight
This satisfies "no built-in hash table" but sacrifices O(1) average-case lookup. A real hash map implementation would bucket entries by `key % capacity` to get O(1) average time — worth revisiting as a follow-up.

---

## Example Walkthrough

Operations: `put(1, 10)`, `put(2, 20)`, `get(1)`, `put(1, 99)`, `get(1)`, `remove(2)`, `get(2)`

| Call | Internal `mp` after call | Return |
|---|---|---|
| `put(1, 10)` | `[(1,10)]` | — |
| `put(2, 20)` | `[(1,10), (2,20)]` | — |
| `get(1)` | `[(1,10), (2,20)]` | `10` |
| `put(1, 99)` | `[(1,99), (2,20)]` | — (existing pair overwritten) |
| `get(1)` | `[(1,99), (2,20)]` | `99` |
| `remove(2)` | `[(1,99)]` | — |
| `get(2)` | `[(1,99)]` | `-1` (not found) |
