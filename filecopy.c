#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//You may also add more include directives as well.

// THIS VALUE CANNOT BE CHANGED.
// You should use this value when creating your buffer.
// And also to limit the amount of bytes each read CAN do.
#define BUFF_MAX 21
// ABOVE VALUE CANNOT BE CHANGED //

#define NAME "Brian Lai"

int main(int argc, char const *argv[]) {
    char inputFile[128];
    char outputFile[128];
    int bytesCopied;

    printf("Welcome to the File Copy Program by %s\n", NAME);
    printf("Enter the name of the file to copy from:\n");
    scanf("%s", inputFile);
    printf("Enter the name of the file to copy to:\n");
    scanf("%s", outputFile);

    open(inputFile);
    bytesCopied = read(inputFile);
    write(outputFile);

    printf("File Copy Successful, %d bytes copied", bytesCopied);

    return 0;
}
