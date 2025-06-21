class Solution {
public:
    // vector<string> fullJustify(vector<string>& words, int maxWidth) {
    //     vector<string>temp;
    //     vector<string>ans;
    //     string temp1="";
    //     int size=0;
    //     for(int i=0;i<words.size();i++){
    //          if(size+words[i].length()<maxWidth){
    //             size+=words[i].length()+1;
    //             temp.push_back(words[i]);
    //          }
    //          else if(size+words[i].length()==maxWidth){
    //              for(auto &each:temp)
    //              temp1=temp1+each+" ";
    //              temp1+=words[i];
    //              ans.push_back(temp1);
    //              size=0;
    //              temp1="";
    //              temp.clear();
    //          }
    //          else{
    //             size--;
    //             int extraspaces=maxWidth-size;
    //             int extra=0;
    //             if(temp.size()>1)
    //             extra=extraspaces/(temp.size()-1);
    //             else
    //             extra=extraspaces;
    //             int extraOne=0;
    //             if(temp.size()>1)
    //             extraOne=(extraspaces%(temp.size()-1));
    //             if(temp.size()!=1)
    //             temp1+=temp[0]+" ";
    //             else
    //             temp1+=temp[0];
    //             for(int i=0;i<extra;i++)
    //             temp1+=" ";
    //             if(extraOne>0){
    //             temp1+=" ";
    //             extraOne--;
    //             }
    //             for(int i=1;i<temp.size()-1;i++){
    //                 temp1+=temp[i]+" ";
    //                 for(int j=0;j<extra;j++)
    //                 temp1+=" ";
    //                 if(extraOne>0){
    //                 temp1+=" ";
    //                 extraOne--;
    //                 }
    //             }
    //             if(temp.size()>1)
    //             temp1+=temp[temp.size()-1];
    //             ans.push_back(temp1);
    //             size=words[i].length()+1;
    //             temp.clear();
    //             temp1="";
    //             temp.push_back(words[i]); 
    //          }
    //     }
    //     if(temp.size()==1)
    //     temp1+=temp[0];
    //     else if(!temp.empty()){
    //          for(int i=0;i<temp.size()-1;i++)
    //          temp1+=temp[i]+" ";
    //          if(temp.size()>1)
    //          temp1+=temp[temp.size()-1];
    //     }
    //     if(temp1.length()>0){
    //     for(int i=temp1.length();i<maxWidth;i++)
    //     temp1+=" ";
    //     ans.push_back(temp1);
    //     }
    //     return ans;
    // }


    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        vector<string>currLine;
        int charCount=0;
        for(int i=0;i<words.size();i++){
            if(charCount+currLine.size()+words[i].size()>maxWidth){
                   int extraspaces=maxWidth-charCount;
                   int spaceBetween=extraspaces/max(1,(int)(currLine.size()-1));
                   int remainder=extraspaces%max(1,(int)(currLine.size()-1));
                   for(int j=0;j<currLine.size()-1;j++){
                      for(int k=0;k<spaceBetween;k++)
                      currLine[j]+=" ";
                      if(remainder>0){
                        currLine[j]+=" ";
                        remainder--;
                      }
                   }
                   if(currLine.size()==1){
                    while(extraspaces--)
                    currLine[0]+=" ";
                   }
                   string temp="";
                   for(auto &each:currLine)
                   temp+=each;
                   ans.push_back(temp);
                   currLine.clear();
                   charCount=0;
            }
            currLine.push_back(words[i]);
            charCount+=words[i].length();
        }
        string temp="";
        for(auto &each:currLine)
        temp+=each+" ";
        temp.pop_back();
        int rightspaces=maxWidth-temp.length();
        while(rightspaces--)
        temp+=" ";
        ans.push_back(temp);
        return ans;
    }
};