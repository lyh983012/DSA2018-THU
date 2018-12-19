#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
const int N = 204800;
 
void Merge(int arr[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q + 1;
    int left[n1 + 1], right[n2];
 
    for (int i = 0; i != n1; ++i){
        left[i] = arr[p + i];
    }
    left[n1] = N;
 
    for (int j = 0; j != n2 - 1; ++j){
        right[j] = arr[q + j + 1];
    }
    right[n2 - 1] = N;
 
    int i = 0, j = 0;
    for(int k = p; k != r + 1; ++k){
        if(left[i] > right[j]){
            arr[k] = right[j];
            ++j;
        }
        else{
            arr[k] = left[i];
            ++i;
        }
    }
}
 
void MergeSort(int arr[], int p, int r){
    if(p < r){
        int q = (p + r)/2;
        MergeSort(arr, p, q);
        MergeSort(arr, q + 1, r);
        Merge(arr, p, q, r);
    }
}