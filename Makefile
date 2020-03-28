CXX = g++
INCLUDE_DIR = .
CXXFLAGS = -Wall -Wextra -std=c++17 $(INCLUDE_DIR:%=-I%)
LIBS = fmt

.PHONY: format color_core color_8bit color_rgb
all: build format color_core color_8bit color_rgb
build:
	@mkdir -p build

format: build/format
	@$^
	@read
build/format: examples/format.cpp termfmt.h
	$(CXX) $(CXXFLAGS) $(LIBS:%=-l%) $(filter %.cpp, $^) -o $@

color_core: build/color_core
	@$^
	@read
build/color_core: examples/color_core.cpp termfmt.h
	$(CXX) $(CXXFLAGS) $(LIBS:%=-l%) $(filter %.cpp, $^) -o $@

color_8bit: build/color_8bit
	@$^
	@read
build/color_8bit: examples/color_8bit.cpp termfmt.h
	$(CXX) $(CXXFLAGS) $(LIBS:%=-l%) $(filter %.cpp, $^) -o $@

color_rgb: build/color_rgb
	@$^
	@read
build/color_rgb: examples/color_rgb.cpp termfmt.h
	$(CXX) $(CXXFLAGS) $(LIBS:%=-l%) $(filter %.cpp, $^) -o $@