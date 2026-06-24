//array tiverse implement if condition check linear search of array {16,17,19,26,8}
/*#include<iostream>
using namespace std;
int main(){
    int arr[] = {16,17,19,26,8};
    int size = 5;
    for(int i = 0; i < size; i+1){
        if(arr[i] == 26){
            cout<<"so the element function index: "<<i<<endl;
        }
    }
    return 0;
}*/

//binary search:
#include<iostream>
using namespace std;
int binarySearch(int arr[], int size, int target){
    int start = 0;
    int end = size -1;
    while(start<=end){
        int mid = (start+end)/2;
        // condition 1:
        if(arr[mid]==target){
            return mid;
        }
        // condition 2:
        else if(arr[mid]<target){
            start = mid+1;
        }
        // condition 3:
        else{
            end = mid-1;
        }
    }
    return -1; // element not found
}
int main(){
    int arr[]={2,5,8,12,16,23,38,56,72,91};
    int size = 10;
    int target;
    cout<<"enter the number to search"<<endl;
    cin>>target;
    int result = binarySearch(arr,size,target);
    cout<<"we got the element at index"<<result<<endl;
    return 0;
}
