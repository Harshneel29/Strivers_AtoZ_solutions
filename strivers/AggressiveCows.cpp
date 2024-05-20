bool counting(vector<int> &v,int d,int c){
    int count = 1;
    int temp = v[0];
 
    int n = v.size();

    for(int i = 1; i < n; i++){
        if(v[i]-temp >= d){
            count++;
            temp = v[i];
        }
        if(count >= c) return true;
    }
    return false;

}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = stalls[n-1]-stalls[0];

    while(low <= high){
        int mid = (low + high)/2;
        bool temp = counting(stalls,mid,k);
        if(temp) low = mid + 1;
        else high = mid - 1;

    }

    return high;

}