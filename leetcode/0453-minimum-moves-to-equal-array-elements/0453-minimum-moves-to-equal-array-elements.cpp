class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
    int tot=0;
        for(int i=0;i<nums.size();i++)
        {
            tot+=abs(nums[i]-mini);
        }
        return tot;
    }
};