class Solution {
public:
    void dfs( vector<set<int>> &gh,int node,vector<int> &vis,int &ans){
        vis[node]=1;
        for(auto &it:gh[node]){
            if(!vis[it]){
                ans++;
                dfs(gh,it,vis,ans);
            }
        }
    }
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
         vector<set<int>> gh(n);
        for(auto &it:edges){
            gh[it[0]].insert(it[1]);
            gh[it[1]].insert(it[0]);
        }
        queue<int> leaves;
        int tot=n*2;
        int lost=0;
        for(int i=0;i<n;i++){
            if(coins[i]==0 and gh[i].size()==1){
                leaves.push(i);
            }
        }
        while(leaves.size()){
            auto ft=leaves.front();
            leaves.pop();
            if(gh[ft].empty())continue;
            auto it=*gh[ft].begin();
            gh[it].erase(ft);
            gh[ft].erase(it);
            lost+=2;
            if(gh[it].size()==1 and !coins[it]){
                leaves.push(it);
            }
        }
        // now trim the edges upto their two ansestors
        for(int i=0;i<n;i++){
            if(gh[i].size()==1){
                leaves.push(i);
            }
        }
        int sz=2;
        while(sz--){
            int ss=leaves.size();
            while(ss--){
                auto ft=leaves.front();
                leaves.pop();
                if(gh[ft].empty())continue;
                auto it=*gh[ft].begin();
                gh[it].erase(ft);
                gh[ft].erase(it);
                lost+=2;
                if(gh[it].size()==1){
                    leaves.push(it);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(gh[i].size());
        }
        return ans;
    }
};
