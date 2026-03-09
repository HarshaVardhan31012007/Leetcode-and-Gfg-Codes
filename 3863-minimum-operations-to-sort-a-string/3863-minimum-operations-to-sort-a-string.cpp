class Solution {
public:
    int minOperations(string s) {
        // string temp=s;
        // sort(temp.begin(),temp.end());
        // int n=s.length();
        // if(n==1) return 0;
        // if(n==2) return(temp==s?0:-1);
        // bool allmatched=true;
        // bool ends=false;
        // bool middle=false;
        // vector<int>pos(n);
        // for(int i=0;i<n;i++){
        //     if(s[i]!=temp[i]){
        //         allmatched=false;
        //     }
        //     if(s[i]==temp[i]){
        //         if(i>0&&i<n-1)
        //             middle=true;
        //         if(i==0||i==n-1)
        //             ends=true;
        //     }
        //     pos[i]=lower_bound(temp.begin(),temp.end(),s[i])-temp.begin();
        // }
        // if(allmatched) return 0;
        // if(ends) return 1;
        // string temp2=s;
        // sort(temp2.begin()+1,temp2.end());
        // if(temp2[n-1]==temp[n-1]) return 2;
        // string temp3=s;
        // sort(temp3.begin(),temp3.begin()+n-1);
        // if(temp3[0]==temp[0]) return 2;
        // return 3;

        int n=s.length();
        bool issorted=true;
        char maxi='a';char mini='z';
        for(int i=0;i<n;i++){
           if(i+1<n&&s[i]>s[i+1]){
             issorted=false;
           }
           if(s[i]>maxi) maxi=s[i];
           if(s[i]<mini) mini=s[i];
        }
        if(issorted) return 0;
        else if(n==2) return -1;
        else if(s[0]==mini||s[n-1]==maxi) return 1; 
        bool miniOnlyAtEnd=true;
        bool maxiOnlyAtStart=true;
        for(int i=0;i<n;i++){
             if(i!=0&&s[i]==maxi) maxiOnlyAtStart=false;
             if(i!=n-1&&s[i]==mini) miniOnlyAtEnd=false;
        }
        if(miniOnlyAtEnd&&maxiOnlyAtStart) return 3;
        return 2;
    }
};