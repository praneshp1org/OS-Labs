// custom ls command
#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    const char *dir_path = argc > 1 ? argv[1] : "."; // Directory path, defaulting to current directory if not provided

    DIR *dir;
    struct dirent *entry;

    dir = opendir(dir_path);
    if (dir == NULL) {
        printf("Cannot open directory: %s\n", dir_path);
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
