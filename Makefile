CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -IInclude
TARGET   := multipurpose-cli-tool
SRCS     := Source/Main.cpp Source/Utility.cpp
OBJS     := $(SRCS:.cpp=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

Source/%.o: Source/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
