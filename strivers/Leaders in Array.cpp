vector<int> superiorElements(vector<int>&a) {
    vector<int> res;
    int n = a.size();
    int max = a[n-1];
    res.push_back(max);

    for(int i = n-2; i >= 0; i--){
        if(a[i] > max){
            max = a[i];
            res.push_back(max);
        }
    }
    return res;

}