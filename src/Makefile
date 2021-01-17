CC = icc
CPP = icpc
CFLAGS = -O3 -xHost
LDFLAGS=

TARGETS=example_read example_write

all: $(TARGETS)

example_read: example_read.c mmio.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

example_write: example_write.c mmio.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGETS) *.o .depend *~