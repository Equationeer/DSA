#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
        
        long long s= x+4LL*y;
        if(s<0||s%3!=0){
            cout<<"NO\n";
            continue;
        }
         s/=3;

         long long lo = max(0LL,y);
         long long hi = s/2;
         cout<<(lo<=hi ? "YES\n" : "NO\n");
     }
    
    return 0;
}