CC=clang
CFLAGS=-c
LDFLAGS=
OBJECT=weapon.o
TARGET=weaponfix
SRC=weap.c

all: $(TARGET)

clean:
	rm -f $(TARGET) $(OBJECT)

$(TARGET): $(OBJECT)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJECT)

$(OBJECT): $(SRC)
	$(CC) $(CFLAGS) -o $(OBJECT) $(SRC)

