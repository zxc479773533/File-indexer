#ifndef __HEAD_H_
#define __HEAD_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include "mylibqueue.h"
#include "mylibhash.h"

// the num of threads
#define THREAD_NUM 4

// the fir struct
typedef struct dirent INDEX;
/*
Here is the defination in dirent.h

struct dirent {
    ino_t          d_ino;
    off_t          d_off;
    unsigned short d_reclen;
    unsigned char  d_type;
    char           d_name[256];
};
*/

// the dabase file
FILE *fp;

// the datastructure to save file path and text
LinkQueue fileQueue;

// the mutex lock
pthread_mutex_t path_mutex = PTHREAD_MUTEX_INITIALIZER;


#endif // !__HEAD_H_