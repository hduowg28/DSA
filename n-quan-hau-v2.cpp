#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb(x) push_back(x)
#define vi vector<int>
#define all(x) x.begin(), x.end()
using namespace std;

int mx[8]={-1, -1, -1, 0, 0, 1, 1, 1};
int my[8]={-1,  0,  1, -1, 1,-1, 0, 1};
int cheo1[100], cheo2[100], cot[100], n, sum, cott[100], a[100][100];

// x[i]=j; // con hậu thứ hàng thứ i nằm ở cột thứ j
// cheo xuoi i+j-1
// cheo nguoc i-j+n
void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt","w",stdout);
    #endif
}
void ktao(){
    n=8;
    memset(cheo1, 1, sizeof(cheo1));
    memset(cheo2, 1, sizeof(cheo2));
    memset(cot, 1, sizeof(cot));
    sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Try(int i){
    for(int j=1;j<=8;j++){
        if(cot[j]&&cheo1[i+j-1]&&cheo2[i-j+n]){
            cot[j]=cheo1[i+j-1]=cheo2[i-j+n]=0;
            cott[i]=j;
            if(i==n){
                int tmp=0;
                for(int k=1;k<=8;k++){
                    tmp+=a[k][cott[k]];
                    // cout<<a[k][cott[k]]<<endl;
                }
                sum=max(sum, tmp);
            }
            Try(i+1);
            cot[j]=cheo1[i+j-1]=cheo2[i-j+n]=1;
        }
    }
}
void solve(){
    ktao();
    Try(1);
    cout<<sum;
}
int main(){
    io();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
