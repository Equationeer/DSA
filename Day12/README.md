# A. Everybody Likes Good Arrays!

**Platform:** Codeforces  
**Difficulty:** A  
**Language Used:** C++  
**Time Complexity:** O(n) per test case  
**Space Complexity:** O(n)

---

## Problem Summary

An array `a` is considered **good** if for every pair of adjacent elements:

aᵢ and aᵢ₊₁ have **different parity** (one is even, the other is odd).

You are allowed to perform the following operation:

- Select any adjacent pair with the **same parity**
- Delete both elements
- Insert their **product** at the same position

👉 Find the **minimum number of operations** required to make the array good.

---

## Key Observation

- Even × Even = Even  
- Odd × Odd = Odd  

👉 Merging two elements of the same parity **does not change parity**, it only reduces the array size.

So, the only problem is **adjacent elements having same parity**.

Each such pair must be resolved with **one operation**.

---

## Approach

1. Traverse the array.
2. For every adjacent pair `(a[i], a[i+1])`:
   - If both have the same parity:
     - Increment operation count.
3. Print the total count.

---

## Complexity Analysis

- **Time Complexity:**  
  O(n) per test case  
  (Single traversal of array)

- **Space Complexity:**  
  O(n)  
  (Array storage)

This works efficiently for n ≤ 100.

---

## C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin >> t;
    
    while(t--){
        long long n;
        cin >> n;
        
        long long operation = 0;
        long long a[n];
        
        for(long long i = 0; i < n; i++){
            cin >> a[i];
        }
        
        for(int i = 0; i < n - 1; i++){
            if((a[i] % 2) == (a[i+1] % 2)){
                operation++;
            }
        }
        
        cout << operation << endl;
    }
}
