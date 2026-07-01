/*#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[], int start, int mid, int end) {
    // size of left and right size
    int leftsize = mid - start + 1;
    int rightsize = end - mid;
    // temp array
    vector<int> left;
    vector<int> right;
    // copy element to left array
    for (int i = 0; i < leftsize; i++) {
        left.push_back(arr[start + i]);
    }
    // copy element to right array
    for (int i = 0; i < rightsize; i++) {
        right.push_back(arr[mid + 1 + i]);
    }
    // compare both elements and put smaller first
    int i = 0, j = 0, k = start;
    while (i < leftsize && j < rightsize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    // copy remaining elements of left array
    while (i < leftsize) {
        arr[k++] = left[i++];
    }
    // copy remaining elements of right array
    while (j < rightsize) {
        arr[k++] = right[j++];
    }
}
void mergeSort(int arr[], int start, int end) {
    // base case
    // if array has only 1 element or its already sorted
    if (start >= end) {
        return;
    }
    // processing
    int mid = start + (end - start) / 2;
    // function call
    // 1. sort left array
    mergeSort(arr, start, mid); 
    // 2. sort right array
    mergeSort(arr, mid + 1, end);
    // 3. merge both sorted half
    merge(arr, start, mid, end);
}
int main() {
    int arr[] = {8, 4, 2, 9, 5, 1, 7, 6, 3};
    int size = 9;
    mergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}*/


#include<iostream>
#include<vector>
using namespace std;
//function to arange two sorted half
void merge(vector<int>& arr, int start, int mid, int end) {
    //will find the size of left and right subarray
    int leftsize = mid - start + 1;
    int rightsize = end - mid;
    //will create temp array
    vector<int> left(leftsize);
    vector<int> right(rightsize);
    //will copy the elements into left array
    for (int i = 0; i < leftsize; i++) {
        left[i] = arr[start + i];
    }
    //will copy the elements into right array
    for (int i = 0; i < rightsize; i++) {
        right[i] = arr[mid + 1 + i];
    }
    int i = 0; //pointer for left
    int j = 0; //pointer for right
    int k = start; //pointer for original array
    //now merge the two sorted array
    while (i < leftsize && j < rightsize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    //copy remaining elements of left array
    while (i < leftsize) {
        arr[k++] = left[i++];
    }
    //copy remaining elements of right array
    while (j < rightsize) {
        arr[k++] = right[j++];
    }
}
void mergeSort(vector<int>& arr, int start, int end) {
    //base case
    if (start >= end) {
        return;
    }
    //processing
    int mid = start + (end - start) / 2;
    //function call
    //1. sort left array
    mergeSort(arr, start, mid);
    //2. sort right array
    mergeSort(arr, mid + 1, end);
    //3. merge both sorted array
    merge(arr, start, mid, end);
}
int main() {
    vector<int> arr = {38, 24, 43, 33, 9, 82, 10};
    mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

