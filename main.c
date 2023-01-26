#include <stdio.h>
#include <stdlib.h>

#include "deq.h"

/**@Author: Raymundo escobedo
 * CS 452
 * Spring 2023
 */

/**
 * run test for rem
 * Deq - q
 * ht - 0 = deq_head_put, 1 = deq_tail_put
 * r - 0 = deq_head_ith, 1 = deq_tail_ith
 *
 */
// static void run_rem (Deq q,int ht, int r){
//   char *t1 = "test1 ";
//   char *t2 = "test2 ";
//   char *t3 = "test3 ";
//   char *t4 = "test4 ";
//   char *t5 = "test5 ";
//   char *t6 = "test6 ";
//   char *t7 = "test7 ";

//   if (ht == 0){
//   printf("*****PUT HEAD *****\n");

//   deq_head_put(q, t1);
//   deq_head_put(q, t2);
//   deq_head_put(q, t3);
//   deq_head_put(q, t4);
//   deq_head_put(q, t5);
//   deq_head_put(q, t6);
//   deq_head_put(q, t7);

//   }
//   else if(ht == 1 ){
//   printf("*****PUT TAIL *****\n");

//   deq_tail_put(q,t1);
//   deq_tail_put(q,t2);
//   deq_tail_put(q,t3);
//   deq_tail_put(q,t4);
//   deq_tail_put(q,t5);
//   deq_tail_put(q,t6);
//   deq_tail_put(q,t7);

//   }
//   else {
//     printf("An invalid option was entered for ht\n");
//     return ;
//   }
//   char *s=deq_str(q,0);
//   printf("%s\n",s);
//   free(s);

//   if(r == 0){
//     char *x;
//     printf("*****REM Head *****\n");
//     x =deq_head_rem(q,t2);
//     printf("%s\n",x);
//     //free(x);
//     printf("*****NEW LIST*****\n");

//     char *s=deq_str(q,0);
//     printf("%s\n",s);
//    free(s);
//   }
//   else if (r == 1)
//   {
//     char *y;
//     printf("*****REM Tail *****\n");
//     y =deq_tail_rem(q, t3);
//     printf("%s\n",y);
//     //free(y);
//     printf("*****NEW LIST*****\n");

//    char  *s=deq_str(q,0);
//     printf("%s\n",s);
//     free(s);
//   }
//   else {
//     printf("An invalid option was entered for r \n");
//     return ;
//   }
//   printf("*****Test complete*****\n\n");

// }

// /**
//  * run test for ith
//  * Deq - q
//  * ht - 0 = deq_head_put, 1 = deq_tail_put
//  * r - 0 = deq_head_ith, 1 = deq_tail_ith
//  * index - index to remove
// */
// static void run_ith(Deq q,int ht, int r, int index){
//   char *t1 = "test1 ";
//   char *t2 = "test2 ";
//   char *t3 = "test3 ";
//   char *t4 = "test4 ";
//   char *t5 = "test5 ";
//   char *t6 = "test6 ";
//   char *t7 = "test7 ";

//   if (ht == 0){
//   printf("*****PUT HEAD *****\n");

//   deq_head_put(q, t1);
//   deq_head_put(q, t2);
//   deq_head_put(q, t3);
//   deq_head_put(q, t4);
//   deq_head_put(q, t5);
//   deq_head_put(q, t6);
//   deq_head_put(q, t7);

//   }
//   else if(ht == 1 ){
//   printf("*****PUT TAIL *****\n");

//   deq_tail_put(q,t1);
//   deq_tail_put(q,t2);
//   deq_tail_put(q,t3);
//   deq_tail_put(q,t4);
//   deq_tail_put(q,t5);
//   deq_tail_put(q,t6);
//   deq_tail_put(q,t7);

//   }else {
//     printf("An invalid option was entered for ht\n");
//     return ;
//   }

//   char *s=deq_str(q,0);
//   printf("%s\n",s);
//   free(s);
//   printf("Index to remove: %d \n", index);

//   if(r == 0){
//     printf("*****iTH Head *****\n");
//     s =deq_head_ith(q,index);
//     printf("%s\n",s);
//   }
//   else if (r == 1)
//   {
//     printf("*****iTH Tail *****\n");
//     s =deq_tail_ith(q, index);
//     printf("%s\n",s);
//   }
//   else {
//     printf("An invalid option was entered for r \n");
//     return ;
//   }
//   printf("*****Test complete*****\n");

// }

// /**
//  * run_test - test put get
//  * t - test to run ( 1 = head put, 2 - tail put, 3 = tail put/get head,
//  *    4 - tail put/get tail )
// */

// static void run_test(Deq q, int t){

//   char *t1 = "test1 ";
//   char *t2 = "test2 ";
//   char *t3 = "test3 ";
//   char *t4 = "test4 ";
//   char *t5 = "test5 ";
//   char *t6 = "test6 ";
//   char *t7 = "test7 ";

//   if (t == 1){
//     printf("*****PUT H *****\n");
//     deq_head_put(q, t1);
//     deq_head_put(q, t2);
//     deq_head_put(q, t3);
//     deq_head_put(q, t4);
//     deq_head_put(q, t5);
//     deq_head_put(q, t6);
//     deq_head_put(q, t7);
//   }
//   else if (t == 2){

//    printf("*****PUT T *****\n");
//     deq_tail_put(q, t1);
//     deq_tail_put(q, t2);
//     deq_tail_put(q, t3);
//     deq_tail_put(q, t4);
//     deq_tail_put(q, t5);
//     deq_tail_put(q, t6);
//     deq_tail_put(q, t7);

//   }
//   else if (t == 3){
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
//   else if (t == 4){
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

int main()
{
  Deq q = deq_new();

  // run_test(q,5);
  // run_ith(q,0, 0, 2);
  // run_rem(q,0,1);
  // run_rem(q,1,0);

  deq_del(q, 0);
  return 0;
}
