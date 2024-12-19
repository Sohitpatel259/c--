#include <iostream>
using namespace std;
class base1{
    protected:
    int base1int;
    public:
    void set_base1int(int a){
        base1int=a;
    }
};
class base2{
    protected:
    int base2int;
    public:
   void set_base2int(int b) {
    base2int=b;
   }
};
class drived:public base1,public base2 {
    public:
    void show(){
    cout <<"the value of a is"<<base1int<<endl;
    cout <<"the value of b is"<<base2int<<endl;
    cout<<"the product of a and b is "<<base1int*base2int<<endl;
    }
};
int main () {
drived harsh;
harsh.set_base1int(78);
harsh.set_base2int(87);
harsh.show();
return 0;
}