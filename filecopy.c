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

    printf("Welcome to the File Copy Program by %s\n", NAME);
    printf("Enter the name of the file to copy from:\n");
    scanf("%s", input_filename);
    printf("Enter the name of the file to copy to:\n");
    scanf("%s", output_filename);

    input_file = open(input_filename, O_RDONLY);
    if (input_file < 0) {
        printf("open for read of %s failed\n", input_filename);
        exit(EXIT_FAILURE);
    }

    // Write only | create if file does not exist | overwrite if file exists
    output_file = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR);
    if (output_file < 0) {
        printf("open for write of %s failed\n", output_filename);
        close(input_file);
        exit(EXIT_FAILURE);
    }

    ssize_t total_bytes_copied;
    for (;;) {
        ssize_t bytes_read = read(input_file, buffer, BUFF_MAX);
        if (bytes_read <= 0) {
            break;
        }

        ssize_t bytes_written = write(output_file, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            printf("bytes_written != bytes_read");
            close(input_file);
            close(output_file);
            exit(EXIT_FAILURE);
        }
    }

    printf("files open correct\n");
    printf("bytes copied: %d", total_bytes_copied);

    close(input_file);
    close(output_file);
    
    return 0;
}
