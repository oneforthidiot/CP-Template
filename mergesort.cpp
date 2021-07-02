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

void merge(vi &arr,ll int low, ll int mid, ll int high){
    ll int n1=mid-low+1;
    ll int n2=high-mid;
    vi left(n1),right(n2);
    for(int i=0;i<n1;i++){
        left[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=arr[mid+i+1];
    }
    ll int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }
    while(i<n1){
        arr[k++]=left[i++];
    }
    while(j<n2){
        arr[k++]=right[j++];
    }
}

void mergesort(vi &arr,ll int low,ll int high){
    if(low>=high)return;
    ll int mid=low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void solve(){
   
    ll int n;
    cin>>n;
    vi arr(n);
    mergesort(arr,0,n-1);
    show(arr)cout<<line;

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
