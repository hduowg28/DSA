#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb(x) push_back(x)
#define vi vector<int>
#define all(x) x.begin(), x.end()
using namespace std;

int m, n, k, mark[3][3];
char a[4][4];
string s, ans;
set <string> se;
vector <string> vs;
void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
}
int mx[8]={-1, -1, -1, 0, 0, 1, 1, 1};
int my[8]={-1,  0,  1, -1, 1,-1, 0, 1};
void Try(int i, int j){
    ans+=(char)a[i][j];
    // cout<<ans<<endl;
    if(se.count(ans)){
        vs.pb(ans);
        cout<<ans<<" ";
    }
    for(int k=0;k<8;k++){
        int i1=i+mx[k], j1=j+my[k];
        if(i1>=0&&i1<n&&j1>=0&&j1<n&&mark[i1][j1]==false){
            mark[i1][j1]=1;
            Try(i1, j1);
            mark[i1][j1]=0;
        }
        
   }
   ans.pop_back();
   
}
void solve(){
    memset(mark, 0, sizeof(mark));
    cin>>k>>m>>n;
    FOR(i, 0, k){
        string tmp;
        cin>>tmp;
        se.insert(tmp);
    }
  
    FOR(i, 0, m){
        FOR(j, 0, n){
            cin>>a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<m;i++){
        FOR(j, 0, n){
            mark[i][j]=1;
            Try(i, j);
             mark[i][j]=0;
        }
    }
}

int main(){
    io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
