#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
template <class T>
class stack
{
    struct Node
    {
        T item;
        Node* next;
    };
public:
    Node* top;
    Node* cur;
    stack()
    {
        top=NULL;
    }
    void push(T NewElment)
    {
        Node* NewItemPtr=new Node;
        NewItemPtr->item=NewElment;
        NewItemPtr->next=top;
        top=NewItemPtr;
    }
    bool IsEmpty()
    {
        return top==NULL;
    }
    void pop()
    {
        if(IsEmpty())
            cout<<"Stack is Empty to pop item !"<<endl;
        else
        {
            Node* temp=new Node;
            temp=top;
            top=top->next;
            temp->next=NULL;
            delete temp;
        }
    }
    void pop(T& Element)
    {
        if(IsEmpty())
            cout<<"Stack is Empty to pop item !"<<endl;
        else
            Element=top->item;
        Node* temp=new Node;
        temp=top;
        top=top->next;
        temp->next=NULL;
        delete temp;
    }
    void GetTop(T& Element)
    {
        if(IsEmpty())
            cout<<"Stack is Empty to GetTop item !"<<endl;
        else
            Element=top->item;
    }
    void Print()
    {
        if(IsEmpty())
            cout<<"Stack is Empty to Print item !"<<endl;
        else
        {

            cout<<"[";
            cur=top;
            while(cur!=NULL)
            {
                cout<<cur->item<<" ";
                cur=cur->next;
            }
            cout<<"]";
            cout<<endl;
        }
    }
};
bool ArePair(char open,char closed)
{
    if(open=='(' && closed==')')
        return true;
    else if(open=='{' && closed=='}')
        return true;
    else if(open=='[' && closed==']')
        return true;
    return false;
}
bool AreBalanced(string exp)
{
    stack<char> s;
    for(int i=0; i<exp.length(); i++)
    {
        if(exp[i]=='(' ||exp[i]=='{' || exp[i]=='[')
            s.push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(s.IsEmpty() || !ArePair(s.top->item,exp[i]))
                return false;
            else
                s.pop();
        }
    }
    if(s.IsEmpty())
        return true;
    return false;
}
bool IsOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}
int performOperation(int op1, int op2, char op)
{
    int ans;
    switch (op)
    {
    case '+':
        ans = op2 + op1;
        break;
    case '-':
        ans = op2 - op1;
        break;
    case '*':
        ans = op2 * op1;
        break;
    case '/':
        ans = op2 / op1;
        break;
    }
    return ans;
}
void CalcPostfix()
{
    char exp[1000], buffer[15];
    int i, op1, op2, len, j, x;
    stack<int> s;
    cout<<"Enter a Postfix Expression: ( e.g. 4 5 * )\n";
    cin.getline(exp,1000);
    len = strlen(exp);
    j = 0;
    bool AllNumbers=true;
    for (i = 0; i < len; i++)
    {
        if(bool test1=IsOperator(exp[0]))
        {
            cout<<"Invalid input can not start with operator !"<<endl;
            s.top->item=NULL;
            break;
        }
        if (exp[i] >= '0' && exp[i] <= '9')
        {

            buffer[j++] = exp[i];
            if (j > 0)
            {
                buffer[j] = '\0';
                x = atoi(buffer); //convert string to int
                s.push(x);
                j = 0;

            }
        }
        else if (bool test=IsOperator(exp[i]))
        {
            AllNumbers=false;
            op1 = s.top->item;
            s.pop();
            op2 = s.top->item;
            s.pop();
            s.push(performOperation(op1, op2, exp[i]));
        }
        else if(exp[i]!=' ')
        {
            cout<<"the input can not be character or Symbols !"<<endl;
            s.top->item=NULL;
            break;
        }
    }
    if(AllNumbers)
    {
        cout<<"There is no operators in the equation !"<<endl;
        s.top->item=NULL;
    }
   cout<<"Answer = "<<s.top->item;
}
string InfixToPostfix(string expression);

int HasHigherPrecedence(char operator1, char operator2);

bool isOperator(char C);

bool IsOperand(char C);

string InfixToPostfix(string expression)
{
	stack<char> S;
	string postfix = "";
	for (unsigned int i = 0; i < expression.length(); i++) {

		if (expression[i] == ' ' || expression[i] == ',') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back.
		else if (isOperator(expression[i]))
		{
			while (!S.IsEmpty() && S.top->item != '(' && HasHigherPrecedence(S.top->item, expression[i]))
			{
				postfix += S.top->item;
				S.pop();
			}
			S.push(expression[i]);
		}
		else if (IsOperand(expression[i]))
		{
			postfix += expression[i];
		}

		else if (expression[i] == '(')
		{
			S.push(expression[i]);
		}

		else if (expression[i] == ')')
		{
			while (!S.IsEmpty() &&S.top->item != '(') {
				postfix += S.top->item;
				S.pop();
			}
			S.pop();
		}
	}

	while (!S.IsEmpty()) {
		postfix += S.top->item;
		S.pop();
	}

	return postfix;
}
bool IsOperand(char C)
{
	if (C >= '0' && C <= '9') return true;
	if (C >= 'a' && C <= 'z') return true;
	if (C >= 'A' && C <= 'Z') return true;
	return false;
}
bool isOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;

	return false;
}
int IsRightAssociative(char op)
{
	if (op == '$') return true;
	return false;
}
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	if (op1Weight == op2Weight)
	{
		if (IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ? true : false;
}
int main()
{
    string expression;
	cout << "Enter Infix Expression \n";
	getline(cin, expression);
	string postfix = InfixToPostfix(expression);
	cout << "Output = " << postfix << "\n";
    return 0;
}
