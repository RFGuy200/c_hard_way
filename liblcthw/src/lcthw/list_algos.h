#ifndef lcthw_List_algos_h
#define lcthw_List_algos_h

#include <list.h>

int bubble_sort(List *list);
void node_swap(List *list);

void merge_sort(List *list);
void merge_split(List *list);
void merge_list(List *left, List *right);
int already_sorted(List *list);
void bu_merge(List *list);
void bu_sort(List *list, List *temp, int i, int width);

#endif
