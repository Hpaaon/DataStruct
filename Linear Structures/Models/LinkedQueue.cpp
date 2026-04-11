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

        Node* m_front; // 指向队头节点（删除端）
        Node* m_rear; // 指向队尾结点（插入端）
        size_t m_size;
    
    public:
        LinkedQueue();
        ~LinkedQueue();

        // 禁止拷贝构造和赋值，防止浅拷贝导致双重释放内存
        LinkedQueue(const LinkedQueue&) = delete;
        LinkedQueue& operator=(const LinkedQueue&) = delete;

        void push(const T& value); // 入队
        void pop(); // 出队
        T& front() const; // 获取队头
        bool empty() const; // 判空
        size_t size() const; // 获取长度
        void clear(); // 清空队列
};

template <typename T>
LinkedQueue<T>::LinkedQueue()
    : m_front(nullptr), m_rear(nullptr), m_size(0) {}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
    clear();
}

template <typename T>
void LinkedQueue<T>::push(const T& value)
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

template <typename T>
void LinkedQueue<T>::pop()
{
    if (empty()) 
    {
        throw std::underflow_error("Queue is empty, cannot pop.");
    }

    Node* temp = m_front;
    m_front = m_front->next;

    delete temp; // 显式释放堆内存
    m_size--;

    //如果队列空了，必须重置尾指针，否则它将变成野指针
    if(m_front == nullptr)
    {
        m_rear = nullptr;
    }
}

template <typename T>
T& LinkedQueue<T>::front() const
{
    if (empty())
    {
        throw std::runtime_error("Queue is empty.");
    }
    return m_front->data;
}

template <typename T>
bool LinkedQueue<T>::empty() const 
{
    return m_size == 0;
}

template <typename T>
size_t LinkedQueue<T>::size() const 
{
    return m_size;
}

template <typename T>
void LinkedQueue<T>::clear() 
{
    while (!empty()) 
    {
        pop();
    }
}