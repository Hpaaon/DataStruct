// Que4. 优先队列
#include <iostream>
using namespace std;

class Pque
{
private:
    int* m_heap;
    int m_size;
    int m_capacity;

    void expand()
    {
        int newCap = (m_capacity == 0) ? 1 : m_capacity * 2;
        int* newData = new int[newCap];
        for(int i=0; i<m_size; i++)
        {
            newData[i] = m_heap[i];
        }
        delete[] m_heap;
        m_heap = newData;
        m_capacity = newCap;
    }

    void shiftUp(int index)
    {
        int temp = m_heap[index];
        while(index > 0)
        {
            int parent = (index - 1) / 2;
            if(temp < m_heap[parent])
            {
                m_heap[index] = m_heap[parent];
                index = parent;
            }
            else
            {
                break;
            }
        }
        m_heap[index] = temp;
    }

    void shiftDown(int index)
    {
        int temp = m_heap[index];
        int half = m_size / 2;
        while (index < half)
        {
            int left = 2 * index + 1;
            int right = left + 1;
            int child = left;

            if (right < m_size && m_heap[right] < m_heap[left])
            {
                child = right;
            }

            if(temp <= m_heap[child]) break;

            m_heap[index] = m_heap[child];
            index = child;
        }   
        m_heap[index] = temp;

    }

public:
    Pque(int initCap = 10) : m_capacity(initCap), m_size(0)
    {
        m_heap = new int[m_capacity];
    }

    bool empty() const { return m_size == 0; }
    int size() const { return m_size; }

    void push(int val)
    {
        if (m_size == m_capacity) expand();
        m_heap[m_size] = val;
        shiftUp(m_size);
        m_size++;
    }

    void pop()
    {
        m_size--;
        if(m_size > 0)
        {
            m_heap[0] = m_heap[m_size];
            shiftDown(0);
        }
  
    }

    int top()
    {
        return m_heap[0];
    }
};


int main()
{
    Pque q;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
            int val;
            cin >> val;
            q.push(val);
            break;
        
        case 2:
            cout << q.top() << endl;
            break;

        case 3:
            q.pop();

        default:
            break;
        }
    }
    return 0;
}