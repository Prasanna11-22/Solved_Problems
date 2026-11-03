class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int tot=0;

        for(int i=0;i<nums.size();i++)
        {
            tot+=abs(maxi-nums[i]);
        }

        return tot;
        
    }
};