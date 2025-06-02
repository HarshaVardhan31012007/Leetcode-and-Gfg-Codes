class Solution {
public:
    int compress(vector<char>& chars) {
       int i=0;char ch=0;int count=0;
       for(int j=0;j<chars.size();j++){
         if(ch==0)
         ch=chars[j];
         if(ch==chars[j])
         count++;
         else{
            chars[i++]=ch;
            if(count>1){
              string temp="";
              while(count>0){
                char p=count%10+'0';
                temp=p+temp;
                count/=10;
              }
              for(int j=0;j<temp.size();j++)
              chars[i++]=temp[j];
            }
            ch=chars[j];
            count=1;
         }
       }
       if(ch!=0){
       chars[i++]=ch;
       if(count>1){
        string temp="";
        while(count>0){
        char p=count%10+'0';
        temp=p+temp;
        count/=10;
        }
         for(int j=0;j<temp.size();j++)
        chars[i++]=temp[j];   
       }                    
       }
       return i;
    }
};