#include <iostream>
using namespace std;

struct Array 
{
    int *A;
    int size;
    int length;
};

void Missing_Element2(struct Array arr)
{
    int difference;
    int low = arr.A[0];
    difference = low - 0;
    for(int i=0 ; i< arr.length ;i++)
    {
      if(arr.A[i]-i != difference)
       {
         cout<<"Missing element found  "<< i+difference <<endl;
         break;
       }
    }
    cout<<"no missing elements"<<endl;
}

struct Array Display(struct Array arr)
{
    for(int i=0;i< arr.length ;i++)
    {
        cout<<arr.A[i]<<" ";
    }
    return arr;
}

int main()
{
    struct Array arr1;
    arr1.size =11;
    arr1.length = 9;
    arr1.A = new int[arr1.size];
    
    cout<<"Enter the elements"<<endl;
    for(int i=0;i< arr1.length ;i++)
    {
        cin>> arr1.A[i];
    }
    Display(arr1);
    cout<<endl;
    
    Missing_Element2(arr1);
    return 0;
}
