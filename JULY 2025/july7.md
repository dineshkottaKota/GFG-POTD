# 🔍 Next Greater Element

## 📘 Problem Statement

You are given an array `arr[]` of size `n`.

For each element `arr[i]`, your task is to find the **next greater element** on its right side in the array.  
If there is no greater element, return `-1` for that index.

---

## 🧪 Examples

### Example 1:
**Input:**  
`arr = [1, 3, 2, 4]`  
**Output:**  
`[3, 4, 4, -1]`

**Explanation:**  
- Next greater for `1` is `3`  
- Next greater for `3` is `4`  
- Next greater for `2` is `4`  
- No greater for `4`, so `-1`

---

### Example 2:
**Input:**  
`arr = [6, 8, 0, 1, 3]`  
**Output:**  
`[8, -1, 1, 3, -1]`

**Explanation:**  
- Next greater for `6` is `8`  
- No greater for `8`  
- Next greater for `0` is `1`  
- Next greater for `1` is `3`  
- No greater for `3`

---

## 📋 Constraints

- `1 ≤ n ≤ 10^5`  
- `1 ≤ arr[i] ≤ 10^8`

---

## 💡 Approach

We use a **monotonic stack** to efficiently find the next greater element:

1. Traverse the array in reverse (`i = 2n-1` to `0`) to simulate circular array behavior.
2. Use a **stack** to store potential next greater elements.
3. For each element:
   - Pop from the stack until we find a greater element.
   - If stack is not empty, set the top as next greater.
   - Push current element into the stack.

This technique ensures that each element is processed in constant time on average.

---

## 🔁 Dry Run

For `arr = [1, 3, 2, 4]`  
Iterating from right to left:

- i = 3 → 4 → Stack: [] → Push 4  
- i = 2 → 2 < 4 → Next = 4 → Push 2  
- i = 1 → 3 > 2 → Pop 2 → 3 < 4 → Next = 4 → Push 3  
- i = 0 → 1 < 3 → Next = 3 → Push 1

Answer: `[3, 4, 4, -1]`

---

## ⏱ Time & Space Complexity

- **Time Complexity:** `O(n)`  
  Each element is pushed and popped at most once.
- **Space Complexity:** `O(n)`  
  For the stack and result array.

---

## 🧾 C++ Code

```cpp
class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i % n]) {
                st.pop();
            }
            if (i < n && !st.empty()) {
                ans[i] = st.top();
            }
            st.push(arr[i % n]);
        }

        return ans;
    }
};
