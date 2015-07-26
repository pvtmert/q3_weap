CC=clang
CFLAGS=-c
LDFLAGS=
OBJECT=weapon.o
TARGET=weaponfix
SRC=weap.c

all: $(TARGET)

clean:
	rm -f $(TARGET) $(OBJECT) fix_c4_mp comp_fix_c4_mp

$(TARGET): $(OBJECT)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJECT)

$(OBJECT): $(SRC)
	$(CC) $(CFLAGS) -o $(OBJECT) $(SRC)

test: $(TARGET)
	./$(TARGET) c4_mp -fix_c4_mp
	diff c4_mp comp_fix_c4_mp
	echo "$$?"
