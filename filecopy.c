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

// int copyBuffer(int fileIn, int fileOut, void* buffer, size_t bufferSize) {
//     for (;;) {
//         void *pos;

//         ssize_t bytesToWrite = read(fileIn, buffer, bufferSize);
        
//         pos = buffer;
//         while (bytesToWrite > 0) {
//             ssize_t bytesWritten = write(fileOut, pos, bytesToWrite);
//             bytesToWrite -= bytesWritten;
//             pos += bytesWritten;
//         }
//     }
    
//     return 0;
// }

int main(int argc, char const *argv[]) {
    int input_file, output_file, read_file;
    char input_filename[128], output_filename[128];
    char buffer[BUFF_MAX];

    printf("Welcome to the File Copy Program by %s\n", NAME);
    printf("Enter the name of the file to copy from:\n");
    scanf("%s", input_filename);
    printf("Enter the name of the file to copy to:\n");
    scanf("%s", output_filename);

    // input_file = open(input_filename, 0);
    // output_file = open(output_filename, 1);

    // printf("File Copy Successful, %d bytes copied\n", bytes_written);

    input_file = open(input_filename, O_RDONLY);
    if (input_file < 0) {
        printf("open for read of %s failed\n", input_filename);
        exit(EXIT_FAILURE);
    }

    output_file = open(output_filename, O_WRONLY | O_CREAT, S_IWUSR);
    if (output_file < 0) {
        printf("open for write of %s failed\n", output_filename);
        close(input_file);
        exit(EXIT_FAILURE);
    }

    while ()
    read_file = read(input_file, buffer, sizeof(buffer));
    write(output_file, buffer, read_file);

    printf("files open correct\n");

    close(input_file);
    close(output_file);
    
    return 0;
}
