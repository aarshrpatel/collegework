# Compiler and flags
CXXFLAGS = -std=c++11 -Wall

# Targets and file names
QUICKSORT = Aarsh_Patel_QuickSort
INPUTGEN = InputFileGenerator
OUTPUT_FILES = output_*.txt executionTime.txt input_*.txt

# Default target to compile both programs
all: $(QUICKSORT) $(INPUTGEN)

# Compile quicksort
$(QUICKSORT): Aarsh_Patel_QuickSort.cpp
	g++ $(CXXFLAGS) -o $(QUICKSORT) Aarsh_Patel_QuickSort.cpp

# Compile input generator
$(INPUTGEN): InputFileGenerator.cpp
	g++ $(CXXFLAGS) -o $(INPUTGEN) InputFileGenerator.cpp

# Run input generator to generate input files
generate_inputs: $(INPUTGEN)
	./$(INPUTGEN)

# Run sorting program for all generated input files
run_sort:
	@for file in input_*.txt; do \
		echo "Processing $$file..."; \
		./$(QUICKSORT) $$file sorted_$$file; \
	done

# Clean up all generated files and executables
clean:
	rm -f $(QUICKSORT) $(INPUTGEN) $(OUTPUT_FILES) sorted_*.txt

# Target to run everything in sequence: compile, generate inputs, run sort, and then clean
run_all: all generate_inputs run_sort clean

.PHONY: all generate_inputs run_sort clean run_all
