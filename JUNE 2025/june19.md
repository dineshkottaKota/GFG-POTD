# 🧩 Case-specific Sorting of Strings

## 📝 Problem Statement

Given a string `s` consisting of only uppercase and lowercase letters, sort the uppercase and lowercase characters **separately**, but preserve their **original case positions**. That is, if the `i-th` character in the original string is uppercase, the character at the same position in the sorted result must also be uppercase (though not necessarily the same character).

---

### ✅ Constraints:
- 1 ≤ s.length ≤ 10⁵

---

## 📥 Input

A single string `s` of mixed uppercase and lowercase characters.

## 📤 Output

A new string where:
- Uppercase characters are sorted and placed in their original uppercase positions.
- Lowercase characters are sorted and placed in their original lowercase positions.

---

## 🧪 Examples

### Example 1:
**Input:**  
`s = "GEekS"`  
**Output:**  
`EGekS`  
**Explanation:**  
Uppercase letters: G, E, S → sorted: E, G, S  
Lowercase letters: e, k → sorted: e, k  
Placed back in original case positions.

---

### Example 2:
**Input:**  
`s = "XWMSPQ"`  
**Output:**  
`MPQSWX`  
**Explanation:**  
All characters are uppercase → sort directly.

---

## 🚀 Approach

We follow these steps:

1. Separate all **uppercase** and **lowercase** characters.
2. Sort each of them individually.
3. Traverse the original string:
   - If a character is uppercase, pick the next character from the sorted uppercase list.
   - If lowercase, pick from the sorted lowercase list.
4. Construct the result maintaining the original case structure.

---

### Time Complexity:
- **O(n log n)** — for sorting both parts.

### Auxiliary Space:
- **O(n)** — to store separate upper and lower case characters and final result.

---

## 🧠 Code Explanation (C++)

```cpp
class Solution {
  public:
    string caseSort(string& s) {
        string uc, lc;
        for(auto ch : s){
            if(islower(ch)) lc += ch;
            else uc += ch;
        }
        
        sort(uc.begin(), uc.end());
        sort(lc.begin(), lc.end());
        
        int i = 0, j = 0;
        string ans = "";
        
        for(auto ch : s){
            if(islower(ch))
                ans += lc[i++];
            else
                ans += uc[j++];
        }
        
        return ans;
    }
};
