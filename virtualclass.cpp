#include <iostream>
using namespace std;
class barbase {
    public:
    int var_base=1;
   virtual void display(){
  cout<<"the value of base calss is "<<var_base<<endl;
    }
};
class derivedbase:public barbase{
    public:
    int var_derived=2;
    void display(){
        cout<<"display base class var_base"<<var_base<<endl;
        cout<<"display drived class var_drived"<<var_derived<<endl;
    }
};
int main () {
    barbase *base_class_pointer;
    barbase obj_base;
    derivedbase obj_derived;

    base_class_pointer =&obj_derived;
    base_class_pointer->display();
return 0;
}