#ifndef algos_h
#define algos_h

#include <string.h>
#include <list.h>

int cmp_func(ListNode *node1, ListNode *node2);
void bubble_sort(List *list);

void merge_sort(List *list);
void merge(List *left, List *right);

void upside_merge(List *list);

void insert_sort(List *list);

void shell_sort(int *array, int length);

#endif
