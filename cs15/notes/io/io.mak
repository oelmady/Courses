CXX: g++
CXXFLAGS: -Wall -Wextra
INCLUDES = $(shell echo *.h)

%.o: %.cpp ${INCLUDES}
${CXX} ${CXXFLAGS} -c $<
