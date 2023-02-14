#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define line "\n"
#define vi vector<ll>
#define mi map<ll,ll>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define PI 3.141592653589793238462
#define check(x) cout<<"Check#"<<x<<line;
#define p_c(x) __builtin_popcountll(x)
#define show(x) for(auto it:x)cout<<it<<" ";
typedef unsigned long long ull;
typedef long double lld;
const ll int MX=1e9+7;
void Case(ll int x,ll int t){cout<<"Case #"<<x-t<<": ";}
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/******************************************/
ll binpow(ll a,ll b,ll m=MX) {
    a%=m;
    ll res=1;
    while(b>0){
        if(b&1)res=res*a%m;
        a=a*a%m;
        b>>=1;
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
/*******************************************/
 
// const int X=2e5+1;
// vi gh[X];
// ll int vis[X];
// ll int dp1[X],pr[X];
// const int X1=100;


/* 


*/
const ll SZ=pow(2,21);
ll X[SZ],Y[SZ];
void subsetsum(vi arr,ll x[],ll idx,ll s){
    for(int i=0;i<=(1<<(idx));i++){
        ll sum=0;
        for(int j=0;j<idx;j++){
            if(i&(1<<j))sum+=arr[j+s];
        }
        x[i]=sum;
    }
}
void solve(){
    ll n,S;
    cin>>n>>S;
    vi arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    subsetsum(arr,X,n/2,0);
    subsetsum(arr,Y,n-n/2,n/2);
    ll nx=(1<<(n/2));
    ll ny=(1<<(n-n/2));
    sort(Y,Y+ny);
    ll mx=0;
    for(int i=0;i<nx;i++){
        if(X[i]<=S){
            auto it=lower_bound(Y,Y+ny,S-X[i])-Y;
            if(it==ny or Y[it]!=S-X[i]){
                it--;
            }
            mx=max(mx,Y[it]+X[i]);

        }
    }
    cout<<mx<<endl;

}  
 
int main() { 
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    ll int t=1;
    // cin>>t;
    // ll int x=t;
    while(t--){
        // Case(x,t);
        solve();
    }
    return 0;
}
