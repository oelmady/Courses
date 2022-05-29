# variables
CXX: g++
CXXFLAGS: -Wall -Wextra 

# Makefile rules for compilation
pointClient.o: pointClient.cpp point.h point.cpp
	${CXX} ${CXXFLAGS} -c pointClient.cpp

point.o: point.cpp point.h
	${CXX} ${CXXFLAGS} -c point.cpp

# Makefile rules for linking


# phony target
clean: 
	rm -f $@ *.o