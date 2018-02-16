#######################################################
# makefile for compiling and running drawCircle program
# hprakash@iu.edu, hitenderprakash@gmail.com
#######################################################

COMPILER= g++ 
CFLAG= -std=c++11
# "make" command will only compile the code
all:
	@$(COMPILER) drawCircle.cpp -o drawCircle.out $(CFLAG)

# "make run" command will compile and run the code
run:
	@$(COMPILER) drawCircle.cpp -o drawCircle.out $(CFLAG)
	@ ./drawCircle.out 

# "make clean" will remove the executable. Redirection used to supress error on console	
clean:
	@rm -rf *.out


