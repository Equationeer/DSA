# A. Walking Master – Codeforces Solution

## 📌 Problem Link
Problem: A. Walking Master  
Platform: Codeforces  
Difficulty: Beginner  

---

## 📝 Problem Statement

YunQian is standing on an infinite Cartesian plane at position **(a, b)**.  
She wants to reach position **(c, d)** using only the following two moves:

1. Move diagonally top-right → `(x + 1, y + 1)`
2. Move left → `(x - 1, y)`

For each test case, determine:
- The **minimum number of moves** required to reach the destination, or  
- Print `-1` if it is impossible.

---

## 💡 Approach

### Key Observations

- The only way to increase the `y` coordinate is by moving diagonally `(x + 1, y + 1)`.
- If `d < b`, reaching the destination is impossible.
- First, match the `y` coordinate using diagonal moves.
- Then adjust the `x` coordinate using left moves.
- If at any stage the movement constraints cannot be satisfied, return `-1`.

---

## ⚙️ Algorithm

For each test case:

1. If `destination_y < source_y` → print `-1`
2. Compute diagonal moves required:
3. Update x after diagonal moves:
4. If `source_x < destination_x` → print `-1`
5. Otherwise:
   6. Output total moves.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** O(1) per test case  
- **Overall Complexity:** O(t)  
- **Space Complexity:** O(1)

---

## 💻 Implementation (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
 int t;
 cin >> t;
 while (t--)
 {
     int source_x, source_y, destination_x, destination_y;
     cin >> source_x >> source_y >> destination_x >> destination_y;

     if (destination_y < source_y) 
     {
         cout << -1 << endl;
         continue; 
     }

     int moves = destination_y - source_y; 
     source_x += moves; 

     if (source_x < destination_x) 
     {
         cout << -1 << endl; 
         continue; 
     }

     moves += (source_x - destination_x); 
     cout << moves << endl; 
 }
 return 0;
}
