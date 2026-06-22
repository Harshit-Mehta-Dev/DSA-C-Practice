/*#include<iostream>
using namespace std;
int main(){
    int marks[3][3]={
        {90,85,78},
        {92,88,76},
        {76,85,89}
    };
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<marks[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}*/

//find min/max/average in 2d array
#include<iostream>
using namespace std;
int main(){
    int marks[3][3] = {90,85,78,92,86};
    int maxMarks = marks[0][0];
    int minMarks = marks[0][0];
    int sum = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(marks[i][j]>maxMarks){
                maxMarks = marks[i][j];
            }
            if(marks[i][j]<minMarks){
                minMarks = marks[i][j];
            }
            sum = sum+marks[i][j];
        }
    }
    float average = (float)sum/size;
    cout<<"Max marks is:"<<maxMarks<<endl;
    cout<<"Min marks is:"<<minMarks<<endl;
    cout<<"Average marks is:"<<average<<endl;
    return 0;
}

























































