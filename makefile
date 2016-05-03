CXX = g++
CXXFLAGS = -Wall -Werror --std=c++11 -Wpedantic -lpthread -lstdc++
LINKFLAGS = --std=c++11 -lpthread -lstdc++

lib_SOURCES = \
		Monitor.h \
		BufferA.h \
		BufferB.h \
		BufferC.h \
		Entities.h

lib_OBJECTS=$(lib_SOURCES:.cpp=.o)

SOURCES = \
		Monitor.cpp \
		BufferA.cpp \
		BufferB.cpp \
		BufferC.cpp \
		Entities.cpp \
		main.cpp

OBJECTS=$(SOURCES:.cpp=.o)

main: $(OBJECTS)
	$(CXX) -o $@ $^ $(LINKFLAGS)

%.o : %.cpp
	$(CXX) -c -o $@  $< $(CXXFLAGS)

clean:
	rm -f *.o
	rm main

sclean:
	rm -f *.o

.PHONY:
	clean, sclean
