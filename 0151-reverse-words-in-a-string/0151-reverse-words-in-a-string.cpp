class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        // vector<string>v;
        // int j=0;
        // int k=0;
        // for(int i=0;i<n;i++){
          
        //   if(s[i]!=' '){
        //     j++;
        //   }

        //   if(s[i]==' '){
        //     if(j!=0){
        //     v.push_back(s.substr(k,j));
        //     }
        //     j=0;
        //     k=i+1;
        //   }
        // }
        // if(j!=0)
        // v.push_back(s.substr(k,j));
        // string p=v[v.size()-1];
        // for(int i=v.size()-2;i>=0;i--)
        // p+=" "+v[i];

        // return p;

        //method 2
        reverse(s.begin(),s.end());
        int start=0,end=0;
       // int i=0;
       // while(i<n)
          for(int i=0;i<n;i++){
            //skip spaces
            while(i<n&&s[i]==' ')
            i++;
            //out of bound check
            if(i==n)
            break;
            //copy char to correct positions
            while(i<n&&s[i]!=' ')
            s[end++]=s[i++];
            //reverse each word in one one iteration
            reverse(s.begin()+start,s.begin()+end);
            s[end++]=' ';
            start=end;
        }
        s.resize(end-1);
        return s;
    }
};