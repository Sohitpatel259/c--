#include <iostream>
#include<cmath>
using namespace std;
class calculator{
    public :
    double add (double n1,double n2){
    return n1+n2;
    }
    double subtract(double n1,double n2){
        return n1-n2;
    }
    double multiply(double n1,double n2){
       return n1*n2;
    }
    double divide (double n1,double n2){
        return n1/n2;
    }  
};
class sceintificcalculator :public calculator{
    public:
    double squareroot(double x){
        return sqrt(x);
    }
    double sin (double x){
        return sin(x);
    }
     double cos (double x){
        return cos(x);
     }
};
int main () {
    calculator simple;
    sceintificcalculator scientific;
    double num1,num2;
    char op;
    cout<<"enter first number"<<endl;
    cin>>num1;
    cout<<"enter the character (+,-,*,/,q,s,c)"<<endl;
    cin>>op;
    if (op !='q' && op !='s'&& op !='c'){
    cout<<"enter second number"<<endl;
    cin>>num2;
    }
    switch (op){
        case '+':
        cout<<"result"<<simple.add(num1,num2)<<endl;
        break;
        case '-':
        cout<<"result"<<simple.subtract(num1,num2)<<endl;
        break;
        case '*':
        cout<<"result"<<simple.multiply(num1,num2)<<endl;
        break;
        case '/':
        cout<<"result"<<simple.divide(num1,num2)<<endl;
        break;
        case 'q':
        cout<<"result"<<scientific.squareroot(num1)<<endl;
        break;
        case 's':
        cout<<"result"<<scientific.sin(num1)<<endl;
        break;
        case 'c':
        cout<<"result"<<scientific.cos(num1)<<endl;
        break;
    }

return 0;
}