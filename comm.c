#include "comm.h"

int commShm(int size, int flags) {
    // key_t key = ftok(PATHNAME, PROJ_ID);
    key_t key = 0x666;
    if (key < 0) {
        perror("ftok");
        return -1;
    }

    int shmid = shmget(key, size, flags);

    if (shmid < 0) {
        perror("shmget");
        return -2;
    }

    return shmid;
}

int destroyShm(int shmid) {
    if (shmctl(shmid, IPC_RMID, NULL) < 0) {
        perror("shmid");
        return -1;
    }

    return 0;
}

int createShm(int size) {
    return commShm(size, IPC_CREAT | 0666);
}

int getShm(int size) {
    return commShm(size, IPC_CREAT);
}