#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb(x) push_back(x)
#define vi vector<int>
#define all(x) x.begin(), x.end()
using namespace std;

int n, m, a[100][100], cnt;
void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
}
void Try(int i, int j){
    if(i==n-1&&j==m-1){
        cnt++;
    }
    if(j+1<m&&a[i][j+1]!=-1){
        int tmp=a[i][j];
        a[i][j]=-1;
        Try(i,j+1);
        a[i][j]=tmp;
    }
    if(i+1<n){
        Try(i+1, j);
    }
    if(j-1>=0&&i!=n-1&&a[i][j-1]!=-1){
       int tmp=a[i][j];
        a[i][j]=-1;
        Try(i, j-1);
         a[i][j]=tmp;
    }
}
void solve(){
    cnt=0;
   cin>>n>>m;
   FOR(i, 0, n){
    FOR(j, 0, m){
        cin>>a[i][j];
    }
   }
    Try(0, 0);
    cout<<cnt<<endl;
}

int main(){
    io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
