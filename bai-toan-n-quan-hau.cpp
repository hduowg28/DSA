#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb(x) push_back(x)
#define vi vector<int>
#define all(x) x.begin(), x.end()
using namespace std;

int mx[8]={-1, -1, -1, 0, 0, 1, 1, 1};
int my[8]={-1,  0,  1, -1, 1,-1, 0, 1};

int x[100], cot[100], cheo1[100], cheo2[100], n, cnt=0;
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
    memset(cot, 0, sizeof(cot));
    memset(cheo1, 0, sizeof(cheo1));
    memset(cheo2, 0, sizeof(cheo2));
    
    
}
void Try(int i){
    for(int j=1;j<=n;j++){
        if(cot[j]==0&&cheo1[i-j+n]==0&&cheo2[i+j-1]==0){
            // cot[i]=1;?            // x[i]=j;
            cot[j]=1;
            cheo1[i-j+n]=1;
            cheo2[i+j-1]=1;
            if(i==n){
                cnt++;
            } 
            else Try(i+1);
            cot[j]=0;
            cheo1[i-j+n]=0;
            cheo2[j+i-1]=0; 
        }
    }
}
void solve(){
    ktao();
    cin>>n;
    // cheo1[1]=1;
    // cheo2[1]=1;
    // cot[1]=1;
    Try(1);
    cout<<cnt;
}

int main(){
    io();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
// bài toán di chuyển trong ma trận 
/*
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
*/
