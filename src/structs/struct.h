/********************************************************************
* 
*   This header file provides an interface to be implemented by all
*   the data structures used in this application.
*
*   In a way it recreates the concept of polymorphism, available in
*   languages like C++ and Java, but in C.
*
********************************************************************/

#ifndef _STRUCT_H_
#define _STRUCT_H_

#include "data.h"

typedef struct StructVtable {
    void (*draw_struct)(int section_start_x, int section_start_y,
        int section_width, int section_height);
    void (*draw_struct_stats)(int section_start_x, int section_start_y,
        int section_width, int section_height);
    
    void (*struct_insert)(data* d);
    void (*struct_update)(data* d);
    void (*struct_remove)(data* d);
} StructVtable;

typedef struct Struct {
    const char* name;
    const StructVtable* vtable;

    // Raylib area delimeters.
    int struct_section_start_x;
    int struct_section_start_y;
    int struct_section_width;
    int struct_section_height;

    // Raylib action parameter.
    data* d;
} Struct;

// TODO: add more data structures.
extern const StructVtable HASH_MAP_VTABLE[], TREE_MAP_VTABLE[]; 


static inline void struct_set_struct_section_info(Struct* self, int start_x,
    int start_y, int width, int height)
{
    self->struct_section_start_x = start_x;
    self->struct_section_start_y = start_y;
    self->struct_section_width = width;
    self->struct_section_height = height;
}

static inline void struct_set_struct_data(Struct* self, data* d)
{
    self->d = d;
}

/**
 * @brief Draws the representation of the provided data
 * structure.
 * 
 * @param self The data structure to be drawn.
 */
static void struct_struct_select(Struct* self)
{
    self->vtable->draw_struct(self->struct_section_start_x,
        self->struct_section_start_y, self->struct_section_width,
        self->struct_section_height);

    self->vtable->draw_struct_stats(self->struct_section_start_x,
        self->struct_section_start_y, self->struct_section_width,
        self->struct_section_height);
}

/**
 * @brief Inserts the given data into the provided data
 * structure.
 * 
 * @param self The data structure.
 * @param d The data to be inserted.
 */
static void struct_struct_insert(Struct* self)
{
    self->vtable->struct_insert(self->d);
}

/**
 * @brief Updates the given data in the provided data
 * structure.
 * 
 * @param self The data structure.
 * @param d The data to be updated.
 */
static inline void struct_struct_update(Struct* self)
{
    self->vtable->struct_update(self->d);
}

/**
 * @brief Removes the given data from the provided data
 * structure.
 * 
 * @param self The data structure.
 * @param d The data to be removed.
 */
static inline void struct_struct_remove(Struct* self)
{
    self->vtable->struct_remove(self->d);
}


/**
 * @brief Creates an array of Structs with the given names.
 * 
 * @param struct_names The names of the structs to be created.
 * @param struct_count The number of structs to be created.
 * @return An array of Structs.
 */
Struct** create_structs(char** struct_names, int* struct_count);

#endif // _STRUCT_H_