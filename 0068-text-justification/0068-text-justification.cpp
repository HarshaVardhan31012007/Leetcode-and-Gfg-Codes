class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        vector<string>currentLine;
        int charTotalLine=0;
        for(int i=0;i<words.size();i++){
            string curWord=words[i];
            int spacesbetweenWords=currentLine.size();
            if(charTotalLine+spacesbetweenWords+curWord.size()>maxWidth){
               int extraSpaces=maxWidth-charTotalLine;
               int spacesbetweenw=extraSpaces / max(1,(int)(currentLine.size()-1));
               int remainder=extraSpaces % max(1,(int)(currentLine.size()-1));
               for(int j=0;j<currentLine.size()-1;j++){
                 for(int k=0;k<spacesbetweenw;k++){
                    currentLine[j]+=" ";
                 }
                 if(remainder>0){
                    currentLine[j]+=" ";
                    remainder--;
                 }
               }
               if(currentLine.size()==1){
                while(extraSpaces--)
                  currentLine[0]+=" ";
               }
               //lets make final string
               string finalLine="";
               for(string wordswithspaces:currentLine){
                finalLine+=wordswithspaces;
               }
               ans.push_back(finalLine);
               currentLine.clear();
               charTotalLine=0;
            }
            currentLine.push_back(curWord);
            charTotalLine+=curWord.size();
        }
        //for last line
        string finalLine="";
        for(string word:currentLine){
            finalLine+=word+" ";
        }
        finalLine.pop_back();
        int rightSpaces=maxWidth-finalLine.size();
        while(rightSpaces--){
           finalLine+=" ";
        }
        ans.push_back(finalLine);
         return ans;    
    }
};