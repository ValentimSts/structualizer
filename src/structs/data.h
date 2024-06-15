/********************************************************************
* 
*   This header file provides an interface for the generic data 
*   stored by every data structure implemented in this application.
*
********************************************************************/

#ifndef _DATA_H_
#define _DATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    char* key;
    char* value;
} data;


int hash(data* d, int upper_bound);

data* create_data(char* key, char* value);
int destroy_data(data* d);
int update_data(data* d, char* value);
int compare_data(data* d1, data* d2);
void print_data(data* d);

#endif // _DATA_H_