class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int basket1=-1;int basket2=-1;
        int c1=0;int c2=0;
        int n=fruits.size();
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            if(fruits[j]==basket1){
                c1++;
            }
            else if(fruits[j]==basket2){
                c2++;
            }
            else{
                while(c1!=0&&c2!=0){
                    if(fruits[i]==basket1) c1--;
                    else if(fruits[i]==basket2) c2--;
                    i++;
                }
                if(c1==0){
                    basket1=fruits[j];
                    c1=1;
                }
                else if(c2==0){
                    basket2=fruits[j];
                    c2=1;
                }
            }
            ans=max(ans,c1+c2);
            j++;
        }
        return ans;
    }
};