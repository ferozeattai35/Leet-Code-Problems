/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if(numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }
    int* result = (int*)malloc(sizeof(int)* (numsSize - k +1 )); 
    int* deque = (int*)malloc(sizeof(int)* numsSize);
    int head = 0;
    int tail = 0;
    int resindex = 0;
    for(int i = 0; i < numsSize ; i++){
        if(head < tail && deque[head] <= i-k){
            head++;
        }
        while(head < tail && nums[deque[tail-1]] <= nums[i]){
            tail--;
        }
        deque[tail++]=i;
        if(i >= k-1){
            result[resindex++] = nums[deque[head]];
            }
    }
    *returnSize = resindex;
    free(deque);
    return result;
}