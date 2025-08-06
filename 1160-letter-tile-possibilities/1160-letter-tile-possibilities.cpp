class Solution {
public:
    int solve(string tiles,int i){
        if(i==tiles.length()) return 0;
        int ans=0;
        unordered_map<int,int>mpp;
        for(int j=i;j<tiles.length();j++){
            if(mpp[tiles[j]]) continue;
            mpp[tiles[j]]=true;
            swap(tiles[i],tiles[j]);
            ans=ans+1+solve(tiles,i+1);
            swap(tiles[i],tiles[j]);
        }
        return ans;
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        return solve(tiles,0);
    }
};