#####
# Project name
#####
GAME = WorkTimer

######
# Project directory
#####
IDIR = header
SRCDIR = src
BUILDDIR = bin
DEPDIR = $(BUILDDIR)/.deps
LIBDIR = dependencies/SFML

######
# Debug directory
#####
DBGDIR = $(BUILDDIR)/debug
DBGOBJSDIR = $(DBGDIR)/.obj
DBGEXE = $(DBGDIR)/$(GAME)

######
# Release directory
#####
RELDIR = $(BUILDDIR)/release
RELOBJSDIR = $(RELDIR)/.obj
RELEXE = $(RELDIR)/$(GAME)

#####
# Project files
#####
SRC := $(wildcard $(SRCDIR)/*.cpp)
DEP := $(patsubst $(SRCDIR)/%.cpp, $(DEPDIR)/%.d, $(SRC))

#####
# Debug files
#####
DBGOBJS = $(patsubst $(SRCDIR)/%.cpp, $(DBGOBJSDIR)/%.o, $(SRC))

######
# Release files
#####
RELOBJS = $(patsubst $(SRCDIR)/%.cpp, $(RELOBJSDIR)/%.o, $(SRC))

#####
# Compiler flags
#####
CXX = g++
CXXFLAGS = -Wall -std=c++17 -MMD -MP -DSFML_STATIC -static -static-libgcc \
	-I$(IDIR) -I$(LIBDIR)/include

#####
# Compiler debug flags
#####
DBGCXXFLAGS = -g -O0 -DDEBUG

######
# Compiler release flags
#####
RELCXXFLAGS = -O3 -DNDEBUG

#####
# Linker flags
#####
LDFLAGS = -L$(LIBDIR)/lib -lopengl32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg \
	-lwinmm -lgdi32 -lfreetype -lopenal32 -lws2_32

#####
# Linker debug flags
#####
DBGLDFLAGS = -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-audio-s-d -lsfml-system-s-d \
	-lsfml-network-s-d

######
# Linker release flags
#####
RELLDFLAGS = -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -mwindows \
	-lsfml-network-s

.PHONY:	all debug release prepDebug prepRelease clean deepClean rebuild

#####
# Default build
#####
all:	prepRelease release

#####
# Debug rules
#####
debug:	prepDebug $(DBGEXE)

$(DBGEXE):	$(DBGOBJS)
	$(CXX) -o $@ $^ $(DBGLDFLAGS) $(LDFLAGS)

$(DBGOBJSDIR)/%.o:	$(SRCDIR)/%.cpp
	$(CXX) $(DBGCXXFLAGS) $(CXXFLAGS) -MMD -MP -MF $(DEPDIR)/$*.d -c $< -o $@

prepDebug:
	@mkdir -p $(DEPDIR)
	@mkdir -p $(DBGOBJSDIR)

######
# Release rules
#####
release:	prepRelease $(RELEXE)

$(RELEXE):	$(RELOBJS)
	$(CXX) -o $@ $^ $(RELLDFLAGS) $(LDFLAGS)

$(RELOBJSDIR)/%.o:	$(SRCDIR)/%.cpp
	$(CXX) $(RELCXXFLAGS) $(CXXFLAGS) -MMD -MP -MF $(DEPDIR)/$*.d -c $< -o $@

prepRelease:
	@mkdir -p $(DEPDIR)
	@mkdir -p $(RELOBJSDIR)

#####
# Other rules
#####
clean:
	rm	-f	$(DBGEXE)	$(DBGOBJS)
	rm	-f	$(RELEXE)	$(RELOBJS)

deepClean:
	rm	-f	$(DBGEXE)	$(DBGOBJS)
	rm	-f	$(RELEXE)	$(RELOBJS)
	rm	-f	$(DEP)

rebuild:	clean all

include $(wildcard $(DEP))