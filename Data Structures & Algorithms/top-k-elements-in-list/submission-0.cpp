class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
      unordered_map <int, int> freq;
      for(int i=0; i<n; i++){
        freq[nums[i]]++;
      }

      vector<vector<int>> fnums(n + 1);

      for(auto& [key, val] : freq){
        fnums[val].push_back(key);
      }

      vector<int> result;
      for(int i = n; i >= 0 && result.size() < k; i--){
        for(auto num : fnums[i]){
            result.push_back(num);
            if(result.size() == k) break;
        }
    }
      return result;
    }
};
