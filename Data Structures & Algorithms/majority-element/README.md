# Majority Element

**NeetCode:** [Majority Element](https://neetcode.io/problems/majority-element)
**Difficulty:** Easy | **Pattern:** Arrays / Hashing / Boyer-Moore Voting

---

## Problem

Given an array `nums` of size n, return the majority element — the element that appears more than `⌊n / 2⌋` times. The majority element always exists in the input.

---

## Solution 1 — Hash Map (`solution_hashmap.cpp`)

### Approach
Count occurrences of every number in an `unordered_map<int,int>`, then scan the map for the entry whose count exceeds `n / 2`.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) |
| **Space** | O(n) for the count map |

### Key Insight
Simple and reliable, but uses O(n) extra space. The problem's guarantee that a majority element exists is what makes the smarter Boyer-Moore approach (Solution 2) possible in O(1) space.

---

## Solution 2 — Boyer-Moore Voting (`solution_boyer_moore_voting.cpp`)

### Approach
Track a single candidate and a running count. Walk through the array: if count hits zero, adopt the current number as the new candidate. Increment count when the number matches the candidate, decrement otherwise.

### Algorithm
1. Initialize `count = 0` and an empty candidate.
2. For each number: if `count == 0`, set `candidate = num`.
3. If `num == candidate`, increment `count`; otherwise decrement it.
4. After the scan, `candidate` holds the majority element.

### Complexity

| | Value |
|---|---|
| **Time** | O(n) |
| **Space** | O(1) |

### Key Insight
Because the majority element occurs more than n/2 times, it can never be fully "cancelled out" by the other elements — the voting process always converges on it. This only works because the problem guarantees a majority element exists; without that guarantee, a verification pass would be needed.

---

## Example Walkthrough (Solution 2 — Boyer-Moore Voting)

Input: `nums = [2, 2, 1, 1, 1, 2, 2]`

| Step | num | count before | Action | candidate | count after |
|---|---|---|---|---|---|
| 1 | 2 | 0 | count==0 → candidate = 2 | 2 | 1 |
| 2 | 2 | 1 | num == candidate → count++ | 2 | 2 |
| 3 | 1 | 2 | num != candidate → count-- | 2 | 1 |
| 4 | 1 | 1 | num != candidate → count-- | 2 | 0 |
| 5 | 1 | 0 | count==0 → candidate = 1 | 1 | 1 |
| 6 | 2 | 1 | num != candidate → count-- | 1 | 0 |
| 7 | 2 | 0 | count==0 → candidate = 2 | 2 | 1 |

Final `candidate = 2` → return `2` (appears 4 times out of 7, more than ⌊7/2⌋ = 3).

---

## Comparison

| | Hash Map | Boyer-Moore Voting |
|---|---|---|
| Time | O(n) | O(n) |
| Space | O(n) | O(1) |
| Preferred? | ❌ Uses extra space | ✅ Optimal |
