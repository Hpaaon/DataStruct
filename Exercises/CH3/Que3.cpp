// Que3. 用栈实现队列
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

template <typename T>
class StackQueue
{
private:
    LinkedStack<T> sIn;
    LinkedStack<T> sOut;

    void transfer()
    {
        if(sOut.empty())
        {
            while(!sIn.empty())
            {
                sOut.push(sIn.top());
                sIn.pop();
            }
        }
    }

public:
    void push(const T& val)
    {
        sIn.push(val);
    }

    void pop() 
    {
        transfer();
        if (!sOut.empty()) {
            sOut.pop();
        }
    }

    void peek()
    {
        transfer();
        if (!sOut.empty()) {
            cout << sOut.top() << endl; 
        }
    }

    bool empty()
    {
        return sIn.empty() && sOut.empty();
    }
};


int main()
{
    StackQueue<int> queue;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string op;
        cin >> op;
        if(op == "ENQUEUE")
        {
            int val;
            cin >> val;
            queue.push(val);
        }
        else if(op == "DEQUEUE")
        {
            if(queue.empty())
            {
                cout << "EMPTY" << endl;
            }
            else
            {
                queue.peek();
                queue.pop();
            }
        }
        else
        {
            if(queue.empty())
            {
                cout << "EMPTY" << endl;
            }
            else
            {
                queue.peek();
            }
        }
    }
    return 0;
}