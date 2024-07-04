#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb(x) push_back(x)
#define vi vector<int>
#define all(x) x.begin(), x.end()
using namespace std;
void io();

int n, nt[10]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int Try(int i, int cnt, int tong){
    if(cnt==n) return tong;
    int j=1;
    int tmp=INT_MAX;
    while(1){
        tong*=nt[i];
        if(tong>tmp) break;
        if(cnt*(j+1)>n) break;
        tmp=min(tmp, Try(i+1, cnt*(j+1), tong));
        j++;        
    }
    return tmp;
}
void solve(){
    cin>>n;
    cout<<Try(0, 1, 1)<<endl;
}
int main()
{
    io();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
        // cout<<cnt;
    return 0;
}
void io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  
}
