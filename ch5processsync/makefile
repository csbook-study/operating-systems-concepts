.PHONY:clean ALL

CC=gcc
CFLAGS=-Wall
LIBS=-pthread -lrt

MAIN_PATH=./

main=main

#$(main):$(MAIN_PATH)/.o 
#  $(CC) $^ $(LIBS) -o $@

all:pthreads_scsschedule pthreads_posixschedule

pthreads_scsschedule:$(MAIN_PATH)/pthreads_scsschedule.o 
	$(CC) $^ $(LIBS) -o $@

pthreads_posixschedule:$(MAIN_PATH)/pthreads_posixschedule.o 
	$(CC) $^ $(LIBS) -o $@

%.o:%.c
	$(CC) -c $< -o $@ $(CPPFLAGS) $(CFLAGS)

clean:
	-rm -rf *.o $(main) pthreads_scsschedule pthreads_posixschedule

format:
  $(shell clang-format -style=google -i *.c)