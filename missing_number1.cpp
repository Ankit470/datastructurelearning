
//find the missing number from the set of firs N natural numbers
#include <iostream>
using namespace std;

struct Array 
{
    int *A;
    int size;
    int lenght;
};

int Missing_Number(struct Array arr)
{
    int sum = 0;
    int total_sum = 0;
    int missing_number;
    for(int i=0 ;i<=arr.lenght ;i++)
    {
        sum = (sum +1) + i;
        total_sum = total_sum + arr.A[i];
    }
    missing_number = sum - total_sum;
    return missing_number;
}

struct Array Display(struct Array arr)
{
    for(int i=0;i< arr.lenght ;i++)
    {
        cout<<arr.A[i]<<" ";
    }
    return arr;
}

int main()
{
    struct Array arr1;
    arr1.size =11;
    arr1.lenght = 9;
    arr1.A = new int[arr1.size];
    
    cout<<"Enter the elements"<<endl;
    for(int i=0;i< arr1.lenght ;i++)
    {
        cin>> arr1.A[i];
    }
    Display(arr1);
    cout<<endl;
    
    cout<<"Missing Number is :" <<Missing_Number(arr1) <<endl;
    return 0;
}
