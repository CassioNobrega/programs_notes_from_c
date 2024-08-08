#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 65552


int main ()
{
        char 
        *buffer[BUFFER_SIZE],
        *filename = "README.md";

        FILE *file_1 = fopen(filename, "r");

        if (!file_1)
                return 1;

        size_t read_size = fread(buffer, 1, BUFFER_SIZE - 1, file_1);
        buffer[read_size] = '\0';

        printf("%s\n", buffer);
        printf("READ SIZE: %d\n", read_size);
        printf("%d\n", file_1->_flags);
        printf("%d\n", (FILE *)file_1->_flags);

        return 0;
        
};
