#include<iostream>
using namespace std;
class array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;
public:
    Array(int);
    bool empty();
    bool full();
    void append(int);
    void insert(int,int);
    void edit(int,int);
    void del(int);
    ~array();
};

array::Array(int cap)
{
   capacity=cap;
   lastIndex=-1;
   ptr=new int[capacity];

}
array::~array()
{
    delete[]ptr;
}

void array::del(int index)
{ int i;
    if(empty())
    {
        cout<<"array is empty";
    }
    else if(index<0||index>lastIndex)
    {
        cout<<"invalid index";
    }
    else
    {
         for(i=index;i<lastIndex;i--)
         ptr[i]=ptr[i+1];
         lastIndex--;
    }
}
void array::edit(int index,int data)
{
    if(index>lastIndex+1||index<0 )
        {
         cout<<"invalid index";
        }
    ptr[index]=data;

}
 void array::insert(int index,int data)
{  int i;
    if(lastIndex==capacity-1)
        {
            cout<<"array is full";
        }
     else if(index>lastIndex+1||index<0 )
     {
         cout<<"invalid  index";
     }
     else
     {  for(i=lastIndex;i>=index;i--)
         ptr[i+1]=ptr[i];
         ptr[index]=data;
         lastIndex++;
     }


}
void array::append(int data)
{
    if(lastIndex==capacity-1)
    {
        cout<<"array is full";
    }
    else
    {
        lastIndex++;
        ptr[data]=data;
    }
}
bool array::empty()
{
    return lastIndex==-1;//if condition true it will print true.
}

bool array::full()
{
    return lastIndex==capacity-1;
}


int main()
{
    array obj;
    obj.Array(6);
    obj.insert(0,3);
    return 0;
}
