/**************************************************************
*
*  Data structures for software priority queue in C
*
*************************************************************/

#include <stdint.h>

typedef struct element {
  int32_t key;
  int32_t value;
} Element_t;

const unsigned int HEAP_CAPACITY = 15;  // should be power of 2 - 1

void print_heap();

unsigned int parent(unsigned int i);

unsigned int left(unsigned int i);

unsigned int right(unsigned int i);

void insert(Element_t e);

Element_t min();

Element_t extract_min();
