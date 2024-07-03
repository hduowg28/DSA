#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb(x) push_back(x)
#define vi vector<int>
#define all(x) x.begin(), x.end()
using namespace std;
void io();

int n, s, ok, k, a[100], x[100];
vi v;
int check(){
    int sum=0;
    for(int i=1;i<=k;i++){
        sum+=x[a[i]];
    }
    return sum==s;
}
int next(){
    int i=k;
    while(i>0&&a[i]==n-k+i){
        i--;
    }
    if(i==0){
        return false;
    }
    else {
        a[i]++;
        for(int j=i+1;j<=k;j++){
            a[j]=a[j-1]+1;
        }
        return true;
    }
}
void solve()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)cin>>x[i];
    sort(x+1, x+n+1);
    for(int i=1;i<=n;i++){
        k=i;
        while(next()){
            if(check()){ ok++;break;}
        }
        if(ok){
            cout<<i;
            return ;
        }
    }
}

int main()
{
    io();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
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
