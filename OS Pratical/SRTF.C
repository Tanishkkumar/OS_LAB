#include<stdio.h>
#include<conio.h>
struct sjf{
    int pid,at,bt,ct,tat,wt,demo;
};
void fun(int a){
    int i;
    for( i=0;i<a;i++){
        printf("-");
    }
    printf("\n");
}
int  main(){
 int a;
 struct sjf p[10],temp;
 int t1=0,w=0;
 printf("enter the number of process in the field\n");
 scanf("%d",&a);
 printf("enter the arrival time and burst time in the field\n");
 for(int i=0;i<a;i++){
     printf("enter the value for %d process::",i+1);
     scanf("%d%d",&p[i].at,&p[i].bt);
     p[i].pid=i+1;
 }
   float avgtat=0.0,avgwt=0.0;

 //sorting according to burst time.
    for(int i=0;i<a-1;i++){
        for(int j=0;j<a-1;j++){
            if(p[j].bt>p[j+1].bt){
                 temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }





    //main calculation.
    //initial state.
    int sum;
    int cal=0;
    int count=0;
    int  t=9999;
    int index=-1;
    for(int i=0;i<a;i++){
        cal+=p[i].bt;
       if(p[i].at<t){
           t=p[i].at;
           index=i;
       }
    }
    p[index].bt=p[index].bt-1;
    if(p[index].at==0){
      count=count+1;
    }
    else{
        count=count+p[index].at;
    }
    if(p[index].bt==0){
        p[index].ct=count;
        p[index].demo=-11;
    }
    else{}


    //final state.
    int pre;
    for(int i=1;i<cal;i++){
        t=999;
        pre=index;
        for(int j=0;j<a;j++){
            if(p[j].at<=count && p[j].demo!=-11){
              if(p[j].bt<t){
                  t=p[j].bt;
                  index=j;
              }
            }
        }
        if(p[index].bt==p[pre].bt){
            p[pre].bt=p[pre].bt-1;
            count++;
            if(p[pre].bt==0){
                p[pre].ct=count;
                p[pre].demo=-11;
            }
        }
        else{
            p[index].bt=p[index].bt-1;
            count++;
            if(p[index].bt==0){
                p[index].ct=count;
                p[index].demo=-11;
            }
        }
        
    }









    //for average stuff and all.
    for(int i=0;i<a;i++){
           t1=p[i].ct-p[i].at;
           
           avgtat+=(float)t1;
           p[i].tat=t1;
           w=p[i].tat-p[i].bt;
           avgwt+=(float)w;
           p[i].wt=w;
           t1=0;
           w=0;
       }
       sum=0;
       fun(60);
       printf("Pro.\tArrival Time\tBurts Time\tCompletion Time\n");
       fun(60);
       for(int i=0;i<a;i++){
           printf("%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct);
           sum+=p[i].ct;
       }
       printf("\n");
       printf("\nTAT\t\tWT\n");
       //seperate table for tat and wt.
       for(int i=0;i<a;i++){
           printf("%d\t\t%d\n",p[i].tat,p[i].wt);
       }
       //fun(60);
       float avt,avw;
       avt=avgtat/(float)a;
       avw=avgwt/(float)a;
       printf("Average tat -->%.2f",avt);
       printf("\nAverage wt -->%.2f",avw);
        return 0;
    

}