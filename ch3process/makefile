.PHONY:clean ALL

CC=gcc
CFLAGS=-Wall
LIBS=-pthread -lrt

MAIN_PATH=./

main=main

#$(main):$(MAIN_PATH)/processes_fork.o 
#  $(CC) $^ $(LIBS) -o $@

all:processes_fork ipc_posixshmp ipc_posixshmc ipc_pipe ipc_fifop ipc_fifoc processes_forkalgo ipc_tcpc ipc_tcps processes_daemon

processes_fork:$(MAIN_PATH)/processes_fork.o 
	$(CC) $^ $(LIBS) -o $@

ipc_posixshmp:$(MAIN_PATH)/ipc_posixshmp.o 
	$(CC) $^ $(LIBS) -o $@
	
ipc_posixshmc:$(MAIN_PATH)/ipc_posixshmc.o 
	$(CC) $^ $(LIBS) -o $@
	
ipc_pipe:$(MAIN_PATH)/ipc_pipe.o 
	$(CC) $^ $(LIBS) -o $@
	
ipc_fifop:$(MAIN_PATH)/ipc_fifop.o 
	$(CC) $^ $(LIBS) -o $@

ipc_fifoc:$(MAIN_PATH)/ipc_fifoc.o 
	$(CC) $^ $(LIBS) -o $@

processes_forkalgo:$(MAIN_PATH)/processes_forkalgo.o 
	$(CC) $^ $(LIBS) -o $@
	
ipc_tcpc:$(MAIN_PATH)/ipc_tcpc.o 
	$(CC) $^ $(LIBS) -o $@

ipc_tcps:$(MAIN_PATH)/ipc_tcps.o 
	$(CC) $^ $(LIBS) -o $@

processes_daemon:$(MAIN_PATH)/processes_daemon.o 
	$(CC) $^ $(LIBS) -o $@

%.o:%.c
	$(CC) -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

clean:
	-rm -rf *.o $(main) processes_fork ipc_posixshmp ipc_posixshmc ipc_pipe ipc_fifop ipc_fifoc processes_forkalgo ipc_tcpc ipc_tcps processes_daemon

format:
  $(shell clang-format -style=google -i *.c)