CXX = g++

# compiler flags
# -Wall: enable all common warning
# -g: include debugging information
CXXFLAGS = -Wall -g

TARGET = book_passport

# source files
SRCS = main.cpp User.cpp Book.cpp BookManager.cpp

# object files
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

# --- Rules ---
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp User.h BookManager.h
User.o: User.cpp User.h
Book.o: Book.cpp Book.h
BookManager.o: BookManager.cpp BookManager.h Book.h

# clean rule: remove generated files
# .PHONY: declares clean as a phony target, meaning it's not a file
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
	rm -f *.txt