# A. Serval and Mocha's Array

**Platform:** Codeforces  
**Difficulty:** A (Beginner Level)  
**Language Used:** C++  
**Time Complexity (Optimized Idea):** O(n log A)  
**Space Complexity:** O(1)

---

## Problem Summary

Mocha considers an array of positive integers **good** if:

> The GCD (Greatest Common Divisor) of all elements in the array is **less than or equal to its length**.

An array (length ≥ 2) is considered **beautiful** if:

> Every prefix of length ≥ 2 is good.

Given an array, we must determine whether it can be reordered such that it becomes **beautiful**.

---

## Key Observations

- If the array contains at least one element equal to **1**, it can always be arranged to become beautiful.
- Since GCD decreases or remains the same when more numbers are included, arranging smaller values first helps.
- The presence of small GCD pairs plays an important role.
- If no pair has GCD ≤ 2, forming a beautiful array is impossible.

---

## Approach Used

1. For each test case:
   - Read `n`
   - Read the array elements
2. Check all possible pairs `(i, j)`:
   - If any pair has `gcd(a[i], a[j]) ≤ 2`, mark it as valid
3. If at least one such pair exists → print `"YES"`
4. Otherwise → print `"NO"`

---

## Complexity Analysis

- **Time Complexity:**  
  O(n² log A)  
  (Because we compute GCD for each pair)

- **Space Complexity:**  
  O(n)

Since `n ≤ 100`, this solution works efficiently within constraints.

---

## C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; 
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n); 
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        int flag = 0; 
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                if (__gcd(a[i], a[j]) <= 2) 
                {
                    flag = 1; 
                }
            }
        }

        if (flag == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
