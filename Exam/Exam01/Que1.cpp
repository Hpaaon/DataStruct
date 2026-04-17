// Que1. 完美洗牌问题
#include <iostream>
using namespace std;

template <typename T>
class LinkedQueue
{
    private:
        struct Node
        {
            T data;
            Node* next;
            Node(const T& val) : data(val), next(nullptr) {}
        };

        Node* m_front; 
        Node* m_rear; 
        size_t m_size;
    
    public:
        LinkedQueue() : m_front(nullptr), m_rear(nullptr), m_size(0) {}
        void push(const T& value)
        {
            Node* newNode = new Node(value);
            if (empty())
            {
            m_front = m_rear = newNode;
            }
            else
            {
                m_rear->next = newNode;
                m_rear = newNode;
            }
            m_size++;
        }
        void pop()
        {
            Node* temp = m_front;
            m_front = m_front->next;

            delete temp; 
            m_size--;

            if(m_front == nullptr)
            {
                m_rear = nullptr;
            }
        } 
        T& front()  { return m_front->data; }
        bool empty()  { return m_size == 0; } 
};




void Solution(int n)
{
    LinkedQueue<int> q1, q2, q3;
    for(int i = 1; i <= (n + 1) / 2; i++)
    {
        q1.push(i);
    }
    for(int i = ((n + 1) / 2 ) + 1; i <= n; i++)
    {
        q2.push(i);
    }
    for(int i = 0; i < n / 2; i++)
    {
        q3.push(q1.front());
        q1.pop();
        q3.push(q2.front());
        q2.pop();
    }
    if(!q1.empty())
    {
        q3.push(q1.front());
        q1.pop();
    }
    while(!q3.empty())
    {
        cout << q3.front() << " ";
        q3.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    Solution(n);
    return 0;
}