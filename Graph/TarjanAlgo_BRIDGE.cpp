const int X=1e5+1;
vector<int> gh[X];
int vis[X];
int low[X];
int entry[X];
int time1=0; 
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int node,int parent){
        vis[node]=1;
        low[node]=entry[node]=time1++;
        for(auto it:gh[node]){
            if(it==parent)continue;
            if(!vis[it]){
                dfs(it,node);
                low[node]=min(low[it],low[node]);
                if(entry[node]<low[it]){
                    ans.push_back({node,it});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(int i=0;i<=n;i++){
            vis[i]=0;
            gh[i].clear();
            low[i]=0;
            entry[i]=0;
        }
        time1=0;
        for(auto it:connections){
            gh[it[0]].push_back(it[1]);
            gh[it[1]].push_back(it[0]);
        }
        ans.clear();
        dfs(0,-1);
        return ans;
        
    }
};
