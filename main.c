#include <stdio.h>
#include <stdlib.h>

#include "deq.h"

/**
 * run test for ith 
 * Deq - q 
 * ht - 0 = deq_head_put, 1 = deq_tail_put 
 * r - 0 = deq_head_ith, 1 = deq_tail_ith
 * index - index to remove 
*/
static void run_ith(Deq q,int ht, int r, int index){
  char *t1 = "test1 ";
  char *t2 = "test2 ";
  char *t3 = "test3 "; 
  char *t4 = "test4 ";
  char *t5 = "test5 ";
  char *t6 = "test6 ";
  char *t7 = "test7 "; 

  if (ht == 0){
  printf("*****PUT HEAD *****\n");
  
  deq_head_put(q, t1);
  deq_head_put(q, t2);
  deq_head_put(q, t3);
  deq_head_put(q, t4);
  deq_head_put(q, t5);
  deq_head_put(q, t6);
  deq_head_put(q, t7);

  }
  else if(ht == 1 ){
  printf("*****PUT TAIL *****\n");
  
  deq_tail_put(q,t1); 
  deq_tail_put(q,t2);
  deq_tail_put(q,t3);
  deq_tail_put(q,t4); 
  deq_tail_put(q,t5);
  deq_tail_put(q,t6);
  deq_tail_put(q,t7);

  }else {
    printf("An invalid option was entered for ht\n");
    return ; 
  }

  char *s=deq_str(q,0);
  printf("%s\n",s);
  free(s);
  printf("Index to remove: %d \n", index); 

  if(r == 0){
    printf("*****iTH Head *****\n");
    s =deq_head_ith(q,index); 
    printf("%s\n",s);
  }
  else if (r == 1)
  {
    printf("*****iTH Tail *****\n");
    s =deq_tail_ith(q, index); 
    printf("%s\n",s);
  }
  else {
    printf("An invalid option was entered for r \n");
    return ; 
  }
   
 
}


// //static void run_test(Deq q, int ht){
  
//   char *t1 = "test1 ";
//   char *t2 = "test2 ";
//   char *t3 = "test3 "; 
//   char *t4 = "test4 ";
//   char *t5 = "test5 ";
//   char *t6 = "test6 ";
//   char *t7 = "test7 "; 

//   if (ht == 1){
//     printf("*****PUT H *****\n");
//     deq_head_put(q, t1);
//     deq_head_put(q, t2);
//     deq_head_put(q, t3); 
//     deq_head_put(q, t4);
//     deq_head_put(q, t5);
//     deq_head_put(q, t6);
//     deq_head_put(q, t7);
//   }
//   else if (ht == 2){
    
//    printf("*****PUT T *****\n");
//     deq_tail_put(q, t1);
//     deq_tail_put(q, t2);
//     deq_tail_put(q, t3); 
//     deq_tail_put(q, t4);
//     deq_tail_put(q, t5);
//     deq_tail_put(q, t6);
//     deq_tail_put(q, t7);

//   }
//   else if (ht == 3){
//     //insert nodes 
//     deq_tail_put(q, t1);
//     deq_tail_put(q, t2);
//     deq_tail_put(q, t3); 
//     deq_tail_put(q, t4);
//     deq_tail_put(q, t5);
//     deq_tail_put(q, t6);
//     deq_tail_put(q, t7);

//    deq_head_get(q); 
//   }
//   else if (ht == 4){
//     //insert nodes 
//     deq_tail_put(q, t1);
//     deq_tail_put(q, t2);
//     deq_tail_put(q, t3); 
//     deq_tail_put(q, t4);
//     deq_tail_put(q, t5);
//     deq_tail_put(q, t6);
//     deq_tail_put(q, t7);

//     deq_tail_get(q);
//   }
//   else{
//     printf("Incorrect input, enter 1 to run head_put, enter 2 to run tail_put");
//   }
// }




// static void run_test(Deq q, int putH, int putT){
//   run_he_put(q); 

  
// }




int main() {
  Deq q=deq_new();

 // run_test(q,5);
  //run_ith(q,0, 0, 2);

  deq_del(q,0);
  return 0;

}
