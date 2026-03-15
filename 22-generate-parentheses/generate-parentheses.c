/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 void backtrack(char** result, char* current, int n, int open, int close, int* returnSize){
    if(open == n && close == n){
        current[2 * n] = '\0';
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }
    if(open < n ){
        current[open + close] = '(';
        backtrack(result, current, n, open + 1, close, returnSize);
    }
    if(close < open){
        current[open + close] = ')';
        backtrack(result, current, n, open, close+ 1, returnSize);
    }
}


char** generateParenthesis(int n, int* returnSize) {
    //Get the value of n and generate combinations of well-formed parentheses.
    //If n = 1 then there should be 1 set of perfect parentheses
    //First we need to create a for loop that will print out a well formed parenthese.
    //You can add a ( as long as you have fewer than n of them.
    char** result = malloc(sizeof(char*) * 5000);
    char* current = malloc(sizeof(char) * (2 * n + 1));
    *returnSize = 0;
    backtrack(result, current, n, 0, 0, returnSize);

    free(current);

    return result;
}