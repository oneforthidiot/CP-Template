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

void merge(ll int arr[],ll int temp[],ll int low, ll int mid, ll int high){
    int i=low,j=mid,k=low;
    while((i<mid) and (j<=high)){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<mid)temp[k++]=arr[i++];
    while(j<=high)temp[k++]=arr[j++];
    for(int i=low;i<=high;i++)arr[i]=temp[i];
}

void mergesort(ll int arr[],ll int temp[],ll int low,ll int high){
    if(low>=high)return;
    ll int mid=low+(high-low)/2;
    mergesort(arr,temp,low,mid);
    mergesort(arr,temp,mid+1,high);
    merge(arr,temp,low,mid+1,high);
}

void solve(){
   
    ll int n;
    cin>>n;
    ll int arr[n];
    ll int temp[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    mergesort(arr,temp,0,n-1);
    show(temp)cout<<line;

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
