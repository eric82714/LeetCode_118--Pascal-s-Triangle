/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** pascal = malloc(numRows * sizeof(int*));
    *returnColumnSizes = malloc(numRows * sizeof(int*));
    *returnSize = numRows;
        
    for(int i = 0; i < numRows; i++) {
        *(*(returnColumnSizes+0)+i) = i + 1;
        int* sums = malloc((i+1) * sizeof(int));
        *(sums+0) = 1;
        *(sums+i) = 1;
        
        if(i > 1) {        
            for(int j = 0; j < i-1; j++) {
                *(sums+j+1) = *(*(pascal+i-1)+j) + *(*(pascal+i-1)+j+1);
            }       
        }
        *(pascal+i) = sums;
    }                
    return pascal;
}
