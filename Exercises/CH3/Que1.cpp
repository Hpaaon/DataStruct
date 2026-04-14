// Que1. 中缀转后缀表达式
#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    struct Node
    {
        char data;
        Node* next;
        Node(char val, Node* p = nullptr) : data(val), next(p) {}
    };
    Node* m_top;
    int m_size;

public:
    Stack() : m_top(nullptr), m_size(0) {}
    void push(char val)
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
    char top() { return m_top->data; }
    bool empty() { return m_size == 0; }
};

bool isNum(char val) { return (val >= '0' && val <= '9'); }
bool isOp(char val) { return (val == '+' || val == '-' || val == '*' || val == '/'); }
bool isLeft(char val) { return val == '('; }
bool isRight(char val) { return val == ')'; }

int getPriority(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
void Solution()
{
    string s;
    Stack ops;
    bool first = true;
    cin >> s;
    for(int i=0; i<s.length(); i++)
    {
        if(isNum(s[i]))
        {
            if(!first) cout << " ";
            while(i < s.length() && isNum(s[i]))
            {
                cout << s[i++];
            }
            i--;
            first = false;
        }
        else if(isLeft(s[i])) { ops.push(s[i]); }
        else if(isRight(s[i])) 
        {
            while (!ops.empty() && ops.top() != '(')
            {
                cout << " " << ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else
        {
            while(!ops.empty() && ops.top() != '(' && getPriority(ops.top()) >= getPriority(s[i]))
            {
                cout << " " << ops.top();
                ops.pop();
            }
            ops.push(s[i]);
        }
    }
    while (!ops.empty())
    {
        cout << " " << ops.top();
        ops.pop();
    }
    cout << endl;
}

int main()
{
    Solution();
    return 0;
}