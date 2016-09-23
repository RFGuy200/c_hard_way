#ifndef _ex22_h
#define _ex22_h

//sets external varaible available to all other functions
extern int THE_SIZE;

//gets and sets internal static variable in ex22.c
int get_age();

void set_age(int get_age);

//updates a static variable that's inside update_ratio
double update_ratio(double ratio);

void print_size();

#endif
