PY = python3
TST = tester.py
ROUND = $(round)
URL = $(url)
PROB = $(problem)
CPP = Round$(ROUND)/$(PROB).cpp
EXE = Round$(ROUND)/$(PROB).out

all:
	@echo "Usage: make problem=<problem> round=<round>"

compile:
	@if [ ! -f $(CPP) ]; then \
		echo "Source file not found: $(CPP)"; exit 1; \
	fi
	@echo "Compiling $(CPP)..."
	g++ -std=c++17 -O2 -o $(EXE) $(CPP) -g

test: compile
	@$(PY) $(TST) $(ROUND) $(PROB)

run: compile
	@$(EXE)

nb-run: # No-Build run
	@$(EXE)

setup:
	@$(PY) make-cf-dir.py $(URL)

clean:
	@rm -f Round$(ROUND)/*.out
	@rm -rf Round$(ROUND)/*.dSYM
	@echo "Cleaned executables."
