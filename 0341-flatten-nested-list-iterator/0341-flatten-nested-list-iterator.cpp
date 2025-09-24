/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    // vector<NestedInteger>v;
    // NestedIterator* it=NULL;
    // int i=0;
    // NestedIterator(vector<NestedInteger> &nestedList) {
    //     v=nestedList;
    // }
    
    // int next() {
    //    if(v[i].isInteger()){
    //       return v[i++].getInteger();
    //    }
    //    else{
    //         int ans=it->next();
    //         return ans;
    //    }
    // }
    // bool checkempty(vector<NestedInteger>&temp){
    //     for(auto &x:temp){
    //     if(x.isInteger()) return false;
    //     if(!checkempty(x.getList())) return false;
    //     }
    //     return true;
    // }
    // bool hasNext() {
    //     while(i<v.size()){
    //        if(v[i].isInteger()) return true;

    //        if(checkempty(v[i].getList())){
    //         i++;
    //         continue;
    //        }

    //        if(it==NULL)  
    //        it=new NestedIterator(v[i].getList());

    //        if(it->hasNext())
    //         return true;

    //         delete it;
    //         it=NULL;
    //         i++;
    //     }
    //     return false;
    // }




    // stack<NestedInteger>st;
    // NestedIterator(vector<NestedInteger> &nestedList) {
    //     for(int i=nestedList.size()-1;i>=0;i--){
    //         st.push(nestedList[i]);
    //     }
    // }
    
    // int next() {
    //      int ans=st.top().getInteger();
    //      st.pop();
    //      return ans;
    // }

    // bool hasNext() {
    //     while(!st.empty()){
    //         NestedInteger obj=st.top();
    //         if(obj.isInteger())
    //         return true;
    //              st.pop();
    //             vector<NestedInteger>v=obj.getList();
    //             for(int i=v.size()-1;i>=0;i--){
    //                 st.push(v[i]);
    //             }
    //     }
    //     return false;
    // }



    // stack<NestedInteger*>st;
    // NestedIterator(vector<NestedInteger> &nestedList) {
    //     for(int i=nestedList.size()-1;i>=0;i--){
    //         st.push(&nestedList[i]);
    //     }
    // }
    
    // int next() {
    //      int ans=st.top()->getInteger();
    //      st.pop();
    //      return ans;
    // }

    // bool hasNext() {
    //     while(!st.empty()){
    //         NestedInteger* obj=st.top();
    //         if(obj->isInteger())
    //         return true;
    //              st.pop();
    //             vector<NestedInteger>&v=obj->getList();// ampersand //becuase
    //             // we are maintain actual list otherwise copy bante hai fir before va nd after v they dont use know because that ias coipied
    //             for(int i=v.size()-1;i>=0;i--){
    //                 st.push(&v[i]);
    //             }
    //     }
    //     return false;
    // }




    stack<NestedInteger*>st;
    queue<int>q;
    void flatten(vector<NestedInteger> &nestedList){
           for(int i=0;i<nestedList.size();i++){
              if(nestedList[i].isInteger())
              q.push(nestedList[i].getInteger());
              else{
                flatten(nestedList[i].getList());
              }
           }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    
    int next() {
         int ans=q.front();
         q.pop();
         return ans;
    }

    bool hasNext() {
       return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */