int count(vector<int> &v,int m){
    int n = v.size();
    int s = 1;
    long long ps = 0;

    for(int i = 0; i < n;i++){
        if(ps + v[i] <= m){
            ps += v[i];
        }else{
            s++;
            ps = v[i];
        }
    }
    return s;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int l = *max_element(arr.begin(),arr.end());
    int h = accumulate(arr.begin(),arr.end(),0);

    while(l <= h){
        int mid = (l+h)/2;

        int s = count(arr,mid);

        if(s>m){
            l = mid + 1;
        }else{
            h = mid - 1;
        }
    }
    return  l;
}