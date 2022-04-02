#include <iostream>
using namespace std;
const int  Max1_Size=100;
template <class T>
class Stack
{
    int top;
    T Elements[Max1_Size];
public:
    Stack()
    {
        top=-1;
    }
    void push(T item)
    {
        if(top>=Max1_Size-1) // 0 --> 99
            cout<<"Stack is full to push !"<<endl;
        else
        {
            top++;
            Elements[top]=item;
        }
    }
    bool IsEmpty()
    {
        return top<0;
    }
    void pop()
    {
        if(IsEmpty())
           cout<<"Stack already is Empty to pop !"<<endl;
        else
            top--;
    }
     void pop(T& item)
    {
        if(IsEmpty())
           cout<<"Stack already is Empty to pop !"<<endl;
        else
        {
            item=Elements[top];
            top--;
        }
    }
    T GetTope()
    {
        if(IsEmpty())
            cout<<"Stack is Empty to GetTope !"<<endl;
        else
        return Elements[top];
    }
    void print()
    {
        if(IsEmpty())
            cout<<"Stack is Empty to print items !"<<endl;
        else
        {
            cout<<"[";
            for(int i=0;i<=top;i++)
                cout<<Elements[i]<<" ";
            cout<<"]";
            cout<<endl;
        }
    }
};

int main()
{
    Stack<int> s;
    s.push(100);
    s.push(200);
    s.push(300);
    s.pop();
    s.print();
    return 0;
}
