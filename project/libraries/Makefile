#
# This makefile build a shared library from all static libraries
#

TARGET 		= 	libzappy.so

LIBS 		=	libmy/libmy.a \
			liblist/liblist.a \
			libsocket/libsocket.a \
			libzappy/libzappy.a

SOURCES		=	$(shell find ./libzappy/sources -name "*.c")

OBJECTS		=	$(SOURCES:.c=.o)

CFLAGS 		= 	-fPIC
LDFLAGS 	= 	-shared -L libmy -lmy -L liblist/ -llist -L libsocket/ -lsocket -lssl

$(TARGET)	: 	$(LIBS)
			$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

libmy/libmy.a:
			make -C libmy/

liblist/liblist.a:
			make -C liblist/

libsocket/libsocket.a:
			make -C libsocket/


libzappy/libzappy.a:
			make -C libzappy/

fclean		:
			$(RM) $(TARGET)

re		: 	fclean $(TARGET)


