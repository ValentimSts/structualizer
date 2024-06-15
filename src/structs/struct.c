#include "struct.h"

typedef enum StructType {
    HASH_MAP,
    TREE_MAP,
    UNDEFINED
} StructType;

char const* StructNames[] = {
    "hash-map",
    "tree-map"
};

static StructType get_struct_type(char const* struct_name);

Struct** create_structs(char** struct_names, int* struct_count)
{
    Struct** structs = (Struct**) malloc(sizeof(Struct*) * (*struct_count));
    for (int i = 0; i < (*struct_count); i++) {
        structs[i] = NULL;
    }

    // It may happen that some of the provided struct names have not 
    // been defined, and so we need filter these out.
    char** final_struct_names = (char**) malloc(sizeof(char*) * (*struct_count));
    int final_struct_count = 0;

    for (int i = 0; i < (*struct_count); i++) {
        final_struct_names[i] = (char*) malloc(sizeof(char) * (strlen(struct_names[i]) + 1));
    }

    for (int i = 0; i < (*struct_count); i++) {
        StructType type = get_struct_type(struct_names[i]);

        if (type != UNDEFINED) {
            strcpy(final_struct_names[final_struct_count], struct_names[i]);
            final_struct_count++;

            switch (type) {
                case HASH_MAP:
                    structs[i] = (Struct*) malloc(sizeof(Struct));
                    structs[i]->name = "Hash Map";
                    structs[i]->vtable = NULL; // TODO: temporary solution.
                    break;

                case TREE_MAP:
                    structs[i] = (Struct*) malloc(sizeof(Struct));
                    structs[i]->name = "Tree Map";
                    structs[i]->vtable = NULL; // TODO: temporary solution.
                    break;

                case UNDEFINED:
                    break;
            }
        }
    }

    if (final_struct_count != (*struct_count)) {
        for (int i = 0; i < (*struct_count); i++) {
            free(struct_names[i]);
        }
        free(struct_names);

        struct_names = final_struct_names;
        *struct_count = final_struct_count;
    }
    else {
        for (int i = 0; i < (*struct_count); i++) {
            free(final_struct_names[i]);
        }
        free(final_struct_names);
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
    for (size_t i = 0; i < sizeof(StructNames) / sizeof(char*); i++) {
        if (strcmp(struct_name, StructNames[i]) == 0) {
            return i;
        }
    }

    return UNDEFINED;
}
