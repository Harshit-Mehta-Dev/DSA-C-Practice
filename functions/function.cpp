/*#include<iostream>
using namespace std;
void printName(){
    cout<<"Harshit";
}
int main(){
    printName();
    return 0;
}*/

//types of functions (1) void function (2) non-void function //perimaramites and non perimaramites function // return and non return function
//Types of non-void function (a) return function (b)function with no return type (c) function with no parameter (d) function with parameter
//example of void function
/*#include<iostream>
using namespace std;
void printName(){
    cout<<"Harshit";
}
int main(){
    printName();
    return 0;
}*/

//example of non-void function
/*#include<iostream>
using namespace std;
int main(){
    int sum(int,int);
    int x,y,s;
    cout<<"enter two numbers";
    cin>>x>>y;
    s=sum(x,y);
    cout<<"sum of "<<x<<" and "<<y<<" is "<<s;
    return 0;
}
int sum(int a, int b){
    return a+b;
}*/

/*#include<iostream>
using namespace std;
int printName(int a, int b){
    int sum = a+b;
    return sum;
}
int main(){
    int sum = printName(10,20);
    cout<<sum;
    return 0;
}*/



/*#include<iostream>
using namespace std;
//type 1: no return no perameter goes in, nothing comes out
void great(){
    cout<<"hello world";
}
//type2: parameter but no return
void great2(string firstname, string lastname){
    cout<<"hello "<<firstname<<lastname<<endl;
}
//type3: return type but no parameter
int getNumber(){
    return 100;
}
int main(){
    great();
    great2("harshit","Mehta");
    int a = getNumber();
    cout<<a<<endl;
    return 0;
}
//type4: return type and parameter
int main(){
    great();
    great2("Harshit","mehta");
    int a = getNumber();
    cout<<a<<endl;
    int result = add(10,20);
    cout<<result<<endl;
    return 0;
}*/

