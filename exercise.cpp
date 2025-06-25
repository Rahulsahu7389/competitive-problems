#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr, int st ,int mid , int end){
  vector<int> temp ;
  int i = st;
  int j = mid +1;
  while(i<=mid && j<=end){
    if(arr[i]>=arr[j]){
      temp.push_back(arr[j]);
      j++;
    }
    else{
      temp.push_back(arr[i]);
      i++;
    }
  }
  while(i<=mid){
    temp.push_back(arr[i]);
      i++;
  }
  while(j<=end){
    temp.push_back(arr[j]);
      j++;
  }
  for (int t = 0; t <temp.size() ; t++)
  {
    arr[t + st] = temp[t];
  }
  
}

void mergesort(vector<int>&v, int st , int end){
  if(st<end){
    int mid = st + (end - st)/2;
    mergesort(v,st,mid);
    mergesort(v,mid+1,end);
    merge(v , st, mid,end);
  }
}

int main(){
  vector<int> v = {12 ,31,35,8,32,17};
  mergesort(v,0 , v.size()-1);
  for(auto val: v){
    cout<<val<<endl;
  }

  return 0;
}