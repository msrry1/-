int inc(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
int arrayPairSum(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(nums[0]),inc);

    int i = 0;
    int sum = 0;
    for(i = 0;i < numsSize;i = i + 2)
    {
        sum += nums[i];
    }
    return sum;
}
