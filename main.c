#include <stdio.h>
#include <stdlib.h>

#include "deq.h"

int main() {
  Deq q=deq_new();

  //testing
  char *test = "testing que";
  deq_head_put(q, test);

  char *test2 = "testing que 2";
  deq_head_put(q, test2);

  char *test3 = "testing que 3";
  deq_head_put(q, test3);

  char *s=deq_str(q,0);
  printf("%s\n",s);
  free(s);

  deq_del(q,0);
  return 0;

}
