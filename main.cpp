// Those who don't Remember the History 
// are Destined to Repeat it.  ~DP
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Mod 100000007
#define line "\n"
#define vi vector<ll>
#define show(x) for(auto it:x)cout<<it<<" ";
#define mi map<ll,ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define chk(x) cout<<"Check"<<x<<line;
// const ll int inf=1e18+1;
const ll int MX=1e9+7;

/*Code Begins from Here*/

// ll int dp[5001][5001];
// const ll int N=1e6+1;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void decToBinary(ll n){
    for(int i= 10;i>=0;i--){
        ll int k=n>>i;
        if(k&1)cout<<"1";
        else cout<<"0";
    }
}

void solve(){

 
    
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    ll int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
