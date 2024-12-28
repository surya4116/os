#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_NAME 256

void organize_files(const char *dir) {
    DIR *d = opendir(dir);
    if (!d) return;
    struct dirent *entry;
    while ((entry = readdir(d))) {
        if (entry->d_name[0] == '.') continue;
        char path[MAX_NAME], ext[MAX_NAME], folder[MAX_NAME];
        snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);
        struct stat st;
        if (stat(path, &st) == 0 && S_ISREG(st.st_mode)) {
            char *dot = strrchr(entry->d_name, '.');
            if (dot) {
                snprintf(ext, sizeof(ext), "%s", dot + 1);
                snprintf(folder, sizeof(folder), "%s/%s", dir, ext);
                mkdir(folder, 0777);  // Create folder for the extension
                snprintf(path, sizeof(path), "%s/%s/%s", dir, ext, entry->d_name);
                rename(path, path);   // Move file to the new folder
            }
        }
    }
    closedir(d);
}

int main() {
    char dir[MAX_NAME];
    printf("Enter directory: ");
    scanf("%s", dir);
    organize_files(dir);
    return 0;
}
