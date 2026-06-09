class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hm;

        for (int i=0;i<nums.size();i++){
            int need = target - nums[i];

            if (hm.count(need))
            return {hm[need], i};

            hm[nums[i]] = i;
        }
        return {};
    }
};
