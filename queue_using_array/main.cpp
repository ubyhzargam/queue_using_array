#include <iostream>
using namespace std;

struct queue
{
    int size;
    int f;
    int l;
    int *s;
};

void enqueue(struct queue *q,int x)
{
    if(q->l<q->size)
    {
        q->l++;
        q->s[q->l]=x;
    }
}

void dequeue(struct queue *q)
{
    int x=0;
    if(q->f<q->l)
    {
        q->f++;
    }
}

void Display(struct queue q)
{
    cout<<"The elements of the given queue are : "<<endl;
    for(int i=q.f+1;i<=q.l;i++)
    {
        cout<<q.s[i]<<" ";
    }
    cout<<endl;
}

bool isEmpty(struct queue q)
{
    if(q.f>=q.l)
        return true;
    else
        return false;
}

bool isFull(struct queue q)
{
    if(q.l==(q.size-1))
        return true;
    else
        return false;
}

int last(struct queue q)
{
    return q.s[q.l];
}

int first(struct queue q)
{
    return q.s[q.f+1];
}

int main()
{
    struct queue q;
    cout<<"Enter the size of the queue : "<<endl;
    cin>>q.size;
    q.f=-1;
    q.l=-1;
    q.s=(int*)malloc(sizeof(int)*q.size);
    if(isEmpty(q))
        cout<<"The given queue is Empty "<<endl;
    else
        cout<<"The given queue is not Empty "<<endl;
    enqueue(&q,1);
    enqueue(&q,2);
    if(isEmpty(q))
        cout<<"The given queue is Empty "<<endl;
    else
        cout<<"The given queue is not Empty "<<endl;
    enqueue(&q,3);
    Display(q);
    dequeue(&q);
    Display(q);
    cout<<"The last element in the queue is : "<<last(q)<<endl;
    cout<<"The first element in the queue is : "<<first(q)<<endl;
    return 0;
}
