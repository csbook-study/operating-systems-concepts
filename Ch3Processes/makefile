.PHONY:clean ALL

CC=gcc
CFLAGS=-Wall
LIBS=-pthread

MAIN_PATH=./

main=main

#$(main):$(MAIN_PATH)/processes_fork.o 
#  $(CC) $^ $(LIBS) -o $@

processes_fork:$(MAIN_PATH)/processes_fork.o 
	$(CC) $^ $(LIBS) -o $@

%.o:%.c
	$(CC) -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

clean:
	-rm -rf *.o $(main) processes_fork

format:
  $(shell clang-format -style=google -i *.c)