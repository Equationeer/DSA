# A. One and Two

**Platform:** Codeforces  
**Difficulty:** A  
**Language Used:** C++  
**Time Complexity:** O(n) per test case  
**Space Complexity:** O(1)

---

## Problem Summary

You are given a sequence:

a₁, a₂, …, aₙ  

Each element is either **1** or **2**.

You must determine whether there exists an index `k` such that:

1 ≤ k ≤ n − 1  

and

a₁ × a₂ × … × aₖ = aₖ₊₁ × aₖ₊₂ × … × aₙ  

If multiple valid values of `k` exist, print the **smallest** one.  
If no such `k` exists, print `-1`.

---

## Key Observation

Since each element is either **1 or 2**:

- Multiplying by `1` does not change the product.
- Only the number of `2`s affects the product.

Let:

- Total number of `2`s in the array = T
- Number of `2`s in prefix (up to index i) = P

Then:

Prefix product = 2^P  
Suffix product = 2^(T - P)

For equality:

2^P = 2^(T - P)

Which implies:

P = T - P  
2P = T  
P = T / 2

So the problem reduces to:

> Find the smallest index `k` where the prefix contains exactly half of all `2`s.

If total number of `2`s is odd → no valid split exists.

---

## Approach

1. Count total number of `2`s in the array.
2. Traverse the array:
   - Maintain running count of `2`s in prefix.
   - If prefix count equals half of total `2`s:
     - Return current index + 1.
3. If no valid index found → return `-1`.

---

## Complexity Analysis

- **Time Complexity:**  
  O(n) per test case  
  (One pass for counting + one pass for checking)

- **Space Complexity:**  
  O(1)  
  Only counters are used.

This solution is efficient for n ≤ 1000.

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
        for (long long i = 0; i < n; i++) 
            cin >> a[i];

        long long total_number_of_twos = 0;
        long long current_number_of_twos = 0;

        for (long long i = 0; i < n; i++)
        {
            if (a[i] == 2) 
                total_number_of_twos++; 
        } 

        long long ans = -1; 
        for (long long i = 0; i < n; i++) 
        {
            if (a[i] == 2) 
                current_number_of_twos++; 

            if ((current_number_of_twos) == (total_number_of_twos - current_number_of_twos))
            {
                ans = i + 1;
                break; 
            }
        }

        cout << ans << endl; 
    }
    return 0;
}
