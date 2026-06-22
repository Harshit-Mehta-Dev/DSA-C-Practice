//example of max and min and also bubbleshort
#include<iostream>
using namespace std;
int main(){
    int marks[] = {90,85,78,92,86};
    int size = 5;
    int maxMarks =marks[0];
    int minMarks =marks[0];
    int sum = 0;
    for(int i=0;i<size;i++){
        //check for max
        if(marks[i]>maxMarks){
            maxMarks = marks[i];
        }
        //check for min
        if(marks[i]<minMarks){
            minMarks = marks[i];
        }
        sum = sum+marks[i];
    }
    float average = (float)sum/size;
    cout<<"Max marks is:"<<maxMarks<<endl;
    cout<<"Min marks is:"<<minMarks<<endl;
    cout<<"total marks is:"<<sum<<endl;
    cout<<"average marks is:"<<average<<endl;
    return 0;
}