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
        if (c <= 0x07 || c > 0xff) {
            state = 1;
            break;            
        }
    }
    fclose(p);
    return state;
}

// word filter
int ifword(char c) {
    if (c == 0x5f || (c >= 0x30 && c <= 0x39) || \
    (c >= 0x41 && c <= 0x5a) || (c >= 0x61 && c <= 0x7a))
        return 1;
    else
        return 0; 
}

// read file and write it in database
void readfile(char *path) {
    FILE *p = NULL;
    HashNode* HashTable[512];
    int count = 0;
    char c;
    int index = 0;
    char word[512];
    // make hash table
    p = fopen(path, "r");
    InitHash(HashTable);
    // 1 means in world, 0 means not
    int state = 0;
    while ((c = fgetc(p)) != EOF) {
        // if not in word
        if (ifword(c) == 0 && state == 0)
            continue;
        // if word start
        else if (ifword(c) == 1 && state == 0) {
            state = 1;
            word[index++] = c;
        }
        // if in word
        else if (ifword(c) == 1 && state == 1) {
            word[index++] = c;
        }
        // if word end
        else if (ifword(c) == 0 && state == 1) {
            word[index++] = '\0';
            state = 0;
            count += InsertHash(HashTable, word);
            memset(word, 0, 512);
            index = 0;
        }
    }
    // lock and write it in database
    pthread_mutex_lock(&path_mutex);
    fprintf(fp, "%s\n%d\n", path, count);
    SaveHash(HashTable, fp);
    pthread_mutex_unlock(&path_mutex);
    fclose(p);
}

// get text file in a dir
void getTextFiles(char *path) {

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
            getTextFiles(newpath);
        }
    }
    closedir(dp);
}

void* MakeIndex(void *arg) {
    char *path = NULL;
    pthread_mutex_lock(&path_mutex);
    while ((path = DeQueue(&fileQueue)) != NULL) {
        pthread_mutex_unlock(&path_mutex);
        readfile(path);
        pthread_mutex_lock(&path_mutex);
    }
    pthread_mutex_unlock(&path_mutex);
    pthread_exit(NULL);
}

// main function
int main(int argc, char **argv) {

    // usage
    if (argv[1] == NULL) {
        printf("Usage: ./make_index [path]\n");
        exit(1);;
    }
    // calculate time
    double timeuse;
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // using Multi - threaded programming method
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
    getTextFiles(path);
    
    // for debug, to print the paths in queue
    // PrintQueue(&fileQueue);
    
    // the database header
    fprintf(fp, "%d\n", fileQueue.count);

    // indexed search
    for (thread_count = 0; thread_count < THREAD_NUM; thread_count++)
        res = pthread_create(&thread[thread_count], NULL, MakeIndex, NULL);

    for (thread_count = THREAD_NUM - 1; thread_count >= 0; thread_count--)
        pthread_join(thread[thread_count], &thread_result);

    fclose(fp);

    // get the time used
    gettimeofday(&end, NULL);
    timeuse = end.tv_sec - start.tv_sec + (end.tv_usec -start.tv_usec) / 1e6;
    printf("Done. Used %.6fs\n", timeuse);
    printf("Data saved to .index.dat\n");

    return 0;
}