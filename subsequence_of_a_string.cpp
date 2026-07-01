#include<iostream>
using namespace std;
void printSubsequence(string s,int index,string output){
    //base case
    if(index == s.length()){
        cout<<output<<endl;
        return; 
    }
    //process
    //function call
    //choice 1: exclude the current character and increase index
    printSubsequence(s,index+1,output);
    //choice 2: include the current character and increase index
    printSubsequence(s,index+1,output + s[index]);
}
int main(){
    string s = "abc";
    cout<<"all subsequence are"<<endl;
    printSubsequence(s,0,"");
    return 0;
}

