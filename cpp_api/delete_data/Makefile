
SQLITECPP_ROOT_DIR=$(HOME)/local/SQLiteCpp

RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g
INCLUDES = -I$(SQLITECPP_ROOT_DIR)/include
LDFLAGS = -lSQLiteCpp -lsqlite3 -lpthread -ldl
LDPATH = -Wl,-rpath,$(SQLITECPP_ROOT_DIR)/lib -Wl,--enable-new-dtags -L$(SQLITECPP_ROOT_DIR)/lib

SOURCES = $(shell ls *.cpp)
PROGS = $(SOURCES:%.cpp=%)

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS)

%: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) $^ $(LDFLAGS) $(LDPATH)
