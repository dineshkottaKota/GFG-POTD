# Palindromic Partitioning

## 🧩 Problem Statement

Given a string `s`, find **all possible ways** to partition it such that **every substring** in the partition is a **palindrome**.

### ✅ Constraints:
- 1 ≤ s.length ≤ 20

---

## 📥 Input

A string `s`.

## 📤 Output

A list of lists, where each list is a palindromic partition of the string.

---

## 🧪 Examples

### Example 1:
**Input:**  
`s = "geeks"`  
**Output:**  
`[["g", "e", "e", "k", "s"], ["g", "ee", "k", "s"]]`  
**Explanation:**  
Both `"g", "e", "e", "k", "s"` and `"g", "ee", "k", "s"` are valid palindromic partitions.

---

### Example 2:
**Input:**  
`s = "abcba"`  
**Output:**  
`[["a", "b", "c", "b", "a"], ["a", "bcb", "a"], ["abcba"]]`  
**Explanation:**  
- Each substring in every list is a palindrome.
- All possible partitions are found.

---

## 🚀 Approach

We use **backtracking** to generate all possible partitions of the string and include only those where **each substring is a palindrome**.

### Steps:
1. Start from index `0`, and try all substrings `s[ind...i]`.
2. For each substring, check if it is a **palindrome**.
3. If yes, **include it in the current path**, and **recurse** for the remaining string.
4. Once the index reaches the end, store the current partition in the answer list.

### Time Complexity:
- **O(2^n * n)**  
  Where `2^n` is the number of partition combinations, and `n` is for checking if a substring is a palindrome.

### Auxiliary Space:
- **O(2^n * n)** for storing the results.

---

## 🧠 Code Explanation (C++)

```cpp
class Solution {
  public:
    // Function to check if substring s[l...r] is a palindrome
    bool palindrome(string s, int l, int r){
        while(l <= r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    vector<vector<string>> ans;

    // Recursive backtracking function
    void solve(string &s, int ind, vector<string> v){
        if(ind == s.size()){
            ans.push_back(v); // Found a valid partition
            return;
        }

        for(int i = ind; i < s.size(); i++){
            if(palindrome(s, ind, i)){
                v.push_back(s.substr(ind, i - ind + 1)); // Choose
                solve(s, i + 1, v);                      // Explore
                v.pop_back();                            // Un-choose
            }
        }
    }

    // Main function to be called
    vector<vector<string>> palinParts(string &s) {
        ans.clear(); // Clear global result before use
        vector<string> v;
        solve(s, 0, v);
        return ans;
    }
};
