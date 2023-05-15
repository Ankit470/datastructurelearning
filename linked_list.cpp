#include <iostream>
using namespace std;
struct Node
{
 int data ;
 struct Node *next;
}*first=NULL; 

void create(int A[],int n)
{
   int i;
   struct Node *t,*last;
   first  = new Node();
   //first = (struct Node*)malloc(sizeof(struct Node));
   first->data = A[0];
   first->next = NULL;
   last = first ;

   for(i=1;i<n;i++)
   {
    t = new Node();
    t->data = A[i];
    t->next = NULL;
    last ->next = t;
    last =t;
   }


}

void Display(struct Node *p)
{
  while(p!=NULL)
  {
    cout<<p->data<<" ";
    p  = p->next;
  }
}

void RDisplay(struct Node *p)
{
  if(p !=NULL)
  {
    
    RDisplay(p->next);
    cout<< p ->data<<" ";
  }
}

int Count(struct Node *p)
{
  int c = 0;
  while( p !=0)
  {
    c++;
    p = p->next;
  }
  return c;
}
int Rcount(struct Node *p)
{
  int cn= 0;
   if(p==0)
    return 0;
  else
   return Rcount(p->next)+1;
}

int Add(struct Node *p)
{
  int sum = 0;
  while(p)
  {
    sum = sum + p->data ;
    p = p -> next ;
  }
  return sum;
}

int Radd(struct Node *p)
{
  if(p==0)
  return 0;
  else 
  return Radd(p->next) + p->data;
}


int Max(struct Node *p)
{
  int x = 0;
  if(p==0)
  return INT8_MIN;
  x = Max(p->next);
  return x>p->data?x:p->data;
}

int main()
{
  int A[] = {1,2,3,4,5};
  create(A,5);
  
  Display(first);
  cout<<endl;
  cout<<Rcount(first)<<endl;
  cout<<Add(first)<<endl;
  //cout<<Radd(first)<<endl;
  cout<<Max(first)<<endl;

  return 0;
}
