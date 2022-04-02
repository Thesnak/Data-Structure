#include<iostream>
using namespace std;
typedef int Data;
class DoubleLinkedList
{
private:
    struct Node
    {
        Data item;
        Node* next;
        Node* prev;
    };
    Node* First;
    Node* Last;
    int length;

public:
    DoubleLinkedList()
    {
        First = NULL;
        Last = NULL;
        length = 0;
    }
    bool IsEmpty()
    {
        return (First == NULL);
    }
    ~DoubleLinkedList()
    {
        Node *temp;
        while (First != NULL)
        {
            temp = First;
            First = First->next;
            delete temp;
        }
        Last = NULL;
        length = 0;
    }

    void InsertLast(Data Element)
    {
        Node* NewNode = new Node;
        NewNode->item = Element;
        if (length == 0)
        {
            First = Last = NewNode;
            NewNode->next = NewNode->prev = NULL;
        }
        else
        {
            NewNode->next = NULL;
            NewNode->prev = Last;
            Last->next = NewNode;
            Last = NewNode;
        }
        length++;
    }



    void InsertFirst(Data Element)
    {
        Node*NewNode = new Node;
        NewNode->item = Element;
        if (length == 0)
        {
            First = Last = NewNode;
            NewNode->next = NewNode->prev = NULL;
        }
        else
        {
            NewNode->next = First;
            NewNode->prev = NULL;
            First->prev = NewNode;
            First = NewNode;

        }
        length++;
    }



    void InsertAtPosition(int position, Data Element)
    {
        if (position < 0 || position > length)
            cout << "Out Of Range ...!" << endl;
        else
        {
            Node *NewNode = new Node;
            NewNode->item = Element;
            if (position == 0)
                InsertFirst(Element);
            else if (position == length)
                InsertLast(Element);
            else
            {
                Node *curr = First;
                for (int i = 1; i < position; i++)
                {
                    curr = curr->next;
                }

                NewNode->next = curr->next;
                NewNode->prev = curr;
                curr->next->prev = NewNode;
                curr->next = NewNode;
                length++;
            }

        }
    }


    void DeletFirst()
    {
        if (length == 0)
            cout << "The List is Empty to remove from first !" << endl;
        else if (length == 1)
        {
            delete First;
            Last = First = NULL;
        }
        else
        {
            Node* curr = First;
            First = First->next;
            First->prev = NULL;
            delete curr;

        }
        length--;
    }

    void DeletAtPosition(int Position)
    {
        if (Position < 0 || Position >= length)
        {
            cout << "Out Of Range" << endl;
            return;
        }
        else if (Position == 0)
        {
            DeletFirst();
        }
        else if (Position == length - 1)
        {
            DeletLast();
        }
        else
        {
            Node *curr = First->next;


            for (int i = 1; i < Position; i++)
            {
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
        length--;
    }
    void DeletLast()
    {
        if (length == 0)
            cout << "The List is Empty to remove from Last !" << endl;
        else if (length == 1)
        {
            delete First;
            Last = First = NULL;
            length--;
        }
        else
        {
            Node *curr = Last;
            Last = Last->prev;
            Last->next = NULL;
            delete curr;
            length--;
        }
    }



    void DeletData(Data Element)
    {
        if (IsEmpty())
        {
            cout << "The List in Empty to remove Element ! ";
            return;
        }
        Node*curr = First->next;

        if (First->item == Element)
        {
            DeletFirst();
            return;
        }
        else
        {


            while (curr != NULL&&(curr->item!=Element))
            {
                if (curr->item == Element)
                    break;
                curr = curr->next;
            }

            if (curr == NULL)
            {
                cout << "There is no "<<Element<<" In The list !\n";
                return;
            }
            else if (curr->next == NULL)
            {
                DeletLast();
                return;
            }

            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
                length--;
            }

        }


    }
    void Revers()
    {
        if(IsEmpty())
            cout<<"The List is Empty !"<<endl;
        else if(length==1)
        {
            cout<<"The List Have only one Element !"<<endl;
        }
        else
        {
            Node *temp = NULL;
            Node *curr = First;

            while (curr != NULL)
            {
                temp = curr->prev;
                curr->prev = curr->next;
                curr->next = temp;
                curr = curr->prev;
            }
            if(temp != NULL )
                First = temp->prev;
        }
    }

    void Print()
    {
        if (IsEmpty())
        {
            cout << "The List is Empty";
        }
        else
        {
            Node* temp = First;
            while (temp != NULL)
            {
                cout << temp->item << " ";
                temp = temp->next;
            }
        }
        cout << endl;

    }
    void reverse_display()
    {
        if (IsEmpty())
        {
            cout << "Empty List Can't Display Reverse...!";
        }
        else
        {
            Node* temp = Last;
            while (temp != NULL)
            {
                cout << temp->item << " ";
                temp = temp->prev;
            }
        }

    }
    int Search(Data Element)
    {
        if(IsEmpty())
        {
            return -1;
        }

            Node* curr=First;
            int positio=0;
            while(curr!=NULL)
            {
                if(curr->item==Element)
                    return positio;
                curr=curr->next;
                positio+=1;
            }
            return -2;
    }


};
int main()
{
    DoubleLinkedList test;
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
    test.Revers();
    int Position=test.Search(1);
    if(Position==-2)
        cout<<"Not Found !"<<endl;
    else if(Position==-1)
        cout<<"The List is Empty !"<<endl;
    else
        cout<<"The position is : "<<Position<<endl;
    cout<<"List : ";
    test.Print();
    return 0;
}
