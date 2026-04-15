class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int val = 0;
            for (int j = 0; j < nums.size(); j++) {
            if (nums[i] == nums[j]){
                val = val + 1;
            }
            if (val > 1){
                return 1;
            }
        }
        }
        return 0;
    }
};