#include <iostream>
using namespace std;

void findmax(int arr[], int n){
 int res,max;
 max = arr[0];
 res = INT32_MIN;
for(int i = 0; i < n;i++){
 if(arr[i] > max){
  res = max;
  max = arr[i];
 }else{
  if(arr[i] > res && arr[i] != max){
   res = arr[i];
  }
 }
}
 cout << "second largest number is : " << res;
}

int main(){
  int size;
  cout << "enter size: ";
  cin >> size; 
    int arr[size]; 

    for (int i = 0; i < size; i++) { 
        cout << "Enter the element: "; 
        cin >> arr[i] ;
    } 

 findmax(arr,size);

 return 0;
}