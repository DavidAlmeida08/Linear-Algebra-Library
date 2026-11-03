CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic
CPPFLAGS += -Ihearders

SOURCE_DIRS := src dev
SOURCES := $(wildcard $(addsuffix /*.c,$(SOURCE_DIRS)))
HEADERS := $(wildcard hearders/*.h)
OBJECTS := $(patsubst %.c,bin/%.o,$(SOURCES))
TARGET := bin/lal

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $@ $(LDLIBS)

clean:
	rm -f $(TARGET) $(OBJECTS)
