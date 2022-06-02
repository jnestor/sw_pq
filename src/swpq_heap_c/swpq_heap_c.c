/**************************************************************
*
* C implementation of a heap as described in
* "Introduction to Algorithms" by Cormen, Leiserson, & Rivest
*
**************************************************************/

#include "swpq_heap_c.h"
#include <stdio.h>

static Element_t heap[HEAP_CAPACITY+1];
static unsigned int heap_size;

unsigned int parent(unsigned int i) {
  if (i > 1) return i / 2;
  else {
    printf("parent() error: can't get parent of root!\n");
    return i;
  }
}

unsigned int left(unsigned int i) {
  unsigned int l = 2*i;
  if (l <= heap_size) return l;
  else {
    printf("left() error: left(%d) larger than heap)\n", i);
    return i;
  }
}

unsigned int right(unsigned int i) {
  unsigned int r = 2*i + 1;
  if (r <= heap_size) return r;
  else {
    printf("left() error: right(%d) larger than heap)\n", i);
    return i;
  }
}

void print_heap() {

}

void heapify(unsigned int i) {

}

void insert(Element_t e) {

}


Element_t min()  {
  return heap[1];
}

Element_t extract_min() {

}

int main() {
  // add code to test the queue architecture
  Element_t e;
  e.key = 5;
  e.value = 50;
  insert(e);
  print_heap();
  e.key = 500;
  e.value = 50000;
  insert(e);
  print_heap();
  e.key = 1;
  e.value = 10;
  insert(e);
  print_heap();

}
