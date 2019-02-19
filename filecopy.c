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
    int input_file, output_file;
    char input_filename[128], output_filename[128];
    char buffer[BUFF_MAX];
    ssize_t total_bytes_copied = 0;

    printf("Welcome to the File Copy Program by %s\n", NAME);
    printf("Enter the name of the file to copy from:\n");
    scanf("%s", input_filename);
    printf("Enter the name of the file to copy to:\n");
    scanf("%s", output_filename);

    // Open source file for read only
    input_file = open(input_filename, O_RDONLY);
    if (input_file < 0) {
        printf("Open for read failed: %s\n", input_filename);
        exit(EXIT_FAILURE);
    }

    // Write only | create if file does not exist | overwrite if file exists
    output_file = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR);
    if (output_file < 0) {
        printf("Open for write failed: %s\n", output_filename);
        close(input_file);
        exit(EXIT_FAILURE);
    }

    // Copy contents with buffer limit of BUFF_MAX until entire file is copied
    for (;;) {
        ssize_t bytes_read = read(input_file, buffer, BUFF_MAX);
        if (bytes_read <= 0) {
            break;
        }

        ssize_t bytes_written = write(output_file, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            printf("bytes_written != bytes_read failed\n");
            printf("bytes_read: %zd\n", bytes_read);
            printf("bytes_written: %zd\n", bytes_written);
            close(input_file);
            close(output_file);
            exit(EXIT_FAILURE);
        }

        total_bytes_copied += bytes_written;
    }

    printf("File Copy Successful, %zd bytes copied\n", total_bytes_copied);

    close(input_file);
    close(output_file);
    
    return 0;
}
