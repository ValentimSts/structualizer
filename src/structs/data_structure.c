#include "data_structure.h"

typedef enum DataStructureType {
    HASH_MAP,
    TREE_MAP,
    UNDEFINED
} DataStructureType;

char const* DataStructureNames[] = {
    "hash-map",
    "tree-map"
};

static DataStructureType get_data_structure_type(char const* data_structure_name);

DataStructure** create_data_structures(char** data_structure_names, int* data_structure_count)
{
    DataStructure** data_structures = (DataStructure**) malloc(sizeof(DataStructure*) * (*data_structure_count));
    for (int i = 0; i < (*data_structure_count); i++) {
        data_structures[i] = NULL;
    }

    // It may happen that some of the provided struct names have not 
    // been defined / are invalid, and so we need filter them out.
    char** final_data_structure_names = (char**) malloc(sizeof(char*) * (*data_structure_count));
    int final_data_structure_count = 0;

    for (int i = 0; i < (*data_structure_count); i++) {
        final_data_structure_names[i] = (char*) malloc(sizeof(char) * (strlen(data_structure_names[i]) + 1));
    }

    for (int i = 0; i < (*data_structure_count); i++) {
        DataStructureType type = get_data_structure_type(data_structure_names[i]);

        if (type != UNDEFINED) {
            strcpy(final_data_structure_names[final_data_structure_count], data_structure_names[i]);
            final_data_structure_count++;

            switch (type) {
                case HASH_MAP:
                    data_structures[i] = (DataStructure*) malloc(sizeof(DataStructure));
                    data_structures[i]->name = "Hash Map";
                    data_structures[i]->vtable = HASH_MAP_VTABLE;
                    break;

                case TREE_MAP:
                    data_structures[i] = (DataStructure*) malloc(sizeof(DataStructure));
                    data_structures[i]->name = "Tree Map";
                    data_structures[i]->vtable = TREE_MAP_VTABLE;
                    break;

                case UNDEFINED:
                    break;
            }
        }
    }

    if (final_data_structure_count != (*data_structure_count)) {
        for (int i = 0; i < (*data_structure_count); i++) {
            free(data_structure_names[i]);
        }
        free(data_structure_names);

        data_structure_names = final_data_structure_names;
        *data_structure_count = final_data_structure_count;
    }
    else {
        for (int i = 0; i < (*data_structure_count); i++) {
            free(final_data_structure_names[i]);
        }
        free(final_data_structure_names);
    }

    return data_structures;
}

/**
 * @brief Get the struct type object from the provided struct
 * name.
 * 
 * @param data_structure_name The name of the data structure.
 * @return The DataStructureType of the provided struct name. 
 */
static DataStructureType get_data_structure_type(char const* data_structure_name)
{
    for (size_t i = 0; i < sizeof(DataStructureNames) / sizeof(char*); i++) {
        if (strcmp(data_structure_name, DataStructureNames[i]) == 0) {
            return i;
        }
    }

    return UNDEFINED;
}
