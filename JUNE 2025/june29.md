# 📦 Split Array Largest Sum

## 🧩 Problem Statement

Given an array `arr[]` and an integer `k`, divide the array into `k` contiguous subarrays such that the **maximum sum** among these subarrays is **minimized**.

Return the minimum possible value of this maximum sum.

---

### ✅ Constraints:
- 1 ≤ k ≤ arr.size() ≤ 10⁵  
- 1 ≤ arr[i] ≤ 10⁴  

---

## 📥 Input

- A list of integers `arr[]`
- An integer `k` (number of subarrays to split into)

## 📤 Output

- Minimum value of the **maximum subarray sum** after splitting into `k` parts

---

## 🧪 Examples

### Example 1:
**Input:**  
`arr = [1, 2, 3, 4], k = 3`  
**Output:**  
`4`  
**Explanation:**  
Optimal split is [1, 2], [3], [4] → Max sum = 4

---

### Example 2:
**Input:**  
`arr = [1, 1, 2], k = 2`  
**Output:**  
`2`  
**Explanation:**  
Split as [1, 1], [2] → Max sum = 2

---

## 🚀 Approach

We use **Binary Search on the answer**:

1. **Lower bound** = max(arr)  
2. **Upper bound** = sum(arr)  
3. For each `mid`, check if it's possible to split the array into ≤ `k` subarrays such that each has a sum ≤ `mid`.

Use a **greedy validation function** to count how many parts are needed for a given `mid`.

---

### Time Complexity:
- **O(n × log(sum - max))**

### Auxiliary Space:
- **O(1)**

---

## 🧠 Code (C++)

```cpp
class Solution {
  public:
    bool valid(vector<int>& arr, int k, int mid) {
        int count = 1, sum = 0;
        for (int it : arr) {
            if (sum + it > mid) {
                count++;
                sum = it;
            } else {
                sum += it;
            }
        }
        return count <= k;
    }

    int splitArray(vector<int>& arr, int k) {
        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        int ans = r;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (valid(arr, k, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
