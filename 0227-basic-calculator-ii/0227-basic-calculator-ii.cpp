class Solution {
public:
    int calculate(string s) {
        int total=0;
        int current=0;
        int last=0;
        int n=s.length();
        char op='+';
        for(int i=0;i<=n;i++){
            if(s[i]==' ') continue;
            if(isdigit(s[i])){
                current=current*10+(s[i]-'0');
            }
            else{
                if(op=='+'){
                    total+=last;
                    last=current;
                }
                else if(op=='-'){
                    total+=last;
                    last=-current;
                }
                else if(op=='*'){
                    last=last*current;
                }
                else if(op=='/'){
                    last=last/current;
                }
                current=0;
                if(i<n)
                op=s[i];
            }
        }
        total+=last;
        return total;
    }
};