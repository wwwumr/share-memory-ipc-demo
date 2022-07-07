#include "comm.h"

#define CLIENT_SIZE 4096

int main() {
    int shmid = getShm(CLIENT_SIZE);
    char *addr = shmat(shmid, NULL, 0);

    while (1) {
        printf("%s\n", addr);
    }

    shmdt(addr);
    return 0;    
}