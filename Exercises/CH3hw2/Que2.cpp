//Que2.条件反转循环队列
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class ManualStack 
{
private:
    T* m_data;
    int m_top;
    size_t m_capacity;
public:
    ManualStack(size_t cap) : m_capacity(cap), m_top(-1) 
    {
        m_data = new T[cap];
    }
    void push(const T& val) { m_data[++m_top] = val; }
    T pop() { return m_data[m_top--]; }
    bool empty() { return m_top == -1; }
};

void reverseQueueWithMarkers(int n, int* q) {
    ManualStack<int> s(n);

    for (int i = 0; i < n; i++) 
    {
        if (q[i] != -1) 
        {
            s.push(q[i]);
        }
    }

    for (int i = 0; i < n; i++) 
    {
        if (q[i] != -1) 
        {
            q[i] = s.pop(); 
        }
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    int* queueData = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> queueData[i];
    }

    reverseQueueWithMarkers(n, queueData);

    for (int i = 0; i < n; i++) 
    {
        cout << queueData[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}