CC= gcc
CFLAGS= -g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)

LIBS= -ldl $(OPTLIBS)
PREFIX?= /usr/local

SOURCES= $(wildcard src/**/*.c src/*.c)
OBJECTS= $(pathsubst %.c, %.o, $(SOURCES))

TEST_SRC= $(wildcard tests/*_test.c)
TESTS= $(pathsubst %.c, %, $(TEST_SRC))

TARGET= lib/libYOURLIBRARY.a
SO_TARGET= $(pathsubst %.a, %.so, $(TARGET))

#The Target Build
all: $(TARGET) $(SO_TARGET) TESTS

dev: CFLAGS= -g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS+= -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

DEPS= dbg.h ex22.h

clean:
	rm -f functions

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

main_ex22: main_ex22.o ex22.o
	$(CC) main_ex22.o ex22.o -o main_ex22 $(CFLAGS) -I.
