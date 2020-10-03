#include "parser.h"

int main(int argc, char **argv) {
    char *cub_file;
    const char *error;
    t_maze maze;

    (void)argc;
    cub_file = argv[1];
    error = read_input(cub_file, &maze);
    if (error)
        printf("Error: %s\n", error);
    else 
        printf("Read the maze!\n");
    return (0);
}