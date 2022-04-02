#include <iostream>
#include <cassert>
using namespace std;
template <class T>
class Queue
{
    int Rear,Front,length;
    T *arr;
    int maxSize;
public:
    Queue(int sizee)
    {
        if(sizee<=0)
        {
            cout<<"Size can not be less than or equal to zero so the default sizee = 100"<<endl;
            maxSize=100;
        }
        else
        {
            maxSize=sizee;
        }
        Front=0;
        Rear=maxSize-1;  //BEST for circle array
        length=0;
        arr=new T[maxSize];
    }
    bool IsEmpty()
    {
        return length==0;
    }
    bool IsFull()
    {
        return length==maxSize;
    }
    void AddQueue(T Element)
    {
        if(IsFull())
            cout<<"Queue is Full to add element !"<<endl;
        else
        {

            {
                Rear=(Rear+1)%maxSize; //  move the rear According to circular queue
                arr[Rear]=Element;
                length++;
            }
        }

    }
    void DeletQueue()
    {
        if(IsEmpty())
            cout<<"Empty is Full to delete element !"<<endl;
        else
        {
            Front=(Front+1)%maxSize;
            length--;
        }
    }
    T GetFront()
    {
        assert(!IsEmpty());
        return arr[Front];
    }
    T GetRear()
    {
        assert(!IsEmpty());
        return arr[Rear];
    }
    void PrintQueue()
    {
        if(IsEmpty())
            cout<<"Queue is Empty to print elements !"<<endl;
        else
        {
            cout<<"Elements in Queue :"<<endl;
            cout<<"[";
            for(int i=Front; i!=Rear; i=(i+1)%maxSize)
            {
                cout<<arr[i]<<" "; //her we can not print last element when front equal rear
            }
            cout<<arr[Rear]; // so we print the last element her
            cout<<"]";
        }
    }
    int Search(T Element )
    {
        int pos=-1;
        if(!IsEmpty())
        {
            for(int i=Front ;i!=Rear;i=(i+1)%maxSize)
                    if(arr[i]==Element)
                    {
                        pos=i;
                        break;
                    }
                if(pos=-1)

                {
                    if(arr[Rear]==Element)
                        pos=Rear;
                }
        }
        else
        {
            cout<<"Queue is Empty to search an element !"<<endl;
        }
        return pos;
    }
};

int main()
{
    cout<<"Enter the size of Queue  :";
    int sizee;
    cin>>sizee;
    Queue<int> q(sizee);
    q.AddQueue(10);
    q.AddQueue(20);
    cout<<q.Search(40);
    return 0;
}
