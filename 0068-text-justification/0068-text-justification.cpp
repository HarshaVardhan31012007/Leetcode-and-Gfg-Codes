class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        vector<string>ans;
        int start=-1;
        int len=0;
        for(int i=0;i<n;i++){
            int c=(start==-1?0:1);
            if(len+c+words[i].length()<=maxWidth){
                if(start==-1) start=i;
                len+=c;
                len+=words[i].length();
            }
            else{
                string temp="";
                string empty="";
                int nwords=(i-start);
                if(nwords==1){
                    temp=words[start];
                    while(temp.length()<maxWidth) temp+=" ";
                    ans.push_back(temp);
                    len=words[i].length();
                    start=i;
                    continue;
                }
                int length=(len-(nwords-1));
                int every=(maxWidth-length)/(nwords-1);
                int rem=(maxWidth-length)%(nwords-1);
                for(int i=0;i<every;i++)
                empty+=" ";
                for(int j=start;j<i;j++){
                    temp+=words[j];
                    if(j<i-1){
                        temp+=empty;
                        if(rem>0){
                            temp+=" ";
                            rem--;
                        }
                    }
                }
                ans.push_back(temp);
                len=words[i].length();
                start=i;
            }
        }
        string temp="";
        for(int j=start;j<n;j++){
            temp+=words[j];
            if(j<n-1)
            temp+=" ";
        }
        while(temp.length()<maxWidth) temp+=" ";
        ans.push_back(temp);
        return ans;
    }
};