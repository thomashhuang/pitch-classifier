EXE = pitch_classifier
TEST = test

MAIN_FILE = src/main.cpp

CPP_FILES +=$(wildcard src/*.cpp)

OBJS += $(CPP_FILES:.cpp=.o)

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
	echo ",mlbam_pitch_name,start_speed,spin,pfx_x,pfx_z,x0,z0" >> data/reader_test_data.csv
	echo "0,FF,0.0,1.0,2.0,3.0,4.0,5.0" >> data/reader_test_data.csv
	echo "1,SI,10.0,11.0,12.0,13.0,14.0,15.0" >> data/reader_test_data.csv
	echo "2,SL,20.0,21.0,22.0,23.0,24.0,25.0" >> data/reader_test_data.csv
	echo "3,CH,30.0,31.0,32.0,33.0,34.0,35.0" >> data/reader_test_data.csv
	$(LD) $(LDFLAGS) $(TEST_OBJS) -o $(TEST)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) $(OBJS) $(EXE_OBJ) $(EXE) $(TEST_OBJS)
	rm -f data/reader_test_data.csv
	rm -f tests/*.o
	rm -f test
