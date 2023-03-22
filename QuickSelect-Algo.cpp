int help(int arr[],int l,int r){
        //lomotu partition
        int pivot=arr[r];
        int idx=l;
        for(int i=l;i<r;i++){
            if(arr[i]<=pivot){
                swap(arr[idx],arr[i]);
                idx++;
            }
        }
        swap(arr[idx],arr[r]);
        return idx;
    }
    int qs(int arr[],int l,int r,int k){
        if(l>=r)return l;
        int idx=help(arr,l,r);
        if(idx==k)return idx;
        if(idx>k){
            return qs(arr,l,idx-1,k);
        }
        else{
            return qs(arr,idx+1,r,k);
        }
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        int idx=qs(arr,l,r,k-1);
        return arr[k-1];
    }
