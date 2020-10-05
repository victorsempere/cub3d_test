#include "parser.h"

int main(int argc, char **argv) {
    char *cub_file;
    const char *error;
    t_maze maze;

    (void)argc;
    cub_file = argv[1];
    init_maze(&maze);
    error = read_cub_file(cub_file, &maze);
    if (error)
        printf("Error: %s\n", error);
    else 
        printf("Read the maze!\n");
    release_maze(&maze);
    return (0);
}