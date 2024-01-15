#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//定义动态数组数据结构
#define N 10
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int len;
}SequenceTable;

//初始化随机数组
void init_rand_seq_table(SequenceTable &seq_table,int len)
{
    seq_table.len=len;
    seq_table.elem=(ElemType*)malloc(sizeof(ElemType)*seq_table.len);
    srand(time(NULL));
    for(int i=0;i<seq_table.len;i++)
    {
        seq_table.elem[i]=rand()%100;
    }
}

//初始化数组
void init_seq_table(SequenceTable &seq_table,int len)
{
    seq_table.len=len;
    seq_table.elem=(ElemType*)malloc(sizeof(ElemType)*seq_table.len);
    ElemType element;
    for(int i=0;i<seq_table.len;i++)
    {
        scanf("%d",&element);
        seq_table.elem[i]=element;
    }
}

//打印数组
void print_seq_table(SequenceTable seq_table)
{
    for(int i=0;i<seq_table.len;i++)
    {
        printf("%3d",seq_table.elem[i]);
    }
    printf("\n");
}

//合并数组
void marge(ElemType *arr,int low,int mid,int high)
{
    static ElemType temp_arr[N];
    int i,j,k;
    for(i=low;i<=high;i++)
    {
        temp_arr[i]=arr[i];
    }
    for(i=low,j=mid+1,k=i;i<=mid && j<=high;k++)
    {
        if(temp_arr[i]<=temp_arr[j])
        {
            arr[k]=temp_arr[i++];
        }
        else
        {
            arr[k]=temp_arr[j++];
        }
    }
    while(i<=mid)
    {
        arr[k++]=temp_arr[i++];
    }
    while(j<=high)
    {
        arr[k++]=temp_arr[j++];
    }
}

//两两一组，排序数组
void marge_sort(ElemType *arr,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        marge_sort(arr,low,mid);
        marge_sort(arr,mid+1,high);
        marge(arr,low,mid,high);
    }
}

int main() {
    SequenceTable seq_table;
    int len=N;
//    init_rand_seq_table(seq_table,len);
    init_seq_table(seq_table,len);
//    ElemType arr[10]={12,63,58,95,41,35,65,0,38,44};
//    memcpy(seq_table.elem,arr,sizeof(arr));//使用前提：动态数组的内存空间已经初始化，即已获得一片连续的内存空间
    print_seq_table(seq_table);
    marge_sort(seq_table.elem,0,9);
    print_seq_table(seq_table);
    return 0;
}
