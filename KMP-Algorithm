void calculate_lps(vi &lps,string &str){
    int n=str.length();
    int len=0;
    int i=1;
    while(i<n){
        if(str[i]==str[len]){
            lps[i]=len+1;
            len++;
            i++;
        }
        else{
            if(len==0){
                lps[i]=0;
                i++;
            }
            else{
                len=lps[len-1];
            }
        }
    }
}

void solve(){
    string str,pat;
    cin>>str>>pat;
    int m=pat.length();
    vi lps(m+1,0);
    calculate_lps(lps,pat);
    int i=0,j=0;
    int n=str.length();
    int ans=-1;
    while(i<n){
        if(str[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            ans=i-j;
            j=lps[j-1];
        }
        else
        if(i<n and str[i]!=pat[j]){
            if(j==0)i++;
            else j=lps[j-1];
        }
    }
    cout<<ans<<endl;
}  
