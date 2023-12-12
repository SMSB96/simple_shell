#include "shell.h"

/**
 * free_2d_array - Free memory allocated for a 2D array.
 *
 * @array: The 2D array to free.
 */
void free_2d_array(char **array)
{
    int i;

    if (!array)
        return;

    for (i = 0; array[i]; i++)
    {
        free(array[i]);
        array[i] = NULL;
    }

    free(array);
    array = NULL;
}

