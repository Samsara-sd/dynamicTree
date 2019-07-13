#include "common.h"

int intpow(int N, int k)
{
    int ans = 0;
    if(N != 0)
    {
        ans = 1;
        while(k != 0)
        {
            ans *= N;
            --k;
        }
    }
    return ans;
}
