// Que2.后缀表达式求值
#include <iostream>
#include <string>
#include <sstream>

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

    ~LinkedStack(){ clear(); }

    void push(const T& val)
    {
        Node* newNode = new Node(val, m_top);
        m_top = newNode;
        m_size++;
    }

    void pop()
    {
        Node* temp = m_top;
        m_top = m_top->next;
        delete temp;
        m_size--;
    }

    T& top() { return m_top->data; }

    bool empty() { return m_top == nullptr; }

    int size() const{ return m_size; }

    void clear()
    {
        while(!empty())
        {
            pop();
        }
    }
};

void Solution()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    string token;
    LinkedStack<int> s;
    while(ss >> token)
    {
        if(isdigit(token[0]))
        {
            int val = stoi(token);
            s.push(val);
        }
        else
        {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            switch (token[0])
            {
            case '+':
                s.push(val2 + val1);
                break;
            
            case '-':
                s.push(val2 - val1);
                break;
            
            case '*':
                s.push(val2 * val1);
                break;
            
            case '/':
                s.push(val2 / val1);
                break;
            
            default:
                break;
            }
        }
    }
    if(!s.empty())
    {
        cout << s.top() << endl;
    }
}

int main()
{
    Solution();
    return 0;
}