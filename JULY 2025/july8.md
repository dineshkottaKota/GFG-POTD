# 📊 Next Element with Greater Frequency

## 📝 Problem Statement

Given an array `arr[]` of integers, for each element, find the **closest element to its right** that has a **higher frequency** than the current element.

If no such element exists, return `-1` for that position.

---

## 🧪 Examples

### Example 1:

**Input:**  
`arr = [2, 1, 1, 3, 2, 1]`  

**Output:**  
`[1, -1, -1, 2, 1, -1]`  

**Explanation:**  
- Frequencies: `1 → 3`, `2 → 2`, `3 → 1`  
- For `arr[0] = 2`, the next element with higher frequency is `1`.  
- For `arr[3] = 3`, the next with higher frequency is `2`.  
- Others don't have any valid elements to their right.

---

### Example 2:

**Input:**  
`arr = [5, 1, 5, 6, 6]`  

**Output:**  
`[-1, 5, -1, -1, -1]`  

**Explanation:**  
- Frequencies: `5 → 2`, `6 → 2`, `1 → 1`  
- Only `arr[1] = 1` has a next element `5` with higher frequency.

---

## 📌 Constraints

- `1 ≤ arr.size() ≤ 10^5`  
- `1 ≤ arr[i] ≤ 10^5`

---

## 📈 Expected Time and Space Complexity

| Metric            | Complexity      |
|-------------------|-----------------|
| Time Complexity   | O(n)            |
| Auxiliary Space   | O(n)            |

---

## 🧠 Approach

We use a **monotonic stack** and a **hash map** to track frequencies:

1. **Frequency Map:**  
   Use `unordered_map<int, int>` to count frequency of each number.

2. **Stack (Right to Left):**  
   Traverse the array from the end.  
   Maintain a stack where each element has **higher frequency than current**.

3. **Pop & Push Logic:**  
   While the top of the stack has frequency **≤ current**, pop it.  
   If stack is not empty, top is the required element. Push current.

---

## 🚀 Code (C++)

```cpp
class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        if (n == 0) return {};

        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
            mpp[arr[i]]++;

        vector<int> ans(n, -1);
        st.push(arr[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && mpp[arr[i]] >= mpp[st.top()]) {
                st.pop();
            }
            if (!st.empty()) ans[i] = st.top();
            st.push(arr[i]);
        }

        return ans;
    }
};
