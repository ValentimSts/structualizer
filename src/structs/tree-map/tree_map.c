#include <stdio.h>
#include <stdlib.h>

#include "tree_map.h"
#include "../data_structure.h"


// ---------------------------------------------------------------
// Struct interface implementation
// ---------------------------------------------------------------

static void draw();
static void draw_stats();

static void draw()
{
    printf("Drawing tree map...\n");
}

static void draw_stats()
{
    printf("Drawing tree map statistics...\n");
}


const DataStructureVtable TREE_MAP_VTABLE[] = {
    {draw, draw_stats}
};

// ---------------------------------------------------------------