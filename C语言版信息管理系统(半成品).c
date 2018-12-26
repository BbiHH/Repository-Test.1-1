#ifndef OPERATE_H_INCLUDED
#define OPERATE_H_INCLUDED
/*
*  C语言版信息管理系统(半成品)
*
*  编辑者: **彬 (BbiHH)
*
*  版权所有
*/

#include<stdio.h>
typedef struct student Student;
typedef struct Node node;


//定义学生类
struct student
{
    int acconut ;  //学号
    int score ;    //成绩
};

//定义结点
struct Node
{
    Student stu;  //数据
    node *next;   //指针
};


node *head = NULL ;  //头节点
node *pEnd = NULL ;  //尾结点




//添加学生信息
void Add();
//查询学生信息
void Locate();
//修改学生信息
void Revision();
//删除学生信息
void Delete();
//学生成绩全览
void Show();
//学生成绩统计
void Stat();
//退出函数
void Quit(char *J);
//异常处理函数
void Eorr();


//添加学生信息
void Add()           //学生信息添加
{
    node *pStu ;   //新结点
    int account, score;

    //下面表头比较难处理，直接不用表头
    pStu = malloc(sizeof(node)) ;
    pStu->stu.acconut = 0;
    pStu->stu.score = 0;
    head = pStu;
    pEnd = pStu;

    //添加信息
    printf("  请输入学生学号、成绩（0 0输入完毕）:\n");
    printf("  --输入:\n");
    //输入学生学号、成绩
    while(1)
    {
        scanf("%d %d",&account,&score);
        if(account==0&&score==0)
            break ;
        //生成一个学生
        pStu = malloc(sizeof(node)) ;
        pStu->stu.acconut = account;
        pStu->stu.score = score;

        //添加结点
        if(head==NULL)//如果为首个输入，则创建头结点
            head = pStu;
        else          //非首次输入则尾部添加结点
            pEnd->next = pStu;


        //更新尾结点
        pEnd = pStu;
    }
    printf("  信息已录入！\n");
}

void Locate()
{
    int account;
    printf("  输入学生学号:\n");
    printf("  --输入:");
    scanf("%d",&account);

    //指向指针
    node *pRead=head;
    //寻找学生

    int c = 0;

    while(pRead!=NULL)
    {
        //找到则开始修改
        if(pRead->stu.acconut==account)
        {
            //先输出学生信息
            printf("  该学生成绩信息如下:\n\n");
            printf("  \t学号 \t\t成绩\n");
            printf("  \t%3d \t\t%3d\n",pRead->stu.acconut,pRead->stu.score);
            c++;
            break;
        }
        pRead = pRead->next;
    }
    if(c==0)
        printf("  未找到该学号!\n");
}

void showlist()       //学生信息查询
{
    //pRead 为指向指针
    node *pRead=head;

    printf("  成绩表如下:\n\n");
    printf("  \t学号 \t\t成绩\n");
    while(pRead!=NULL)
    {
        printf("  \t%3d \t\t%3d\n",pRead->stu.acconut,pRead->stu.score);
        printf("  \n");
        pRead = pRead->next;
    }
}

void Revision()    //学生信息修改
{
    int account;
    printf("  输入待修改学生学号:\n");
    printf("  --输入:");
    scanf("%d",&account);

    //指向指针
    node *pRead=head;
    //寻找学生

    int c = 0;

    while(pRead!=NULL)
    {
        //找到则开始修改
        if(pRead->stu.acconut==account)
        {
            //先输出学生信息
            printf("  该学生成绩信息如下:\n");
            printf("  \t学号 \t\t成绩\n");
            printf("  \t%3d \t\t%3d\n",pRead->stu.acconut,pRead->stu.score);
            //修改学生成绩
            printf("  请输入该学生的新成绩:\n");
            int score;
            scanf("%d",&score);
            pRead->stu.score = score ;
            c++;
            //跳出循环
            break ;
        }
        //指向下一个
        pRead = pRead->next;
    }
    if(c == 0)
        printf("  未找到该学号!\n");

}

