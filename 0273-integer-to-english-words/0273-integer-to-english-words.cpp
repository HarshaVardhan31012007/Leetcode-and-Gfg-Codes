//basic logic 

// class Solution {
// public:
//      string func(int n){
//         if(n==2) return "Thousand";
//         else if(n==3) return "Million";
//         else if(n==4) return "Billion";
//         return "";
//     }
//      bool check(string &inp,int k){
//         for(int i=k;i<inp.length();i++){
//             if(inp[i]!='0')
//             return true;
//         }
//         return false;
//     }
//     string func2(int n){
//         string ans="";
//             if(n==1) ans+="One";
//             else if(n==2) ans+="Two";
//             else if(n==3) ans+="Three";
//             else if(n==4) ans+="Four";
//             else if(n==5) ans+="Five";
//             else if(n==6) ans+="Six";
//             else if(n==7) ans+="Seven";
//             else if(n==8) ans+="Eight";
//             else if(n==9) ans+="Nine";
//             return ans;
//     }
//     string func1(int n){
//         cout<<n<<endl;
//         string ans="";
//         int h=n/100;
//         if(h){
//            ans+=func2(h)+" Hundred";
//         }
//         int c=n;
//         c=c/10;
//         int t=c%10;
//         if(h!=0&&t>=1) ans+=" ";
//         if(t==1){
//            int o=n%10;
//            if(o==0) ans+="Ten";
//            else if(o==1) ans+="Eleven";
//            else if(o==2) ans+="Twelve";
//            else if(o==3) ans+="Thirteen";
//            else if(o==4) ans+="Fourteen";
//            else if(o==5) ans+="Fifteen";
//            else if(o==6) ans+="Sixteen";
//            else if(o==7) ans+="Seventeen";
//            else if(o==8) ans+="Eighteen";
//            else if(o==9) ans+="Nineteen";
//         }
//         else if(t>1){
//             if(t==2) ans+="Twenty";
//             else if(t==3) ans+="Thirty";
//             else if(t==4) ans+="Forty";
//             else if(t==5) ans+="Fifty";
//             else if(t==6) ans+="Sixty";
//             else if(t==7) ans+="Seventy";
//             else if(t==8) ans+="Eighty";
//             else if(t==9) ans+="Ninety";
//         }
//             int o=n%10;
//             if(((t!=1&&h)||(t>1))&&(o!=0)) ans+=" ";
//             if(t!=1){
//             if(o==1) ans+="One";
//             else if(o==2) ans+="Two";
//             else if(o==3) ans+="Three";
//             else if(o==4) ans+="Four";
//             else if(o==5) ans+="Five";
//             else if(o==6) ans+="Six";
//             else if(o==7) ans+="Seven";
//             else if(o==8) ans+="Eight";
//             else if(o==9) ans+="Nine";
//             }
//            return ans;
//     }
//     string solve(string &str,int i){
//      if(i>=str.length()) return "";
//       int n=str.length()-i;int p=ceil(n/3.0);
//       string ans="";
//           string output=func(p);
//           string output1=func1(stoi(str.substr(i,3)));
//           if(output!=""&&output1!="")
//           ans=ans+output1+" "+output;
//           else
//           ans=ans+output1;
//           i=i+3;
//       string l=solve(str,i);
//       if(i<str.length()&&check(str,i)&&l.length()!=0&&ans.length()!=0&&l[0]!=' '&&ans[ans.length()-1]!=' ') ans+=" ";
//       return ans+l;
//     }
//     string numberToWords(int num) {
//         if(num==0) return "Zero";
//         string inp=to_string(num);
//         int i=0;string ans="";
//         int p=inp.length()%3;
//         int q=ceil(inp.length()/3.0);
//         if(p!=0){
//           string output=func(q);
//           string output1=func1(stoi(inp.substr(0,p)));
//           if(output!=""&&output1!="")
//           ans=ans+output1+" "+output;
//           else
//           ans+=output1;
//         }
//         if(p!=0&&inp.length()>3&&check(inp,p)) ans+=" ";
//         return ans=ans+solve(inp,p);
//     }
// };


class Solution {
public:
     vector<pair<int,string>>mp={
            {1000000000,"Billion"},{1000000,"Million"},{1000,"Thousand"},{100,"Hundred"},{90,"Ninety"},{80,"Eighty"},{70,"Seventy"},{60,"Sixty"},{50,"Fifty"},{40,"Forty"},{30,"Thirty"},{20,"Twenty"},{19,"Nineteen"},{18,"Eighteen"},{17,"Seventeen"},{16,"Sixteen"},{15,"Fifteen"},{14,"Fourteen"},{13,"Thirteen"},{12,"Twelve"},{11,"Eleven"},{10,"Ten"},{9,"Nine"},{8,"Eight"},{7,"Seven"},{6,"Six"},{5,"Five"},{4,"Four"},{3,"Three"},{2,"Two"},{1,"One"}
        };
    string numberToWords(int num) {
        if(num==0) return "Zero";
       for(auto it:mp){
        if(it.first<=num){
        string a="";
        if(num>=100){
            a=numberToWords(num/it.first)+" ";
        }
        string b=it.second;
        string c="";
        if(num%it.first!=0){
            c=" "+numberToWords(num%it.first);
        }
        return a+b+c;
       }
       }
       return "";
    }
};