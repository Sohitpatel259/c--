// // // 1. calculate the sum of all the elements in the given array ?
// // #include <iostream>
// // using namespace std;
// // int main () {
// //     int a;
// //     cout<<"enter the size of array "<<endl;
// //     cin>>a;
// //     int sum = 0;
// // int arry[a];
// // for (int i = 0; i <= a-1; i++)
// // {
// //    cin>>arry[i];
// // }
// // for (int i = 0; i <= a-1; i++)
// // {
// //     sum = sum + arry[i];
// //    sum++;
// //    cout<<arry[i]<<" ";
 
// // }
// // cout<<endl;
// // cout<<"sum of array is "<<sum -a;

// // return 0;
// // }



// // 2. find the element X in the given array . take array and X as input ?
// // #include <iostream>
// // using namespace std;
// // int linearsearch (int array[],int n,int X){
// //     for (int i = 0; i < n; i++)
// //     {
// //        if (array[i]==X)
// //        {
// //         return i;
// //        }
       
// //     }
// //      return -1;
      
       
// // }
// // int main () {
// //     int n;
// //     cin>>n;
// //     int array[n];
// //     for (int i = 0; i< n; i++)
// //     {
// //        cin>>array[i];
// //     }
// //     int X;
// //     cin>>X;
// //     cout<<linearsearch(array,n,X);
    
    
// // return 0;
// // }
// // 3. find the secound largest value in the  given array ?
// // #include <iostream>
// // using namespace std;

// // int main () {
// //     int n;
// //     cout<<"enter size of array "<<endl;
// //     cin>>n;
// //     int array[n];
// //      cout<<"enter the array elements "<<endl;
// //     for (int i = 0; i < n; i++)
// //     {
       
// //         cin>>array[i];
// //     }
// //     int mx = INT16_MIN;
// //     int smx = INT16_MIN;
// //     for (int i = 0; i < n; i++)
// //     {
// //       if (mx<array[i])
// //       {
// //         mx=array[i];
// //       }
      
// //     }
    
// //     for (int i = 0; i < n; i++)
// //     {
// //        if (smx < array[i] && array[i] != mx)
// //        {
// //         smx=array[i];
// //        }
       
// //     }
// //     cout<<mx<<" "<<smx;
    
// // return 0;
// // }
// // 4. Two sum ?
// // #include <iostream>
// // # include <vector>
// // using namespace std;
// // int main () {
// //     int n ;
// //     cout<<"enter the size of array :"<<endl;
// //     cin>>n;
    
// //  int array[n];
// //    cout<<"enter the array elements :"<<n<<endl;
// //    for (int i = 0; i < n; i++)
// //    {
// //      cin>>array[i];
// //    }
// //    int target;
// //    cout<<"enter target"<<endl;
// //    cin>>target;
// //    for (int i = 0; i < n-1; i++)
// //    {
// //     for (int k = i+1; k <n; k++)
// //     {
// //         if (array[i]+ array[k]==target)
// //         {
// //           return (i,k);
          
// //         }
// //       return (array[i]-array[k-1]);
// //       cout<<i<<k;
// //     }
    
    
// //    }
  
   
   
// // return 0;
// // }
// // #include <iostream>
// // using namespace std;
// // int main () {
// //     int a;
// //     cin>>a;
// //     char ch = 'A';
// //     for (int i = 0; i < a; i++)
// //     {
        
// //        for (int j = 0; j < a; j++)
// //        {
// //         cout<<ch<<" ";
// //         ch=ch+1;
// //        }
// //        cout<<endl;
// //     }
    
// // return 0;
// // }/
// // 
// // #include <iostream>
// // using namespace std;
// // int main () {
// //     int a;
// //     cin>>a;
// //     int num=1;
// //     for (int i = 0; i < a; i++)
// //     {
        
// //        for (int j = 0; j < i+1; j++)
// //        {
// //         cout<<num<<" ";
        
// //        }
// //        num++;
// //        cout<<endl;
// //     }
    
// // return 0;
// // }
// // #include <iostream>
// // using namespace std;
// // int main () {
// //     int a;
// //     cin>>a;
    
// //     for (int i = 0; i < a; i++)
// //     {
        
// //        for (int j = i+1; j >0; j--)
// //        {
// //        cout<<j<<" ";
       
       
// //        }
    
// //        cout<<endl;
// //     }

// // return 0;
// // }
// // #include <iostream>
// // using namespace std;
// // int main () {
// //     int a=5;
// //     char ch='A';
// //     for (int i = 0; i < a; i++)
// //     {
        
