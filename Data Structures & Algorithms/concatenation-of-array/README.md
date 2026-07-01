# Concatenation of Array

**NeetCode:** [Concatenation of Array](https://neetcode.io/problems/concatenation-of-array)
**Difficulty:** Easy | **Pattern:** Arrays

---

## Problem

Given an integer array `nums` of length `n`, return an array of length `2n` where the first `n` elements are `nums` and the last `n` elements are also `nums`.

---

## Solution 1 — Index Copy (`solution_index_copy.cpp`)

### Approach
Pre-allocate a `2n` array, then fill both halves in one pass by assigning `arr[i] = nums[i]` and `arr[i+n] = nums[i]`.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

### Key Insight
Pre-sizing the array avoids dynamic resizing. Direct index assignment is safer than calling `insert()` element-by-element inside a loop — that shifts elements on every call and corrupts the output.

---

## Solution 2 — Vector Insert (`solution_vector_insert.cpp`)

### Approach
Copy `nums` into a new vector, then prepend another copy of `nums` at the front using a single bulk `insert()` call.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) |

### Key Insight
`arr.insert(arr.begin(), nums.begin(), nums.end())` is a single bulk operation — clean and idiomatic C++. The key is doing it in one call, not element-by-element in a loop.

---

## Example Walkthrough (Solution 1 — Index Copy)

Input: `nums = [1, 2, 1]`, so `n = 3`

| i | arr[i] = nums[i] | arr[i+n] = nums[i] | arr so far |
|---|---|---|---|
| 0 | arr[0] = 1 | arr[3] = 1 | `[1, _, _, 1, _, _]` |
| 1 | arr[1] = 2 | arr[4] = 2 | `[1, 2, _, 1, 2, _]` |
| 2 | arr[2] = 1 | arr[5] = 1 | `[1, 2, 1, 1, 2, 1]` |

Final output: `[1, 2, 1, 1, 2, 1]`
