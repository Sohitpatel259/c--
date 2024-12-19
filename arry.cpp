/*#include <iostream>
using namespace std;
int main () {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
    }
    for (int i = 1; i <n; i++)
    {
       int curr=arr[i];
       int j=i-1;
       while (arr[j]>curr && j>=0)
       {
        arr[j+1]=arr[j];
        j--;
       }
       arr[j+1]=curr;
    }
    for (int i = 0; i < n; i++)
    {
        cout <<arr[i]<<" ";
    }
    cout<<endl;
    
return 0;
}
*/
/*#include <iostream>
using namespace std;
int leanersearch(int arr[],int n,int key){
    for (int i = 0; i < n; i++)
    {
       if (arr[i]==key)
       {
        return i;
       }
       
    }
    return -1;
}
int main () {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
       cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<leanersearch(arr,n,key)<<endl;

    
return 0;
}
*/
/*#include <iostream>
using namespace std;
int binarysearch(int arr[],int n,int key){
    int s=0; 
    int e=n;
    while (s<=e)
    {
       int mid=(s+e)/2;
       if (arr[mid]==key)
       {
        return mid; 
       }
       else if (arr[mid]>key)
       {
        e=mid-1;
       }
      else{
        s=mid+1;
      } 
    }
return -1;
    
}
int main () {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
       cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<binarysearch(arr,n,key)<<endl;
return 0;
}*/

#include <iostream>
using namespace std;

int main () {
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
    }
    for (int i = 0; i < n-1; i++)
    {
       for (int j =i+1; j <n;j++)
       {
       if (arr[j]<arr[i])
       {
       int temp=arr[j];
       arr[j]=arr[i];
       arr[i]=temp;
       }
       
       }
       
    }
    for (int i = 0; i < n; i++)
       {
        cout<<arr[i]<<" ";
       }
       cout<<endl;
return 0;
}
