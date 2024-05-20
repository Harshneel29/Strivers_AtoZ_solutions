int check(vector<int> &v,int num){
    int n = v.size();
    long long last = 0;
    int count = 1;

    for(int i = 0; i < n; i++){
        if(last + v[i] <= num){
            last += v[i];

        }else{
            count++;
            last = v[i];
        }
    } 

    return count;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int l = *max_element(boards.begin(),boards.end());
    int h = accumulate(boards.begin(),boards.end(),0);

    while(l<=h){
        int mid = (l+h)/2;

        int res = check(boards, mid);

        if(res > k){
            l = mid+1;
        }else{
            h= mid - 1;
        }
    }
    return l;
}