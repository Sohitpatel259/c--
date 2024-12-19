// #include <iostream>
// using namespace std;
// class sohit;
// class harsh {
//     public :
//    int add (int a,int b){
//         return (a+b);
//     };
// int setrealnumber(sohit,sohit);
// int setimnumber(sohit,sohit);
// };
// class sohit {
// int x,y;
// friend class harsh;
// public:
// void setnumber (int n1,int n2){
//     x=n1;
//     y=n2;
// }
// void printnumber(){
//     cout<<"the value of x and y  is"<<x<<"+"<<y<<"i"<<endl;
// };
// };
// int harsh::setrealnumber(sohit s,sohit p){
//     return (s.x+p.x);
// };
// int harsh::setimnumber(sohit s,sohit p){
//     return (s.y+p.y);
// };
// int main () {
//     sohit s,p;
//     s.setnumber (87,45);
//     s.printnumber();

//     p.setnumber(76,985);
//     p.printnumber();

//     harsh h;
//     int real =h.setrealnumber(s, p);
//     int img=h.setimnumber(s,p);
//     cout<<"the sum of x and y of real no. is"<<real<<endl;
//     cout<<"the sum of x and y of imagenary no. is"<<img<<endl;

// return 0;
// }
#include <iostream>
using namespace std;
class complex{
  private:
  int a,b;
  public:
  void putcomplex(){
    cin>>a>>b;
  }
  void getcomplex(){
    cout<<a<<" + i"<<b;
  }
};
int main () {
  complex c;
  c.putcomplex();
  c.getcomplex();
return 0;
}