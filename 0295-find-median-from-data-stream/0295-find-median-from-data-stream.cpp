class MedianFinder {
public:
    priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<>>pq1;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq.empty())
        pq.push(num);
        else{
            if(num>pq.top())
            pq1.push(num);
            else
            pq.push(num);
        }
        if(pq.size()>pq1.size()+1){
            pq1.push(pq.top());
            pq.pop();
        }
        else if(pq1.size()>pq.size()+1){
            pq.push(pq1.top());
            pq1.pop();
        }
    }
    
    double findMedian() {
        if(pq.size()==pq1.size())
        return (pq.top()+pq1.top())/2.0;
        else{
            if(pq.size()>pq1.size())
            return pq.top();
            else
            return pq1.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */