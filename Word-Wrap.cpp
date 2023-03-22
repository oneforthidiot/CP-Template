int dp[2001][2001];
class Solution {
public:
    int rec(vector<int> &nums,int idx,int k,int rem){
        if(idx==nums.size()-1){
            if(nums[idx]<rem)return 0;
            else return rem*rem;
        }
        if(dp[idx][rem]!=-1)return dp[idx][rem];
        int x=nums[idx];
        if(x<rem){
            int temp=(rem==k)?(rem-x):(rem-x-1);
            int a=rec(nums,idx+1,k,temp);
            int b=rem*rem+rec(nums,idx+1,k,k-x);
            return dp[idx][rem]=min(a,b);
        }
        else{
            return dp[idx][rem]=rem*rem+rec(nums,idx+1,k,k-x);
        }
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        for(int i=0;i<=k;i++){
            if(nums[n-1]<i){
                dp[n-1][i]=0;
            }
            else{
                dp[n-1][i]=i*i;
            }
        }
        for(int idx=n-2;idx>=0;idx--){
            for(int rem=0;rem<=k;rem++){
                int x=nums[idx];
                if(x<rem){
                    int temp=(rem==k)?(rem-x):(rem-x-1);
                    int a=dp[idx+1][temp];//rec(nums,idx+1,k,temp);
                    int b=rem*rem+dp[idx+1][k-x];//rec(nums,idx+1,k,k-x);
                    dp[idx][rem]=min(a,b);
                }       
                else{
                    dp[idx][rem]=rem*rem+dp[idx+1][k-x];//rec(nums,idx+1,k,k-x);
                }
            }
        }
        int ans=dp[0][0];//rec(nums,0,k,0);
        return ans;
    } 
};
