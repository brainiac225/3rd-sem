#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    long long int a,min;
    char name[15];
    struct node* next;
}stack;
void push(struct node **head,long long int n,char arr[])
{
    if((*head)==NULL)
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->a=n;
        strcpy(temp->name,arr);
        temp->min=n;
        (*head)=temp;
        (*head)->next=NULL;
        return;
    }
    long long int m=(*head)->min;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->a=n;
    strcpy(temp->name,arr);
    if(m>n)
    {
        temp->min=n;
    }
    else if(m<=n)
    {
        temp->min=m;
    }
    temp->next=(*head);
    (*head)=temp;
    return;
}
void prn(struct node **head)
{
    long long int m=(*head)->min,i=0;
    struct node *temp=NULL;
    char ten[30];
    while((*head)!=NULL)
    {
        if((*head)->a==m)
        {
            temp=(*head);
            strcpy(ten,(*head)->name);
            (*head)=(*head)->next;
            free(temp);
            break;
        }
        i++;
        temp=(*head);
        (*head)=(*head)->next;
        free(temp);
    }
    printf("%lli %s\n",i,ten);
}
long long int main()
{
    struct node *head=NULL;
    long long int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n;
        scanf("%lli",&n);
        if(n!=-1)
        {
            char ar[30];
            scanf("%s",ar);
            if(n!=0)
            {
                push(&head,n,ar);
            }
            continue;
        }
        prn(&head);
    }
    return 0;
}
