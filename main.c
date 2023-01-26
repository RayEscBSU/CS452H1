#include <stdio.h>
#include <stdlib.h>

#include "deq.h"


// static void run_ith(Deq q){
//   char *t1 = "test1 ";
//   char *t2 = "test2 ";
//   char *t3 = "test3 "; 
//   char *t4 = "test4 ";
//   char *t5 = "test5 ";
//   char *t6 = "test6 ";
//   char *t7 = "test7 "; 

//   printf("*****PUT H *****\n");
//   // deq_head_put(q, t1);
//   // deq_head_put(q, t2);
//   // deq_head_put(q, t3);
//   // deq_head_put(q, t4);
//   // deq_head_put(q, t5);
//   // deq_head_put(q, t6);
//   // deq_head_put(q, t7);

//   //Testing put from tail
//   deq_tail_put(q,t1); 
//   deq_tail_put(q,t2);
//   deq_tail_put(q,t3);
//   deq_tail_put(q,t4); 
//   deq_tail_put(q,t5);
//   deq_tail_put(q,t6);
//  deq_tail_put(q,t7);

//   char *s=deq_str(q,0);
//   printf("%s\n",s);
//   free(s);

//   //s =deq_head_ith(q,2); 
//   //s =deq_tail_ith(q,1); 

//   printf("%s\n",s);
 
// }


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
//   else if (ht == 5){
//   }
//   else if (ht == 6){
//     // ith

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
 // run_ith(q);

 char *test = "test1";
  char *test2 = "test2";
  char *test3 = "test3";
  char *test4 = "test4";

 
  printf("*****PUT H *****\n");
  deq_head_put(q, test);
  deq_head_put(q, test2);
  deq_head_put(q, test3);
  deq_head_put(q, test4);
  //Testing put from tail
  // deq_tail_put(q,test); 
  // deq_tail_put(q,test2);
  // deq_tail_put(q,test3);

  char *s=deq_str(q,0);
  printf("%s\n",s);
  free(s);

  //s =deq_head_ith(q,0);  //works
 // s =deq_tail_ith(q,0); 

  printf("%s\n",s);


  deq_del(q,0);
  return 0;

}
