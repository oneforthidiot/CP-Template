const int X=1e7+1;
int dp[X][3];
class Solution
{
  public:
    int helper(int arr[],int n,int idx,int count){
        if(idx>=n)return 0;
        if(dp[idx][count]!=-1){
            return dp[idx][count];
        }
        if(count<1){
            return dp[idx][count]=min(arr[idx]+helper(arr,n,idx+1,0),helper(arr,n,idx+1,1));
        }
        else{
            return dp[idx][count]=arr[idx]+helper(arr,n,idx+1,0);
        }
    }
    int minAmount(int arr[] , int N){
        for(int i=0;i<=N;i++){
            for(int j=0;j<3;j++){
                dp[i][j]=0;
            }
        }
        for(int idx=N-1;idx>=0;idx--){
            for(int count=1;count>=0;count--){
                if(count<1){
                    dp[idx][count]=min(dp[idx+1][0]+arr[idx],dp[idx+1][1]);
                }
                else{
                    dp[idx][count]=arr[idx]+dp[idx+1][0];
                }
            }
        }
        return dp[0][0];//helper(A,N,0,0);
    }
};