void Delete()     //学生信息删除
{
    printf("  请输入待删除学生信息学号:\n");
    printf("  --输入:");
    int account;
    scanf("%d",&account);

    node *pGuard = head;//防护结点指针

    node *pD;//待删除结点

    int c = 0;

    //寻找学生
    while(pGuard!=NULL)
    {
        //找到则开始修改
        if(head->stu.acconut==account)
        {
            printf("  该学生成绩信息如下:\n");
            printf("  %3d %3d\n",head->stu.acconut,head->stu.score);
            //修改学生成绩
            fflush(stdin);
            char j = 'N';
            printf("  确认删除？（Y/N）\n");
            scanf("%c",&j);
            if(j=='Y');
            {
                pD = head ;        //先找到待删除结点
                head = head->next ;//更改连接指向
                free(pD);         //删除结点
                printf("删除成功！\n");
            }
            c++;
            break;
        }
        else if(pGuard->next->stu.acconut==account)
        {
            //先输出学生信息
            printf("  该学生成绩信息如下:\n");
            printf("  \t学号 \t\t成绩\n");
            printf("  \t%3d \t\t%3d\n",pGuard->next->stu.acconut,pGuard->next->stu.score);
            //修改学生成绩
            fflush(stdin);
            char j = 'N';
            printf("确认删除？（Y/N）");
            scanf("%c",&j);
            if(j=='Y')
            {
                pD = pGuard->next;       //找出待删除结点
                pGuard->next = pD->next; //先连
                free(pD);               //后断
                printf("删除成功!\n");
            }
            c++;
            break ;
        }
        pGuard = pGuard->next;
    }
    //未找到则反馈未找到
    if(c==0)
        printf("  未找到该学号!\n");
}


void sort_account()
{

    node *p, *q, *tail;

    tail = NULL;

    //冒泡法排序
    p = head;

    /*if(head->stu.acconut > head->next->stu.acconut)

    {
        //交换位置

        head = head->next;

        p->next = p->next->next;

        head->next = p ;
    }*/
    while((head->next->next) != tail)
    {
        p = head;
        q = head->next;
        while(q->next != tail)
        {
            /*if(head->stu.acconut > head->next->stu.acconut)

            {
                //交换位置

                head = head->next;

                p->next = p->next->next;

                head->next = p ;
                p = head;
                q = head->next;
            }*/
            if((q->stu.acconut) > (q->next->stu.acconut))
            {
                //位置交换(非交换值)
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = q;
                q = p->next;
            }
            q = q->next;
            p = p->next;
        }
        tail = q;
    }
}
void sort_score()
{

    node *p, *q, *tail;

    tail = NULL;

    //冒泡法排序
    p = head;

    /*if(head->stu.score < head->next->stu.score)

    {
        //交换位置

        head = head->next;

        p->next = p->next->next;

        head->next = p ;
    }*/

    while((head->next->next) != tail)
    {
        p = head;
        q = head->next;
        while(q->next != tail)
        {
            /*if((head->stu.score) < (head->next->stu.score))

            {
                //交换位置

                head = head->next;

                p->next = p->next->next;

                head->next = p ;
                p = head;
                q = head->next;
            }*/
            if((q->stu.score) < (q->next->stu.score))
            {
                //位置交换(非交换值)
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = q;
                q = p->next;
            }
            q = q->next;
            p = p->next;
        }
        tail = q;
    }
}


void Show()       //学生信息全览
{
    printf("-----------------------------\n");
    printf("  欢迎进入班级成绩全览：\n");
    printf("   1---按学号顺序浏览\n");
    printf("   2---按成绩排名浏览\n");
    printf("   0---返回上一级\n");
    int k ;
    do
    {
        scanf("%d",&k);
        switch(k)
        {
        case 1 :   //按学号排序输出成绩
        {
            sort_account();
            showlist();
            break ;
        }
        case 2 :    //按成绩排名输出成绩
        {
            sort_score();
            showlist();
            break ;
        }
        case 0 :    //退出
        {
            break ;
        }
        default :   //异常处理
            printf("  输入有误，请重新输入！\n");
        }
        //刷新缓冲
        fflush(stdin);
    }
    while(k!=0);

    printf("  成功返回上一层！\n");
}

void Stat()     //学生信息统计
{
    printf("-----------------------------\n");
    printf("  欢迎进入班级成绩统计：\n");
    printf("   1----成绩段人数分布统计\n");
    printf("   2----统计不及格人数及名单\n");
    printf("   3----统计优秀人数及名单\n");
    printf("   0----返回上一级\n");

    node *pRead = head;//指向指针

    //统计成绩段人数
    int  A=0,B=0,C=0,D=0,E=0;
    while(pRead!=NULL)
    {
        switch(pRead->stu.score/10)
        {
        case 10:
            A++;
            break;
        case 9 :
            A++ ;
            break;
        case 8 :
            B++ ;
            break;
        case 7 :
            C++ ;
            break;
        case 6 :
            D++ ;
            break;
        default :
            E++ ;
        }
        pRead = pRead->next;
    }
    E = E-1 ;//头结点为0 0


    int k ;
    do
    {
        scanf("%d",&k);
        switch(k)
        {
        case 1 :  //成绩段人数分布
        {
            printf("  成绩段人数分布如下:\n");
            printf("  \t不及格\t及格 \t中等 \t良好 \t优秀\n");
            printf("  \t%3d\t%3d\t%3d\t%3d\t%3d\n",E,D,C,B,A);
            break ;
        }
        case 2 :  //不及格人数统计名单
        {
            pRead = head ;
            printf("  不及格学生名单如下:\n");
            printf("  \t学号 \t\t成绩\n");
            //打印不及格学生信息
            while(pRead!=NULL)
            {
                if(pRead->stu.score<60)
                    printf("  \t%3d \t\t%3d\n",pRead->stu.acconut,pRead->stu.score);
                pRead = pRead->next;
            }
            break ;
        }
        case 3 :  //优秀认识统计名单
        {
            pRead = head ;
            printf("  优秀学生名单如下:\n");
            printf("  \t学号 \t\t成绩\n");
            //打印优秀学生信息
            while(pRead!=NULL)
            {
                if(pRead->stu.score >= 90)
                    printf("  \t%3d \t\t%3d\n",pRead->stu.acconut,pRead->stu.score);
                pRead = pRead->next;
            }
            break ;
        }
        case 0 :  //退出
        {
            break ;
        }
        default : //异常处理
            printf("  输入指令有误,请重新输入！\n");
        }
        fflush(stdin);
    }
    while(k!=0);

    printf("  成功返回上一层！\n");
}

void Quit(char *J)
{
    fflush(stdin);
    printf("  确定退出系统？（Y/N）\n");
    scanf("%c",J);
}

void Eorr()
{
    printf("  输入有误，请重新输入！\n");
}

void Dellist()

{

    node *pD;

    //重复删除操作，直到所有指针为NULL

    while(head!=NULL)

    {

        pD = head;//头结点等待删除

        head = head->next;//头结点指向下一个结点

        free(pD) ;//删除头结点

    }

    printf("\n提示：信息已清除！\n");

}

#endif // OPERATE_H_INCLUDED




#include <stdio.h>
#include <stdlib.h>
#include "student.h" //函数文件


//树状组织结构的话可以改为创建链表函数，生成链表的链表


//菜单
void menu()
{
    printf("\n=========================================================\n");
    printf("欢迎使用成绩管理系统，请选择：\n");
    printf("  1） 学生成绩新增\n");
    printf("  2） 学生成绩查询\n");
    printf("  3） 学生成绩修改\n");
    printf("  4） 学生成绩删除\n");
    printf("  5） 学生成绩全览\n");
    printf("  6） 班级成绩统计\n");
    printf("  7） 退出\n");
}

int main()
{
    int key ;
    char ch1 = 'N';
    do
    {
        fflush(stdin);

        menu();//菜单

        scanf("%d",&key);

        switch(key)
        {
        case 1 :
            Add();//学生信息添加
            break ;
        case 2 :
            Locate();//学生信息查询
            break ;
        case 3 :
            Revision();//学生信息修改
            break ;
        case 4 :
            Delete();//学生信息删除
            break ;
        case 5 :
        {
            Show();//学生信息展示
            break;
        }
        case 6 :
        {
            Stat();//学生信息统计
            break ;
        }
        case 7 :   //系统退出
        {
            Quit(&ch1);
            break ;
        }
        default :  //异常处理
            Eorr();
        }
    }
    while( ch1=='N');

    printf("  系统已安全退出！\n");

    //清除链表，还内存
    Dellist();

    return 0 ;

}
