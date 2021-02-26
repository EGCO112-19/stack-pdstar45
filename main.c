#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j;
  int C;
  C =0;
  
  Stack s;
  s.size=0;
  s.top=NULL;


 
  for(i=1;i<argc;i++){
   
     for(j=0;j<strlen(argv[i]);j++){
        char cut;
       /* Use stack to help with the parentheses*/
       if(argv[i][j]== '[' || argv[i][j] == '{'){
         push(&s,argv[i][j]);
         s.size += 1;
       }
       if(argv[i][j]== ']'){
         cut = pop(&s);
         s.size-= 1;
          if(cut != '[')
           {C=1;
            break;
           }
       }
       if(argv[i][j]== '}'){
         cut = pop(&s);
         s.size -= 1;
          if(cut!= '}')
           {C=1; //แล้ว C จะกลับไปเป็น 0 ตอนไหนคะ 
            break;
           }
       }
    }
     if(s.size>0 ||C==1 ){
       printf("the parentheses don't match successfull in %s \n",argv[i]);
       pop_all(&s);
       
     }else
       printf("the parentheses  match successfull in %s \n",argv[i]);
       C = 0;
   

  }
   return 0;
}
