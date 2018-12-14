#include <stdio.h>
#include <stdlib.h>
struct inf
{
    int num;
    char type[20];
    float area;
    float price;
};
struct inf infs[1000];
int number=0;
int main()
{
    int n,a;
    readinfo();
    while(1)
    {
        system("cls");
        printf("\t\t|-----------------------------Building-----------------------------|\n");
        printf("\t\t| 0.退出                                                           |\n");
        printf("\t\t| 1.添加信息                                                       |\n");
        printf("\t\t| 2.查找信息                                                       |\n");
        printf("\t\t| 3.删除信息                                                       |\n");
        printf("\t\t| 4.更改信息                                                       |\n");
        printf("\t\t| 5.查看全部信息                                                   |\n");
        printf("\t\t|------------------------------------------------------------------|\n\n");
        printf("choose(0-4):");
        scanf("%d",&n);
        printf(("\n"));
        switch(n)
        {
        case 1:
            in();

            break;
        case 2:
            search();
            break;
        case 3:
            Delete();
            break;
        case 4:
            modify();
            writeinfo();
            break;
        case 5:
            Sort();
            Output();
            break;
        case 0:
            writeinfo();
            exit(0);
        }
    }
    system("cls");
}
void in()
{
    int i,n,j,x=0;
    printf("输入要添加数据的个数\n");
    scanf("%d",&n);
    for(i=number; x<n; i++,x++)
    {
        printf("请输入编号: ");
        scanf("%d",&infs[i].num);

        printf("请输入其户型: ");
        scanf("%s",infs[i].type);

        printf("请输入其面积: ");
        scanf("%f",&infs[i].area);

        printf("请输入其价格: ");
        scanf("%f",&infs[i].price);
        number++;
    }
    printf("\n添加数据成功\n按回车键继续......\n");
    getchar();
    getchar();
}
void search()
{
    int i,n=0,NO;
    printf("输入你要查找商品房的编号:");
    scanf("%d",&NO);
    printf("\n");
    for(i=0; i<number; i++)
    {
        if(infs[i].num==NO)
        {
            n=1;
            printf("%10s%8s%12s%12s\n","编号","户型","面积","价格");
            printf("--------------------------------------------------------------\n");
            printf("%10d%8s%12.2f%12.2f\n",infs[i].num,infs[i].type,infs[i].area,infs[i].price);
            printf("--------------------------------------------------------------\n");
        }
    }
    if(n==0)
    {
        printf("未找到该条数据\n");
    }
    printf("\n按回车键继续......\n");
    getchar();
    getchar();
}
void Delete()
{
    int i,n=0,Num;
    printf("%10s%8s%12s%12s\n","编号","户型","面积","价格");
    printf("--------------------------------------------------------------\n");
    for(i=0; i<number; i++)
    {
        printf("%10d%8s%12.2f%12.2f\n",infs[i].num,infs[i].type,infs[i].area,infs[i].price);
    }
    printf("--------------------------------------------------------------\n");
    printf("输入你要删除的商品房编号:");
    scanf("%d",&Num);
    printf("\n");
    for(i=0; i<number; i++)
    {
        if(Num==infs[i].num)
        {
            n=i;
            printf("%10s%8s%12s%12s\n","编号","户型","面积","价格");
            printf("--------------------------------------------------------------\n");
            printf("%10d%8s%12.2f%12.2f\n",infs[i].num,infs[i].type,infs[i].area,infs[i].price);
            printf("--------------------------------------------------------------\n");
            printf("是否要删除此条数据(y/n)?");
            getchar();
            if(getchar()=='y')
            {
                for(n; n<number-1; n++)
                {
                    infs[n]=infs[n+1];
                }
                number--;
                printf("\n删除成功");
            }


        else if(n==0)
            {
                printf("未找到该条数据\n");
            }
        }
    }
    printf("\n按回车键继续......\n");
    getchar();
    getchar();
}
void Output()
{
    int i;
    printf("%10s%8s%12s%12s\n","编号","户型","面积","价格");
    printf("--------------------------------------------------------------\n");
    for(i=0;i<number;i++)
    {
        printf("%10d%8s%12.2f%12.2f\n",infs[i].num,infs[i].type,infs[i].area,infs[i].price);
    }
    printf("--------------------------------------------------------------\n");
    printf("\n按回车键继续......\n");
    getchar();
    getchar();
}
void Sort()
{
    struct inf a;
    int i,j,n;
    printf("|------------------------|\n");
    printf("| 1.按编号排序           |\n");
    printf("| 2.按面积(价格)排序     |\n");
    printf("|------------------------|\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        for(j=0;j<number-1;j++)
        {
            for(i=0;i<number-1-j;i++)
            {
                if(infs[i].num>infs[i+1].num)
                {
                    a=infs[i];
                   infs[i]=infs[i+1];
                    infs[i+1]=a;
                }
            }
        }
        break;
    case 2:
        for(j=0;j<number-1;j++)
        {
            for(i=0;i<number-1-j;i++)
            {
                if(infs[i].price<infs[i+1].price)
                {
                    a=infs[i];
                    infs[i]=infs[i+1];
                    infs[i+1]=a;
                }
            }
        }
        break;
    }
}
void modify()
{
    int i,n=0,NO;
    char j;
    printf("输入你要修改的商品房的编号:");
    scanf("%d",&NO);
    printf("\n");
    for(i=0; i<number; i++)
    {
        if(infs[i].num==NO)
        {
            n=1;
            printf("已找到该条信息，接下来你可以修改该条信息\n");
            printf("%10s%8s%12s%12s\n","a.编号","b.户型","c.面积","d.价格");
            printf("--------------------------------------------------------------\n");
            printf("%10d%8s%12.2f%12.2f\n",infs[i].num,infs[i].type,infs[i].area,infs[i].price);
            printf("--------------------------------------------------------------\n");
            printf("请输入需要修改的类型(a~d)\n");

            getchar();
            j=getchar();
            getchar();
            printf("\n");
            switch(j)
            {

            case 'a':
                printf("将该条编号改为：");
                scanf("%d",&infs[i].num);
                break;

            case 'b':
                printf("将该条户型改为：");
                scanf("%s",&infs[i].type);
                break;

            case 'c':
                printf("将该条面积改为：");
                scanf("%f",&infs[i].area);
                break;

            case 'd':
                printf("将该条价格改为：");
                scanf("%f",&infs[i].price);
                break;
            }
        }
    }
    if(n==0)
    {
        printf("未找到该条数据\n");
    }
    printf("\n按回车键继续......\n");
    getchar();
    getchar();
}

void readinfo()
{
    int i;
    FILE *fp;
    if((fp=fopen("information.txt","r"))==NULL)
    {
        printf("无法找到数据文件\n是否创建新文件(y/n)?\n");
        getchar();
        if(getchar()=='y')
        {
            fp=fopen("information.txt","a");
        }
    }
    for(i=0; i<1000; i++)
    {
        fscanf(fp,"%d %s %f %f ",&infs[i].num,&infs[i].type,&infs[i].area,&infs[i].price);
    }
}

void writeinfo()
{
    int i;
    FILE *fp;
    if((fp=fopen("information.txt","wb"))==NULL)
    {
        printf("无法打开文件\n");
        exit(0);
    }
    for(i=0; i<number; i++)
    {
        fprintf(fp,"%d %s %f %f ",&infs[i].num,&infs[i].type,&infs[i].area,&infs[i].price);
    }
    fclose(fp);
}
