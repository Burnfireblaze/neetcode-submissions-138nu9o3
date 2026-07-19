class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m-1, left = 0, right = n-1;

        vector<int> res;

        int r, c;
        while(top <= bottom && left <= right){

        r = top;

        for(c = left; c<=right; c++){
        matrix[r][c];
        res.push_back( matrix[r][c]);
        }
        top++;

        c = right;

        for(r = top; r<=bottom; r++){
        matrix[r][c];
        res.push_back( matrix[r][c]);
        }
        right--;


        if(top <= bottom){
        r = bottom;
        for(c = right; c>=left; c--){
        matrix[r][c];
        res.push_back( matrix[r][c]);
        }
        bottom--;
        }

        if(left <= right){
        c = left;
        for(r = bottom; r>=top; r--){
        matrix[r][c];
        res.push_back( matrix[r][c]);
        }
        left++;
        }
        }
        return res;
    }
};
