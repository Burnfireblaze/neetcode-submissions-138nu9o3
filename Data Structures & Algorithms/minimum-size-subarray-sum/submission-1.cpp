class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Sliding Window version
        // int left =0;
        // int curr_sum=0;
        // int min_len = INT_MAX;

        // for(int right=0; right<nums.size();right++){
        //     curr_sum += nums[right];
        //     while (curr_sum>=target){
        //         min_len = min((right - left + 1), min_len);
        //         curr_sum -= nums[left];
        //         left++;
        //     }
        // }

        // return min_len == INT_MAX ? 0 : min_len;


        // Prefix Sum version
        int min_len = INT_MAX;
        int n = nums.size();

        vector <int> prefix(n+1,0);

        for(int i=0;i<nums.size();i++)
        prefix[i+1] = nums[i] + prefix[i];

        for(int i=0;i<n;i++){
            int need = prefix[i] + target;
            auto it = lower_bound(prefix.begin(), prefix.end(), need);
            if(it != prefix.end()){
                int j = it - prefix.begin();
                min_len = min(min_len, j-i);
            }

        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};