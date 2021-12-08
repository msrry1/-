int numWaterBottles(int numBottles, int numExchange){
    int x = numBottles;
    int t = 0;
    int sum = 0;
    while(x)
    {
        sum += x;
        if(x == numBottles)
        {
            t = x;
        }
        else
        {
            t = x + t%numExchange;
        }
        x = t/numExchange;
    }
    return sum;
}
