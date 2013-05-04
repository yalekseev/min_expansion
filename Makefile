CC=g++
CFLAGS=--std=c++0x

all: sample

sample.o: sample.cpp
	$(CC) $(CFLAGS) -c $^

min_expand.o: min_expand.cpp
	$(CC) $(CFLAGS) -c $^

sample: sample.o min_expand.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	$(RM) sample

clobber: clean
	$(RM) sample.o min_expand.o
