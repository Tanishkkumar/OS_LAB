#include<stdio.h>
struct sjf{
    int pid,at,bt,ct,tat,wt,demo,test,pot,bt_bro;
};
void fun(int a){
    int i;
    for( i=0;i<a;i++){
        printf("-");
    }
    printf("\n");
}
int main(){
   int a;
   int tq;
 struct sjf p[20],temp;
 int t1=0,w=0;
 printf("enter the number of process in the field\n");
 scanf("%d",&a);
 printf("enter the time quatum in the field\n");
 scanf("%d",&tq);
 printf("\nenter the arrival time and burst time in the field\n");
 for(int i=0;i<a;i++){
     printf("enter the value for %d process::",i+1);
     scanf("%d%d",&p[i].at,&p[i].bt);
     p[i].bt_bro=p[i].bt;
     p[i].pid=i+1;
 }
   float avgtat=0.0,avgwt=0.0;

 //sorting according to burst time.
    for(int i=0;i<a-1;i++){
        for(int j=0;j<a-1;j++){
            if(p[j].at>p[j+1].at){
                 temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    //main calculation
     int st=0;
     int end=0;
     int index=0;
     int count=0;
     int check=0;
     int z=0;
     int re=0;
    
    p[end++].demo=0;
    if(p[0].at!=0){
        count=p[0].at;
    }
    
    while(check!=-1){
        z=0;
         index=p[st].demo;
         //printf("index:%d\n",index+1);
         p[index].pot=0;
        if(p[index].bt<tq && p[index].test!=-11){  //test is testing
            count=count+p[index].bt;
            printf("count::%d\n",count);
            p[index].bt=0;
            p[index].ct=count;
            p[index].test=-11;
        }
        else if(p[index].bt!=0){
            count=count+tq;
           printf("count::%d\n",count);
            p[index].bt=p[index].bt-tq;
            if(p[index].bt==0){
               p[index].ct=count;
               p[index].test=-11; 
            }
        }
        
        for(int i=0;i<a;i++){
           if(p[i].at<=count && p[i].test!=-11 && i!=index && p[i].pot!=-1){
               p[end++].demo=i;
               p[i].pot=-1;
           }
           if(p[i].bt==0){
              z++;
           }
        }
        if(z==a){
            check=-1;
        }
        
        if(p[index].bt!=0){
            p[end++].demo=index;
            p[index].pot=-1;
        }
        else{}
        st++;
    }
    

     
     //calculating average and all
     for(int i=0;i<a;i++){
           t1=p[i].ct-p[i].at;
           
           avgtat+=(float)t1;
           p[i].tat=t1;
           w=p[i].tat-p[i].bt_bro;
           avgwt+=(float)w;
           p[i].wt=w;
           t1=0;
           w=0;
       }
       int sum=0;
       fun(60);
       printf("Pro.\tArrival Time\tBurts Time\tCompletion Time\n");
       fun(60);
       for(int i=0;i<a;i++){
           printf("%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt_bro,p[i].ct);
           sum+=p[i].ct;
       }
       printf("\n");
       printf("\nTAT\t\tWT\n");
       //seperate table for tat and wt.
       for(int i=0;i<a;i++){
           printf("%d\t\t%d\n",p[i].tat,p[i].wt);
       }
       fun(60);
       float avt,avw;
       avt=avgtat/(float)a;
       avw=avgwt/(float)a;
       printf("Average tat -->%.2f",avt);
       printf("\nAverage wt -->%.2f",avw);
        return 0;
}