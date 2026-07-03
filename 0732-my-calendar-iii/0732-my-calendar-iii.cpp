class MyCalendarThree {
public:
    map<int,int>mpp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mpp[startTime]++;
        mpp[endTime]--;
        int currentbookings=0;
        int k=0;
        for(auto &each:mpp){
            currentbookings+=each.second;
            k=max(k,currentbookings);
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */