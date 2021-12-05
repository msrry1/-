bool canJump(int* nums, int numsSize){
    int far=nums[0];
    int i;
    if(numsSize==1)
    {
        return true;
    }
    for(i = 1;i < numsSize;i++)
    {
        if(i>far)
        {
            return false;
        }
        far=fmax(far,nums[i]+i);
    }
    return true;
}
