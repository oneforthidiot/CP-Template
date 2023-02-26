class Solution
{
    public:
        vector<int> search(string pat, string txt)
        {
            string temp=pat+"#"+txt;
            int sz=temp.length();
            int n=pat.size();
            vector<int> Z(sz+1,0);
            int r=0,l=0;
            for(int i=1;i<sz;i++){
                if(i>r){
                    l=r=i;
                    while(r<sz and temp[r-l]==temp[r]){
                        r++;
                    }
                    Z[i]=r-l;
                    r--;
                }
                else{
                    int k=i-l;
                    if(Z[k]<r-i+1){
                        Z[i]=Z[k];
                    }
                    else{
                        l=i;
                        while(r<sz and temp[r-l]==temp[r]){
                            r++;
                        }
                        Z[i]=r-l;
                        r--;
                    }
                }
            }
            vector<int> ans;
            for(int i=0;i<sz;i++){
                if(Z[i]==n)ans.push_back(i-n);
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
