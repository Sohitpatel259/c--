#include <iostream>
using namespace std;
template <class t>
class vector{
    public:
    t* arr;
    int size;
    vector(int m){
        size=m;
        arr=new t[size];
    }
    t dotproduct (vector &v){
        t d=0;
        for (int i = 0; i < size; i++)
        {
            d+=this->arr[i]*v.arr[i];
        }
        return d;
    }
};
int main () {
    vector <float>v1(3);
    v1.arr[0]=1.4;
    v1.arr[1]=1.4;
    v1.arr[3]=1.6;
    vector <float >v2(3);
    v2.arr[0]=1.1;
    v2.arr[1]=1.3;
    v2.arr[2]=16.7;
    float a=v1.dotproduct(v2);
    cout<<"the dot product of vactor is  "<<a<<endl;
    if (a <13)
    {
        cout<<"the value is less then 13"<<endl;
    }
    if (a >13)
    {
        cout<<"the value is greater then 13"<<endl;
    }

    
return 0;
}