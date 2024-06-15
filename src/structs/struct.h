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
    void (*draw_struct)(void);
    void (*draw_struct_stats)(void);
    
    void (*struct_insert)(data* d);
    void (*struct_update)(data* d);
    void (*struct_remove)(data* d);
} StructVtable;

typedef struct Struct {
    const char* name;
    const StructVtable* vtable;
} Struct;

// TODO: add more data structures.
extern const StructVtable HASH_MAP_VTABLE[], TREE_MAP_VTABLE[]; 


/**
 * @brief Draws the representation of the provided data
 * structure.
 * 
 * @param self The data structure to be drawn.
 */
static inline void struct_draw_struct(Struct* self)
{
    self->vtable->draw_struct();
}

/**
 * @brief Draws the statistics of the provided data
 * structure.
 * 
 * @param self The data structure to be drawn. 
 */
static inline void struct_draw_struct_stats(const Struct* self)
{
    self->vtable->draw_struct_stats();
}

/**
 * @brief Inserts the given data into the provided data
 * structure.
 * 
 * @param self The data structure.
 * @param d The data to be inserted.
 */
static inline void struct_struct_insert(Struct* self, data* d)
{
    self->vtable->struct_insert(d);
}

/**
 * @brief Updates the given data in the provided data
 * structure.
 * 
 * @param self The data structure.
 * @param d The data to be updated.
 */
static inline void struct_struct_update(Struct* self, data* d)
{
    self->vtable->struct_update(d);
}

/**
 * @brief Removes the given data from the provided data
 * structure.
 * 
 * @param self The data structure.
 * @param d The data to be removed.
 */
static inline void struct_struct_remove(Struct* self, data* d)
{
    self->vtable->struct_remove(d);
}


/**
 * @brief Creates an array of Structs with the given names.
 * 
 * @param struct_names The names of the structs to be created.
 * @param struct_count The number of structs to be created.
 * @return An array of Structs.
 */
Struct** create_structs(char** struct_names, int struct_count);

#endif // _STRUCT_H_