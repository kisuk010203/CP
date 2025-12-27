# 📝 Codeforces Local Setup & Tester

[![Python](https://img.shields.io/badge/python-3.9+-blue.svg)](https://www.python.org/)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

Automate **Codeforces contest setup** and **local testing**: fetch problems, generate template C++ files, scrape sample testcases, and run tests with colored verdicts.

---

## Features

-   Fetch contest info & problem list via **Codeforces API**
-   Scrape sample testcases for each problem (**cloudscraper** bypasses Cloudflare)
-   Auto-generate directories:
    -   `Round<XXXX>/` for each contest
    -   `Round<XXXX>/<Problem>.cpp` template files
    -   `Round<XXXX>/tests/<Problem>/` input/output files
-   Compile and run tests with colored verdicts:

    -   ✅ **OK** – green
    -   ❌ **WA** – red
    -   ⚠ **RTE** – yellow
    -   ⏱ **TLE** – magenta

-   Fully integrated **Makefile** for setup, testing, and cleaning

---

## Prerequisites

-   Python 3
-   `g++` with C++17 support
-   Python packages:

```bash
pip install cloudscraper beautifulsoup4
```

## Directory Layout

After setup, a contest folder looks like:

```
Round1053/
 ├── A.cpp
 ├── B.cpp
 ├── ...
 └── tests/
     ├── A/
     │    ├── 1.in
     │    └── 1.out
     └── B/
         ├── 1.in
         └── 1.out
```

## Usage

### 0️⃣ Setting up requirements

We will use a `venv` to setup your environment. Run 

```bash
source env.sh
```

### 1️⃣ Setup a Round

Fetch problems, generate templates, and scrape testcases:

```bash
make setup URL=2151 # You need to write the URL, not the verbose ROUND name
```

### 2️⃣ Test a Problem

Compile and run tests for a specific problem:

```bash
make test ROUND=1053 PROB=A
```

Example output:

```bash
Compiling Round1053/A.cpp...
Running tests...
Test 1: ✅ OK
Test 2: ❌ WA
Expected:
42
Got:
43
Test 3: ⏱ TLE
```

#### Color Legend

| Verdict | Color   | Meaning                        |
| ------- | ------- | ------------------------------ |
| ✅ OK   | Green   | Output matches expected        |
| ❌ WA   | Red     | Output does not match expected |
| ⚠ RTE  | Yellow  | Runtime error occurred         |
| ⏱ TLE  | Magenta | Execution timed out            |

### 3️⃣ Clean Compiled Executables

```bash
make clean ROUND=1053 
```

## Notes

The Python scraper uses cloudscraper to bypass Cloudflare; this avoids the “Just a moment…” bot detection page.

Sample testcases are fetched only if available on the problem page.

The Makefile supports colored terminal output for easy scanning of verdicts.

You can extend the Makefile to loop over all problems automatically if desired.

## License

MIT License – free to use and modify.
