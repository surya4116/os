#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    int src = open(argv[1], O_RDONLY);
    int dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buffer[1024];
    ssize_t n;

    while ((n = read(src, buffer, sizeof(buffer))) > 0)
        write(dest, buffer, n);

    close(src);
    close(dest);

    printf("File copied successfully!\n");
    return 0;
}
