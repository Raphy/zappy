TARGET=lib.so

CFLAGS=-Wall -g -fPIC
LDFLAGS=-shared

SRC=lib.c
OBJ=$(SRC:.c=.o)

all: $(TARGET)
	
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(TARGET)

re: fclean all
