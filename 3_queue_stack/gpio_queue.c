#include<stdio.h>
#include<stdlib.h>
#include "lgpio.h"

#define FAST_BLINK_DURATION 200000   //50ms
#define BLINK_SEPERATE_TIME 500000  //500ms
#define WAIT_PUSH_BUTTON_TIME 1     //1s

#define LIMIT 100 // Specifying the maximum limit of the queue
int queue[LIMIT]; // Array implementation of queue
int front, rear; // To insert and deletee the data elements in the queue respectively
int h=0;

void insert(int element)
{
    if (rear == LIMIT - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == - 1)
            front = 0;
        queue[rear] = element;
        rear++;
    }
}

void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
    }
    else
    {
        printf("The deleteed element in the queue is: %d\n", queue[front]);
        front++;
    }
}


void gpio_blink(int blink_times)
{
    int i=0;

    for(i=0;i<blink_times;i++)
    {
        lgGpioWrite(h,2,1);
        lgGpioWrite(h,3,1);
        lgGpioWrite(h,4,1);

        usleep(FAST_BLINK_DURATION);
        lgGpioWrite(h,2,0);
        lgGpioWrite(h,3,0);
        lgGpioWrite(h,4,0);
        usleep(FAST_BLINK_DURATION);
    }
}

void gpio_display()
{
    int i;
    if (front == - 1)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("The elements of the queue are:\n");
        for (i = front; i < rear; i++){
            printf("%d\n", queue[i]);
            gpio_blink(queue[i]);
            usleep(BLINK_SEPERATE_TIME);
        }    
    }
}

void main(int argc, char **argv)
{
    int button_pressed = 0;
    int index,value;

    if(argc<=1){
        printf("Usage: qpio_queue number1 number2 number3 number4 ......\n");
        printf("Example: qpio_queue 2 3 4 1\n");
		exit(0);
    }

    for(index=1;index<argc;index++)
    {
        value=atoi(argv[index]);
        insert(value);
    }

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

    lgGpioClaimOutput(h,0,2,0);
    lgGpioClaimOutput(h,0,3,0);
    lgGpioClaimOutput(h,0,4,0);
    lgGpioClaimInput(h,0,23);


    while(1){

        gpio_display(); 

        printf("Wait 1s , if want to delelet , please press PUSH button\n");
        sleep(1);       
        button_pressed = (lgGpioRead(h,23)==0)?1:0;
        printf("button_pressed:%d\n",button_pressed);
        if(button_pressed)
            delete();
    }

    lgGpiochipClose(h);
}
