#include <iostream>
using namespace std;
class student{
    protected:
    int sub1;
    public :
    void setsubject1(int math){
    sub1=math;
    }
};
class exam{
    protected:
    int sub2;
    public:
    void setsubject2(int physics){
        sub2=physics;
    }
};
class drived:public student,public exam{
    public:
    void show(){
        cout<<"enter the marks of maths is "<<endl;
        cin>>sub1;
        cout<<"enter the marks of physics "<<endl;
        cin>>sub2;
        cout<<"the total marks "<<sub1+sub2<<endl;
        cout<<"the persentage is "<<(sub1+sub2)*(100)/200<<endl;
        cout<<"the passing marks is "<<33<<endl;
        if (sub1+sub2 <33){
            cout<<"sorry dear but you are fail "<<endl;
        }
        if (sub1+sub2 >=33){
            cout<<" congratulations sohit you are pass "<<endl;
        }
    }
};
int main () {
    drived sohit;
    sohit.show();
return 0;
}