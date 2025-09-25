class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>radiantQ;
        queue<int>direQ;
        int position;
        for(position=0;position<senate.size();position++){
             if(senate[position]=='R') radiantQ.push(position);
             else direQ.push(position);
        }
        while(!radiantQ.empty()&&!direQ.empty()){
              int front1=radiantQ.front();
              radiantQ.pop();
              int front2=direQ.front();
              direQ.pop();
              if(front1<front2){
                    radiantQ.push(position++);
              }
              else{
                   direQ.push(position++);
              }
        }
        if(!radiantQ.empty()) return "Radiant";
        return "Dire";
    }
};