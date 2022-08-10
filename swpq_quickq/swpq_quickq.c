/**************************************************************
*
* Software implementation of Rios' Quick-Q
* This code implmeents the logic of a single node in isolation
*
*************************************************************/

#include <stdint.h>
#include <stdio.h>
#include "swpq_quickq.h"

Element_t qarray[QQ_CAPACITY];

static uint8_t empty, full;
uint32_t last;

void init() {
  empty = 1;
  full = 0;
  for (int i=0; i < QQ_CAPACITY; i++) qarray[i] = QQ_EMPTY;
}

void enqueue(Element_t e) {
  // search for first element >e
  int i;
  Element_t ea;
  for (i=0; i < QQ_CAPACITY; i++) {
    ea = qarray[i];
    if (ea.key > e.key) break;  // location to write
  }
  qarray[i] = e;
  e = ea;
  i++;
  while (e.key != QQ_KEYINF && i < QQ_CAPACITY) {
    ea = qarray[i];
    qarray[i] = e;
    e = ea;
    i++;
  }
  if (i==QQ_CAPACITY) full = 1;
  else full = 0;
  empty = 0;
}

Element_t dequeue() {
  Element_t e, rv;
  rv = qarray[0];
  int i;
  for (i=0; i < QQ_CAPACITY-1; i++) {
    e = qarray[i+1];
    qarray[i] = e;
    if (e.key == QQ_KEYINF) break;
  }
  if (i == QQ_CAPACITY-1) qarray[i] = QQ_EMPTY;
  if (i == 0) empty = 1;
  else empty = 0;
  full = 0;
  return rv;
}

void print_pq() {
  printf("[");
  for (int i=0; i < QQ_CAPACITY; i++) {
    printf(" %d", qarray[i].key);
  }
  printf("] ");
  if (full) printf(" full");
  if (empty) printf(" empty");
  printf("\n");
}

void enqueue_key(uint16_t k) {
  Element_t kv = {k, k};
  enqueue(kv);
}

int main() {
  init();
  print_pq();
  enqueue_key(18);
  print_pq();
  enqueue_key(3);
  print_pq();
  enqueue_key(2);
  print_pq();
  enqueue_key(33);
  print_pq();
  dequeue();
  print_pq();
  dequeue();
  print_pq();
  dequeue();
  print_pq();
  dequeue();
  print_pq();
  enqueue_key(300);
  enqueue_key(22);
  enqueue_key(680);
  enqueue_key(12);
  print_pq();
}
