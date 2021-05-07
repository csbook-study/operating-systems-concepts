.PHONY:clean ALL

CC=gcc
CFLAGS=-Wall
LIBS=-pthread -lrt

MAIN_PATH=./

main=main

#$(main):$(MAIN_PATH)/processes_fork.o 
#  $(CC) $^ $(LIBS) -o $@

all:processes_fork ipc_posixshmp ipc_posixshmc

processes_fork:$(MAIN_PATH)/processes_fork.o 
	$(CC) $^ $(LIBS) -o $@

ipc_posixshmp:$(MAIN_PATH)/ipc_posixshmp.o 
	$(CC) $^ $(LIBS) -o $@
	
ipc_posixshmc:$(MAIN_PATH)/ipc_posixshmc.o 
	$(CC) $^ $(LIBS) -o $@

%.o:%.c
	$(CC) -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

clean:
	-rm -rf *.o $(main) processes_fork ipc_posixshmp ipc_posixshmc

format:
  $(shell clang-format -style=google -i *.c)