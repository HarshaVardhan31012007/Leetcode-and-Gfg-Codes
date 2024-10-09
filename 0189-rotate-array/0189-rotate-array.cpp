class Solution {
public:
void reverse(vector<int>&nums,int l,int h){

    while(l<h){
    swap(nums[l],nums[h]);
    l++;
    h--;
}

}

    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int l=0;
        int h=n-1;
        reverse(nums,l,h);
        reverse(nums,l,k-1);
        reverse(nums,k,h);
    }
};