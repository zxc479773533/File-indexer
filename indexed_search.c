#include "head.h"

void IndexedSearch(char *str) {
    int file_num;
    int word_num;
    int count;
    int len = strlen(str);
    int path_len;
    int status;
    char *p = NULL;
    char path[256];
    char line[256];
    // read file nums
    fgets(line, 256, fp);
    file_num = atoi(line);
    printf("File Numes:%d\n", file_num);
    // search
    while ((p = fgets(path, 256, fp)) != NULL) {
        status = 0;
        path_len = strlen(path);
        fgets(line, 256, fp);
        word_num = atoi(line);
        for (count = 0; count < word_num; count++) {
            fgets(line, 256, fp);
            if (status == 0 && strncmp(line, str, len) == 0 && line[len] == ':') {
                path[path_len - 1] = '\0';
                printf("%s", path);
                printf("%s", line + len);
                memset(line, 0, 256);
                status = 1;
            }
        }
        memset(path, 0, 256);
    }
}

int main(int argc, char **argv) {
    
    // calculate time
    double timeuse;
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // load file
    fp = fopen(argv[1], "r");
    printf("Searching in %s\n", argv[1]);

    // search in file
    IndexedSearch(argv[2]);

    // get the time used
    gettimeofday(&end, NULL);
    timeuse = end.tv_sec - start.tv_sec + (end.tv_usec -start.tv_usec) / 1e6;
    printf("Done. Used %.6fs\n", timeuse);

    return 0;
}