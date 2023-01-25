#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "deq.h"
#include "error.h"

// indices and size of array of node pointers
typedef enum {Head,Tail,Ends} End;

typedef struct Node {
  struct Node *np[Ends];		// next/prev neighbors
  Data data;
} *Node;

typedef struct {
  Node ht[Ends];			// head/tail nodes
  int len;
} *Rep;

static Rep rep(Deq q) {
  if (!q) ERROR("zero pointer");
  return (Rep)q;
}

/**
 * Put - adds a node to the end of the list
 * When called from head nodes is added left to right
 * when called from tail nodes are added right to left
*/
static void put(Rep r, End e, Data d) {
    struct Node *newN = (struct Node*) malloc(sizeof (struct Node) + sizeof(d));
    newN -> data = d;
    int h = Head; 
    int t = Tail; 

    if(e == Tail){ //put starting at tail, revers H and T values
      h  = Tail; 
      t = Head; 
    }

    if ( r->len == 0){  // if list is empty
      r->ht[Head] = newN; //set new node to h and t
      r->ht[Tail] = newN;
      newN -> np[1] = NULL;
      newN -> np[0] = NULL;
    }
    else{
    //     list is not empty
      struct Node *temp= r->ht[t];
      temp->np[t] = newN;
      newN -> np[h] = temp;
      newN -> np[t] = NULL;
      r->ht[t] = newN;  
    }

    r->len = +1;
    return ;
}

static Data ith(Rep r, End e, int i)  {
    return 0;
}
static Data get(Rep r, End e)         {
  struct Node *t = r->ht[Tail]; 
  struct Node *nT = t->np[Head]; 

  t->np[Head] = NULL; 
  nT->np[Tail] = NULL; 

  r->ht[Tail] = nT; 
  r-> len--; 
  free(t); 
  return nT->data;

}
static Data rem(Rep r, End e, Data d) {
    return 0;
}

extern Deq deq_new() {
  Rep r=(Rep)malloc(sizeof(*r));
  if (!r) ERROR("malloc() failed");
  r->ht[Head]=0;
  r->ht[Tail]=0;
  r->len=0;
  return r;
}


extern int deq_len(Deq q) { return rep(q)->len; }

extern void deq_head_put(Deq q, Data d) {        put(rep(q),Head,d); }
extern Data deq_head_get(Deq q)         { return get(rep(q),Head); }
extern Data deq_head_ith(Deq q, int i)  { return ith(rep(q),Head,i); }
extern Data deq_head_rem(Deq q, Data d) { return rem(rep(q),Head,d); }

extern void deq_tail_put(Deq q, Data d) {        put(rep(q),Tail,d); }
extern Data deq_tail_get(Deq q)         { return get(rep(q),Tail); }
extern Data deq_tail_ith(Deq q, int i)  { return ith(rep(q),Tail,i); }
extern Data deq_tail_rem(Deq q, Data d) { return rem(rep(q),Tail,d); }

extern void deq_map(Deq q, DeqMapF f) {
  for (Node n=rep(q)->ht[Head]; n; n=n->np[Tail])
    f(n->data);
}

extern void deq_del(Deq q, DeqMapF f) {
  if (f) deq_map(q,f);
  Node curr=rep(q)->ht[Head];
  while (curr) {
    Node next=curr->np[Tail];
    free(curr);
    curr=next;
  }
  free(q);
}

extern Str deq_str(Deq q, DeqStrF f) {
  char *s=strdup("");
  for (Node n=rep(q)->ht[Head]; n; n=n->np[Tail]) {
    char *d=f ? f(n->data) : n->data;
    char *t; asprintf(&t,"%s%s%s",s,(*s ? " " : ""),d);
    free(s); s=t;
    if (f) free(d);
  }
  return s;
}
