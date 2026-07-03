// class MyCalendar {
// public:
//     vector<vector<int>>intervals;
//     MyCalendar() {
        
//     }
    
//     bool book(int startTime, int endTime) {
//         if(intervals.empty()){
//             intervals.push_back({startTime,endTime});
//             return true;
//         }
//         int n=intervals.size();
//         vector<vector<int>>temp;
//         if(endTime<=intervals[0][0]){
//             temp.push_back({startTime,endTime});
//             temp.insert(temp.end(),intervals.begin(),intervals.end());
//             intervals=temp;
//             return true;
//         }
//         if(intervals.back()[1]<=startTime){
//             intervals.push_back({startTime,endTime});
//             return true;
//         }
//         bool inserted=false;
//         for(int i=0;i<n;i++){
//             if(intervals[i][1]<=startTime){
//                 temp.push_back(intervals[i]);
//             }
//             else if(intervals[i][0]>=endTime){
//                 if(!inserted)
//                 temp.push_back({startTime,endTime});
//                 temp.push_back(intervals[i]);
//             }
//             else
//             return false;
//         }
//         intervals=temp;
//         return true;
//     }
// };

// /**
//  * Your MyCalendar object will be instantiated and called as such:
//  * MyCalendar* obj = new MyCalendar();
//  * bool param_1 = obj->book(startTime,endTime);
//  */




// class MyCalendar {
// public:
//     set<pair<int,int>>intervals;
//     MyCalendar() {
        
//     }
    
//     bool book(int startTime, int endTime) {
//         if(intervals.empty()){
//             intervals.insert({startTime,endTime});
//             return true;
//         }
//         auto it=intervals.upper_bound({startTime,endTime});
//         if(it==intervals.begin()){
//             if(endTime<=it->first){
//                 intervals.insert({startTime,endTime});
//                 return true;
//             }
//             return false;
//         }
//         if(it==intervals.end()){
//             it--;
//             if(startTime>=it->second){
//                 intervals.insert({startTime,endTime});
//                 return true;
//             }
//             return false;
//         }
//         auto it1=it;
//         it--;
//         if(it->second<=startTime&&it1->first>=endTime){
//             intervals.insert({startTime,endTime});
//             return true;
//         }
//         return false;
//     }
// };

// /**
//  * Your MyCalendar object will be instantiated and called as such:
//  * MyCalendar* obj = new MyCalendar();
//  * bool param_1 = obj->book(startTime,endTime);
//  */



class MyCalendar {
public:
    set<pair<int,int>>intervals;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto it=intervals.upper_bound({startTime,endTime});
        if(it!=intervals.end()){
            if(it->first<endTime) return false;
        }
        if(it!=intervals.begin()){
            it--;
            if(it->second>startTime) return false;
        }
        intervals.insert({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */