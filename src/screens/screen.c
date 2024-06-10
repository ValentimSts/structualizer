#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <raylib.h>

#include "screen.h"

// retrieve the names of all sub directories of the ../strcuts directory
// and store them in the given array
char** get_struct_names(char* structs_dir)
{
    DIR* dir = opendir(structs_dir);
    if (dir == NULL) return NULL;

    int starting_size = 5;
    char** names = (char**) malloc(starting_size * sizeof(char*));
    for (int i = 0; i < starting_size; i++) {
        names[i] = NULL;
    }
    int struct_count = 0;

    struct dirent* entry;
    while((entry = readdir(dir)) != NULL) {
        if (struct_count == starting_size) {
            starting_size *= 2;
            names = (char**) realloc(names, starting_size * sizeof(char*));
            for (int i = struct_count; i < starting_size; i++) {
                names[i] = NULL;
            }
        }

        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            names[struct_count] = (char*) malloc(strlen(entry->d_name) + 1);
            if (names[struct_count] == NULL) return NULL;
            strcpy(names[struct_count], entry->d_name);
            struct_count++;
        }
    }

    closedir(dir);

    return names;
}