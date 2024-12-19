// bubble sort
// #include <iostream>
// using namespace std;
// void bubble_sort(int arr[],int n){
//      int temp,i,j;
//     for (int i = 0; i < n; i++)
//     {
       
//         for (int j = 0; j<n-i-1; j++)
//         {
//            if (arr[j]>arr[j+1])
//            {
//              temp = arr[j];
//             arr[j]=arr[j+1];
//             arr[j+1]=temp;
//            }
           
//         }
        
//     }
    
// }


// int main () {
//     int n;
//     cin>>n;
//    int arr[n];
//    for (int  i = 0; i <n; i++)
//    {
//     cin>>arr[i];
//    }
//    for (int  i = 0; i < n; i++)
//    {
//     cout<<arr[i]<<" ";
//    }
//    cout<<endl;
//    bubble_sort(arr,n);
//    for (int i = 0; i < n; i++)
//    {
//    cout<<arr[i]<<" ";
//    }
   


// return 0;
// }

// selection sort
#include <iostream>
using namespace std;
void selection_sort(int arr[],int n){
    int i,j,t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            while (arr[j]>arr[j+1])
            {
               t=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=t;
               
            }
            
        }
        
    }
    
    
}
int main () {
    int n=7;
    int arr[] = {34,82,23,4,6,0,77};
    
   selection_sort(arr,n);
for (int i = 0; i < n; i++)
{
   cout<<arr[i]<<" ";
}

return 0;
}