/**
 * CMSC 212, 2008 Fall, Project #5
 * Public Test #6, public06.c
 * 
 * Ensures reset() sets size to 0.
 *
 * Link with list.o table implementation.
 */

#include <malloc.h>
#include <mcheck.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

static void memory_leak_check();
static void test_function();
static int compare_ints(const void *a, const void *b);

int main() {
  memory_leak_check();
  return 0;
}

static void memory_leak_check() {
  unsigned int memory_used;

  mcheck_pedantic(NULL);
  memory_used= mallinfo().uordblks;
  test_function();
  memory_used= mallinfo().uordblks - memory_used;

  if (memory_used != 0)
    printf("Memory leak detected (%d bytes)\n", memory_used);
  else printf("No memory leak detected.\n");
}

static void test_function() {
  int keys[]= {1, 2, 3, 4, 5, 6, 7};
  int i;
  int sz;
  Table t;
  
  t= create(compare_ints, NULL, compare_ints, NULL);
  for (i= 0; i < sizeof(keys) / sizeof(*keys); i++)
    insert(&t, (void *) (long) keys[i], (void *) (long) 42);
  reset(&t);
  sz= size(t);
  if (sz != 0)
    printf("Incorrect size (reported size = %d)\n", sz);
  clear(&t);
}

static int compare_ints(const void *a, const void *b) {
  if (a == b)
    return 0;
  if ((int) (long) a < (int) (long) b)
    return -1;
  else return 1;
}
