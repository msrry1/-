bool lemonadeChange(int* bills, int billsSize){
    int a[2]={0},i;
    for(i=0;i<billsSize;i++)
    {
        if(bills[i]==5)
        {
            a[0]++;
        }
        if(bills[i]==10)
        {
            a[1]++;
            a[0]--;
        }
        if(bills[i]==20)
        {
            if(a[1]>0)
            {
                a[1]--;
                a[0]--;
            }
            else
            {
                a[0]-=3;
            }
        }
        if(a[0]<0 || a[1]<0)
        {
            return false;
        }
    }
    return true;
}
