#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb(x) push_back(x)
#define vi vector<int>
#define all(x) x.begin(), x.end()
using namespace std;

int n, a[100][100], dmin, x[100], used[100], sum, toiuu;
void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
}
void ktao(){
    toiuu=1e9+5;sum=0;
    dmin=INT_MAX;
    memset(used, false, sizeof(used));
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j])
                dmin=min(a[i][j],dmin);
        }
    }
    // cout<<dmin;
}

void Try(int i){
    for(int j=2;j<=n;j++){
        if(!used[j]){
            used[j]=true;
            x[i]=j;
            sum+=a[x[i]][x[i-1]];
            if(i==n){
                toiuu=min(toiuu, sum+a[x[n]][1]);
                // cout<<toiuu<<endl;
            }
            else if(sum+dmin*(n-i+1)<toiuu){
                Try(i+1);
            }
            sum-=a[x[i]][x[i-1]];
            used[j]=0;
        }
    }
}

void solve(){
    ktao();
    x[1]=1;
    Try(2);
    cout<<toiuu;
}

int main(){
    io();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
