int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here

	int i = 0;
	int j = n - 1;
	int mid;
	int ans = n ;

	while(i <= j){
		mid = (i + j)/2;
		if(arr[mid] >= x){
			ans = mid;
			j = mid - 1;
		}
		else{

			i = mid + 1;
		}
	}

	return ans;
}
