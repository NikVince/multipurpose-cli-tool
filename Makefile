CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -IInclude
TARGET   := multipurpose-cli-tool
TEST_TARGET := base-converter-tests
SRCS     := Source/Main.cpp Source/Utility.cpp Source/BaseConverter.cpp
OBJS     := $(SRCS:.cpp=.o)
TEST_SRCS := Tests/BaseConverterTest.cpp Source/BaseConverter.cpp
TEST_OBJS := Tests/BaseConverterTest.o Source/BaseConverter.o

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

Source/%.o: Source/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Tests/%.o: Tests/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

test: $(TEST_TARGET)
	./$(TEST_TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)
