#include "comm.h"

#define CLIENT_SIZE 4096

int main() {
    int shmid = getShm(CLIENT_SIZE);
    msg_queue *addr = (msg_queue *)shmat(shmid, NULL, 0);

    int running = 1;

    char msg[MSG_SIZE];

    addr->flag = 0;
    addr->data[0] = '\0';

    while (running) {
        if (addr->flag) {
            strcpy(msg, addr->data);
            printf("receve msg: %s\n", msg);
            addr->flag = 0;
        }
    }

    shmdt(addr);
    return 0;    
}