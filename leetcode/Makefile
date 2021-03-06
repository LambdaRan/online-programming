
#
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make clean  - removes all files generated by make.

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = ../googletest

# Points to the location of the Google Test libraries
GTEST_LIB_DIR = .

# Where to find user code.
USER_DIR = .

# LeetCode Solution COde
SRC = prob33.cpp

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# CFLAGS += -isysroot /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk
# CPATH = `xcrun --show-sdk-path`/usr/include

# Flags passed to the C++ compiler.
#CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11
CXXFLAGS += -g -Wall -Wextra -Wshadow  -std=c++11 -pthread
CXXFLAGS += -Wconversion -Wconversion-null -Wfatal-errors -Wpointer-arith \
		-Wunreachable-code -Wundef -Wctor-dtor-privacy -Wcast-align \
		-Wformat -Wformat-nonliteral -Wchar-subscripts -Wmissing-braces \
		-Wuninitialized -Winline -Wcast-qual -Wdiv-by-zero -Wdouble-promotion \
		-Wempty-body -Wendif-labels
# -Werror -Weffc++
# Google Test libraries
GTEST_LIBS = libgtest.a libgtest_main.a

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = zmain

# AR = /Library/Developer/CommandLineTools/usr/bin/ar
# CXX = /Library/Developer/CommandLineTools/usr/bin/cc

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

all : $(GTEST_LIBS) $(TESTS)

clean :
	rm -f $(TESTS) *.o
clean_lib :
	rm -f $(GTEST_LIBS)
# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

libgtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

libgtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

# sample1.o : $(USER_DIR)/sample1.cc $(USER_DIR)/sample1.h $(GTEST_HEADERS)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1.cc

# sample1_unittest.o : $(USER_DIR)/sample1_unittest.cc \
#                      $(USER_DIR)/sample1.h $(GTEST_HEADERS)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1_unittest.cc

# sample1_unittest : sample1.o sample1_unittest.o $(GTEST_LIBS)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -L$(GTEST_LIB_DIR) -lgtest_main -lpthread $^ -o $@

zmain:$(SRC) $(GTEST_LIBS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -L$(GTEST_LIB_DIR) -lgtest_main -lpthread $^ -o $@