// //         for (int j = i+1; j >0; j--)
// //         {
// //             cout<<ch<<" ";
// //             ch=ch+1;
// //         }
        
// //         cout<<endl;
// //     }
    
// // return 0;
// // }
// // #include <iostream>
// // using namespace std;
// // int main () {
// //     int a=6;
    
// //     for (int i = 0; i <a; i++)
// //     {
// //         for (int j =0; j <a-i-1; j++)
// //         {
// //            cout<<" ";
// //         }
// //        for (int j = 1; j <= i+1; j++)
// //        {
// //        cout<<j<<"";
// //        }
// //        for (int j = i; j > 0; j--)
// //        {
// //        cout<<j<<"";
// //        }
      
// //         cout<<endl;
// //     }
    
// // return 0;
// // }
// // #include <iostream>
// // using namespace std;
// // int main () {
// //     int a=4;
    
// //     for (int i = 0; i < a; i++)
// //     {
// //        for (int j = 0; j < a-i-1; j++)
// //        {
// //         cout<<" ";
        
// //        }
// //        cout<<"*";
// //       if (i !=0)
// //       {
// //         for (int j = 0; j < a+2*i-5; j++)
// //        {
// //         cout<<" ";
// //        }
// //        cout<<"*";
       
// //       }
      
      
// //        cout<<endl;
// //     };
// //     for (int i = 0; i < a; i++)
// //     {
       
      
// //       //if (i!=0)
// //       //{
// //          for (int j = 0; j < a+2*i-7; j++)
// //        {
// //         cout<<" ";
// //        }
// //        cout<<"*";
// //      // }
      
       
       
// //       //if (i!=0){
      
// //         for (int j = 0; j < a-2*i+3; j++)
// //        {
// //         cout<<" ";
        
// //        }
// //        cout<<"*";
      
// //     //  }
        
       
      
      
      
// //        cout<<endl;
// //     }
// // return 0;
// // }
// #include <iostream>
// using namespace std;
// int leaner_search(int arr[],int n,int key){
//   for (int i = 0; i < n; i++)
//   {
//    if (arr[i]==key)
//    {
//     cout<<i;
//    }
   
//   }

// }
// int main () {
//   int n;
//   cout<<"enter the num of elements : "<<endl;
//   cin>>n;
//   int arr[n];
//   cout<<"enter the  elements : "<<endl;
//   for (int i = 0; i < n; i++)
//   {
//     cin>>arr[i];
//   }
//   int key;
//   cout<<"enter the target : "<<endl;
//   cin>>key;
//   cout<<leaner_search(arr,n,key);
// return 0;
// }
#include <iostream>
using namespace std;
class Account_holder{
  public:
  string name;
  int account_num;
  int cif;
  public:
  void set_holder(){
    cout<<"Enter the Name, Account no. and cif number :"<<endl;
    cin>>name>>account_num>>cif;
  }
  void get_holder(){
    cout<<" Account Holder : "<<name<<endl;
    cout<<" Account Number : "<<account_num<<endl;
    cout<<" CIF Number : "<<cif<<endl;
  }
  
};
class Saving_Account:public Account_holder
{
  private:
  string acctype;
  int intrest;
  int Amount;
  public:
  void set_saving(){
    cout<<"Enter the Account type, set Intrest  and Amount in account :"<<endl;
    cin>>acctype>>intrest>>Amount;
  }
  void get_saving(){
     cout<<" Account Holder : "<<name<<endl;
    cout<<" Account Number : "<<account_num<<endl;
    cout<<" CIF Number : "<<cif<<endl;
    cout<< "Account type : "<<acctype<<endl;
    cout<< "Intrest you get : "<<intrest<<endl;
    cout<< "Amount : "<<Amount<<endl;

  }
  
};
class Current_Account:public Account_holder
{
  private:
  string acctype;
  int intrest;
  int Amount;
  public:
  void set_current(){
    cout<<"Enter the Account type, set Intrest  and Amount in account :"<<endl;
    cin>>acctype>>intrest>>Amount;
  }
  void get_current(){
     cout<<" Account Holder : "<<name<<endl;
    cout<<" Account Number : "<<account_num<<endl;
    cout<<" CIF Number : "<<cif<<endl;
    cout<< "Account type : "<<acctype<<endl;
    cout<< "Intrest you get : "<<intrest<<endl;
    cout<< "Amount : "<<Amount<<endl;

  }
  
};
int main () {
  Saving_Account s;
  Current_Account c;
  s.set_holder();
  s.set_saving();
  c.set_current();
  s.get_holder();
  s.get_saving();
  c.get_current();
return 0;
}