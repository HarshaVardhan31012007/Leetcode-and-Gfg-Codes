class Solution {
public:
    string predictPartyVictory(string senate) {
        int position=0;
        queue<int>q1;
        queue<int>q2;
        for(;position<senate.length();position++){
            if(senate[position]=='R'){
                q1.push(position);
            }
             if(senate[position]=='D'){
                q2.push(position);
            }
        }
        while(!q1.empty()&&!q2.empty()){
            int a=q1.front();
            q1.pop();
            int b=q2.front();
            q2.pop();
            //equality case not there practically
            if(a<b){
                q1.push(position++);
            }
            else{
                q2.push(position++);
            }
        }
        if(!q1.empty())
        return "Radiant";

        return "Dire";
    }
};