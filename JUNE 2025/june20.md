# 🎯 Group Balls by Sequence

## 📝 Problem Statement

You are given an array `arr[]` of positive integers, where each element represents the number on a ball, and a positive integer `k`.

Your task is to determine whether it's possible to rearrange all balls into groups such that:

- Each group contains exactly `k` balls.
- The numbers in each group are **consecutive integers**.

---

### ✅ Constraints:
- 1 ≤ arr.size() ≤ 10⁶  
- 0 ≤ arr[i] ≤ 10⁵  
- 1 ≤ k ≤ 10³

---

## 📥 Input

- An array `arr[]` of integers
- An integer `k`

## 📤 Output

- `true` if such grouping is possible, otherwise `false`.

---

## 🧪 Examples

### Example 1:
**Input:**  
`arr = [10, 1, 2, 11], k = 2`  
**Output:**  
`true`  
**Explanation:**  
Can be grouped as [1, 2] and [10, 11], both of size 2 with consecutive numbers.

---

### Example 2:
**Input:**  
`arr = [7, 8, 9, 10, 11], k = 2`  
**Output:**  
`false`  
**Explanation:**  
Cannot divide 5 elements into groups of size 2.

---

## 🚀 Approach

1. If the total number of balls is not divisible by `k`, return `false`.
2. Use a `map<int, int>` to count frequencies of each number.
3. Iterate through the sorted keys:
   - For each key `num`, if it appears `cnt` times:
     - Check and subtract `cnt` from `num`, `num+1`, ..., `num+k-1`
     - If any value is insufficient, return `false`.
4. If all groups are formed successfully, return `true`.

---

### Time Complexity:
- **O(n log n)** — due to map operations (sorting + frequency counting)

### Auxiliary Space:
- **O(n)** — for storing frequencies

---

## 🧠 Code Explanation (C++)

```cpp
class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if (n % k != 0) return false;

        map<int, int> mp;
        for (int it : arr) mp[it]++;

        for (auto it : mp) {
            int num = it.first;
            int cnt = it.second;

            if (cnt > 0) {
                for (int i = 0; i < k; i++) {
                    if (mp[num + i] < cnt) return false;
                    mp[num + i] -= cnt;
                }
            }
        }

        return true;
    }
};
