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
//append element into array
void Append(struct Array *arr, int x)
{
  if(arr->length < arr->size )
  {
    arr->A[arr->length++] = x;
  }
}
//Insert element into the array at given index
void insert(struct Array *arr,int index,int x)
{
    int i;
    if(index>=0 && index <= arr->length)
    {
        for(i=arr->length ; i>index ; i--)
        {
            arr->A[i] = arr->A[i-1];
            arr->A[index] = x;
            arr->length++ ;
        }
    }
}

//Deleting element from a given index
int Delete(struct Array *arr, int index )
{
    int x=0;
    int i;
    if(index >=0  && index <= arr->length)
    {
        x = arr->A[index] ;
        for( i = index ;i<arr->length-1 ; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return -1;
}
//swapping of elements
void Swap(int *x , int *y)
{
    int temp ;
    temp = *x;
    *x = *y;
    *y = temp;
}
//Linear Search

int LinearSearch(struct Array *arr,int key)
{
    int i;
    for(i=0 ; i<arr->length ; i++)
    {
        if(key == arr->A[i])
        {
          Swap(&arr->A[i],&arr->A[i-1]);
          cout<<"Element found at index : ";
          return i;
        }


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

    Append(&arr1,45);

    Display(arr1);


    cout<<"deleted item at the given index : " << Delete(&arr1,0)<<endl;
    Display(arr1);

    cout<<LinearSearch(&arr1,10)<<endl;
    Display(arr1);
    return 0;
}
