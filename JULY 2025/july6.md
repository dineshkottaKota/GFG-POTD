# 🚀 Maximum Sum Combination

## 📘 Problem Statement

You are given two integer arrays `a[]` and `b[]` of equal length. A sum combination is defined as the sum of one element from `a` and one from `b`, i.e., `a[i] + b[j]`.

Your task is to return the **top k maximum sum combinations**, sorted in **non-increasing** order.  
Each index pair `(i, j)` can be used at most once.

---

## 🧪 Examples

### Example 1:
**Input:**  
`a = [3, 2], b = [1, 4], k = 2`  
**Output:**  
`[7, 6]`  

**Explanation:**  
All combinations:  
- `(3+1)=4`  
- `(3+4)=7`  
- `(2+1)=3`  
- `(2+4)=6`  
Top 2 sums = `[7, 6]`.

---

### Example 2:
**Input:**  
`a = [1, 4, 2, 3], b = [2, 5, 1, 6], k = 3`  
**Output:**  
`[10, 9, 9]`  

**Explanation:**  
Top combinations:
- `4+6 = 10`
- `3+6 = 9`
- `4+5 = 9`

---

## 📋 Constraints

- `1 ≤ a.length == b.length ≤ 10^5`  
- `1 ≤ k ≤ a.length`  
- `1 ≤ a[i], b[i] ≤ 10^4`

---

## 💡 Approach

1. **Sort** both arrays `a` and `b` in ascending order.
2. Use a **max-heap** (priority queue) to track the largest possible sums.
3. Always push the **largest unvisited pairs** into the heap.
4. Use a **set** to avoid repeating index pairs.
5. Extract the **top k** combinations.

---

## ⏱ Time & Space Complexity

- **Time Complexity:** `O(n log n + k log k)`
- **Space Complexity:** `O(k)` (for heap + set + result)

---

## 🧾 C++ Code

```cpp
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int m = a.size(), n = b.size();

        vector<int> ans;
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> st;

        pq.push({a[m - 1] + b[n - 1], {m - 1, n - 1}});
        st.insert({m - 1, n - 1});

        while (k-- && !pq.empty()) {
            auto it = pq.top(); pq.pop();
            int sum = it.first;
            int i = it.second.first, j = it.second.second;
            ans.push_back(sum);

            if (i - 1 >= 0 && st.find({i - 1, j}) == st.end()) {
                pq.push({a[i - 1] + b[j], {i - 1, j}});
                st.insert({i - 1, j});
            }
            if (j - 1 >= 0 && st.find({i, j - 1}) == st.end()) {
                pq.push({a[i] + b[j - 1], {i, j - 1}});
                st.insert({i, j - 1});
            }
        }
        return ans;
    }
};
