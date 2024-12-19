//this is the example of inheristance class of oop.
#include <iostream>
using namespace std;
class employ {
    public:
    int id;
    float salary;
    employ(int inputid){
id=inputid;
salary=1668780.0;
    };
    employ(){}
};
class programmer :public employ{
    public:
    programmer(int inputid){
        id=inputid;
    }
    int language =27;
    void getdata(){
        cout<<id<<endl;
    }
};
 int main() {
    employ sohit(8), harsh(9);
    cout<<sohit.salary<<endl;
    cout<<harsh.salary<<endl;
    programmer skillf(7);
    cout<<skillf.language<<endl;
    cout<<skillf.id<<endl;
    skillf.getdata();

return 0;
}