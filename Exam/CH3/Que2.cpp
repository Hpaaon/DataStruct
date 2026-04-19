// Que2. 第三章 列车编组
#include <iostream>
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

    bool empty() const { return m_top == -1; }
 
};


void Solution()
{
    int n;
    cin >> n;
    SeqStack<int> S(n);
    int ans[n];
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if(i != 0)  cout << " ";
        cout << "in" ;
        S.push(val);
        if(val % 2 != 0)
        {
            cout << " " << "out";
            ans[cnt] = S.top();
            cnt++;
            S.pop();
        }
    }
    while(!S.empty())
    {
        cout << " " << "out";
            ans[cnt] = S.top();
            cnt++;
            S.pop();
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main()
{
    Solution();
    return 0;
}