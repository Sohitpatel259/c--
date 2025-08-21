#include <iostream>
using namespace std;
int main () {
    int n=6;
    int arr[]={2,4,1,1,6,5};
    int count=0;
    int counthill=0;
    int countvally=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]<arr[j] && arr[j]>arr[j+1]){
                counthill++;
            }
            else if (arr[j]<arr[i] && arr[i]>arr[i-1]){
                countvally++;
            }
            count=counthill+countvally;
            
        }
        
    }
    cout<<count;
    
return 0;
}