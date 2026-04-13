template <typename T>
class LinkedStack
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& val, Node* p = nullptr) : data(val), next(p) {}
    };

    Node* m_top;
    int m_size;

public:
    LinkedStack() : m_top(nullptr), m_size(0) {}

    ~LinkedStack(){ clear(); }

    void push(const T& val)
    {
        Node* newNode = new Node(val, m_top);
        m_top = newNode;
        m_size++;
    }

    void pop()
    {
        Node* temp = m_top;
        m_top = m_top->next;
        deletr temp;
        m_size--;
    }

    T& top() { return m_top->data; }

    bool empty() { return m_top == nullptr; }

    int size() const{ return m_size; }

    void clear()
    {
        while(!empty)
        {
            pop();
        }
    }
};