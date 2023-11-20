BUILDDIR := build

SRC := $(wildcard Source/*.cpp)
SRC := $(filter-out Source/main.cpp, $(SRC))

TEST_SRC := $(wildcard Test/*.cpp)
TEST_EXE := $(TEST_SRC:Test/%.cpp=$(BUILDDIR)/%)
TEST_RUN := $(TEST_EXE:$(BUILDDIR)/%=Run%)

OBJ := $(SRC:Source/%.cpp=$(BUILDDIR)/%.o)
EXE := main

CXXFLAGS += -I Source
CXXFLAGS += -std=c++20
CXXFLAGS += -MMD
CXXFLAGS += -MP
DEPS := $(OBJ:%.o=%.d)

.PHONY: all clean build-exe build-tests run test

build-exe: $(BUILDDIR)/$(EXE)

all:
	@echo $(TEST_SRC)
	@echo $(TEST_EXE)

run: Run$(EXE)

test: $(TEST_RUN)

build-tests: $(TEST_EXE)

$(BUILDDIR)/$(EXE): $(BUILDDIR)/main.o $(OBJ)
	$(CXX) $(LDFLAGS) $(BUILDDIR)/main.o $(OBJ) -o $@

$(BUILDDIR)/%.o: Source/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/%: Test/%.cpp $(OBJ)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(OBJ) $< -o $@

Run%: $(BUILDDIR)/%
	@echo Running $<
	@./$<

clean:
	rm -rf $(BUILDDIR)

-include $(DEPS)
