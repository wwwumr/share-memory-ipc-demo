all: server client

client: client.c comm.c
	gcc client.c comm.h comm.c -o client

server: server.c comm.c
	gcc server.c comm.h comm.c -o server

.PHONY: clean
clean:
	rm -f client server
