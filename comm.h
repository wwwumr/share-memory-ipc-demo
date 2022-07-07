#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PATHNAME "."
#define PROJ_ID 0x666
#define MSG_SIZE 16

typedef struct msg_queue {
    int flag;
    char data[MSG_SIZE];
} msg_queue;


int createShm(int size);

int destroyShm(int shmid);

int getShm(int size);

#endif