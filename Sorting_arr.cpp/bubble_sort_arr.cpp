//sorting technique:-
//1. bubble sort:- if element is big then ok if not put at first again arange 
/*#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        bool swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped = true;    
            }
        }
        if (swapped==false){
            break;
        }
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={64,34,25,12,22};
    int n =5;
    cout<<"before";
    printArray(arr,n);
    bubbleSort(arr,n);
    cout<<"after";
    printArray(arr,n);
    return 0;
}*/

/*#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if(swapped==false){
            break;
        }
    }
};
int main(){
    Solution obj;
    int arr[] = {4,1,3,9,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Input: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    obj.bubbleSort(arr, n);
    cout << "Output: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}*/


/*#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<int>sortArray(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i){
            bool swapped = false;
            for(int j = 0; j < n - i - 1; ++j){
                if(nums[j] > nums[j + 1]){
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped){
                break;
            }
        }
        return nums;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {5,2,3,1};
    cout << "Input: ";
    for(int num : nums) cout<<num<<" ";
    cout << "\n";
    sol.sortArray(nums);
    cout << "Output: ";
    for(int num : nums) cout<<num<<" ";
    cout << "\n";
    return 0;
}*/


/*class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
        return nums;
    }
};*/




