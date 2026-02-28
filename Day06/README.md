# A. Parkour Design

**Platform:** Codeforces  
**Difficulty:** A  
**Language Used:** C++  
**Time Complexity:** O(1) per test case  
**Space Complexity:** O(1)

---

## Problem Summary

Alex wants to design a parkour course starting from:

q₀ = (0, 0)

and ending at:

qₖ = (x, y)

Steve can only perform the following moves:

1. (x, y) → (x + 2, y + 1)
2. (x, y) → (x + 3, y)
3. (x, y) → (x + 4, y − 1)

We must determine whether it is possible to reach the coordinate (x, y) using only these moves.

---

## Key Observations

Let:
- a = number of moves of type (2, +1)
- b = number of moves of type (3, 0)
- c = number of moves of type (4, −1)

Then total displacement becomes:

X-coordinate:
x = 2a + 3b + 4c

Y-coordinate:
y = a − c

From the second equation:

a = y + c

Substituting into the first equation:

x = 2(y + c) + 3b + 4c  
x = 2y + 2c + 3b + 4c  
x = 2y + 6c + 3b  

Rearranging:

x − 2y = 3(b + 2c)

Let:

s = x − 2y

Since the right-hand side is divisible by 3:

👉 s must be divisible by 3  
👉 s ≥ 0  

After dividing:

s / 3 = b + 2c

We now check whether non-negative integers b and c exist satisfying this condition.

---

## Conditions for Valid Path

For a valid parkour course:

1. s = x − 2y must be non-negative
2. s must be divisible by 3
3. A feasible integer solution must exist within valid bounds

If all conditions are satisfied → output `"YES"`  
Otherwise → output `"NO"`

---

## Complexity Analysis

- **Time Complexity:** O(1) per test case  
- **Space Complexity:** O(1)

The solution uses only arithmetic checks and avoids simulation, making it efficient even for very large coordinates (up to 10⁹).

---

## C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        long long x, y;
        cin >> x >> y;
        
        long long s = x + 4LL * y;
        if(s < 0 || s % 3 != 0){
            cout << "NO\n";
            continue;
        }

        s /= 3;

        long long lo = max(0LL, y);
        long long hi = s / 2;

        cout << (lo <= hi ? "YES\n" : "NO\n");
    }
    
    return 0;
}
