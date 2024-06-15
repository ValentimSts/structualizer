#include "struct.h"

typedef enum StructType {
    HASH_MAP
} StructType;

char const* StructNames[] = {
    "hash-map"
};

static StructType get_struct_type(char const* struct_name);

Struct** create_structs(char** struct_names, int struct_count)
{
    Struct** structs = (Struct**) malloc(sizeof(Struct*) * struct_count);
    for (int i = 0; i < struct_count; i++) {
        structs[i] = NULL;
    }

    for (int i = 0; i < struct_count; i++) {
        StructType type = get_struct_type(struct_names[i]);
        if (type == -1) {
            continue;
        }

        switch (type) {
            case HASH_MAP:
                structs[i] = (Struct*) malloc(sizeof(Struct));
                structs[i]->name = "hash-map";
                structs[i]->vtable = HASH_MAP_VTABLE;
                break;
        }
    }

    return structs;
}

/**
 * @brief Get the struct type object from the provided struct
 * name.
 * 
 * @param struct_name The name of the struct.
 * @return The StructType of the provided struct name. 
 */
static StructType get_struct_type(char const* struct_name)
{
    for (int i = 0; i < sizeof(StructNames) / sizeof(char*); i++) {
        if (strcmp(struct_name, StructNames[i]) == 0) {
            return i;
        }
    }

    return -1;
}
