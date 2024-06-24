#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb(x) push_back(x)
#define vi vector<int>
#define all(x) x.begin(), x.end()
using namespace std;

int n, a[100][100];
string s;

void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
}
void Try(int i, int j){
   //in ra ket qua
   if(i==n&&j==n){
    cout<<s<<" ";
   }
   //truong hop di xuong duoi
   if(i+1<=n&&a[i+1][j]){
    a[i][j]=0;
    s+="D";
    Try(i+1,j);
    s.pop_back();
    a[i][j]=1;
   }
   
    //truong hop di qua trai
   if(j-1>0&&a[i][j-1]){
    a[i][j]=0;
    s+="L";
    Try(i, j-1);
    s.pop_back();
    a[i][j]=1;
   }
   //truong hop di qua phai
   if(j+1<=n&&a[i][j+1]){
    a[i][j]=0;
    s+="R";
    Try(i, j+1);
    s.pop_back();
    a[i][j]=1;
   }
  //truong hop di len tren 
   if(i-1>0&&a[i-1][j]){
    a[i][j]=0;
    s+="U";
    Try(i-1, j);
    s.pop_back();
    a[i][j]=1;
   }
}
void solve(){
   cin>>n;
   FOR(i, 1, n+1){
    FOR(j, 1, n+1){
        cin>>a[i][j];
    }
   }
   Try(1, 1);
   cout<<endl;
}

int main(){
    io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
