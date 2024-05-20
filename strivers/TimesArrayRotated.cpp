/*
	Time Complexity: O(LogN)

	Space Complexity: O(1)

	Where 'N' is the number of elements in the vector 'arr'.
*/

int findKRotation(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    //Handling the case for sorted array 
    //and array with 1 element.
    if (arr[low] <= arr[high])
        return 0;
    int ans = 0;

    //Binary searching for the position of minimum element.
    //If arr[mid] > arr[high] minimum is in range [mid+1,high],
    //else it is in range [low,mid].
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        else
            high = mid;
    }
    ans = low;
    return ans;
}

