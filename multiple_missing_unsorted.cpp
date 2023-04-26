
//multiple missing element from unsorted array 
#include <iostream>
using namespace std;

struct Array 
{
    int *A;
    int size;
    int length;
};

int Low(struct Array arr)
{
    int low = arr.A[0] ;
    for(int i=1;i< arr.length ;i++)
    {
        if(low > arr.A[i])
        {
            low =  arr.A[i];
        }
    }
    return low ;
}

int High(struct Array arr)
{
    int high = arr.A[0];
    for(int i=1;i< arr.length;i++)
    {
        if(arr.A[i] > high)
        high = arr.A[i];
    }
    return high;
}

void Unsort_Missing(struct Array arr)
{
    int new_high = High(arr);
    int new_low = Low(arr);
    
    int A[new_high];
    for(int i=0;i<new_high;i++)
    {
        A[i] = 0;
    }
    
    for(int i=0 ;i<arr.length ; i++)
    {
        A[arr.A[i]]++ ; 
    }
    
    for(int i=new_low ;i <= new_high ;i++)
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
