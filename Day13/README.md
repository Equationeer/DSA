# A. Grasshopper on a Line

Platform: Codeforces  
Difficulty: Easy  
Language Used: C++  
Time Complexity: O(1) per test case  
Space Complexity: O(1)

---

## Problem Summary

You are given two integers `x` and `k`. A grasshopper starts at position `0` on the number line.

In one move, it can jump any integer distance (positive or negative), but the distance must NOT be divisible by `k`.

The goal is to reach position `x` using the minimum number of moves.

For each test case, print:
1. The minimum number of moves
2. The sequence of jumps

---

## Key Observation

- If `x % k != 0`:
  - You can directly jump to `x` in one move
  - Because `x` itself is not divisible by `k`

- If `x % k == 0`:
  - You cannot jump directly to `x`
  - So break it into two valid jumps:
    - `1` and `x - 1`
  - Both are not divisible by `k` (since `k >= 2`)

---

## Approach

For each test case:

1. Read values `x` and `k`
2. Check:
   - If `x % k == 0`:
     - Output `2`
     - Moves: `1` and `x - 1`
   - Else:
     - Output `1`
     - Move: `x`

This guarantees:
- Minimum number of moves
- Valid jumps (not divisible by `k`)

---

## Complexity Analysis

Time Complexity: O(1) per test case  
(Only simple arithmetic operations)

Space Complexity: O(1)  
(No extra space used)

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
        long long x, k;
        cin >> x >> k;

        if (x % k == 0)
        {
            cout << 2 << endl;
            cout << 1 << " " << x - 1 << endl;
        }
        else
        {
            cout << 1 << endl;
            cout << x << endl;
        }
    }

    return 0;
}
