class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         // Start both pointers at the first "node"
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle
        do {
            // move one step
            slow = nums[slow];

            // move two steps
            fast = nums[nums[fast]];

        } while (slow != fast);


        // Phase 2: Find start of cycle
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow]; // one step
            fast = nums[fast]; // one step
        }

        return slow; // duplicate number
    }
};
