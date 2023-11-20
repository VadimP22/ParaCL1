BUILDDIR := build

SRC := $(wildcard Source/*.cpp)
SRC := $(filter-out Source/main.cpp, $(SRC))

TEST_SRC := $(wildcard Test/*.cpp)
TEST_EXE := $(TEST_SRC:Test/%.cpp=$(BUILDDIR)/%)
TEST_RUN := $(TEST_EXE:$(BUILDDIR)/%=Run%)

OBJ := $(SRC:Source/%.cpp=$(BUILDDIR)/%.o)
EXE := main

CXXFLAGS += -std=c++20
CXXFLAGS += -I Source
CXXFLAGS += -MMD
CXXFLAGS += -MP
DEPS := $(OBJ:%.o=%.d)

.PHONY: clean test run

build: $(OBJ) $(BUILDDIR)/main.o

run: Run$(EXE)

test: $(TEST_RUN)

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
	rm -f compile_commands.json

# WARN: Do not use -jN option on this target!
compile_commands.json:
	@make CXX="bear --append -- $(CXX)"

-include $(DEPS)
