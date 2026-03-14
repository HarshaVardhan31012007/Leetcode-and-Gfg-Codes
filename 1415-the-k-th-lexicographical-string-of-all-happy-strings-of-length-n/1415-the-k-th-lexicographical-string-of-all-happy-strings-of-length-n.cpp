class Solution {
public:
    void generateHappyStrings(int n,vector<string>&allHappyStrings,string &temp,int prev){
        if(n==0){
            allHappyStrings.push_back(temp);
            return;
        }
        if(prev!=0){
            temp.push_back('a');
            generateHappyStrings(n-1,allHappyStrings,temp,0);
            temp.pop_back();
        }
        if(prev!=1){
            temp.push_back('b');
            generateHappyStrings(n-1,allHappyStrings,temp,1);
            temp.pop_back();
        }
        if(prev!=2){
            temp.push_back('c');
            generateHappyStrings(n-1,allHappyStrings,temp,2);
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string>allHappyStrings;
        string temp="";
        generateHappyStrings(n,allHappyStrings,temp,-1);
        sort(allHappyStrings.begin(),allHappyStrings.end());
        if(k<=allHappyStrings.size())
        return allHappyStrings[k-1];
        else
        return "";
    }
};