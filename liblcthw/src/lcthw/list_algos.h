#ifndef lcthw_List_algos_h
#define lcthw_List_algos_h

#include <list.h>

int bubble_sort(List *list);
void node_swap(List *list);

void merge_sort(List *list);
void merge_split(List *list);
List *merge_list(List *left, List *right);
int already_sorted(List *list);

#endif
