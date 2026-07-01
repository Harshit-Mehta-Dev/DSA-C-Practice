//array [8,9,7,9,8] it is palindrome find true or false is it palidrome or not use TWO pointer approach
/*#include<iostream>
using namespace std;
bool checkPalindrome(int arr[], int size){
    int left = 0;
    int right = size -1;
    while(left <= right){
        if(arr[left] != arr[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main(){
    int arr[]= {8,9,7,9,8};
    int size = 5;
    bool ans = checkPalindrome(arr, size);
    cout<<"the given array is palindrome: "<<ans<<endl;
    return 0;
}*/

//array {15,12,23,25,50} find true and false if it is sorting or not using two pointer approach
#include<iostream>
using namespace std;
bool checkSort(int arr[], int size){ 
    int left = 0;
    int right = size -1;
    while(left <= right){
        if(arr[left] > arr[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main(){
    int arr[]= {15,12,23,25,50};
    int size = 5;
    bool ans = checkSort(arr, size);
    cout<<"the given array is sorting: "<<ans<<endl;
    return 0;
}

  
