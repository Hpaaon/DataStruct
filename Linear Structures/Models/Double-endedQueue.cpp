template <typename T>
class Deque
{
private:
    T* m_data; //  动态数组存储数据
    int m_capacity; // 数组容量
    int m_front; // 队头指针
    int m_rear; // 队尾指针（指向下一个插入位置）
    int m_size; // 当前元素个数

public:
    //构造函数
    Deque(int cap) : m_capacity(cap), m_front(o), m_rear(0), m_size(0)
    {
        m_data = new T[m_capacity];
    }

    //析构函数
    ~Deque
    {
        delete[] m_data;
    }

    bool isFull() const { return m_size == m_capacity; }
    bool isEmpty() const { return m_size == 0; }
    int size() const { return m_size; }
    
    // 1.队头插入
    void push_front(const T& val)
    {
        m_front = (m_front - 1 + m_capacity) % m_capacity;
        m_data[m_front] = val;
        m_size++;
    }

    // 2.队尾插入
    void push_back(const T& val);
    {
        m_data[m_rear] = val;
        m_rear = (m_rear + 1) % m_capacity;
        m_size++;
    }

    // 3.队头删除
    void pop_front()
    {
        m_front = (m_front + 1) % m_capacity;
        m_size--;
    }

    // 4.队尾删除
    void pop_back()
    {
        m_rear = (m_rear - 1 + m_capacity) % m_capacity;
        m_size--;
    }

    // 获取元素
    T& front() { return m_data[m_front]; }

    T& back() { return m_data[(m_rear - 1 + m_capacity) % m_capacity]; }
};