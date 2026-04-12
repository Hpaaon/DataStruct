// Que3. faebdc玩扑克
#include <iostream>
using namespace std;

class Deque
{
private:
    int* m_data;
    int m_front;
    int m_rear;
    int m_capacity;
    int m_size;

public:
    Deque(int cap) : m_front(0), m_rear(0), m_size(0), m_capacity(cap)
    {
        m_data = new int[m_capacity];
    }

    ~Deque()
    {
        delete[] m_data;
    }

    void push_front(int val)
    {
        m_front = (m_front - 1 + m_capacity) % m_capacity;
        m_data[m_front] = val;
        m_size++; 
    }

    void push_back(int val)  
    {
        m_data[m_rear] = val;
        m_rear = (m_rear + 1) % m_capacity;
        m_size++;
    }

    void pop_front()
    {
        m_front = (m_front + 1) % m_capacity;
        m_size--;
    }

    void pop_back()
    {
        m_rear = (m_rear - 1 + m_capacity) % m_capacity;
        m_size--;
    }

    int get_front() { return m_data[m_front]; }

    int get_back() { return m_data[(m_rear - 1 + m_capacity) % m_capacity]; }

    void print()
    {
        int curr = m_front;
        for(int i=0; i<m_size; i++)
        {
            cout << m_data[curr] << " ";
            curr = (curr + 1) % m_capacity;
        }
        cout << endl;
    }
};

void PlayPoke(int n)
{
    Deque pokes(n);
    pokes.push_front(n);
    for(int i= n - 1; i > 0; i--)
    {
        pokes.push_front(i);
        int tmp = pokes.get_back();
        pokes.push_front(tmp);
        pokes.pop_back();
    };
    pokes.print();
}

int main()
{
    int n;
    cin >> n ;
    PlayPoke(n);
    return 0;
}