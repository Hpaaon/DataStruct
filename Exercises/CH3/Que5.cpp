//Que5. 顺序栈基本操作
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class SeqStack
{
private:
    T* m_data;
    int m_top;
    int m_capacity;

public:
    SeqStack(int initCap) : m_capacity(initCap), m_top(-1)
    {
        m_data = new T[m_capacity];
    }

    void push(const T& val)
    {
        if(m_top + 1 == m_capacity)
        {
            cout << "FULL" << endl;
        }
        else
        {
            m_data[++m_top] = val;
        }
    }

    void pop(){ m_top--; }

    T& top() { return m_data[m_top]; }

    int size() { return m_top + 1; }

    bool empty() { return m_top == -1; }

};



int main()
{
    int n, m;
    cin >> n >> m;
    SeqStack<int> Stack(n);
    string op;
    while(m--)
    {
        cin >> op;
        if (op == "PUSH") 
        {
            int val;
            cin >> val;
            Stack.push(val);
        } 
        else if (op == "POP") 
        {
            if (Stack.empty()) 
            {
                cout << "EMPTY" << endl;
            } 
            else 
            {
                cout << Stack.top() << endl;
                Stack.pop();
            }
        } 
        else if (op == "TOP") 
        {
            if (Stack.empty()) 
            {
                cout << "EMPTY" << endl;
            } 
            else 
            {
                cout << Stack.top() << endl;
            }
        } 
        else if (op == "SIZE") 
        {
            cout << Stack.size() << endl;
        }
    }
    return 0;
}