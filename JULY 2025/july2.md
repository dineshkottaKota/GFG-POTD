# 🔢 Longest Subarray with At Most Two Distinct Integers

## 🧩 Problem Statement

Given an array `arr[]` consisting of positive integers, find the **length of the longest subarray** that contains **at most two distinct integers**.

---

### ✅ Constraints:
- 1 ≤ arr.length ≤ 10⁵  
- 1 ≤ arr[i] ≤ 10⁵

---

## 📥 Input

- An array of integers `arr[]`.

## 📤 Output

- An integer representing the length of the longest valid subarray.

---

## 🧪 Examples

### Example 1:
**Input:**  
`arr = [2, 1, 2]`  
**Output:**  
`3`  
**Explanation:**  
The entire array `[2, 1, 2]` has only two distinct elements.

---

### Example 2:
**Input:**  
`arr = [3, 1, 2, 2, 2, 2]`  
**Output:**  
`5`  
**Explanation:**  
The longest subarray with ≤2 distinct elements is `[1, 2, 2, 2, 2]`.

---

## 🚀 Approach

We use a **sliding window** and a **hash map** to track the frequency of elements within the window.

### Steps:
1. Initialize two pointers `i` and `j` for the window.
2. Expand the window (`j++`) until more than 2 distinct elements are present.
3. When that happens, shrink the window from the left (`i++`) until it has at most 2 distinct elements.
4. Track the **maximum window size**.

---

### ⏱️ Time Complexity:
- **O(n)** — Each element is visited at most twice.

### 🧠 Space Complexity:
- **O(1)** — At most 3 keys in the map (since only 2 distinct values allowed).

---

## 🧠 Code (C++)

```cpp
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        int i = 0, j = 0, ans = 0;
        unordered_map<int, int> mpp;

        while (i <= j && j < n) {
            while (mpp.size() <= 2 && j < n) {
                if (mpp.find(arr[j]) == mpp.end() && mpp.size() == 2) break;
                mpp[arr[j++]]++;
            }
            ans = max(ans, j - i);
            mpp[arr[i]]--;
            if (mpp[arr[i]] == 0) mpp.erase(arr[i]);
            i++;
        }
        return ans;
    }
};
