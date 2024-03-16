#include "lgpio.h"
#define DURATION 50000
void main(int argc, char **argv)
{
	int h=0;
    int duration=0;

    if(argc!=2){
        printf("Usage: test_gpio duration_in_ms\n");
		exit(0);
    }

    duration=atoi(argv[1])*1000;

	h = lgGpiochipOpen(0); // open /dev/gpiochip0

	if (h >= 0)
	{
		printf("Get GPIO handle OK\n");
	}
	else
	{
		printf("Get GPIO handle FAILE\n");
		exit(0);
	}

    printf("argv[1]=%s, atoi:%d, duration:%d\n",argv[1],atoi(argv[1]),duration);

    printf("atoi(5)=%d\n",atoi("5"));

    lgGpioClaimOutput(h,0,2,0);
    lgGpioClaimOutput(h,0,3,0);
    lgGpioClaimOutput(h,0,4,0);

//    duration = DURATION;

    while(1){
        lgGpioWrite(h,2,1);
        lgGpioWrite(h,3,1);
        lgGpioWrite(h,4,1);

        usleep(duration);
        lgGpioWrite(h,2,0);
        lgGpioWrite(h,3,0);
        lgGpioWrite(h,4,0);
        usleep(duration);
    }

    lgGpiochipClose(h);
}
