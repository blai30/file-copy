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

int copyBuffer(int fileIn, int fileOut, void* buffer, size_t bufferSize) {
    for (;;) {
        void *pos;

        ssize_t bytesToWrite = read(fileIn, buffer, bufferSize);
        
        pos = buffer;
        while (bytesToWrite > 0) {
            ssize_t bytesWritten = write(fileOut, pos, bytesToWrite);
            bytesToWrite -= bytesWritten;
            pos += bytesWritten;
        }
    }
    
    return 0;
}

int main(int argc, char const *argv[]) {
    int inputFile, outputFile;
    char inputFilename[128];
    char outputFilename[128];
    size_t bytesCopied;
    int bytesWritten;

    printf("Welcome to the File Copy Program by %s\n", NAME);
    printf("Enter the name of the file to copy from:\n");
    scanf("%s", inputFilename);
    printf("Enter the name of the file to copy to:\n");
    scanf("%s", outputFilename);

    inputFile = open(inputFilename, 0);
    outputFile = open(outputFilename, 1);

    printf("File Copy Successful, %d bytes copied\n", bytesWritten);

    return 0;
}
