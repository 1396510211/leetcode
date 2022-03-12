struct LinkedNode
{
    int value;
    LinkedNode* next;
    LinkedNode() : value(0), next(nullptr) {}
    LinkedNode(int _value) : value(_value), next(nullptr) {}
};
class MyCircularQueue {
public:
    MyCircularQueue(int k)
    {
        campacity = k;
        front = new LinkedNode();
        real = front;
    }

    bool enQueue(int value)
    {
        if (size < campacity) {
            LinkedNode* node = new LinkedNode(value);
            real->next = node;
            real = node;
            size++;
            return true;
        }
        return false;
    }

    bool deQueue()
    {
        if (isEmpty()) {
            return false;
        }
        LinkedNode* node = front->next;
        front->next = front->next->next;
        if (real == node) {
            real = front;
        }
        delete node;
        size--;
        return true;
    }

    int Front()
    {
        return front->next->value;
    }

    int Rear()
    {
        if (isEmpty()) {
            return -1;
        }
        return real->value;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == campacity;
    }
private:
    LinkedNode* front{ nullptr };
    LinkedNode* real{ nullptr };
    int size{ 0 };
    int campacity{ 0 };
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */