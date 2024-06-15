#include <stdio.h>
#include <stdlib.h>

#include "tree_map.h"
#include "../struct.h"


// ---------------------------------------------------------------
// Struct interface implementation
// ---------------------------------------------------------------

static void draw_struct();
static void draw_struct_stats();
static void struct_insert(data* d);
static void struct_update(data* d);
static void struct_remove(data* d);

static void draw_struct()
{
    printf("Drawing tree map...\n");
}

static void draw_struct_stats()
{
    printf("Drawing tree map statistics...\n");
}

static void struct_insert(data* d)
{
    printf("Inserting data into tree map...\n");
    print_data(d);
}

static void struct_update(data* d)
{
    printf("Updating data in tree map...\n");
    print_data(d);
}

static void struct_remove(data* d)
{
    printf("Removing data from tree map...\n");
    print_data(d);
}

const StructVtable TREE_MAP_VTABLE[] = {
    {draw_struct, draw_struct_stats, struct_insert, struct_update, struct_remove}
};

// ---------------------------------------------------------------