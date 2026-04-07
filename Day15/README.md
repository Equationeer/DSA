# A. Twin Permutations

Platform: Codeforces  
Difficulty: Easy  
Language Used: C++  
Time Complexity: O(n) per test case  
Space Complexity: O(1)

---

## Problem Summary

You are given a permutation `a` of length `n`.

Your task is to construct another permutation `b` of length `n` such that:

a₁ + b₁ ≤ a₂ + b₂ ≤ a₃ + b₃ ≤ ... ≤ aₙ + bₙ

It is guaranteed that at least one valid permutation `b` always exists.

---

## Key Observation

- We need to ensure that the sequence `(a[i] + b[i])` is non-decreasing
- A simple and valid construction is:

b[i] = n + 1 - a[i]

- This works because:

a[i] + b[i] = a[i] + (n + 1 - a[i]) = n + 1

- So all values become equal, which satisfies the non-decreasing condition

---

## Approach

1. Read input `n` and permutation `a`
2. Construct `b` using:
   - `b[i] = n + 1 - a[i]`
3. Print the resulting permutation `b`

---

## Complexity Analysis

Time Complexity: O(n) per test case  
- Single traversal of the array  

Space Complexity: O(1)  
- No extra space used  

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

        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
        {
            cout << n + 1 - a[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
