class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
        hm[0] = 1;
        int prefix = 0, count = 0;

        for(int num : nums){
            prefix += num;
            int need = prefix - k;
            if (hm.find(need) != hm.end()){
                count += hm[need];
            }
            hm[prefix]++;
        }
        return count;
    }
};