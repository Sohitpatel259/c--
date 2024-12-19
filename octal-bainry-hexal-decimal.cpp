#include <bits/stdtr1c++.h>
using namespace std;
int octalToDecimal (int n){
    int ans=0;
    int x=1;
    while (n>0)
    {
      int y=n%10;
      ans+=x*y;
      x *= 8;
     n /=10;
    }
   return ans; 
}


int binaryToDecimal (int n){
    int ans=0;
    int x=1;
    while (n>0)
    {
      int y=n%10;
      ans+=x*y;
      x *= 2;
     n /=10;
    }
   return ans; 
}


int hexadecimalToDecimal (string n){
    int ans=0;
    int x=1;
    int s=n.size();
    for (int i=s-1;i>=0;i--){
        if (n[i]>='0' && n[i]<='9'){
            ans+=x*(n[i]-'0');
        }
        else if (n[i]>='a' && n[i]<='f')
        {
           ans+= x*(n[i]-'a'+10);
        }
        x*=16;
    }
   return ans; 
}

int main () {
   //only for hexadecimaltodecimaluse string n;
   int n;
    cin>>n;
//cout<<octalToDecimal(n)<<endl;
cout<<binaryToDecimal(n)<<endl;
//cout<<hexadecimalToDecimal(n)<<endl;

return 0;
}