#include <stdlib.h>
#include <string.h>
#include "errors-finder.h"
#include "diagnostics.h"

/**
 * Defines constants for indexing `argv`.
 */
enum Args
{
    ARG_DICT_FILE_PATH = 1,
    ARG_INPUT_FILE_PATH,
    ARG_MAX_HEIGHT
};

/**
 * Finds errors in the input file using the specified dictionary.
 */
static void process_file(const char *dict_file_path, const char *in_file_path, size_t max_height)
{
    FILE *dict_file, *input_file;

    dict_file = fopen(dict_file_path, "r");
    ASSERT(dict_file, "Unable to open the dictionary file", process_file);

    input_file = fopen(in_file_path, "r");
    ASSERT(input_file, "Unable to open the input file", process_file);

    find_errors(dict_file, input_file, max_height);

    ASSERT(!fclose(input_file), "Unable to close the input file", process_file);
    ASSERT(!fclose(dict_file), "Unable to close the dictionary file", process_file);
}

/**
 * Entry point.
 */
int main(int argc, char *argv[])
{
    const char *dict_path;
    const char *in_path;
    int max_height;

    ASSERT(argc > ARG_DICT_FILE_PATH, "Wrong number of arguments (dictionary file path not found)", main);
    ASSERT(argc > ARG_INPUT_FILE_PATH, "Wrong number of arguments (input file path not found)", main);
    ASSERT(argc > ARG_MAX_HEIGHT, "Wrong number of arguments (maximum skip list height not found)", main);

    dict_path = argv[ARG_DICT_FILE_PATH];
    in_path = argv[ARG_INPUT_FILE_PATH];
    max_height = atoi(argv[ARG_MAX_HEIGHT]);

    process_file(dict_path, in_path, max_height);

    return EXIT_SUCCESS;
}