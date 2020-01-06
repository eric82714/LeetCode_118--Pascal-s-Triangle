class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascal = []
        
        for i in range(numRows):
            if i == 0: pascal.append([1])
                
            if i == 1: pascal.append([1, 1])
                
            if i > 1:
                sums = []
                
                for j in range(len(pascal[i-1])-1):
                    sums.append(pascal[i-1][j]+pascal[i-1][j+1])
                
                pascal.append([1]+sums+[1])
                
        return pascal
