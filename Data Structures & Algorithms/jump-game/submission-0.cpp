class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), i=0, max_val=0;
        while(max_val >= i){
            if((nums[i] + i )>= n-1) return true;
            max_val = max(max_val,i + nums[i]);
            i++;
        }
        return false;
    }
};
