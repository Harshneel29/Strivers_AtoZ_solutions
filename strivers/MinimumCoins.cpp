vector<int> MinimumCoins(int n)
{
    vector<int> v= {1,2,5,10,20,50,100,500,1000};
    vector<int> res;
    int m = v.size();
    int sum = 0;

    for(int i = m-1; i >= 0; i--){
        if(n-v[i] >= 0){
            while(n-v[i] >= 0){
            n = n - v[i];
            res.push_back(v[i]); 
            }
        }else{
            continue;
        }
    }

    return res;
}