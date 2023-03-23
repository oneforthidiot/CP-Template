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
 
const int X=2e5+1;
vector<ll> gh[X];
ll vis[X];
// ll dp1[X],pr[X];
// const int X1=100;

/*

*/

void bfs(ll node){
    queue<ll> qt;
    qt.push(node);
    vis[node]=1;
    vi out;
    out.push_back(node);
    while(!qt.empty()){
        auto ft=qt.front();
        qt.pop();
        for(auto &it:gh[ft]){
            if(!vis[it]){
                qt.push(it);
                vis[it]=1;
            }
        }
    }
    for(auto it:out){
        cout<<it<<" ";
    }
    cout<<endl;
}


void dfs(ll node){
    cout<<node<<" ";
    vis[node]=1;
    for(auto it:gh[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}


bool isBipartite(ll n){
    vi color(n+1,0);
    vi done(n+1,0);
    queue<ll> qt;
    for(int i=1;i<=n;i++){
        if(!done[i]){
            done[i]=1;
            color[i]=1;
            qt.push(i);
            while(!qt.empty()){
                auto ft=qt.front();
                qt.pop();
                for(auto &it:gh[ft]){
                    if(!vis[it]){
                        vis[it]=1;
                        qt.push(it);
                        if(color[ft]==1){
                            color[it]=2;
                        }
                        else{
                            color[it]=1;
                        }
                    }
                    else{
                        if(color[ft]==color[it]){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

void dfshelper(ll node,stack<ll> &st){
    vis[node]=1;
    for(auto it:gh[node]){
        if(!vis[it]){
            dfshelper(node,st);
        }
    }
    st.push(node);
}

void dfshelper2(vi gh1[],ll node){
    vis[node]=1;
    cout<<node<<" ";
    for(auto it:gh1[node]){
        if(!vis[it])dfshelper2(gh1,it);
    }
    cout<<endl;
}


void SCC(ll n){
    vi vis1(n+1,0);
    stack<ll> st;
    vi gh1[n+1];
    for(int i=0;i<=n;i++){
        vis[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(auto it:gh[i]){
            gh1[it].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfshelper(i,st);
        }
    }
    memset(vis,0,sizeof(vis));
    while(!st.empty()){
        ll ft=st.top();
        st.pop();
        dfshelper2(gh1,ft);
    }

}
void solve(){
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        gh[x].push_back(y);
        gh[y].push_back(x);
    }

}

int main() { 
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    ll int t=1;
    cin>>t;
    // ll int x=t;
    while(t--){
        // Case(x,t);
        solve();
    }
    return 0;
}
 
