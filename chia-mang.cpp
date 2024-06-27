#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb(x) push_back(x)
#define vi vector<int>
#define all(x) x.begin(), x.end()
using namespace std;

int n, k, a[100], ok, used[100],s;
void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
}
void Try(int sum, int cnt){
    if(cnt==k){
        ok=1;
    }
    if(ok==1) return ;
    else {
        for(int j=0;j<n;j++){
            if(!used[j]){
                used[j]=true;
                if(sum+a[j]==s) Try(0, cnt+1);
                else   
                    Try(sum+a[j], cnt);
                used[j]=false;
            }
        }
    }
}
void ktao(){
    cin>>n>>k;
    for(int i=0;i<n;i+=1) {
        cin>>a[i];
        s+=a[i];
    }
    memset(used, 0, sizeof(used));
    ok=false;
    if(s%k){
        ok=false;
    }
    else  {s/=k;Try(0, 0);}
    // else {
    //     int mark[sum/k+1];
    //     memset(mark, 0, sizeof(mark));
    //     for(int i=0;i<n;i++){
    //         for(int j=sum/k;j>=a[i];j--){
    //             if(mark[j-a[i]]||a[i]==j){
    //                 mark[j]=true;
    //             }
    //         }
    //     }
    //     cout<<(mark[sum/n]?1:0);
    // }
    // cout<<"\n";
}

void solve(){
    ktao();
   
    cout<<(ok?1:0)<<endl;
    // if(!ok) cout<<-1<<endl;
}

int main(){
    io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
