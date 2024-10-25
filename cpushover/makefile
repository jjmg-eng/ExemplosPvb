CC = g++
CURLFLAGS = $(shell curl-config --libs)
CFLAGS = -c -Wall -DCPSH_APPLICATION -fpermissive -I /opt/pvb/rllib/lib/
LDFLAGS = $(CURLFLAGS) -lm -lrllib
SOURCES = cpushover.c cJSON.c 
HEADERS = $(SOURCES:.c=.h)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = cpushover

.PHONY: default debug clean

default: $(SOURCES) $(HEADERS) $(EXECUTABLE) 

debug: CFLAGS += -g
debug: default

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $< $(CFLAGS) -o $@ 

clean:
	rm -f *.o $(EXECUTABLE)
