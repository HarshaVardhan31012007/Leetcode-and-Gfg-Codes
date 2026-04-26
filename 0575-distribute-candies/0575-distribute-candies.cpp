class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int>visited;
        int d=0;
        for(int i=0;i<candyType.size();i++){
            if(!visited.count(candyType[i])){
                visited.insert(candyType[i]);
                d++;
            }
        }
        return min(d,(int)candyType.size()/2);
    }
};