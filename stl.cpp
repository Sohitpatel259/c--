#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &v){
    for (int i = 0; i <v.size(); i++)
    {
      cout<<v[i] <<" " ;
    }
    cout<<endl;
};
int main () {
    vector<int>vec1;
    int element,size;
    cout<<"enter the size of your vector"<<endl;
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cout<<"enter an element to add to this vector ";
        cin>>element;
        vec1.push_back(element);
    }
    // pop_back ka use 1 no. kam krne ke liye kiya jata h jaise hume 5 elements ka vector banaya usme cin >> dala 1,2,3,4,5
    // to result sir hume 1,2,3,4 hi show hoga lakin agar use na kare to pure 5 hi show hong .
   //
    //vec1.pop_back();
    display(vec1);
    
return 0;
}