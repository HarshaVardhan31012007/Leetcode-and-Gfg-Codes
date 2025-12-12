class Solution {
public:
    // vector<int> countMentions(int n, vector<vector<string>>& events) {
    //     vector<int>mentions(n,0);
    //     sort(events.begin(),events.end(),[&](vector<string>&a,vector<string>&b){
    //             if(a[1]!=b[1])
    //             return stoi(a[1])<stoi(b[1]);
    //             if(a[0]=="MESSAGE"&&b[0]=="OFFLINE")
    //             return false;
    //             return true;
    //     });
    //     vector<int>online(n,0);
    //     for(auto &event:events){
    //         int time=stoi(event[1]);
    //         if(event[0]=="MESSAGE"){
    //              if(event[2]=="ALL"){
    //                 for(int i=0;i<n;i++){
    //                     mentions[i]++;
    //                 }
    //              }
    //              else if(event[2]=="HERE"){
    //                  for(int i=0;i<n;i++){
    //                     if(time>=online[i])
    //                     mentions[i]++;
    //                 }
    //              }
    //              else{
    //                  string s=event[2];
    //                  int j=2;
    //                  while(j<s.length()){
    //                     int num=0;
    //                     while(j<s.length()&&isdigit(s[j])){
    //                         num=num*10+(s[j]-'0');
    //                         j++;
    //                     }
    //                     mentions[num]++;
    //                     j=j+3;
    //                  }
    //              }
    //         }
    //         else{
    //             online[stoi(event[2])]=time+60;
    //         }
    //     }
    //     return mentions;
    // }



    void handleMevent(vector<int>&mentions,vector<string>&event,vector<int>&online,int n){
        stringstream ss(event[2]);
        string word;
        vector<string>v;
        while(ss>>word){
            v.push_back(word);
        }
        int time=stoi(event[1]);
        for(auto &each:v){
            if(each=="ALL"){
                for(int i=0;i<n;i++){
                    mentions[i]++;
                }
            }
            else if(each=="HERE"){
                for(int i=0;i<n;i++){
                    if(online[i]==0||online[i]+60<=time)
                    mentions[i]++;
                }
            }
            else{
            mentions[stoi(each.substr(2))]++;
            }
        }
    }
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int>mentions(n,0);
        sort(events.begin(),events.end(),[&](vector<string>&a,vector<string>&b){
               int f=stoi(a[1]);
               int s=stoi(b[1]);
               if(f==s){
                  return a[0]>b[0];//as offine>message as o>m as we need true in this case
               }
               return f<s;
        });
        vector<int>online(n,0);
        for(auto &event:events){
            if(event[0]=="MESSAGE"){
                handleMevent(mentions,event,online,n);
            }
            else{
                online[stoi(event[2])]=stoi(event[1]);
            }
        }
        return mentions;
    }
};