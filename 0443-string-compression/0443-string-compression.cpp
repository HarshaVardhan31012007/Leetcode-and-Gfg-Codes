class Solution {
public:
    int compress(vector<char>& chars) {
    //    int i=0;char ch=0;int count=0;//here ch means prev
    //    for(int j=0;j<chars.size();j++){
    //      if(ch==0)
    //      ch=chars[j];
    //      if(ch==chars[j])
    //      count++;
    //      else{
    //         chars[i++]=ch;
    //         if(count>1){
    //         //   string temp="";
    //         //   while(count>0){
    //         //     char p=count%10+'0';
    //         //     temp=p+temp;
    //         //     count/=10;
    //         //   }
    //         //   for(int j=0;j<temp.size();j++)
    //         //   chars[i++]=temp[j];

    //         // string k=to_string(count);
    //         // for(auto &each:k)
    //         // chars[i++]=each;
    //         // }
    //         // ch=chars[j];
    //         // count=1;
              
    //           int start=i;
    //           while(count>0){
    //             chars[i++]=count%10+'0';
    //             count/=10;
    //           }
    //           reverse(chars.begin()+start,chars.begin()+i);
    //      }
    //       ch=chars[j];
    //       count=1;
    //      }
    //    }
    //    if(ch!=0){
    //    chars[i++]=ch;
    //    if(count>1){
    //     string temp="";
    //     while(count>0){
    //     char p=count%10+'0';
    //     temp=p+temp;
    //     count/=10;
    //     }
    //      for(int j=0;j<temp.size();j++)
    //     chars[i++]=temp[j];   
    //    }                    
    //    }
    //    return i;
    // }



    //  int count=1;int idx=0;int prev=chars[0];
    //  for(int i=1;i<chars.size();i++){
    //     if(prev==chars[i])
    //     count++;
    //     else{
    //         chars[idx++]=prev;
    //         if(count>1){
    //         if(count>=10){
    //          int start=idx;
    //         while(count>0){
    //             chars[idx++]=count%10+'0';
    //             count/=10;
    //         }
    //         reverse(chars.begin()+start,chars.begin()+idx);
    //         }
    //         else
    //         chars[idx++]=count+'0';
    //         }
    //         prev=chars[i];
    //         count=1;
    //     }
    //  }
    //  chars[idx++]=prev;
    //   if(count>1){
    //         if(count>=10){
    //          int start=idx;
    //         while(count>0){
    //             chars[idx++]=count%10+'0';
    //             count/=10;
    //         }
    //         reverse(chars.begin()+start,chars.begin()+idx);
    //         }
    //         else
    //         chars[idx++]=count+'0';
    //         }
    //    return idx;



    int count=1;int idx=0;int prev=chars[0];
     for(int i=1;i<chars.size();i++){
        if(chars[i-1]==chars[i])
        count++;
        else{
            chars[idx++]=prev;
            if(count>1){
            if(count>=10){
             int start=idx;
            while(count>0){
                chars[idx++]=count%10+'0';
                count/=10;
            }
            reverse(chars.begin()+start,chars.begin()+idx);
            }
            else
            chars[idx++]=count+'0';
            }
            prev=chars[i];
            count=1;
        }
     }
     chars[idx++]=prev;
      if(count>1){
            if(count>=10){
             int start=idx;
            while(count>0){
                chars[idx++]=count%10+'0';
                count/=10;
            }
            reverse(chars.begin()+start,chars.begin()+idx);
            }
            else
            chars[idx++]=count+'0';
            }
       return idx;
    }
};