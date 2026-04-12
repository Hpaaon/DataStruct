template <typename T>
class PriorityQueue
{
private:
    T* m_heap; // 动态存储数组
    int m_capacity; // 总容量
    int m_size; // 当前元素个数

    // 动态扩容：当空间不足时，申请两倍空间
    void expand()
    {
        int newCap = (m_capacity == 0) ? 1 : m_capacity * 2;
        T* newData = new T[newCap];
        for (int = 0; i < m_size; i++)
        {
            newData[i] = m_heap[i];
        }
        delete[] m_heap;
        m_heap = newData;
        m_capacity = newCap;
    }

    // 上浮逻辑：用于插入元素
    void shiftUp(int index)
    {
        T temp = m_heap[index];
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (temp > m_heap[parent])
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

    // 下沉逻辑：用于弹出堆顶
    void shiftDown(int index)
    {
        T temp = m_heap[index];
        int half = m_size / 2;
        while (index < half)
        {
            int left = 2 * index + 1;
            int right = left + 1;
            int child = left;

            // 如果右孩子存在且比左孩子大，选右孩子
            if (right < m_size && m_heap[right] > m_heap[left])
            {
                child = right;
            }

            // 如果暂存值比最大的孩子大，则停止下沉
            if (temp >= m_heap[child]) break;

            m_heap[index] = m_heap[child];
            index = child;
        }
        m_heap[index] = temp;
    }

public:
    PriorityQueue(int initCap = 10) : m_capacity(initCap), m_size(0)
    {
        m_heap = new T[m_capacity];
    }

    ~PriorityQueue()
    {
        delete[] m_heap;
    }

    bool empty() const  { return m_size == 0; }
    int size() const { return m_size; }

    void push(const T& val)
    {
        if (m_size == m_capacity) expand();
        m_heap[m_size] = val;
        shiftUp(m_size);
        m_size++;
    }

    void pop()
    {
        m_size--;
        if (m_size > 0)
        {
            m_heap[0] = m_[m_size];
            shiftDown(0);
        }
    }

    T top() const
    {
        return m_heap[0];
    }
};