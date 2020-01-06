class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        
        for(int i = 0; i < numRows; i++) {
            if(i == 0) pascal.push_back(vector<int>{1});
                
            if(i == 1) pascal.push_back(vector<int>{1, 1});
                
            if(i > 1) {
                vector<int> sums = {1, 1};
                
                for(int j = 0; j < pascal[i-1].size()-1; j++) {
                    sums.insert(sums.begin()+j+1, pascal[i-1][j]+pascal[i-1][j+1]);
                }
                pascal.push_back(sums);
            }
        }                
        return pascal;
    }
};
