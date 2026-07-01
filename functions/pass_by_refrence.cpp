#include<iostream>
using namespace std;
/*void abc(int &a){
    a = 20;
}
int main(){
    int a = 10;
    abc(a);
    cout<<a<<endl;
    return 0;
}*/
//pass by reference
void xyz(int &p){
    p = 50;
}
int main(){
    int p = 25;
    xyz(p);
    cout<<p<<endl;
    return 0;
}