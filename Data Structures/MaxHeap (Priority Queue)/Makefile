CC := g++
CFLAGS := -Wall -Werror -g
targets := test
objs := MaxHeap.o

all: $(targets)

test: $(objs) MaxHeap_Test.cpp
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(targets) $(objs)