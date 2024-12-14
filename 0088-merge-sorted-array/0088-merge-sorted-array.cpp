class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
    vector<int>unionarr;//or we can set datastructure
    int i=0;
    int j=0;
    while(i<m&&j<n){
        if(a[i]<=b[j]){
            unionarr.push_back(a[i]);
            i++;
        }
        else{
            unionarr.push_back(b[j]);
            j++;
        }
    }
    while(i<m){
                unionarr.push_back(a[i]);
            i++;
    }
    while(j<n){

            
                unionarr.push_back(b[j]);
            
            j++;
        
    }
    int size=unionarr.size();
    for(int i=0;i<size;i++){
        a[i]=unionarr[i];
    }

    }
};