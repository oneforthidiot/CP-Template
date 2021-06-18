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
const ll int N=1e6+1;

bool prime[N];
void seive(){
    memset(prime,true,sizeof(prime));
    for(int i=2;i<N;i++){
        if(prime[i]){
            for(int j=i+i;j<N;j+=i)
                prime[j]=false;
        }
    }
}

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

// To Make a Number as Sum of power of 2s
vector<int> powerSetof2(ll n,ll k){
    ll int x=__builtin_popcount(n);
    // if(k<x || k>n) Not Possible in this Condition
    ll int val=31;
    vector<int> ans;
    while(val>=0 && k){
        ll int num=pow(2,val);
        if(n-num<k-1){
            --val;
            continue;
        }
        --k;
        n-=num;
        ans.push_back(val);
    }
    return ans;
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
