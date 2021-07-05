#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define line "\n"
#define vi vector<ll>
#define show(x) for(auto it:x)cout<<it<<" ";
#define mi map<ll,ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define chk(x) cout<<"Check#"<<x<<line;
#define p_c(x) __builtin_popcountll(x)
const ll int MX=1e9+7;

/*Code Begins From Here*/

//  Segment Tree (BASICS)
const int sz=1e5+1;
ll int st[sz];

// Main function parameters v=1,left=0,right=n-1
void build(vi arr,ll int v, ll int left, ll int right){
    if(left==right){
        st[v]=arr[left];
    }
    else{
        ll int mid=(left+right)/2;
        build(arr,2*v,left,mid);
        build(arr,2*v+1,mid+1,right);
        st[v]=st[2*v]+st[2*v+1];
    }
}

// Answersing Sun Queries

ll int sum(ll int v,ll left,ll right,ll l, ll r){
    if(l>r)return 0;
    if(l==left && r==right)return st[v];
    ll int mid=(l+r)/2;
    return sum(2*v,left,mid,l,min(r,mid))+sum(2*v+1,mid+1,right,max(mid+1,l),r);
}



void solve(){
    
    ll int n;
    cin>>n;
    vi arr(n);
    for(auto i:arr)cin>>i;
    build(arr,1,0,n-1);
    ll int l,r;
    cin>>l>>r;
    cout<<sum(1,0,n-1,l,r)<<line;
    
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    ll int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}