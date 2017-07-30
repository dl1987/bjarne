TARGET		:= calculator

SRC			:= $(wildcard *.cpp)

OBJ			:= $(SRC:.cpp=.o)


CPPFLAGS	:= -I../include

$(TARGET): $(OBJ)
	$(CXX) $^ -o $@
		
all: $(TARGET)

clean:
	$(RM) $(TARGET) $(OBJ)


