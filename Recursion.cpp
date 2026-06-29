/*#include<iostream>
using namespace std;
void countdown(int n){
    cout<<n<<endl; // Base case
    if(n==0){
        return;
    }
    countdown(n-1);
    cout<<"TikTik"<<n<<endl; // processing
}
int main(){
    countdown(10); // function call
    return 0;
}*/

/*#include<iostream>
using namespace std;
int function(int n){
    if(n==0){
        return 1; // base case
    }
    int ans = function(n-1); // processing
    return n * ans; // processing
}
int main(){
    int ans = function(5);
    cout<<ans<<endl;
    return 0;
}*/

/*#include<iostream>
using namespace std;
void printArray(int arr[], int size){
    if(size==0){
        return; // base case
    }
    printArray(arr, size-1); // processing
    cout<<arr[size-1]<<endl; // processing
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);
    return 0;
}*/

//reverse string using recurstion:-
/*#include<iostream>
using namespace std;
void reverseString(string s, int size){
    if(size<0){
        return; // base case
    }//process
    cout<<s[size];
    reverseString(s, size-1); // Function call
}
int main(){
    string s = "hello";
    cout<<"before: "<<s<<endl;
    cout<<"after: ";
    reverseString(s,s.length()-1);
    return 0;
}*/

//find sum of digit:-
/*#include<iostream>
using namespace std;
int sumOfDigit(int n){
    if(n==0){
        return 0; // base case
    }//process
    return (n%10) + sumOfDigit(n/10); // Function call
}
int main(){
    int n = 12345;
    cout<<"sum of digit: "<<sumOfDigit(n)<<endl;
    return 0;
}*/


/*#include<iostream>
using namespace std;
int sumOfDigit(int n){
    //base case
    if(n==0){
        return 0;
    }
    //process
    int lastdigit = n%10;
    //function call
    return lastdigit + sumOfDigit(n/10);
}
int main(){
    cout<<sumOfDigit(12345)<<endl;
    return 0;
}*/

//check if array is sorted  or not using recursion:-
#include<iostream>
using namespace std;
bool isSorted(int arr[], int n){
    if(n==1){ // base case
        return true;
    }
    if(arr[0]<arr[1]){ // processing
        return false;
    }
    return isSorted(arr+1,n-1); // function call
}
int main() {
    int arr[] = {1,2,3,4,5};
    cout<<isSorted(arr,5);
    return 0;
}
