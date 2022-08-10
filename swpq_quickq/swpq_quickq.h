/**************************************************************
*
*  Software implementation of Rios' Quick-Q
*
*************************************************************/
#ifndef SWPQ_QUICKQ
#define SWPQ_QUICKQ

#include <stdint.h>

typedef struct element {
  uint16_t key;
  uint16_t value;
} Element_t;

const unsigned int QQ_CAPACITY = 4;
const uint16_t QQ_KEYINF = 0xffff;
const Element_t QQ_EMPTY = {QQ_KEYINF,0};


void enqueue(Element_t e);

Element_t dequeue();

void print_pq();

#endif
