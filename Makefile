# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++17 -Wall

# Directories
SRCDIR = src
INCDIR = $(SRCDIR)/headers
BUILDDIR = build

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

# Executable name
TARGET = ticketility

# Build rule
all: $(TARGET)

$(OBJS): | $(BUILDDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile rule
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

# Clean rule
clean:
	rm -rf $(BUILDDIR) $(TARGET)
