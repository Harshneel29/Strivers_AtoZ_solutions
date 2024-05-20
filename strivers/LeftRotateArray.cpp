#include <iostream>
using namespace std;

int main(){

 int arr[7] = {1,2,3,4,5,6,7};
 int num;

 cout << "Enter Shift : ";
 cin >> num;

 for ( int k = 0; k < num; k++){

  for( int j = 0; j < 6; j++ ){

   int temp = arr[j];
   arr[j] = arr[j+1];
   arr[j+1] = temp;

  }

 }

 for(int i = 0; i < 7;i++){
  cout << arr[i];
 }

 return 0;
}