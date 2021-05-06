.PHONY:clean ALL

CC=gcc
CFLAGS=-Wall
LIBS=-pthread

MAIN_PATH=./

main=main

#$(main):$(MAIN_PATH)/syscall_cpfile.o 
#  $(CC) $^ $(LIBS) -o $@

syscall_cpfile:$(MAIN_PATH)/syscall_cpfile.o 
#  $(CC) $^ $(LIBS) -o $@

%.o:%.c
	$(CC) -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

clean:
	-rm -rf *.o $(main) syscall_cpfile

format:
  $(shell clang-format -style=google -i *.c)