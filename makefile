#######################################################
# makefile for compiling and running drawCircle program
# hprakash@iu.edu, hitenderprakash@gmail.com
#######################################################
CC=g++ -std=c++11
OPTS=
INCS=
LIBS=

%.o: %.cpp
	$(CC) $(OPTS) $(INCS) -c $<

drawCircle: main.o RasterImp.o
	$(CC) $(OPTS) $(INCS) -o $@ $^  $(LIBS)

run: drawCircle
	@./drawCircle

clean:
	rm -f drawCircle *.o
