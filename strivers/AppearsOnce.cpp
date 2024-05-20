#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int AppearsOnce(int arr[],int n){

 int hash[n/2 + 1] = {0};

 for(int i=0; i<n;i++){

  hash[arr[i]]++;

 }

  for (int i = 0; i <= n/2 ; i++) {
        if (hash[i] == 1) {
            return i;
        }

        // cout << hash[i];
    }

    return -1;

}

int AppearsOnce2(int arr[],int n){

map<int,int> mpp;

for (int i = 0; i < n; i++){
 mpp[arr[i]]++;
}

for (auto it: mpp){

 if(it.second == 1){
  return it.first;
 }

}

    return -1;

}

int AppearsOnce3(int arr[],int n){

 int result = 0;

 for(int i = 0; i < n; i++){
  result = result ^ arr[i];
 }

 return result ;
}


int main(){

 int arr[9] = {1,1,2,2,3,4,3,0,0};
 int result  =  AppearsOnce3(arr,9);
 cout<< result;
 return 0;
}