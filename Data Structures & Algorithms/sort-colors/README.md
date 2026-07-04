# Sort Colors

**NeetCode:** [Sort Colors](https://neetcode.io/problems/sort-colors)
**Difficulty:** Medium | **Pattern:** Three Pointers (Dutch National Flag)

---

## Problem

Given an array `nums` containing only the values `0`, `1`, and `2` (representing colors red, white, and blue), sort it in-place so all `0`s come first, then all `1`s, then all `2`s — without using a library sort.

---

## Solution — Dutch National Flag Partition (`solution_dutch_national_flag.cpp`)

### Approach
Maintain three pointers that partition the array into four regions as you scan once: `[0, i)` confirmed `0`s, `[i, k)` confirmed `1`s, `[k, j]` unknown/unprocessed, and `(j, n)` confirmed `2`s. A single pointer `k` walks forward reading the current element and deciding where it belongs; `i` and `j` mark the boundaries of the `0`s and `2`s regions and only move when a swap places a new value at the front or back.

### Algorithm
1. Initialize `i = 0`, `k = 0`, `j = n - 1`.
2. While `k <= j`:
   - If `nums[k] == 0`: swap `nums[i]` and `nums[k]`, then increment both `i` and `k` (the swapped-in value at `k` is already known to be `0` or was already scanned, so it's safe to advance `k` too).
   - Else if `nums[k] == 2`: swap `nums[j]` and `nums[k]`, then decrement `j` only (the value swapped into `k` from the back hasn't been checked yet, so `k` stays put).
   - Else (`nums[k] == 1`): it's already in the middle region, just increment `k`.
3. Stop once `k` passes `j` — every element has been classified.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) — single pass, each index visited a constant number of times |
| **Space** | O(1) |

### Key Insight
The asymmetry between the two swap branches is the crux of this pattern: after swapping a `0` into place from the front, the element now at `k` came from a region already known to be scanned, so `k` can safely advance. After swapping a `2` into place from the back, the element now at `k` came from unscanned territory (`j`'s old value), so `k` must stay and be re-examined next iteration.

---

## Example Walkthrough

Input: `nums = [2, 0, 2, 1, 1, 0]`

| Step | i | k | j | nums[k] | Action | nums after |
|---|---|---|---|---|---|---|
| 1 | 0 | 0 | 5 | 2 | swap(nums[j], nums[k]); j-- | `[0, 0, 2, 1, 1, 2]` |
| 2 | 0 | 0 | 4 | 0 | swap(nums[i], nums[k]); i++, k++ | `[0, 0, 2, 1, 1, 2]` |
| 3 | 1 | 1 | 4 | 0 | swap(nums[i], nums[k]); i++, k++ | `[0, 0, 2, 1, 1, 2]` |
| 4 | 2 | 2 | 4 | 2 | swap(nums[j], nums[k]); j-- | `[0, 0, 1, 1, 2, 2]` |
| 5 | 2 | 2 | 3 | 1 | k++ | `[0, 0, 1, 1, 2, 2]` |
| 6 | 2 | 3 | 3 | 1 | k++ | `[0, 0, 1, 1, 2, 2]` |
| — | 2 | 4 | 3 | — | k > j, stop | `[0, 0, 1, 1, 2, 2]` |

Final result: `[0, 0, 1, 1, 2, 2]` — all `0`s, then `1`s, then `2`s.

## Common Mistake
After swapping in a value from the back (`nums[j]`), it's tempting to advance `k` along with `j` — but the value that just landed at `k` hasn't been inspected yet and could itself be a `0` or a `2`. Advancing `k` in that branch would silently skip classifying it. Only the front-swap branch (`0` case) is safe to advance both pointers together, because everything before `k` has already been scanned in this pass.
