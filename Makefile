CC = gcc
CFLAGS = -fPIC -Wall -Wextra -O2 `pkg-config --cflags seed`
LDFLAGS = -shared `pkg-config --libs seed`
RM = rm -f
TARGET = libseed_Maleo.so

SOURCES = seed-maleo.c
OBJS = $(SOURCES:.c=.o)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(SOURCES:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)
.PHONY: clean

clean:
	$(RM) $(TARGET) $(OBJS) $(SOURCES:.c=.d)
