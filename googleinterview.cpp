/* 1. largest subarray arithamatic problem;
#include <iostream>
using namespace std;
int main () {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
       cin>>arr[i];
    }
   int ans=2;
   int pd=arr[1]-arr[0];
   int j=2;
   int current=2;
   while (j<n)
   {
    if (pd==arr[j]-arr[j-1])
    {
       current++;
    }
    else{
        pd=arr[j]-arr[j-1];
        current=2;
    }
    ans=max(ans,current);
    j++;
   }
   cout<<ans<<endl;
   
return 0;
}*/

/* 2. record breaking day problem;
#include <iostream>
using namespace std;
int main () {
   int n;
   cin>>n;
   int a[n+1];
   a[n]=-1;
   for (int i = 0; i < n; i++)
   {
     cin>>a[i];
   }
   if (n==1)
   {
     cout<<"1"<<endl;
     return 0;
   }
   int ans=0;
   int mx=-1;
   for (int i = 0; i <n; i++)
   {
   if (a[i]>mx && a[i]>a[i+1])
   {
     ans++;
   }
   mx=max(mx,a[i]);
   }
   cout<<ans<<endl;

return 0;
}
*/
#include "bits/stdc++.h"
using namespace std;
int main () {
   int n;
   cin>>n;
   int a[n];
   for (int i=0; i<n; i++)
   {
      cin>>a[i];
   }
const int N = 1e6 + 2;
int idx[N];
for (int i=0; i<N; i++)
{
   idx[i]=-1;
}
int minidx = INT_MAX ;
for (int i = 0; i <n; i++)
{
   if (idx[a[i]] != -1)
   {
      minidx = min(minidx , idx[a[i]]);
   }
   else{
      idx[a[i]]  = i;
   }
}
if (minidx == INT_MAX)
{
  cout<<"-1"<<endl;
}
else{
   cout<<minidx + 1<<endl;
} 

return 0;
}