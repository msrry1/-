//小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。
//
//如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。
//
//请你计算 最多 能喝到多少瓶酒。
//
//?
//
//示例 1：
//
//
//
//输入：numBottles = 9, numExchange = 3
//输出：13
//解释：你可以用 3 个空酒瓶兑换 1 瓶酒。
//所以最多能喝到 9 + 3 + 1 = 13 瓶酒。
//示例 2：
//
//
//
//输入：numBottles = 15, numExchange = 4
//输出：19
//解释：你可以用 4 个空酒瓶兑换 1 瓶酒。
//所以最多能喝到 15 + 3 + 1 = 19 瓶酒。
//示例 3：
//
//输入：numBottles = 5, numExchange = 5
//输出：6
//示例 4：
//
//输入：numBottles = 2, numExchange = 3
//输出：2
//?
//
//提示：
//
//1 <=?numBottles <= 100
//2 <=?numExchange <= 100


int numWaterBottles(int numBottles, int numExchange){
    int x = numBottles;				//x 	为每次能喝的酒的数目 
    int t = 0;						//t 	每次为空瓶数目 
    int sum = 0;					//sum 	总喝的酒数 
    while(x)						// 			当每次有酒可喝时 
    {
        sum += x;					//			总喝的酒数 = 总酒数 + 每次喝的酒数 
        if(x == numBottles)			//对第一次空瓶数进行赋值 
        {
            t = x;					//第一次喝完之后，空瓶数为总酒数（第一次喝的酒的数目） 
        }
        else
        {
            t = x + t%numExchange;	// 空瓶数 = 上次喝完酒的数目 + 不够兑换的酒的数目（空瓶数对兑换数取余，即为上次剩余空瓶数） 
        }
        x = t/numExchange;			//	每次喝的酒的数目 = 总空瓶数 / 兑换数 
    }
    return sum;						//	返回总喝的酒数 
}
