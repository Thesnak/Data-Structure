#include <iostream>
using namespace std;
template <class T>
class Queue
{
    struct Node
    {
        T item;
        Node* next;
    };
    Node* Front;
    Node* Rear;
    int length;
public:
    Queue()
    {
        Front=Rear=NULL;
        length=0;
    }
    void AddQueue(T Element)
    {
        Node* NewNode = new Node;
        if(IsEmpty())
        {
            Front=NewNode;
            Front->item=Element;
            Front->next=NULL;
            Rear=Front;
            length++;
        }
        else
        {
            NewNode->item=Element;
            NewNode->next=NULL;
            Rear->next=NewNode;
            Rear=NewNode;
            length++;
        }

    }
    void DeletQueue()
    {
        if(IsEmpty())
            cout<<"The Queue is Empty to delete an element !"<<endl;
        else
        {
            Node* temp=Front;
            if(Front==Rear)
            {
                Front=NULL;
                Rear=NULL;
                length=0;
            }
            else
            {
                length--;
                Front=Front->next;
                temp->next=NULL;
                delete temp;
            }
        }
    }
    bool IsEmpty()
    {
        return length==0;
    }
    T GetFront()
    {
        if(IsEmpty())
            return-1;
        return Front->item;
    }
    T GetRear()
    {
        if(IsEmpty())
            return-1;
        return Rear->item;
    }
    void Clear()
    {
        Node* curr;
        while(Front!=NULL)
        {
            curr=Front;
            Front=Front->next;
            delete curr;
        }
        Rear=NULL;
        length=0;
    }
    void Print()
    {
        if(IsEmpty())
            cout<<"Queue is Empty "<<endl;
        else
        {
            cout<<"Elements in the Queue : "<<endl;
            cout<<"[";
            Node* curr=Front;
            while(curr!=NULL)
            {
                cout<<curr->item<<" ";
                curr=curr->next;
            }
            cout<<"]";
            cout<<endl;
        }
    }
    int GetSize()
    {
        return length;
    }
    void Search(T Element)
    {
        bool Notfound=true;
        if(IsEmpty())
            cout<<"Queue is Empty to search on it !"<<endl;
        else
        {
            Node* curr=Front;
            if(curr->item==Element)
            {

                cout<<"Element "<<Element<<" is in index "<<0<<endl;
                Notfound=false;
            }
            else
            {
                curr=Front->next;
                for(int i=1; i<length; i++)
                {
                    if(curr->item==Element)
                    {
                        cout<<"Element "<<Element<<" is in index "<<i<<endl;
                        Notfound=false;
                        break;
                    }
                    curr=curr->next;
                }
            }

        }
        if (Notfound) cout<<"There is no "<<Element<<" in the Queue !"<<endl;
    }
};

int main()s
{
    Queue<int> q;
    q.AddQueue(10);
    q.AddQueue(20);
    q.AddQueue(30);
    q.Search(40);
    //q.Print();
    return 0;
}
