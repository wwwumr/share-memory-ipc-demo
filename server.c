#include "comm.h"

#define SERVER_SIZE 4096

int write_data(char *src, msg_queue *dst) {

    while ( dst->flag ) {}

    strcpy(dst->data, src);
    dst->flag = 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("argc isn' t 2\n");
        return 0;
    }

    int shmid = createShm(SERVER_SIZE);

    msg_queue *addr = (msg_queue *)shmat(shmid, NULL, 0);
    if (addr < 0) {
        perror("shmat");
        return -1;
    }

    char *info = argv[1];
    write_data(info, addr);

    shmdt(addr);
    return 0;
} 