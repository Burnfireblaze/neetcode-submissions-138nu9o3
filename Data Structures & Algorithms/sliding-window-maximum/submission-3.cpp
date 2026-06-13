class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;        // output: one max per window
        deque<int> dq;          // stores INDICES; nums[dq[i]] is strictly decreasing front→back
                                // so nums[dq.front()] is always the current window's max

        for (int r = 0; r < nums.size(); ++r) {
            // Kick weaker elements from the back.
            // Anything smaller-or-equal than nums[r] can never be a future max,
            // because nums[r] is bigger AND lives longer in upcoming windows.
            while (!dq.empty() && nums[dq.back()] <= nums[r]) {
                dq.pop_back();
            }

            // Push the current INDEX (not the value — indexing is how we check window membership later).
            dq.push_back(r);

            // Evict the front if it has slid out of the window [r-k+1, r].
            // Only the front can be stale, and at most one per step, so 'if' not 'while'.
            if (dq.front() <= r - k) {
                dq.pop_front();
            }

            // Once the first full window is formed (r reaches k-1), emit one max per iteration.
            // nums[dq.front()] is the answer by the deque invariant.
            if (r >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};
