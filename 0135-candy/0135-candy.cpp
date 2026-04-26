class Solution {
public:
    // int candy(vector<int>& ratings) {
    //    vector<pair<int,int>>v;
    //    for(int i=0;i<ratings.size();i++){
    //       v.push_back({ratings[i],i});
    //    }
    //    sort(v.begin(),v.end());
    //    vector<int>candies(ratings.size(),1);
    //    int candie=ratings.size();
    //    for(int i=0;i<v.size();i++){
    //       if(v[i].second>0&&ratings[v[i].second]>ratings[v[i].second-1]){
    //         int before=candies[v[i].second];
    //         candies[v[i].second]=max(candies[v[i].second],candies[v[i].second-1]+1);
    //         candie+=candies[v[i].second]-before;
    //       }
    //       if(v[i].second+1<ratings.size()&&ratings[v[i].second]>ratings[v[i].second+1]){
    //         int before=candies[v[i].second];
    //         candies[v[i].second]=max(candies[v[i].second],candies[v[i].second+1]+1);
    //         candie+=candies[v[i].second]-before;
    //       }
    //    }
    //    return candie;
    // }



    // int candy(vector<int>& ratings) {
    //    vector<int>candies(ratings.size(),1);
    //    for(int i=1;i<ratings.size();i++){
    //       if(ratings[i]>ratings[i-1])
    //       candies[i]=max(candies[i],candies[i-1]+1);
    //    }
    //    for(int i=ratings.size()-2;i>=0;i--){
    //       if(ratings[i]>ratings[i+1])
    //       candies[i]=max(candies[i],candies[i+1]+1);
    //    }
    //    return accumulate(candies.begin(),candies.end(),0);
    // }       
    

    int candy(vector<int>& ratings) {
         int candie=1;
         int i=1;
         int peak=1;int down=1;
         while(i<ratings.size()){
            if(ratings[i]==ratings[i-1]){
                candie+=1;
                i++;
                continue;
            }
            peak=1;
            while(i<ratings.size()&&ratings[i]>ratings[i-1]){
                peak++;
                candie+=peak;
                i++;
            }
            down=1;
            while(i<ratings.size()&&ratings[i]<ratings[i-1]){
                candie+=down;
                down++;
                i++;
            }
            if(down>peak)
            candie+=down-peak;
         }
         return candie;
    } 


};