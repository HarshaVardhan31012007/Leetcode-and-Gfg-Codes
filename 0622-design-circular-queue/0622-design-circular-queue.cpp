class MyCircularQueue {
public:
    vector<int>arr;
    int front;
    int rear;
    int size;
    MyCircularQueue(int k) {
        arr.resize(k);
        front=-1;
        rear=-1;
        size=k;
    }
    
    bool enQueue(int value) {
        if((rear+1)%size==front) return false;
        if(front==-1){
            front=0;
            rear=0;
            arr[front]=value;
        }
        else{
            rear=(rear+1)%size;
            arr[rear]=value;
        }
        return true;
    }
    
    bool deQueue() {
        if(front==-1) return false;
        if(front==rear){
            arr[front]=0;
            front=-1;
            rear=-1;
            return true;
        }
        arr[front]=0;
        front=(front+1)%size;
        return true;
    }
    
    int Front() {
        if(front==-1) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(rear==-1) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return (rear+1)%size==front;
    }
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