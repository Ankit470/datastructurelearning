#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data ;
  struct Node *next;
}*first = NULL ,*last = NULL;

void Create(int A[],int n)
{
   struct Node *t;
   first  = new Node();
   first->data = A[0];
   first->next = NULL;
   last = first;
   for(int i=1;i<n;i++)
   {
    t = new Node();
    t->data = A[i];
    t->next = NULL;
    last ->next = t;
    last = t;
   }
}

int Count(struct Node *p)
{
  int c= 0;
  while(p !=NULL)
  {
     c++;
     p = p->next;
  }

  return c;
}

int Sum(struct Node *p)
{
  int s = 0;
  while(p!=NULL)
  {
    s = s + p->data;
    p = p->next;

  }
  return s;
}

void Display(struct Node *p)
{
  while(p!=NULL)
  {
    cout<<p->data << " ";
    p = p->next;
  }
}

int Max(struct Node *p)
{
  int max = INT16_MIN;
  while( p !=NULL)
  {
    if(max < p->data)
      max = p->data;
    p = p->next;
    
  }
  return max;
}

int Min(struct Node *p)
{
  int min = INT16_MAX;
  while( p !=NULL)
  {
    if(min > p->data)
     min = p->data;
    p= p->next;
  }
  return min;
}

Node *Search(struct Node *p,int x)
{
  Node *q = NULL;
  while( p !=NULL)
  {
    if( x == p->data)
    {
      q->next = p->next;
      p->next = first;
      first = p;
      return (p);
    }
    q = p;
    p=p->next;
  }
  return NULL;
}

void InsertFirst(struct Node *p,int x)
{
  struct Node *t;
   t= new Node();
  t->data = x;
  t->next = first;
  first = t;
}

void InsertAny(struct Node *p, int pos,int x)
{
  
  if(pos == 0)
  {
    struct Node *t;
    t= new Node();
    t->data = x ;
    t->next = first;
    first = t;
  }

  else if(pos > 0 )
        {
           struct Node *t;
           t = new Node();
           t->data = x;
           p = first;
           for(int i=0;i<pos -1 ;i++)
           {
            p = p->next;
           }
           t->next = p->next;
           p->next = t;
        }
  
}
void Push(int x)
{
  struct Node *t;
  t = new Node ();
  t->data = x;
  t->next = NULL;
  if(first == NULL)
  {
    first = last = t;
  }
  else
  {
    last ->next =t;
    last = t;
  }
}

void InsertSort(struct Node *p,int x)
{
  struct Node *t , *q =NULL;
  t = new Node ();
  t->data = x;
  t->next = NULL;

  if(first ==NULL)
  {
    first = t ;
  }
  else
   {
    while( p && p->data < x)
    {
      q = p;
      p = p->next;
    }
    if( p == first)
    {
      t->next = first ;
      first = t;
    }
    else 
     {
      t->next  = q->next ;
      q ->next = t;
     }
   }
}

void Delete(struct Node *p , int posi)
{
  int x;
  if(posi == 0)
  {
    struct Node *t = first ;
    first = first -> next;
    x = t->data;
    delete t;
  }
  else
   {
    struct Node *q = NULL , *t = first;
     for(int i=0 ;i<posi-1;i++)
     { 
      q = t;
      t  = t->next;
     }
     q->next = t->next ;
     x = t->data;
     delete t;
   }
}

int Is_Sorted(struct Node*p)
{
   int x = INT16_MIN;
    while( p!=0)
    {
       if(p->data <x)
        return 0;
      x = p->data;
      p = p->next;
    }
    return 1;
}
int main()
{
  struct Node *temp;
  int A[]={10,20,30,40,50};
  Create(A,5);
  
  Display(first);
  // cout<<endl;
  // cout<<"Number of nodes = " << Count(first)<<endl; 
  // cout<<"Sum = "<<Sum(first)<<endl;
  // cout<<"MIN = "<<Min(first)<<endl;
  // cout<<"MAX = "<<Max(first)<<endl;
  // temp = Search(first,40);
  // if(temp)
  //  cout<< "element found"<<endl;
  // else
  //  cout<<"element Not Found"<<endl;
  // Display(first);
  // cout<<endl;
  // InsertFirst(first,5);
  // Display(first);
  // cout<<endl;
  // InsertAny(first,3,70);
  // Display(first);
  // cout<<endl;

  // Push(60);
  // Display(first);
  // cout<<endl;
  
  // InsertSort(first , 70);
  // InsertSort(first , 25);
  cout<<endl;
  //Delete(first,0);
  //Delete(first,4);
  //Display(first);
  if(Is_Sorted(first))
   cout<<"Sorted "<<endl;
  else
   cout<<"Not sorted"<<endl;


  return 0;
}


