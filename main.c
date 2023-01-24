#include <stdio.h>
#include <stdlib.h>

#include "deq.h"

int main() {
  Deq q=deq_new();

  
  char *test = "test 1";
  char *test2 = "test 2";
  char *test3 = "test 3";

  //testing add from head
  // deq_head_put(q, test);
  // deq_head_put(q, test2);
  // deq_head_put(q, test3);
  
  //Testing add from tail
  deq_tail_put(q,test); 
  printf("2\n");
  deq_tail_put(q,test2);
  printf("3\n");
  deq_tail_put(q,test3);


  char *s=deq_str(q,0);
  printf("%s\n",s);
  free(s);

  deq_del(q,0);
  return 0;

}
