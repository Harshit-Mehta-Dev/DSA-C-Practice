//2. selection sort:-
#include<iostream>
using namespace std;
void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        //find min element in remaining unsorted array
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        //swap the found minimum element 
        if(minIndex !=i){
            int temp =arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
}
int main(){
    int arr[]={64,34,25,12,22};
    int n=5;
    for (int i =0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    selectionSort(arr,n);
    cout<<endl;
    for (int i =0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}