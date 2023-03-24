//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int dp[501][501];
class Solution{
public:
    bool isPalindrome(string str){
        int l=0,r=str.length()-1;
        while(l<r){
            if(str[l]!=str[r])return false;
            l++;
            r--;
        }
        return true;
    }
    int helper(string &str,int l,int r){
        if(l>=r)return 0;
        if(isPalindrome(str.substr(l,r-l+1))){
            return 0;
        }
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=INT_MAX;
        for(int i=l;i<r;i++){
            int temp=1+helper(str,l,i)+helper(str,i+1,r);
            ans=min(ans,temp);
        }
        return dp[l][r]=ans;
    }
    int palindromicPartition(string str){
        int l=0,r=str.length()-1;
        int n=str.length();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>=j)dp[i][j]=0;
                else
                if(isPalindrome(str.substr(i,j-i+1))){
                        dp[i][j]=0;
                }
                else{
                    dp[i][j]=INT_MAX;
                }
            }
        }
        for(int l=n-1;l>=0;l--){
            for(int r=0;r<n;r++){
                if(l>=r)continue;
                for(int i=l;i<r;i++){
                    int temp=dp[l][i]+dp[i+1][r]+1;
                    dp[l][r]=min(dp[l][r],temp);
                }
            }
        }
        return dp[0][n-1];//helper(str,l,r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
