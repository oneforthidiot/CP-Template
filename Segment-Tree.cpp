#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define line "\n"
#define vi vector<ll>
#define mi map<ll,ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define chk(x) cout<<"Check#"<<x<<line;
#define p_c(x) __builtin_popcountll(x)
#define show(x) for(auto it:x)cout<<it<<" ";
const ll int MX=1e9+7;

/*Code Begins From Here*/

// Building a Segment Tree O(N)
void build(vi arr,int start,int end,int idx,int tree[]){
    if(start==end){
        tree[idx]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    build(arr,start,mid,2*idx,tree); // Building Left Subtree
    build(arr,mid+1,end,2*idx+1,tree); // Building Right Subtree
    tree[idx]=tree[idx*2]+tree[idx*2+1]; // Min Max Sum etc
}

// Answering a Range Query fron Segment tree (log(N))
int query(int tree[],int ss,int se,int qs,int qe,int idx){
    // Complete Overlap
    if(ss>=qs and se<=qe)return tree[idx];
    // No Overlap
    if(qe<ss || qs>se)return -1;
    // Partial Overlap
    int mid=(ss+se)/2;
    int right=query(tree,mid+1,se,qs,qe,2*idx+1);
    int left=query(tree,ss,mid,qs,qe,2*idx);
    return left+right; // Min Max Sum etc
}

// Point Update (log(N))
// Incremating the Value
void update1(int tree[],int ss,int se,int i,int val,int idx){
    // Case where i is out of Bound
    if(i>se || i<ss)return;
    if(ss==se){
       tree[idx]+=val; // Plus Sub Min Max etc
       return; 
    }
    int mid=(ss+se)/2;
    update1(tree,ss,mid,i,val,idx*2);
    update1(tree,mid+1,se,i,val,idx*2+1);

    tree[idx]=tree[2*idx]+tree[2*idx+1]; // Rebuilding the Tree with Updated Value
}

// Range Update
// O(N)
void update2(int tree[],int ss,int se,int l,int r,int val,int idx){
    if(l>se || r<ss)return; // Range out of Bound
    if(ss==se){
        tree[idx]+=val;
        return;
    }
    int mid=(ss+se)/2;
    update2(tree,ss,mid,l,r,val,2*idx); // Updateing left subtree
    update2(tree,mid+1,se,l,r,val,2*idx+1); // Updating right subtree

    tree[idx]=tree[2*idx]+tree[2*idx+1]; // Rebuilding the tree with updated value
}
void solve(){
    
    ll int n,m;
    cin>>n>>m;
    vi arr(n);
    for(auto &i:arr)cin>>i;
    int tree[4*n];
    build(arr,0,n-1,1,tree);
    update1(tree,0,n-1,2,1,1);
    update2(tree,0,n-1,0,3,1,1);
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<query(tree,0,n-1,l,r,1)<<line;
    }
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