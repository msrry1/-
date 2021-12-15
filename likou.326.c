bool isPowerOfThree(int n){
    if(n <= 0 || (n%3 != 0)&&(n!=1))        //n<=0 时必false 或者n不能被三整除同时n不为1
    {
        return false;
    }
    if(n == 1)                              //n为1时为true
    {
        return true;
    }
    else
    {
        return isPowerOfThree(n/3);         //递归到最后如果是3的幂则n为1
    }
}
