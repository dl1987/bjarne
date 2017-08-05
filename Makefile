# $@ : $< .....//first
# $@ : $^      //all

TARGET		:= calculator

INCDIR		:= include
SRCDIR		:= src
BUILDDIR	:= build

SRCEXT		:= cpp

SRC		:= $(shell find $(SRCDIR) -name *.$(SRCEXT))

OBJ		:= $(patsubst $(SRCDIR)/%.$(SRCEXT), $(BUILDDIR)/%.o, $(SRC))

CPPFLAGS	:= -c -Wall -I$(INCDIR)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $^ -o $@
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CXX) $(CPPFLAGS) $< -o $@

clean:
	$(RM) $(TARGET) $(OBJ)

