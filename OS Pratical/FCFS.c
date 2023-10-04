#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct pcb{
    int pid,at,wt,tat,ct,bt,temp;
};
void fun(int a){
    for(int i=0;i<a;i++){
        printf("-");
    }
    printf("\n");
}
int main(){
  struct pcb p[10],ptr;
  int a;
  printf("enter the number of process in the field");
  scanf("%d",&a);
  for(int i=0;i<a;i++){
  printf("enter the arrival time and the burst time in the field::");
  scanf("%d%d",&p[i].at,&p[i].bt); 
  p[i].pid=i+1; 
  }
  //sort the table according to the arrival time.

  for(int i=0;i<a-1;i++){
      for(int j=0;j<a-1;j++){
          if(p[j].at>p[j+1].at){
              ptr=p[j];
              p[j]=p[j+1];
              p[j+1]=ptr;
          }
      }
  }

  //calculation 
  if(p[0].at!=0){
      p[0].ct=p[0].at+p[0].bt;
  } 
  else{
      p[0].ct=p[0].bt;
  }
  for(int i=1;i<a;i++){
      if(p[i].at!=p[i-1].ct){
          if(p[i-1].ct>p[i].at){
              p[i].ct=p[i-1].ct+p[i].bt;
          }
          else{
              p[i].ct=p[i].at + p[i].bt;
          }
      }
      else{
         p[i].ct=p[i-1].ct+p[i].bt; 
      }
  }

  // calculation tat and wt;
  float avgtat=0.0,avgwt=0.0;
  int sum1=0,sum2=0;
  for(int i=0;i<a;i++){
      p[i].tat=p[i].ct-p[i].at;
      sum1+=p[i].tat;
      p[i].wt=p[i].tat-p[i].bt;
      sum2+=p[i].wt;
  }
  avgtat=sum1/(float)a;
  avgwt=sum2/(float)a;
 
  fun(60);

  printf("Pro.\tArrival Time\tBurts Time\tCompletion Time\n");
       fun(60);
  for(int i=0;i<a;i++){
      printf("%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct);
  }
  printf("\n");
       printf("\nTAT\t\tWT\n");
       //seperate table for tat and wt.
       for(int i=0;i<a;i++){
           printf("%d\t\t%d\n",p[i].tat,p[i].wt);
       }

       fun(60);
       printf("the average tat is::%.2f\n",avgtat);
       printf("the average wt is::%.2f\n",avgwt);
    return 0;
}