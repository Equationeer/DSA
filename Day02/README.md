# Day 01 – Twin Permutations

## Platform
Codeforces

## Problem
A. Twin Permutations

---

## Problem Summary

You are given a permutation `a` of length `n`.

Your task is to construct another permutation `b` of length `n` such that:

a1 + b1 ≤ a2 + b2 ≤ a3 + b3 ≤ ... ≤ an + bn

It is guaranteed that such a permutation always exists.

---

## Key Insight

Since `a` is a permutation of numbers from `1` to `n`, we can construct `b` using:

b[i] = n + 1 - a[i]

For every index `i`:

a[i] + b[i] = n + 1

Thus, all sums become equal. Because the sequence of sums is constant, the required non-decreasing condition is satisfied automatically.

---

## Approach

1. Read the number of test cases `t`.
2. For each test case:
   - Read `n`.
   - Read permutation `a`.
   - Construct permutation `b` using `b[i] = n + 1 - a[i]`.
   - Output permutation `b`.

---

## Implementation (C++)

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
            cout << n + 1 - a[i] << " ";

        cout << endl; 
    }
    return 0; 
}
