/*

    Simple REPL System

*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef struct
{
    char *buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

/* Get a new input */
InputBuffer *new_input_buffer()
{
    InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

/* read a line of the input */
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void read_input(InputBuffer *input_buffer)
{
    ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    if (bytes_read <= 0)
    {
        printf("Error Reading Input");
        exit(EXIT_FAILURE);
    }

    // Ignore trailing newline
    input_buffer->input_length = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = 0;
}

void close_input_buffer(InputBuffer *input_buffer)
{
    free(input_buffer->buffer);
    free(input_buffer);
}

/* print */
void print_prompt()
{
    printf("DB > ");
}

/* Main Function */

int main(int argc, char *argv[])
{

    InputBuffer *input_buffer = new_input_buffer();

    while (1)
    {
        print_prompt();
        read_input(input_buffer);

        if (strcmp(input_buffer->buffer, ".exit") == 0)
        {
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Unrecognized command '%s'.\n", input_buffer->buffer);
        }
    }
}