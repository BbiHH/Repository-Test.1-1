#include<stdio.h>
//windows 使用 Windos.h
//#inclued <unistd.h>
#include <Windows.h>
#define N 5

//后续工作：
//完善排序算法
//由面向程序输入数组到面向对象用结构体
//启用自定义结构描述students的特征 Name/Sex/ID/Score/some else


void Input_info (char name[N][8],int amount[N],float score[N]);//输入信息
void Countdown(int hour,int min,int sec);//倒计时
void Sort()//顺序排列
int main()
{
   char name[N][8];
   int amount[N];
   float score[N];
   Input_info(name,amount,score);/*输入数组名表示数组的首地址*/
   return 0;
}
//输入汉字数组
void Input_info (char name[N][8],int amount[N])
{
    for(int i=0;i<N;i++)
    {
        printf("Please write your Name/ID(the LAST two number)/score:");
        scanf("%s%*c%d%*c%f",name[i],amount,score[i]);
    }
    printf("  *name* \t\t\t *amount* \t\t\t score\n");
    for(int i=0;i<N;i++)
    {
       printf("%8s \t\t\t 201804408%02d \t\t\t %f\n",name[i],amount[i],score[i]);
    }
}
//倒计时函数
void Countdown(int hour,int min,int sec)
{

    printf("倒计时开始！\n");
    for(int h=hour; h>=0; h--)
    {
        for(int m=min; m>=0; m--)
        {
            for(int s=sec; s>=0; s--)
            {
                printf("\a\r%02d:%02d:%02d", h, m, s);  /*用%02d来表示输出整形占两位*/
                Sleep(1000);
                //sleep(1);
            }
        sec = 59;
        }
    min = 59;
     }
     printf("结束!\n");
}
