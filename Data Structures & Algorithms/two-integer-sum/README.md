# Two Sum

## Approach
- Use a hash map (`unordered_map`) to store each number along with its index.
- For every element, calculate the required complement:
  ```cpp
  complement = target - nums[i];
  ```
- Check if the complement already exists in the hash map.
  - If it does, return the stored index and the current index.
  - Otherwise, store the current number and its index.

---

## Why It Works
If `nums[i] + nums[j] = target`, then while iterating through the array:
- One of the numbers will already be stored in the hash map.
- The other number's complement will match the stored value, allowing us to find the answer in constant average time.

This avoids checking every possible pair.

---

## Algorithm
1. Create an empty hash map.
2. Traverse the array once.
3. Compute the complement:
   ```cpp
   complement = target - nums[i];
   ```
4. If the complement exists in the hash map, return its stored index and the current index.
5. Otherwise, store the current number and its index in the hash map.
6. Return an empty vector (not required for this problem since a solution is guaranteed).

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| **Time** | **O(n)** (average) |
| **Space** | **O(n)** |

- Each element is processed exactly once.
- Hash map lookup and insertion are **O(1)** on average.

---

## Key Insight
Instead of comparing every pair (`O(n²)`), store previously seen numbers in a hash map. For each element, directly check whether its complement has already been seen, reducing the solution to a single pass.

---

## Common Mistake

❌ Storing the current element before checking for its complement.

```cpp
mp[nums[i]] = i;

if (mp.find(complement) != mp.end()) {
    return {mp[complement], i};
}
```

This may incorrectly use the same element twice when `target == 2 * nums[i]`.

✅ Always check for the complement first, then store the current element.

```cpp
if (mp.find(complement) != mp.end()) {
    return {mp[complement], i};
}

mp[nums[i]] = i;
```

---

## Data Structure Used

```cpp
unordered_map<int, int> mp;
```

Stores:

| Key | Value |
|-----|-------|
| Number | Index |

Example:

```text
nums = [2, 7, 11, 15]

Hash Map
2  -> 0
7  -> 1
11 -> 2
15 -> 3
```
