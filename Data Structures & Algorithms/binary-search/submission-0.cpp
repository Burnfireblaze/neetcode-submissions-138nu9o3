class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Classical

        // int left = 0;
        // int right = nums.size() -1;

        // while(left<=right){
        //     int mid = left+((right-left)/2);

        //     if(nums[mid] ==target)
        //     return mid;

        //     if(nums[mid] < target){
        //         left = mid + 1;
        //     }
        //     else{
        //         right = mid - 1;
        //     }
        // }
        // return -1;



        // Using lower bound
        auto it = lower_bound(nums.begin(), nums.end(), target);

        if(it != nums.end() && *it == target){
            return it - nums.begin();
        }

        return -1;

    }
};
