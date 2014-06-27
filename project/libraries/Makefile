#
# This makefile build a shared library from all static libraries
#

TARGET = libzappy.so

LIBS =	liblist/liblist.a \
		libsocket/libsocket.a \
		libzappy/libzappy.a

SOURCES		=	$(shell find ./libzappy/sources -name "*.c")

OBJECTS		=	$(SOURCES:.c=.o)

CFLAGS = -fPIC 
LDFLAGS = -shared -L liblist/ -llist -L libsocket/ -lsocket

$(TARGET): $(LIBS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

liblist/liblist.a:
	make -C liblist/

libsocket/libsocket.a:
	make -C libsocket/

libzappy/libzappy.a:
	make -C libzappy/

fclean:
	$(RM) $(TARGET)

re: fclean $(TARGET)


