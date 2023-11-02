SOURCES = $(wildcard Source/*.cpp)
OBJECTS = $(SOURCES:%.cpp=%.o)

help:
	@echo "Targets availible:"
	@echo " build"
	@echo " clean"
	@echo " run"

$(OBJECTS):
	$(CXX) -I include -c $(@:%.o=%.cpp) -o $@

build: $(OBJECTS)
	$(CXX) $(OBJECTS) -o main

clean:
	rm Source/*.o
	rm main

run: build
	./main

