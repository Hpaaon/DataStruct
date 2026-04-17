//Que4. 用队列实现栈
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class QueueStack
{
private:
    queue<int> q1, q2;
public:
    void push(int val)
    {
        q1.push(val);
    }   
    void pop()
    {
        if (q1.empty()) 
        {
            cout << "EMPTY" << endl;
            return;
        }
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        cout << q1.front() << endl;
        q1.pop();
        swap(q1, q2);
    }
    void top()
    {
        if (q1.empty()) 
        {
            cout << "EMPTY" << endl;
            return;
        }
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        cout << q1.front() << endl;
        q2.push(q1.front());
        swap(q1, q2);
    }
};


int main()
{   
    QueueStack stack;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string op;
        cin >> op;
        if(op == "PUSH")
        {
            int val;
            cin >> val;
            stack.push(val);
        }
        else if(op == "POP")
        {
            stack.pop();
        }
        else
        {
            stack.top();
        }
    }
    return 0;
}