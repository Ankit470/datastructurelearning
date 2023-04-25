//include variable low and high in the array ...

#include <iostream>
using namespace std;

struct Array 
{
    int *A;
    int size;
    int length;
};

void Unsort_Missing(struct Array arr)
{
    int low = 1;
    int high = 12;
    
    int A[high];
    for(int i=0;i<high;i++)
    {
        A[i] = 0;
    }
    
    for(int i=0 ;i<arr.length ; i++)
    {
        A[arr.A[i]]++ ; 
    }
    
    for(int i=low ;i <= high ;i++)
    {
        if(A[i] ==0)
        {
            cout<<i<<" " ;
        }
    }
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
    
    Unsort_Missing(arr1);
    return 0;
}
