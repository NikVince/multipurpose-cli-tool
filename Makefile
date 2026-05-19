CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -IInclude
TARGET   := multipurpose-cli-tool
BASE_TEST_TARGET := base-converter-tests
PASSWORD_TEST_TARGET := password-strength-tests
SRCS     := Source/Main.cpp Source/Utility.cpp Source/BaseConverter.cpp Source/PasswordStrength.cpp
OBJS     := $(SRCS:.cpp=.o)
BASE_TEST_OBJS := Tests/BaseConverterTest.o Source/BaseConverter.o
PASSWORD_TEST_OBJS := Tests/PasswordStrengthTest.o Source/PasswordStrength.o

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BASE_TEST_TARGET): $(BASE_TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(PASSWORD_TEST_TARGET): $(PASSWORD_TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

Source/%.o: Source/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Tests/%.o: Tests/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

test: $(BASE_TEST_TARGET) $(PASSWORD_TEST_TARGET)
	./$(BASE_TEST_TARGET)
	./$(PASSWORD_TEST_TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) Tests/BaseConverterTest.o Tests/PasswordStrengthTest.o \
		$(TARGET) $(BASE_TEST_TARGET) $(PASSWORD_TEST_TARGET)
