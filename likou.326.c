bool isPowerOfThree(int n){
    if(n <= 0 || (n%3 != 0)&&(n!=1))        //n<=0 ʱ��false ����n���ܱ�������ͬʱn��Ϊ1
    {
        return false;
    }
    if(n == 1)                              //nΪ1ʱΪtrue
    {
        return true;
    }
    else
    {
        return isPowerOfThree(n/3);         //�ݹ鵽��������3������nΪ1
    }
}
