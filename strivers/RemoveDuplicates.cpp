#include <iostream>
using namespace std;

int main(){

 int arr[8] = {1,1,2,2,2,3,3,3};

 int i = 0;
 for(int j = 1; j < 8; j++){

  if(arr[i] != arr[j]){
   i++;
   arr[i] = arr[j];
  }

 }

for(int k = 0; k <= i; k++){

 cout << arr[k] << " ";

}

 return 0;
}