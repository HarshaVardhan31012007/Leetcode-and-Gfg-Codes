// class ExamRoom {
// public:
//     vector<int>seats;
//     ExamRoom(int n) {
//         seats.resize(n,0);
//     }
    
//     int seat() {
//         int prev=-1;
//         int pos=-1;
//         int maxdiff=INT_MIN;
//         for(int i=0;i<seats.size();i++){
//             if(seats[i]==1){
//                 if(prev==-1){
//                     if(i>maxdiff){
//                         maxdiff=i;
//                         pos=0;
//                     }
//                 }
//                 else{
//                     if((i-prev)/2>maxdiff){
//                         maxdiff=(i-prev)/2;
//                         pos=prev+(i-prev)/2;
//                     }
//                 }
//                 prev=i;
//             }
//         }
//         if(pos==-1){
//             seats[0]=1;
//             return 0;
//         }
//         if(((int)seats.size()-1-prev)>maxdiff){
//             seats[(int)seats.size()-1]=1;
//             return (int)seats.size()-1;
//         }
//         seats[pos]=1;
//         return pos;
//     }
    
//     void leave(int p) {
//         seats[p]=0;
//     }
// };

// /**
//  * Your ExamRoom object will be instantiated and called as such:
//  * ExamRoom* obj = new ExamRoom(n);
//  * int param_1 = obj->seat();
//  * obj->leave(p);
//  */


class ExamRoom {
public:
    set<int>seats;
    int n;
    ExamRoom(int n1) {
        n=n1;
    }
    
    int seat() {
        int prev=-1;
        int pos=-1;
        int maxdiff=INT_MIN;
        for(auto &each:seats){
            int i=each;
            if(prev==-1){
                if(i>maxdiff){
                    maxdiff=i;
                    pos=0;
                }
            }
            else{
                if((i-prev)/2>maxdiff){
                    maxdiff=(i-prev)/2;
                    pos=prev+(i-prev)/2;
                }
            }
            prev=i;
        }
        if(pos==-1){
            seats.insert(0);
            return 0;
        }
        if((n-1-prev)>maxdiff){
            seats.insert(n-1);
            return n-1;
        }
        seats.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */