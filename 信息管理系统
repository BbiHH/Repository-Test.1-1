#include<iostream>
#include"string"
using namespace std ;
#include<iomanip>

class Student
{
private:
    string name ;
    string id   ;
    string class_;
    string score;
public:
    Student();
    void  Add_N(string Name);//添加姓名
    void  Add_ID(string ID);//添加学号
    void  Add_C(string Class);//添加班级
    void  Add_S(string Score);//添加成绩
    void  Show(void);//展示个体
    string S_N()
    {
        return name;
    }
    string S_ID()
    {
        return id;
    }
    string S_C()
    {
        return class_;
    }
    string S_S()
    {
        return score;
    }
};
Student::Student()
{
    name = '0';
    id = '0';
    class_='0';
    score='0';
}
void Student::Add_N(string Name)
{
    name = Name;
}
void Student::Add_ID(string ID)
{
    id = ID;
}
void Student::Add_C(string Class)
{
    class_ = Class;
}
void Student::Add_S(string Score)
{
    score = Score;
}
void Student::Show(void)
{
    cout<<setw(12)<<left<<id<<" "<<setw(5)<<left<<name<<" "<<setw(5)<<left<<class_<<" "<<setw(3)<<left<<score<<endl;
}


Student stu ;

//定义结点
struct node
{
    Student stu;//数据域
    node *next;//结构域
};

//创造链表表头
node *create();
//读取链表数据
void Showlist(node *head);
//删除链表
void Dellist(node *&head);
//搜寻结点
node *Seach(node *head,string Kayword);
//删除结点
void Delnode(node *&head,string Keyword);



int main()
{
    node *head = NULL;
    cout<<"#####1.添加信息 2.信息展示 3.删除链表 4.查找 #####"<<endl;
    cout<<"#####5.精确删除 0.退出 #####"<<endl;
    cout<<endl;
    int J;
    while(1)
    {
        cout<<"***$:";
        cin>>J;
        if(J==0)
            break ;
        switch(J)
        {
        case 1:
        {
            cout<<"#添加信息#"<<endl;
            cout<<"请依次输入学生信息"<<endl;
            cout<<"学号  姓名  班级  成绩"<<endl;
            head = create();
            break;
        }//创建链表
        case 2:
        {
            cout<<"#信息展示#"<<endl;
            Showlist(head);
            break;
        }//展示链表
        case 3:
        {
            cout<<"#删除全部#"<<endl;
            Dellist(head);
            break;
        }//删除链表
        case 4:
        {
            cout<<"查找"<<endl;
            string Key1;
            node *pRead;//搜寻关键结点
            cout<<"请输入关键字"<<endl;
            cin>>Key1;
            pRead = Seach(head,Key1);
            cout<<setw(12)<<left<<pRead->stu.S_ID()<<" "<<setw(5)<<left<<pRead->stu.S_N()<<" "<<setw(5)<<left<<pRead->stu.S_C()<<" "<<setw(3)<<left<<pRead->stu.S_S()<<endl;//输出结点数据
            break ;
        }
        case 5:
        {
            cout<<"#精确删除#"<<endl;
            cout<<"输入（名字、学号）";
            string Key2 ;
            cin>>Key2;
            Delnode(head,Key2);
            break ;
        }
        }
    }
    return 0 ;
}





node *create()
{
    node *head=NULL;//创建链表时头结点指向空
    node *pEnd=head;//pEnd为尾结点
    node *pS;       //pS为新创结点地址
    string  Juge, ID, Name, Class, Score ;
    while(cin>>ID>>Name>>Class>>Score>>Juge)
    {
        if(Juge=="#")
            break ;
        pS = new node;
        pS->stu.Add_ID(ID);//添加学号
        pS->stu.Add_N(Name);//添加姓名
        pS->stu.Add_C(Class);//添加班级
        pS->stu.Add_S(Score);//添加成绩
        pS->next = NULL;
        if(head==NULL)
            head = pS;
        else
            pEnd->next = pS;
        pEnd = pS;
    }

    return head ; //创建链表后返回头结点
}

void Showlist(node *head)
{
    //pR 为指向指针
    node *pRead=head;
    while(pRead!=NULL)
    {
        pRead->stu.Show();
        pRead = pRead->next;
    }
}

//入口为需要删除链表的头结点
void Dellist(node *&head)
{
    node *pD;
    //重复删除操作，直到所有指针为NULL
    while(head!=NULL)
    {
        pD = head;//头结点等待删除
        head = head->next;//头结点指向下一个结点
        delete pD ;//删除头结点
    }
    cout<<"提示：信息已清除！"<<endl;
}

node *Seach(node *head,string Keyword)
{
    node *pRead=head;
    while(pRead!=NULL)
    {
        if(pRead->stu.S_N()==Keyword||pRead->stu.S_ID()==Keyword||pRead->stu.S_C()==Keyword||pRead->stu.S_S()==Keyword)
        {
            return pRead ;
        }
        pRead=pRead->next;
    }
    return NULL;
}

void Delnode(node *&head,string Keyword)
{
    node *pD;
    node *pGuard=head;
    while(pGuard!=NULL)
    {
        if(head->stu.S_N()==Keyword||head->stu.S_ID()==Keyword||head->stu.S_C()==Keyword||head->stu.S_S()==Keyword)
        {
            pD = head;
            head = head->next;//先连接下一个结点
            delete pD;//后删除目标结点
        }
        else
        {
            while(pGuard!=NULL)
            {
                if(pGuard->next->stu.S_N()==Keyword||pGuard->next->stu.S_ID()==Keyword||pGuard->next->stu.S_C()==Keyword||pGuard->next->stu.S_S()==Keyword)//找出需删结点前结点
                {
                    pD = pGuard->next;//找出待删除结点
                    pGuard->next = pD->next;//先连
                    delete pD;//后断
                    return ;
                }
                pGuard=pGuard->next;//继续搜寻
            }
        }
    }
}
