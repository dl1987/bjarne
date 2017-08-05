# $@ : $< .....//first
# $@ : $^      //all

TARGET		:= calculator

INCDIR		:= include
SRCDIR		:= src
OBJDIR		:= build

SRCEXT		:= cpp

SRC			:= $(shell find $(SRCDIR) -name *.$(SRCEXT))

OBJ			:= $(patsubst $(SRCDIR)/%.$(SRCEXT), $(OBJDIR)/%.o, $(SRC))

CPPFLAGS	:= -c -Wall -I$(INCDIR)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $^ -o $@
	
$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(RM) $(TARGET) $(OBJ); $(RM) -r $(OBJDIR)

