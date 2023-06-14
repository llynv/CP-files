#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    int split = (int)ceil(n / 3.0);
    int sum = 0;
    n -= split;

    if (split <= 17){
        sum += split * 1678;
    }
    else if (split <= 34){ 
        sum += (17 * 1734) + (split - 17) * 1678;
    }
    else if (split <= 67){
        sum += (17 * 1678) + (17 * 1734) + (split - 34) * 2014;
    }
    else if (split <= 100){
        sum += (17 * 1678) + (17 * 1734) + (33 * 2014) + (split - 67) * 2536;
    }        
    if (split <= 133){
        sum += (17 * 1678) + (17 * 1734) + (33 * 2014) + (33 * 2536) + (split - 100) * 2834;
    }    
    else {
        sum += (17 * 1678) + (17 * 1734) + (33 * 2014) + (33 * 2536) + (33 * 2834) + (split - 133) * 2927;
    }

    if (n <= 33){
        sum += n * 1728;
    } else if (n <= 66){
        sum += (33 * 1786) + (n - 33) * 1728;
    } else if (n <= 133){
        sum += (33 * 1728) + (33 * 1786) + (n - 66) * 2074;
    } else if (n <= 200){
        sum += (33 * 1728) + (33 * 1786) + (67 * 2074) + (n - 133) * 2612;
    } else if (n <= 267){
        sum += (33 * 1728) + (33 * 1786) + (67 * 2074) + (67 * 2612) + (n - 200) * 2919;
    } else {
        sum += (33 * 1728) + (33 * 1786) + (67 * 2074) + (67 * 2612) + (67 * 2919) + (n - 267) * 3015;
    }

    printf("Total of money : %d", sum + (int)(10.0 * sum / 100.0));
}