# A1. Lost Civilization (Easy Version)

**Platform:** Codeforces  
**Difficulty:** A1 (Easy)  
**Language Used:** C++  
**Time Complexity:** O(n) per test case  
**Space Complexity:** O(n)

---

## Problem Summary

An ancient civilization used a specific algorithm to generate a longer sequence from an initial sequence.

### Algorithm Definition

1. Start with a sequence `x` of length `m`.
2. If `k = 0`, return `x`.
3. Otherwise:
   - Select any index `i`
   - Insert `(x[i] + 1)` immediately after `x[i]`
4. Repeat until the sequence length becomes `m + k`.

---

### Objective

Given the final sequence `a` of length `n`, determine:

> The length of the shortest possible initial sequence that could generate `a`.

---

## Key Insight

From the algorithm:

- New elements are always created as `previous_element + 1`.
- Therefore, the final sequence is composed of one or more **increasing chains** of consecutive integers.
- Each chain must originate from one element of the original sequence.
- The answer equals the number of such independent chains.

So, the problem reduces to:

> Count how many times a new increasing chain must start.

---

## Approach Used

We process the array while maintaining a stack-like structure:

1. Iterate through each element.
2. If it continues the current increasing chain (`x == previous + 1`), extend the chain.
3. Otherwise:
   - Remove invalid elements.
   - If it cannot extend any previous valid chain:
     - Start a new chain.
     - Increment the root counter.
4. The number of started chains equals the shortest possible original sequence length.

---

## Complexity Analysis

- **Time Complexity:**  
  O(n) per test case  
  (Each element is pushed and popped at most once)

- **Space Complexity:**  
  O(n) for maintaining the stack

This satisfies the constraint:
- Total `n` across test cases ≤ 300000

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
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<long long> st;
        st.reserve(n);

        int roots = 0;

        for (long long x : a) {
            if (st.empty()) {
                roots++;
                st.push_back(x);
                continue;
            }

            if (x == st.back() + 1) {
                st.push_back(x);
                continue;
            }

            while (!st.empty() && st.back() >= x) st.pop_back();

            if (!st.empty() && x == st.back() + 1) {
                st.push_back(x);
            } else {
                roots++;
                st.clear();
                st.push_back(x);
            }
        }

        cout << roots << "\n";
    }
    return 0;
}
