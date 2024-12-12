class Solution {
public:
    int count=0;
    void solve(string tiles,int i){
    count++;
    if(i>=tiles.length())
    return;
    for(int j=i;j<tiles.length();j++){
        if(i==j||tiles[i]!=tiles[j]){
            swap(tiles[i],tiles[j]);
            solve(tiles,i+1);
        }
    }
    }
    int numTilePossibilities(string tiles) {
        int i=0;
        sort(tiles.begin(),tiles.end());
        solve(tiles,i);
        return count-1;//subtract empty set
    }
};