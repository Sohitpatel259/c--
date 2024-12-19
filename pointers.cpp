#include <iostream>
using namespace std;
class shopitem{
    int id;
    int price;
    public:
  void setnumber(int a,int b){
    id=a;
    price=b;
  }
void getnumber(void){
    cout<<"the id of this product is"<<id<<endl;
    cout<<"the price of this product is"<<price<<endl;
}
};
int main () {
    int size=2;
   // int *ptr=&size;
   // int *ptr=new int[32];
    shopitem *ptr=new shopitem[size];
    shopitem *ptr1=ptr;
    int p,q,i;
    for (int i=0;i<size;i++){
        cout<<"enter id and price of product"<<i+1<<endl;
        cin>>p>>q;
        ptr->setnumber(p,q);
        ptr++;

    }
    for (int i=0;i<size;i++){
        cout<<"enter number:"<<i+1<<endl;
        ptr1->getnumber();
        ptr1++;
    }
return 0;
}