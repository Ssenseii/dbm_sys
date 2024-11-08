/*

This is a very simple SQL Compiler and can also double as a command center.

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

/* Enums */

typedef enum
{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum
{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum
{
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

/* Structs */

typedef struct
{
    StatementType type;
} Statement;

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

/* Checking Meta Command */
/*
this will take the input buffer and check if its a certain command, or something else. it will return a meta command.
*/

MetaCommandResult do_meta_command(InputBuffer *input_buffer)
{
    if (strcmp(input_buffer->buffer, ".exit") == 0)
    {
        close_input_buffer(input_buffer);
        exit(EXIT_SUCCESS);
    }
    else
    {
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

/* Prepare Statement */
/*
    this will check whether the buffer has certain keyword. and prepare the result of the checking.
*/
PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *statement)
{
    if (strncmp(input_buffer->buffer, "insert", 6) == 0)
    {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    if (strcmp(input_buffer->buffer, "select") == 0)
    {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNIZED_STATEMENT;
}

/* Execute the statement*/
/*
depending on the statement: it'll execute a certain function.
*/
void execute_statement(Statement *statement)
{
    switch (statement->type)
    {
    case (STATEMENT_INSERT):
        printf("This is where we would do an insert.\n");
        break;
    case (STATEMENT_SELECT):
        printf("This is where we would do a select.\n");
        break;
    }
}

/* Main Function */

int main(int argc, char *argv[])
{

    // create a new input buffer
    InputBuffer *input_buffer = new_input_buffer();

    while (1)
    {
        print_prompt();
        read_input(input_buffer);

        /* Check whether its a keyword */
        if (input_buffer->buffer[0] == '.')
        {
            switch (do_meta_command(input_buffer))
            {
            case (META_COMMAND_SUCCESS):
                continue;

            case (META_COMMAND_UNRECOGNIZED_COMMAND):
                printf("unrecognized command '%s'\n", input_buffer->buffer);
                continue;
            }
        }

        Statement statement;
        /* Check Whether it's a valid statement */
        switch (prepare_statement(input_buffer, &statement))
        {
        case (PREPARE_SUCCESS):
            break;
        case (PREPARE_UNRECOGNIZED_STATEMENT):
            printf("Unrecognized keyword at start of '%s'\n", input_buffer->buffer);
            continue;
        }

        execute_statement(&statement);
        printf("Executed.\n");
    }
}
