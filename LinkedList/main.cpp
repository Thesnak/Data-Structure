#include <iostream>
using namespace std;
typedef int Data;

class LinkedList
{
    struct Node
    {
        Data item;
        Node *next;
    };
    Node* First;
    Node* last;
    int length;
public:
    LinkedList()
    {
        First=last=NULL;
        length=0;
    }
    bool isEmpty()
    {
        return First==NULL;
    }
    void InsertFirst(int element)
    {
        Node* NewNode=new Node;
        NewNode->item=element;
        if(First==0)
        {
            First=last=NewNode;
            NewNode->next=NULL;
        }
        else
        {
            NewNode->next=First;
            First=NewNode;
        }
        length++;
    }
    void InsertLast(int element)
    {
        Node* NewNode=new Node;
        NewNode->item=element;
        if(First==0)
        {
            First=last=NewNode;
            NewNode->next=NULL;
        }
        else
        {
            last->next=NewNode;
            NewNode->next=NULL;
            last=NewNode;

        }
        length++;
    }
    void InsertAtPosition(int Position,int Element)
    {
        if(Position<0 || Position>length)
        {
            cout<<"Out Of Range !"<<endl;
        }
        else
        {
            Node* NewNode=new Node;
            NewNode->item=Element;
            if(Position==0)
                InsertFirst(Element);
            else if (Position==length)
                InsertLast(Element);
            else
            {
                Node* Curunt=First;
                for(int i=1; i<Position; i++) //Start From 1 to stop at last-1;
                {
                    Curunt=Curunt->next;
                }
                NewNode->next=Curunt->next;
                Curunt->next=NewNode;
            }
        }
        length++;
    }
    void DeletFirst()
    {
        if(isEmpty())
            cout<<"List is Empty"<<endl;
        else if(length==1)
        {
            delete First;
            First=last=NULL;
            length--;
        }
        else
        {
            Node* Curr=First;
            First=First->next;
            delete Curr;
            length--;
        }

    }
    void DeletLast()
    {
        if(isEmpty())
            cout<<"List is Empty"<<endl;
        else if(length==1)
        {
            delete First;
            First=last=NULL;
            length--;
        }
        else
        {
            Node* Curr=First->next;
            Node* Preve=First;
            while(Curr!=last)
            {
                Preve=Curr;
                Curr=Curr->next;
            }
            delete Curr;
            Preve->next=NULL;
            last=Preve;
            length--;
        }
    }
    void DeletAtPosition(int Position)
    {
        Node* Curr=First;
        Node* prev;
        if(Position<0 || Position>length)
            cout<<"Out Of Range !"<<endl;
        else if(Position==0)
            DeletFirst();
        else if(Position==length)
            DeletLast();
        else
        {

            for(int i=0; i!=Position; i++)
            {
                prev=Curr;
                Curr=Curr->next;

            }
            prev->next=Curr->next;
            delete Curr;

        }
    }
    void DeletData(Data ElementRemov)
    {
        if(isEmpty())
            cout<<"There is no Data in The List"<<endl;
        else
        {
            if(ElementRemov==First->item)
            {
                Node* Curr=First;
                First=First->next;
                delete Curr;
                length--;
                if(length==0)
                    last=NULL;
            }
            else
            {
                Node* Currunt;
                Node* prev;
                Currunt=prev=First;
                while((Currunt!=NULL)&&(Currunt->item!=ElementRemov))
                {
                    prev=Currunt;
                    Currunt=Currunt->next;
                }
                if(Currunt==NULL)
                {
                    cout<<"There is no "<<ElementRemov<<" In the List !"<<endl;

                }
                else
                {
                    prev->next=Currunt->next;
                    if(Currunt->next==NULL)
                    {
                        DeletLast();
                    }
                }
                delete Currunt;
                length--;
            }
        }
    }
    void Reverse()
    {
        bool flag=true;;
        if(isEmpty())
        {
            cout<<"The List is Empty can not do reverse!"<<endl;
                flag=false;
        }
        else if(length==1)
        {
            cout<<"The List have only one element !"<<endl;
            flag=false;
        }
        if(flag)
        {
            Node *Next,*Curr,*Prev;
            Prev=NULL;
            Curr=First;
            Next=Curr->next;
            while(Next!=NULL)
            {
                Next=Curr->next;
                Curr->next=Prev;
                Prev=Curr;
                Curr=Next;
            }
            First=Prev;
        }
    }
    int Search(Data Element)
    {
        if(isEmpty())
        {
            return -1;
        }

            Node* Curr=First;
            int position=0;
            while(Curr!=NULL)
            {
                if(Curr->item==Element)
                    return position;
                Curr=Curr->next;
                position+=1;
            }
            return -2;
    }
    void print()
    {
        if(isEmpty())
            cout<<"The List is Empty !"<<endl;
        Node *Curunt=First;
        while(Curunt!=NULL)
        {
            cout<<Curunt->item<<" ";
            Curunt=Curunt->next;
        }
    }
};

int main()
{
    LinkedList test;
    cout<<"Add at First :"<<endl;
    test.InsertFirst(10);
    cout<<"Add at Last :"<<endl;
    test.InsertLast(100);
    cout<<"Insert at position :"<<endl;
    test.InsertAtPosition(1,20);
    cout<<"Delete First :"<<endl;
    test.DeletFirst();
    cout<<"Delete Last :"<<endl;
    test.DeletLast();
    cout<<"Delete At position :"<<endl;
    test.DeletAtPosition(0);
    cout<<"Delete Data :"   <<endl;
    test.DeletData(1000);
    cout<<"Reverse List : ";
    test.Reverse();
    int Position=test.Search(1);
    if(Position==-2)
        cout<<"Not Found !"<<endl;
    else if(Position==-1)
        cout<<"The List is Empty !"<<endl;
    else
        cout<<"The position is : "<<Position<<endl;
    cout<<"List : ";
    test.print();
    return 0;
}
