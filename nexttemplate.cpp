#include <iostream>
using namespace std;
template <class T>
void swapp(T &a,T &b){
    T temp =a;
    a=b;
    b=temp;
}
template <class T1,class T2>
float funcaverage(T1 a,T2 b){
    float avg =(a+b)/2.0;
    return avg;

}
int main () {
    float a;
    a=funcaverage(3,8);
    printf("the avg of these no. is %.3f \n",a);
    int x=4,y=9;
    swapp(x,y);
    cout<<x<<endl<<y;
    return 0;
}