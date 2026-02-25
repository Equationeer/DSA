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


