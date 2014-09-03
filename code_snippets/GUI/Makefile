#
# This is a common Makefile for code examples from the book
# "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
#

#
# Usage:
#     make        - Build all examples
#     make clean  - Clean all examples
#

INCLUDES = -I"$(FLTK)"
LIBS     = -lstdc++
CXXFLAGS = $(INCLUDES) -Wall -time -O3 -DNDEBUG
LIBFLAGS =  
AR       = ar

.SUFFIXES: .cpp .o

# Create a list of source files.
SOURCES  = $(shell ls *.cpp)
# Create a list of object files from the source file lists.
OBJECTS = ${SOURCES:.cpp=.o}     
# Create a list of targets.
TARGETS = libbookgui.a

# Build all targets by default
all: 	$(TARGETS)

%.a: $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)

# A rule to build .o file out of a .cpp file
%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# A rule to clean all the intermediates and targets
clean:	
	rm -rf $(TARGETS) $(OBJECTS) *.out *.stackdump
