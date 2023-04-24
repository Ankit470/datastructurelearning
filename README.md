
#include <iostream>
using namespace std;
struct Array
{
 int *A;
 int size;
 int length;
};
//Display the array
void Display(struct Array arr)
{
    cout<<"Elements are : " ;
 for(int i=0;i<arr.length ; i++)
 {
    cout<<arr.A[i]<<" ";
 }
  cout<<endl;
}

//Binary Search 

int Binary_Search(struct Array arr,int key)
{
    int low, mid , high;
    low =0 ;
    high = arr.length -1 ;
    while(low<=high)
    {
        mid = (low + high)/2 ;
        if(key == arr.A[mid])
         return mid;
        else if(key < arr.A[mid])
         high = mid -1 ;
        else 
         low = mid + 1;
    }
    return -1 ;
}

int RBinSearch(int a[],int l, int h,int key)
{
    if(l<=h)
    {
        int mid = (l+h)/2;
        if(key == a[mid])
         return mid;
        else if(key < a[mid])
         return RBinSearch(a, l , mid-1 ,key);
        else
         return RBinSearch(a, mid+1 ,h ,key);
    }
    return -1;
}




int main()
{
    int i,n;
    struct Array arr1;
    arr1.size = 10;
    arr1.A = new int[arr1.size];
    cout<<"Enter number of inputs"<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(i=0 ;i<n ;i++)
    {
        cin>>arr1.A[i];
    }
    arr1.length = n ;

    Display(arr1);
    cout << Binary_Search(arr1,16)<<endl;
    cout<<RBinSearch(arr1.A,0,arr1.length,10)<<endl;

    return 0;
}
