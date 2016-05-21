OPT_FLAGS = -O3
#OPT_FLAGS = -O0 -g3 -D_DEBUG
COMMON_FLAGS = -fbuiltin $(OPT_FLAGS)  -Wall
CPPFLAGS= $(COMMON_FLAGS) 
CFLAGS =  $(COMMON_FLAGS)
LDFLAGS = 

all:
	$(CC) $(CFLAGS) mandelbrot.c $(LDFLAGS) -o mandelbrot

.PHONY : clean
clean :
	rm -rf ./mandelbrot

