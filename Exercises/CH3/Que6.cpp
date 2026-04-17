//Que6. 链栈基本操作
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LinkedStack
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& val, Node* p = nullptr) : data(val), next(p) {}
    };
    Node* m_top;
    int m_size;

public:
    LinkedStack() : m_top(nullptr), m_size(0) {}

    void push(const T& val)
    {
        Node* newNode = new Node(val, m_top);
        m_top = newNode;
        m_size++;
    }

    void pop()
    {
        if(empty())
        {
            cout << "EMPTY" << endl;
        }
        else
        {
            cout << m_top->data << endl;
            Node* temp = m_top;
            m_top = m_top->next;
            delete temp;
            m_size--;
        }
    }

    void top()
    {
        if(empty())
        {
            cout << "EMPTY" << endl;
        }
        else
        {
            cout << m_top->data << endl;
        }
    }

    bool empty() { return m_top == nullptr; }

};
int main()
{
    int m;
    cin >> m;
    string op;
    LinkedStack<int> Stack;
    while(m--)
    {
        cin >> op;
        if(op == "PUSH")
        {
            int val;
            cin >> val;
            Stack.push(val);
        }
        else if(op == "POP")
        {
            Stack.pop();
        }
        else if(op == "TOP")
        {
            Stack.top();
        }
        else if(op == "IS_EMPTY")
        {
            if(Stack.empty())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}