#include "head.h"

// judge whether a file is a Binary file
// here I simply judge it by the 0x0's existence
// Although this way is not perfect, the accuracy is enough
int isBinfile(char *path) {
    FILE *p = fopen(path, "r");
    short c;
    int state = 0;
    while ((c = fgetc(p)) != EOF) {
        // judge binart file
        if (c <= 0x07 || c > 0xff)
            state = 1;
    }
    fclose(p);
    return state;
}

// get text file in a dir
void getTextFile(char *path) {

    INDEX *ep = NULL;
    DIR *dp = opendir(path);

    while ((ep = readdir(dp)) != NULL) {
        if (strncmp(ep->d_name, ".", 1) == 0)
            continue;
        // d_type == 8 means normal file
        if (ep->d_type == 8) {
            char *fullpath = (char *)malloc(sizeof(path) + sizeof(ep->d_name) + 2);
            sprintf(fullpath, "%s/%s", path, ep->d_name);
            if (isBinfile(fullpath) == 1)
                continue;
            EnQueue(&fileQueue, fullpath);
        }
        // d_type == 4 means dir
        else if (ep->d_type == 4) {
            char newpath[1000];
            memset(newpath, 0, sizeof(newpath));
            strcpy(newpath, path);
            if (strcmp(path, "/") != 0)
                strcat(newpath, "/");
            strcat(newpath, ep->d_name);
            getTextFile(newpath);
        }
    }
    closedir(dp);
}

// read file and write it in database
void readfile(char *path) {
    FILE *p = NULL;
    struct stat fileInfo;
    int res;
    p = fopen(path, "r");
    if ((res = stat(path, &fileInfo)) == 0) {
        char *txt = (char *)malloc(fileInfo.st_size + strlen(path) + 3);
        strcpy(txt, path);
        strcpy(txt + strlen(path), "\n");
        fread(txt + strlen(path) + 1, fileInfo.st_size, 1, p);
        strcpy(txt + fileInfo.st_size + strlen(path) + 1, "\n\n");
        fwrite(txt, fileInfo.st_size + strlen(path) + 3, 1, fp);
        free(txt);
    }
    fclose(p);
}

// a thread to make index
void *makeIndex(void *arg) {
    char *str = NULL;    
    // lock it
    pthread_mutex_lock(&path_mutex);
    while ((str = DeQueue(&fileQueue)) != NULL) {
        pthread_mutex_unlock(&path_mutex);
        // unlock and read the file
        readfile(str);
        // lock when get a str from queue
        pthread_mutex_lock(&path_mutex);
    }
    pthread_mutex_unlock(&path_mutex);
    pthread_exit(NULL);
}

// main function
int main(int argc, char **argv) {

    // calculate time
    double timeuse;
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // using multiply-threading
    pthread_t thread[THREAD_NUM];
    void *thread_result;
    int thread_count;
    int res;

    // get the path of this file
    char path[1000];
    memset(path, 0, sizeof(path));
    fp = fopen(".index.dat", "w+");
    chdir(argv[1]);
    getcwd(path, sizeof(path));
    InitQueue(&fileQueue);

    // get the file path
    getTextFile(path);

    // for debug, to print the paths in queue
    // PrintQueue(&fileQueue);

    // make index
    for (thread_count = 0; thread_count < THREAD_NUM; thread_count++)
        res = pthread_create(&thread[thread_count], NULL, makeIndex, NULL);

    for (thread_count = THREAD_NUM - 1; thread_count >= 0; thread_count--)
        pthread_join(thread[thread_count], &thread_result);

    fclose(fp);

    // get the time used
    gettimeofday(&end, NULL);
    timeuse = end.tv_sec - start.tv_sec + (end.tv_usec -start.tv_usec) / 1e6;
    printf("Done. Used %.6fs\n", timeuse);

    return 0;
}