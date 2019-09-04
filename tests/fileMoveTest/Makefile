#- MM scan source file and makes depends for user made h files
#mbouncingBall

TARGET = test2
#TARGET = sharedPtrTest
#SOURCES += $(wildcards *.cpp)
SOURCES = $(TARGET).cpp ../../imp/folderScan.cpp ../../imp/fileMover.cpp ../../imp/blibrary.cpp  ../../imp/csvReader.cpp 

OBJECTS = $(SOURCES:.cpp=.o)
INC_DIR = ../../inc ../../../include usr/include/boost_1_40_0
LIB_DIR = .
# compiler and linker flags
CC		 =g++
#

LDLIBS = -ldl -export-dynamic -lboost_system -lboost_filesystem 
CPPFLAGS = $(addprefix -I,$(INC_DIR))
CFLAGS   = -g -pedantic -ansi -Wall -Werror -DDEBUG
CXXFLAGS += $(CFLAGS) -std=c++11
LDFLAGS  = -g -pthread -lboost_thread
LDFLAGS +=  $(addprefix -L,$(LIB_DIR))
	
.PHONY: all clean run

all:	$(TARGET) 

$(TARGET): $(OBJECTS)

include depends 

depends: $(SOURCES)
	$(CC) -MM $(CPPFLAGS) $^ > depends

clean:
	rm -f $(TARGET) $(OBJECTS) depends *.gch

run:
	./$(TARGET) -v
