template <typename T>
class SeqStack
{
private:
    T* m_data;
    int m_top;
    int m_capacity;

    void expand()
    {
        int newCap = (m_capacity == 0) ? 1 : m_capacity * 2;
        T* newData = new T[newCap];
        for (int i = 0; i < m_top; i++)
        {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
        m_capacity = newCap;
    }

public:
    SeqStack(int initCap = 10) : m_capacity(initCap), m_top(-1)
    {
        m_data = new T[m_capacity];
    }

    ~SeqStack()
    {
        if (m_data)
        {
            delete[] m_data;
            m_data = nullptr;
        }
    }

    void push(const T& val)
    {
        if (m_top + 1 == m_capacity)
        {
            expand();
        }
        m_data[++m_top] = val;
    }

    void pop() { m_top--; }

    T& top() { return m_data[m_top]; }

    bool empty() const { return m_top == -1; }

    int size() const { return m_top + 1; }

    void clear() { m_top = -1; }
    
};