template <typename T, size_t CAPACITY>
class CircularQueue
{
private:
    T* m_data; // 连续内存空间
    size_t m_front; // 队头索引（指向第一个元素）
    size_t m_rear; // 队尾索引（指向最后一个元素的下一个位置）
    size_t m_count; // 当前有效元素个数

public:
    CircularQueue();
    ~CircularQueue();

    bool push(const T& value);
    void pop();
    T& front() const;
    bool empty() const;
    bool full() const;
    size_t size() const;
};

template <typename T, size_t CAPACITY>
CircularQueue<T, CAPACITY>::CircularQueue()
    : m_front(0), m_rear(0), m_count(0)
    {
        // 一次性申请连续内存，缓存友好
        m_data = new T[CAPACITY];
    }

template <typename T, size_t CAPACITY>
CircularQueue<T, CAPACITY>::~CircularQueue() 
{
    delete[] m_data; // 释放整块连续内存
}

template <typename T, size_t CAPACITY>
bool CircularQueue<T, CAPACITY>::push(const T& value)
{
    if(full()) return false;

    m_data[m_rear] = value;
    // 关键：取模运算实现“环状”跳转
    m_rear = (m_rear + 1) % CAPACITY;
    m_count++;
    return true;
}

template <typename T, size_t CAPACITY>
void CircularQueue<T, CAPACITY>::pop()
{
    if (empty()) throw runtime_error("Queue empty");
    // 逻辑删除：移动头索引即可
    m_front = (m_front + 1) % CAPACITY;
    m_count--;
}

template <typename T, size_t CAPACITY>
T& CircularQueue<T, CAPACITY>::front() const {
    if (empty()) throw runtime_error("Queue empty");
    return m_data[m_front];
}

template <typename T, size_t CAPACITY>
bool CircularQueue<T, CAPACITY>::empty() const {
    return m_count == 0;
}

template <typename T, size_t CAPACITY>
bool CircularQueue<T, CAPACITY>::full() const {
    return m_count == CAPACITY;
}

template <typename T, size_t CAPACITY>
size_t CircularQueue<T, CAPACITY>::size() const {
    return m_count;
}