class MedianFinder {
public:
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minh.size()==maxh.size()){
            if(num>findMedian()){
              minh.push(num);
            }
            else{
                maxh.push(num);
            }
        }
        else if(minh.size()+1==maxh.size()){
            if(num<findMedian()){
                int x=maxh.top();
                maxh.pop();
                minh.push(x);
                maxh.push(num);
            }
            else{
                minh.push(num);
            }
        }
        else if(minh.size()==maxh.size()+1){
            if(num>findMedian()){
                int x=minh.top();
                minh.pop();
                maxh.push(x);
                minh.push(num);
            }
            else{
                maxh.push(num);
            }
        }
    }
    
    double findMedian() {
        if(minh.size()==0&&maxh.size()==0)
        return 0;
        else if(minh.size()==maxh.size()){
            return (minh.top()+maxh.top())/2.0;
        }
        else if(minh.size()+1==maxh.size()){
            return maxh.top();
        }
        else if(minh.size()==maxh.size()+1){
            return minh.top();
        }
        else
        return -1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */