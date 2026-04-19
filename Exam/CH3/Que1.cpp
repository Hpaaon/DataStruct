// Que1. 判断对称字符串
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
        m_data[++m_top] = val;
    }

    void pop() { m_top--; }

    T& top() { return m_data[m_top]; }
 
};


void Solution()
{
    string str;
    cin >> str;
    SeqStack<char> S(str.length());
    int i;
    for(i = 0; i < str.length(); i++)
    {
        if(str[i] != '@')
        {
            S.push(str[i]);
        }
        else
        {
            i++;
            break;
        }
    }
    if(str.length() - i != i - 1)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        while(i < str.length())
        {
            if(S.top() != str[i])
            {
                cout << 0 << endl;
                return;
            }
            S.pop();
            i++;
        }
        cout << 1 << endl;
    }
}
int main()
{
    Solution();
    return 0;
}