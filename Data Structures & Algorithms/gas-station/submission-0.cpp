class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int currTotal = 0, total=0, start=0;

        for(int i =0; i<gas.size();i++){
            int diff = gas[i] - cost[i];
            currTotal += diff;
            total += diff;
            if(currTotal < 0){
                currTotal =0;
                start = i+1;
            }
        }

        return total >=0 ? start : -1;
    }
};
