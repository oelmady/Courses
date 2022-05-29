# variables
CXX: g++
CXXFLAGS: -Wall -Wextra 
# Shell function
INCLUDES = $(shell echo *.h)

# Makefile rules for compilation
%.o: %.cpp ${INCLUDES}
	${CXX} ${CXXFLAGS} -c $<

# Makefile rules for linking
pointClient: pointClient.o point.o
	${CXX} -o $@ $^

# phony target
clean: 
	rm -f $@ *.o

# Notes: 
# $@ is the file name of the target of the rule
# $< is the name of the first prerequisite
# $^ includes all prerequisites 
# % wildcard that matches names
