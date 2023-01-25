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
  struct Node *temp = r->ht[Head]; 
  int c =0; 
  while(temp){
    if(c == i ){
      return temp->data; 
    }
    temp = temp->np[Tail];
    c++; 
  }

  printf("*****Node Does Not Exist*****\n");
  return NULL; 
}

/**
 * Get - Returns node data at the end of the list depnding on direction
 * When called from head nodes at the far right is returned
 * when called from tail node at the far left is returned 
 * Reutrns node data 
*/
static Data get(Rep r, End e)         {
  if (r->len == 0 ){
    printf("*****Empy list*****\n");
    return 0; 
  }
  int h = Tail; 
  int t = Head; 
  if(e == Tail){ //put starting at tail, revers H and T values
    h  = Head; 
    t = Tail; 
  }
  
  struct Node *oT= r->ht[t]; 
  struct Node *nT = oT->np[h]; 

  oT->np[h] = NULL; 
  nT->np[t] = NULL; 

  r->ht[t] = nT; 
  r-> len--; 
  Data ret = oT->data; 
  free(oT); 
  return ret;

}


static Data rem(Rep r, End e, Data d) {
  struct Node *curr = r->ht[Head]; 
  struct Node *tempH; //store values of head and node from curr
  struct Node *tempT; 


  while(curr){
    if(curr->data == d){
      //rem begining 
      if(curr == r->ht[Head]){
        return get(r, Head); 
      }
      else if(curr == r->ht[Tail]){ // rem from end 
        return get(r,Tail);
      }
      else {
      //rem middle 
      tempH = curr->np[Head];
      tempT = curr->np[Tail];

      tempH->np[Tail] = NULL; 
      tempT->np[Head] = NULL;
      
      tempH->np[Tail] = tempT; 
      tempT->np[Head] = tempH; 

      curr->np[Head] = NULL; 
      curr->np[Tail] = NULL; 

      r->len --;
      Data ret = curr->data; 
      free(curr);  
      return ret; 
      }
    }
    else
    {
      printf("next node\n");
      curr = curr->np[Tail];
    }
  }

  printf("*****Node Does Not Exist*****\n");
  return NULL; 
    
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
