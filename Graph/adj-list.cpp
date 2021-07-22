#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define line "\n"
#define vi vector<ll>
#define mi map<ll,ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define check(x) cout<<"Check#"<<x<<line;
#define p_c(x) __builtin_popcountll(x)
#define show(x) for(auto it:x)cout<<it<<" ";
const ll int MX=1e9+7;

class Graph{
    int v;// Vertices
    list<int> *l; //List to store edges
public:
    Graph(int v){
        this->v=v;
        l=new list<int>[v]; //Initilizing with size of V
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printAdjlist(){
        for(int i=0;i<v;i++){
            cout<<"Vertex"<<i<<"->";
            for(int nbr:l[i]){
                cout<<nbr<<",";
            }
            cout<<"\n";
        }
    }
};

void solve(){
    
    Graph g(4);//Graph with 4 vertices
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.printAdjlist();
    
    
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