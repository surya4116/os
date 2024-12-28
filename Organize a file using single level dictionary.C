#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void organize_files(const char *dir) {
    DIR *d = opendir(dir);
    if (!d) return;

    struct dirent *entry;
    while ((entry = readdir(d))) {
        // Skip hidden files (those starting with a dot)
        if (entry->d_name[0] == '.') continue;

        char path[1024], ext[100], folder[1024];
        snprintf(path, sizeof(path), "%s/%s", dir, entry->d_name);

        // Check if it's a regular file
        struct stat st;
        if (stat(path, &st) == 0 && S_ISREG(st.st_mode)) {
            char *dot = strrchr(entry->d_name, '.'); // Get the file extension
            if (dot) {
                snprintf(ext, sizeof(ext), "%s", dot + 1); // Get extension
                snprintf(folder, sizeof(folder), "%s/%s", dir, ext); // Create folder path

                // Create folder if it doesn't exist
                struct stat folder_stat;
                if (stat(folder, &folder_stat) != 0) {
                    mkdir(folder, 0777); // Create the directory with read/write/execute permissions
                }

                // Move the file to the new folder
                char new_path[1024];
                snprintf(new_path, sizeof(new_path), "%s/%s", folder, entry->d_name);
                rename(path, new_path); // Move the file
            }
        }
    }

    closedir(d);
}

int main() {
    char dir[1024];
    printf("Enter directory: ");
    scanf("%s", dir);
    organize_files(dir);
    return 0;
}
