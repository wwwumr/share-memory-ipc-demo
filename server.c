#include "comm.h"

#define SERVER_SIZE 4096

int main() {
    int shmid = createShm(SERVER_SIZE);

    char *addr = (char *)shmat(shmid, NULL, 0);
    if (addr < 0) {
        perror("shmat");
        return -1;
    }

    char *info = "hello me!";
    int len = strlen(info);
    for (int i = 0; i < len; i++) {
        addr[i] = info[i];
    }
    addr[len] = '\0';

    shmdt(addr);
    return 0;
} 