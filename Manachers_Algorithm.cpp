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
// vector<pair<ll,ll>> gh[X];
// ll vis[X];
// ll dp1[X],pr[X];
// const int X1=100;

/*
 
*/
string cvt(string str){
    string temp="";
    temp+="&";
    for(auto it:str){
        temp+="#";
        temp+=it;
    }
    temp+="#@";
    return temp;
}

string palindromic_substring(string str){
    string s=cvt(str);
    ll r=0,c=0;
    ll sz=s.length();
    vector<ll> p(sz+1,0);
    for(int i=1;i<sz-1;i++){
        ll mirror=c-(i-c); //Corresponding letter to i
        if(r>i){
            p[i]=min(r-i,p[mirror]);
        }
        //Expanding Around the Centre
        while(s[i+1+p[i]]==s[i-1-p[i]]){
            p[i]++;
        }
        //If it goes beyond the R range, then update the centre
        if(i+p[i]>r){
            c=i; //next centre
            r=i+p[i];
        }
    }
    // debug(p)
    ll mx=0;
    ll mx_idx=0;
    for(int i=1;i<sz-1;i++){
        if(p[i]>mx){
            mx=p[i];
            mx_idx=i;
        }
    }
    // debug(mx)
    string ans=str.substr((mx_idx-mx-1)/2,mx);
    return ans;
} 
void solve(){
    // Manacher's Algo
    string str;
    cin>>str;
    ll n=str.length();
    string ans=palindromic_substring(str);
    cout<<ans<<line;
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
