#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb(x) push_back(x)
#define vi vector<int>
#define all(x) x.begin(), x.end()
using namespace std;
void io();

int a, x[100];
vector <vector<int>> ans;
void Try(int sum, int i, int val){
    if(sum==a){
        vector <int> tmp(x+1, x+i);
        ans.pb(tmp);
        return;
    }
    for(int j=val;j>=1;j--){
        if(sum+j<=a){
        x[i]=j;
        Try(sum+j, i+1, j);}
    }
}
void solve(){
    cin>>a;
    Try(0, 1, a);
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<"(";
       for(int i=0;i<it.size();i++){
        cout<<it[i];
        if(i==it.size()-1) cout<<")";
        else cout<<" ";
       }
    }
    ans.clear();
    cout<<endl;
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
