#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb(x) push_back(x)
#define vi vector<int>
#define all(x) x.begin(), x.end()
using namespace std;

int n, x, a[100], ok;
vi v;
void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
}
void ktao(){
    cin >>n>>x;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ok=0;
}
void Try(int i, int pos, int sum){
    if(sum==x){
        cout<<"[";
        for(int j=0;j<i;j++){
            cout<<v[j];
            if(j==v.size()-1) cout<<"]";
            else cout<<" ";
        }
        ok=1;
        return ;
    }
    for(int j=pos;j<n;j++){
        v.pb(a[j]);
        if(sum<=x) Try(i+1, j, sum+a[j]);
        v.pop_back();
    }
}
void solve(){
    ktao();
    Try(0, 0, 0);
}

int main(){
    io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
