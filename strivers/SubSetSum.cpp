
void sum(int i, int s, vector<int> &num, int n, vector<int> &ds){
	if( i == n){
		ds.push_back(s);
		return;
	}

	sum(i + 1, s + num[i],num,n,ds);
	sum(i + 1, s ,num,n,ds);
}


vector<int> subsetSum(vector<int> &num){
	vector<int> ds;
	int n = num.size();
	sum(0,0,num,n,ds);	
	sort(ds.begin(),ds.end());
	return ds;
}