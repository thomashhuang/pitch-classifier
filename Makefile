EXE = pitch_classifier
TEST = test

MAIN_FILE = src/main.cpp

CPP_FILES +=$(wildcard src/*.cpp)

OBJS += $(src/CPP_FILES:.cpp=.o)

TEST_FILES += $(filter-out $(MAIN_FILE), $(CPP_FILES))
TEST_FILES += $(wildcard tests/*.cpp)

TEST_OBJS = $(TEST_FILES:.cpp=.o)

RM = rm -f

CXX = g++
CXXFLAGS = -std=c++11 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = g++
LDFLAGS = 

all : $(EXE)

$(EXE) : $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(EXE)

$(TEST): $(TEST_OBJS)
	$(LD) $(LDFLAGS) $(TEST_OBJS) -o $(TEST)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) $(OBJS) $(EXE_OBJ) $(EXE) $(TEST_OBJS)
	rm -f tests/*.o
	rm test
