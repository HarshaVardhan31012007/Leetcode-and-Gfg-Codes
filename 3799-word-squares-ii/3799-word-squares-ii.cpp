class Solution {
public:
    // vector<vector<string>> wordSquares(vector<string>& words) {
    //     vector<vector<string>>ans;
    //     int n=words.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(j==i) continue;
    //             for(int k=0;k<n;k++){
    //                 if(k==j||k==i) continue;
    //                 for(int p=0;p<n;p++){
    //                     if(p==k||p==j||p==i) continue;
    //                     string top=words[i];
    //                     string left=words[j];
    //                     string right=words[k];
    //                     string bottom=words[p];
    //                     if(top[0]==left[0]&&top[3]==right[0]&&bottom[0]==left[3]&&bottom[3]==right[3])
    //                         ans.push_back({top,left,right,bottom});
    //                 }
    //             }
    //         }
    //     }
    //     sort(ans.begin(),ans.end());
    //     return ans;
    // }




     vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>>ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i||words[j][0]!=words[i][0]) continue;
                for(int k=0;k<n;k++){
                    if(k==j||k==i||words[i][3]!=words[k][0]) continue;
                    for(int p=0;p<n;p++){
                        if(p==k||p==j||p==i) continue;
                        string top=words[i];
                        string left=words[j];
                        string right=words[k];
                        string bottom=words[p];
                        if(bottom[0]==left[3]&&bottom[3]==right[3])
                            ans.push_back({top,left,right,bottom});
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};