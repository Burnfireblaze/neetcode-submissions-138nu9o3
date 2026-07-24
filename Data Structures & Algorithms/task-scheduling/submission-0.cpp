class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector <int> arr(26, 0);
        int num_max =0, max_count=0;

        for(auto  t : tasks){
            ++arr[t-'A'];
        }
        for(auto c : arr){
            if(c > max_count){
            max_count =c;
            num_max = 1;
            }
            else if(c == max_count){
                num_max++;
            }
        }


        int frameSize = (max_count - 1) * (n + 1) + num_max;
        return max(frameSize, (int)tasks.size());
    }
};
