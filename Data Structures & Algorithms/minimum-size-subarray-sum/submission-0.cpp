class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left =0;
        int curr_sum=0;
        int min_len = INT_MAX;

        for(int right=0; right<nums.size();right++){
            curr_sum += nums[right];
            while (curr_sum>=target){
                min_len = min((right - left + 1), min_len);
                curr_sum -= nums[left];
                left++;
            }
        }

        return min_len == INT_MAX ? 0 : min_len;
    }
};