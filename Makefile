# Makefile for Codeforces local testing
# Usage: make problem=A round=1053

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
	g++ -std=c++17 -O2 -o $(EXE) $(CPP)

test: compile
	@$(PY) $(TST) $(ROUND) $(PROB)

run: compile
	@$(EXE)

setup:
	@$(PY) make-cf-dir.py $(URL)

clean:
	@rm -f Round$(ROUND)/*.out
	@echo "Cleaned executables."
