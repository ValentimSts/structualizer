/********************************************************************
* 
*   This header file provides an interface to be implemented by all
*   the data structures used in this application.
*
*   In a way it recreates the concept of polymorphism, available in
*   languages like C++ and Java, but in C.
*
********************************************************************/

#ifndef _DATA_STRUCT_H_
#define _DATA_STRUCT_H_

#include "data.h"

typedef struct DataStructureVtable {
    void (*draw)(
        int section_start_x,
        int section_start_y,
        int section_width,
        int section_height
        );

    void (*draw_stats)(
        int section_start_x,
        int section_start_y,
        int section_width,
        int section_height
        );
} DataStructureVtable;

typedef struct DataStructure {
    const char* name;
    const DataStructureVtable* vtable;

    // Raylib area delimeters.
    int data_structure_section_start_x;
    int data_structure_section_start_y;
    int data_structure_section_width;
    int data_structure_section_height;

    // Raylib action parameter.
    data* d;
} DataStructure;

// TODO: add more data structures.
extern const DataStructureVtable HASH_MAP_VTABLE[], TREE_MAP_VTABLE[]; 


static inline void set_data_structure_section_info(DataStructure* data_structure,
    int start_x, int start_y, int width, int height)
{
    data_structure->data_structure_section_start_x = start_x;
    data_structure->data_structure_section_start_y = start_y;
    data_structure->data_structure_section_width = width;
    data_structure->data_structure_section_height = height;
}

static inline void set_data_structure_data(DataStructure* data_structure, data* d)
{
    data_structure->d = d;
}

/**
 * @brief Draws the representation of the provided data
 * structure.
 * 
 * @param data_structure The data structure to be drawn.
 */
static void select_data_structure(DataStructure* data_structure)
{
    data_structure->vtable->draw(
        data_structure->data_structure_section_start_x,
        data_structure->data_structure_section_start_y, 
        data_structure->data_structure_section_width,
        data_structure->data_structure_section_height
    );

    data_structure->vtable->draw_stats(
        data_structure->data_structure_section_start_x,
        data_structure->data_structure_section_start_y,
        data_structure->data_structure_section_width,
        data_structure->data_structure_section_height
    );
}

/**
 * @brief Inserts the given data into the provided data
 * structure.
 * 
 * @param data_structure The data structure.
 * @param d The data to be inserted.
 */
static inline void insert_data_structure_data(DataStructure* data_structure, data* d)
{
    data_structure->d = d;
}

/**
 * @brief Updates the given data in the provided data
 * structure.
 * 
 * @param data_structure The data structure.
 * @param d The data to be updated.
 */
static inline void update_data_structure_data(DataStructure* data_structure, data* d)
{
    data_structure->d = d;
}

/**
 * @brief Clears any data stored in the provided data structure.
 * 
 * @param data_structure The data structure.
 */
static inline void clear_data_structure_data(DataStructure* data_structure)
{
    data_structure->d = NULL;
}


/**
 * @brief Creates an array of DataStructures with the given names.
 * 
 * @param data_structure_names The names of the data structures to be created.
 * @param data_structure_count The number of data structures to be created.
 * @return An array of DataStructures.
 */
DataStructure** create_data_structures(char** data_structure_names, int* data_structure_count);

#endif // _DATA_STRUCT_H_