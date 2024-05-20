#include <iostream>
using namespace std;


void maxones(int arr[], int n){
 int result ;
 
 for(int i = 0; i < n; i++){

  if(arr[i] == 1){
   int count = 0;
   int j = i;
   while(arr[j] == 1){
    count++;
    j++;

   }
   if(result < count){
    result = count;
   }
  }

 }

 cout << result;
}

int main(){

 int arr[7] = {1,1,0,0,1,1,1};

 maxones(arr,7);

 return 0;
}