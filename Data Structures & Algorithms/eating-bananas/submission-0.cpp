class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto feasible = [&](int k){
                long hours = 0;
                for(auto p : piles){
                    hours += (p+k-1)/k;
                }

                return hours <= h;
            };


            int left = 1;
            int right = *max_element(piles.begin(), piles.end());

            while (left < right){
                int mid = left + (right-left)/2;
                if(feasible(mid)){
                    right = mid;
                }
                else{
                    left = mid + 1;
                }
            }
        return left;
    }
};
