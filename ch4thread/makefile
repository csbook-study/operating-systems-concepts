.PHONY:clean ALL

CC=gcc
CFLAGS=-Wall
LIBS=-pthread -lrt

MAIN_PATH=./

main=main

#$(main):$(MAIN_PATH)/.o 
#  $(CC) $^ $(LIBS) -o $@

all:pthreads_sum 

pthreads_sum:$(MAIN_PATH)/pthreads_sum.o 
	$(CC) $^ $(LIBS) -o $@

%.o:%.c
	$(CC) -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

clean:
	-rm -rf *.o $(main) pthreads_sum

format:
  $(shell clang-format -style=google -i *.c)