int lower(vector<int> &v,int a,int b){
    int l = 0, h = a-1;
    int ans = a;

    while(l <= h){
        int mid = (l+h)/2;

        if(v[mid] >= b){
            ans =  mid;
            h = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return  ans;
}


int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int maxcount = 0;
    int ans = -1;
    for(int i = 0; i < n; i++){
        int current = m - lower(matrix[i], m, 1);
        
        if(current > maxcount){
            maxcount = current;
            ans = i;
        }
        // else if(current == maxcount){
        //     ans = min(ans,i);
        // }else{
        //     continue;
        // }
    }

    return ans;
}