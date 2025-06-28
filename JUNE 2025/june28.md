# 📊 Counting Elements in Two Arrays

## 📝 Problem Statement

You are given two unsorted arrays `a[]` and `b[]`, which may contain duplicate elements.

For **each element in array `a`**, count how many elements in array `b` are **less than or equal** to it.

---

### ✅ Constraints:
- 1 ≤ a.size(), b.size() ≤ 10⁵  
- 0 ≤ a[i], b[j] ≤ 10⁵

---

## 📥 Input

- An array `a[]` of integers  
- An array `b[]` of integers

## 📤 Output

- An array where each element corresponds to the count of elements in `b` that are ≤ the respective element in `a`.

---

## 🧪 Examples

### Example 1:
**Input:**  
`a = [4, 8, 7, 5, 1]`  
`b = [4, 48, 3, 0, 1, 1, 5]`  
**Output:**  
`[5, 6, 6, 6, 3]`  
**Explanation:**  
- `4` → [4, 3, 0, 1, 1] → 5  
- `8`, `7`, `5` → all ≥ 6 elements in `b`  
- `1` → [0, 1, 1] → 3

---

### Example 2:
**Input:**  
`a = [10, 20]`  
`b = [30, 40, 50]`  
**Output:**  
`[0, 0]`  
**Explanation:**  
No element in `b` is ≤ 10 or 20.

---

## 🚀 Approach

1. **Sort** array `b`.
2. For each element in `a`, use **binary search** (`upper_bound`) to count how many elements in `b` are ≤ that element.
3. To **optimize repeated queries**, sort a copy of `a` and **precompute** counts for unique elements.
4. Use a **map** to store and reuse results efficiently.

---

### Time Complexity:
- **O(n log n + m log m)**  
  `n` = size of `a`, `m` = size of `b`

### Auxiliary Space:
- **O(n + m)** for extra arrays and map

---

## 🧠 Code (C++)

```cpp
class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> mpp;
        vector<int> temp = a;

        sort(temp.begin(), temp.end());
        sort(b.begin(), b.end());

        for (auto it : temp) {
            mpp[it] = upper_bound(b.begin(), b.end(), it) - b.begin();
        }

        for (int i = 0; i < a.size(); i++) {
            a[i] = mpp[a[i]];
        }

        return a;
    }
};
