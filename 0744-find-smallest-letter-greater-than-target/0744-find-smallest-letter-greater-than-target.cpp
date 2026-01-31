class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // sort(letters.begin(),letters.end());
        // auto it=upper_bound(letters.begin(),letters.end(),target);
        // if(it==letters.end()) return letters[0];
        // return *it;


        int temp=123;
        for(int i=0;i<letters.size();i++){
            if(letters[i]>target&&letters[i]<temp){
                 temp=letters[i];
            }
        }
        return temp==123?letters[0]:temp;
    }
};