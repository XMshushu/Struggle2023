#define maxSize 50
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;
typedef struct Sqlist{
    int data[maxSize];
    int length;
}Sqlist;
int findElem(Sqlist l,int x){
    int i;
    for (i = 0; i < l.length ; ++i)
        if(x<l.data[i])
            return i;
}

int insertElem(Sqlist &l,int x){
    int pos= findElem(l,x);
    for (int i = l.length ; i >= pos ; --i)
        l.data[i]=l.data[i-1];
    l.data[pos]=x;
    l.length++;
}

int findElemByValue(Sqlist l,int e){
    int p=-1;
    for(int i=0;i<l.length;i++){
        if(l.data[i]==e) {
            p = i;
            break;
        }
    }
    return p;
}

int insertElemTP(Sqlist &l,int p,int e){
    if(p<0 || p>l.length || l.length==maxSize)
        return 0;
    for(int i=l.length;i>p;i--){
        l.data[i]=l.data[i-1];
    }
    l.data[p]=e;
    l.length++;
    return 1;
}

int deleteElem(Sqlist &l,int p,int &e){
    if(p<0 || p>l.length-1)
        return 0;
    e=l.data[p];
    for (int i = p; i < l.length-1; ++i) {
        l.data[i]=l.data[i+1];
    }
    l.length--;
    return 1;
}

void merge(LNode *A,LNode *B,LNode *&C){
    LNode *p=A->next;
    LNode *q=B->next;
//  少写的部分
    LNode *c;
    C=A;
    C->next=NULL;
    c=C;
    free(B);
//  少写的部分
    while(p!=NULL && q!=NULL){
        if(p->data<q->data){
            c->next=p;
            p=p->next;
        }else{
            c->next=q;
            q=q->next;
        }
        c=c->next;
    }
    if(p!=NULL)
        c->next=p;
    else if(q!=NULL)
        c->next=q;
}

void createListR(LNode *&L,int a[],int n){
    LNode *p,*q;
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    p=L;
    for(int i=0;i<n;i++){
        q=(LNode*)malloc(sizeof(LNode));
        q->data=a[i];
        p->next=q;
        p=p->next;
    }
    p->next=NULL;
}

void createListF(LNode *&L,int a[],int n){
    LNode *p;
    L=(LNode*)malloc(sizeof(LNode));
    L->data=0;
    L->next=NULL;
    for(int i=0;i<n;i++){
        p=(LNode*)malloc(sizeof(LNode));
        p->data=a[i];
        p->next=L->next;
        L->next=p;
    }
}

void mergeDecline(LNode *A,LNode *B,LNode *&C){
    LNode *p=A->next;
    LNode *q=B->next;
    LNode *m;
//  少写的部分
    C=A;
    C->next=NULL;
    free(B);
//  少写的部分
    while(p!=NULL && q!=NULL){
        if(p->data<=q->data){
            m=p;
            p=p->next;
        }else{
            m=q;
            q=q->next;
        }
        m->next=C->next;
        C->next=m;
    }
    while(p!=NULL){
       m=p;
       p=p->next;
       m->next=C->next;
       C->next=m;
    }
    while(q!=NULL){
        m=q;
        q=q->next;
        m->next=C->next;
        C->next=m;
    }
}

int findAndDelete(LNode *L,int e){
    LNode *m,*p=L;
    while(p->next!=NULL){
        if(p->next->data==e)
            break;
        p=p->next;
    }
//    查找结束
    if(p->next==NULL)
        return 0;
    else{
        m=p;
        p=p->next;
        m->next=m->next->next;
        free(p);
        return 1;
    }


//    while(p!=NULL){
//        if(p->data==e){
//            m->next=m->next->next;
//            free(p);
//            return 1;
//        }else{
//            m=p;
//            p=p->next;
//        }
//    }
//    return 0;
}

//逆置代码
/*
 for(int i=left,j=right;i<j;i++,j--){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
 }
*/
void reverse(int a[],int left,int right,int k){
    int temp;
    for(int i=left,j=right;i<left+k && i<j;++i,--j){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}

void moveToEnd(int a[],int n,int k){
    reverse(a,0,k-1,k);
    reverse(a,0,n-1,k);
}

void moveP(int a[],int n,int p){
    reverse(a,0,p-1,p);
    reverse(a,p,n-1,n-p);
    reverse(a,0,n-1,n);
}

void resort(int a[],int m,int n){
   int temp,p=0;
   for(int j=m;j<m+n;++j){
       for(int i=p;i<m;++i)
           if(a[j]<=a[i]){
               temp=a[j];
               for(int k=j;k>i;k--)
                    a[k]=a[k-1];
               a[i]=temp;
               p=i+1;
           }
   }
}

void diff(LNode *A,LNode *B){
    LNode *p,*q,*tmp;
    p=A;
    q=B->next;
    while(p->next!=NULL && q!=NULL){
        if(p->next->data<q->data)
            p=p->next;
        else if(p->next->data==q->data){
            tmp=p->next;
            p->next=p->next->next;
            q=q->next;
            free(tmp);
        }else
            q=q->next;
    }
}