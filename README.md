//Binary_Search
#include <iostream>
using namespace std;
struct Array
{
  int *A;
  int size;
  int length;
};
void Swap(int *x , int *y)
{
    int temp ;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Display(struct Array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        cout<<arr.A[i]<<" ";
    }
}

int Binary_Search(struct Array arr,int key)
{
    int low ;
    int high;
    int mid;
    low = 0;
    high = arr.length -1;
    while(low <= high)
    {
        mid = (low+high)/2 ;
        if(key == arr.A[mid])
        {
            return mid ;
        }else if (key < arr.A[mid])
        {
            high = mid-1;
        }else
          low = mid + 1 ;
    }return -1 ;
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

int Get(struct Array arr,int index)
{
    if(index >=0 && index < arr.length)
    {
        return arr.A[index] ;
    }
    return -1;
}
 void Set(struct Array *arr ,int index,int x )
 {
     if(index >=0 && index < arr-> length)
     {
         arr->A[index] = x ;
     }
 }
 
 int Max(struct Array arr)
 {
     int max = arr.A[0];
     for(int i=1 ;i<arr.length ;i++)
     {
         if(arr.A[i] > max)
          max = arr.A[i];
     }
     return max;
 }
 
 int Min(struct Array arr)
 {
     int min = arr.A[0];
     for(int i=1;i<arr.length ; i++)
     {
         if(arr.A[i] < min )
          min = arr.A[i];
     }
     return min;
 }
 
 int Sum(struct Array arr)
 {
     int sum = 0;
     for(int i=0;i<arr.length;i++)
     {
         sum += arr.A[i]; 
     }
     return sum;
 }
 
 float Average(struct Array arr)
 {
     return (float)Sum(arr)/(arr.length);
 }
 
 void Reverse(struct Array *arr)
 {
     int *B ;
     int i,j;
     B = new int[arr->length];
     for(i = arr->length-1 , j = 0 ; i >=0  ; i--,j++)
     {
         B[j] = arr->A[i];
     }
     
     for(i = 0 ;i < arr->length ;i++)
     {
         arr->A[i] = B[i];
     }
 }
 void Reverse2(struct Array *arr)
 {
     int i,j;
     for(i=0,j = arr->length-1; i<j;i++,j--)
     Swap(&arr->A[i],&arr->A[j]);
 }
  
  struct Array MergeArray(struct Array *arr1 , struct Array *arr2)
 {
     struct Array arr3;
     arr3.size = arr1->size + arr2->size ;
     arr3.length = arr1->length + arr2->length;
     arr3.A = new int[arr3.size];
     
     int i= 0 ,j = 0,k = 0;
     while(i <arr1->length && j < arr2->length)
     {
      if(arr1->A[i] < arr2->A[j])
      {
          arr3.A[k++] = arr1->A[i++];
      }
      else
      {
          arr3.A[k++] = arr2->A[j++];
      }
     }
     
     for( ;i < arr1->length;i++)
     {
         arr3.A[k++] = arr1->A[i];
     }
     for( ;j<arr2->length ; j++)
     {
         arr3.A[k++] = arr2->A[j];
     }
     
     return arr3;
 }
 

int main()
{
    struct Array arr1,arr2;
    struct Array merge_array;
    int i;
    //cout<<"Enter the size of array"<<endl;
    //cin>> arr1.size ;
    //arr1.A = new int[arr1.size];
    //cout<<"Enter the number of elements"<<endl;
    //cin >> n;
    
    arr1.size = 10 ;
    arr2.size = 10;
    
    arr1.A = new int[arr1.size];
    arr2.A = new int[arr2.size];
    arr1.length = 5;
    arr2.length = 5;
  
    cout<<"enter the elements into arr1"<<endl;
    for(i = 0;i<arr1.length;i++)
    {
        cin >> arr1.A[i];
    }
    
    cout<<"Enter the elements into arr2"<<endl;
    for(i =0 ;i<arr2.length ;i++)
    {
        cin >>arr2.A[i];
    }
  
    
    cout<< "elements into arr1 : ";
    Display(arr1);
    cout<<endl;
    cout<<"Elements into arr2 : ";
    Display(arr2);
    cout<<endl;
  
    //cout<< Binary_Search(arr1,5)<<endl;
    //cout<<RBinSearch(arr1.A,0,arr1.length,10)<<endl;
    //cout<<Get(arr1,4)<<endl;
    //Set(&arr1,0,15);
    //Display(arr1);
    //cout<<endl;
    //cout<<Max(arr1)<<endl;
    //cout<<Min(arr1)<<endl;
    //cout<<Sum(arr1)<<endl;
    //cout<<Average(arr1)<<endl;
    //Reverse(&arr1);
    //Reverse2(&arr1);
    //cout<<"Reversed array : " ;
    //Display(arr1);
  
    merge_array = MergeArray(&arr1,&arr2);
    cout<<endl;
    Display(merge_array);
    cout<<endl;
  
    return 0;
    
}

