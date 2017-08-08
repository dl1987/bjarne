# $@ : $< .....//first
# $@ : $^      //all

STDLIB		:= ../std_lib
INCDIR		:= include
SRCDIR		:= src
OBJDIR		:= build
BINDIR		:= ../bin
BIN			:= $(BINDIR)/$(TARGET)

SRCEXT		:= cpp

SRC			:= $(shell find $(SRCDIR) -name *.$(SRCEXT))

OBJ			:= $(patsubst $(SRCDIR)/%.$(SRCEXT), $(OBJDIR)/%.o, $(SRC))

CPPFLAGS	:= -c -Wall -I$(INCDIR) -I$(STDLIB)

$(BIN): $(OBJ)
	$(CXX) $^ -o $@
	
$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ): | $(OBJDIR)
$(BIN): | $(BINDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

clean:
	$(RM) -r $(OBJDIR) $(BINDIR)
