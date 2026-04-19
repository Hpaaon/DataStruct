//Que3. 第三章 链栈删除第K个结点
    #include <iostream>
    using namespace std;


    struct Node
    {
        int val;
        Node* next;
        Node(): next(nullptr) {}
        Node(int v): next(nullptr), val(v) {} 
    };

    class List
    {
        private:
            Node dummy;
            Node* tail;
            int size;
        public:
            List()
            {
                size = 0;
                tail = &dummy;
            }
            void addAtTail(int v)
            {
                tail->next = new Node(v);
                tail = tail->next;
                size++;
            }
            int deleteK(int k)
            {
                if(k <= 0 || k > size)
                {
                    return -1;
                }
                else
                {
                    Node* cur = &dummy;
                    while(--k)
                    {
                        cur = cur->next;
                    }
                    Node* tmp = cur->next;
                    int v = tmp->val;
                    cur->next = tmp->next;
                    delete tmp;
                    tmp = nullptr;
                    size--;
                    return v;
                }
                
            }
            void print()
            {
                Node* cur = &dummy;
                while(cur->next)
                {
                    cur = cur->next;
                    cout << cur->val << " ";
                }
                cout << endl;
            }
    };

    int main()
    {
        int n;
        int v;
        List list;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> v;
            list.addAtTail(v);
        }
        int k;
        cin >> k;
        int a = list.deleteK(k); 
        if(a == -1)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << a << endl;
        }
        list.print();
        return 0;
    }