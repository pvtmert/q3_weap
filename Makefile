CC=clang
CFLAGS=-c
LDFLAGS=
OBJECT=weapon.o
TARGET=weaponfix
SRC=weap.c

all: $(TARGET)

$(TARGET): $(OBJECT)

$(OBJECT): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(SRC)
