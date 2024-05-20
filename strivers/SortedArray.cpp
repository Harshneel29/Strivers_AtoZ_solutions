#include <iostream>
using namespace std;

int main(){

 int arr[5] = {1,2,3,7,5};
 int num = 0;

 for(int i = 0; i < 4; i++){
  if(arr[i] > arr[i+1]){
   num = 1;
  }
 }

 if(num == 0){
  cout << "sorted";
 }else{
  cout << "unsorted";
 }

 return 0;
}