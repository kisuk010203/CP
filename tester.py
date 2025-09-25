#!/usr/bin/env python3
import os, sys, subprocess, glob

TIME_LIMIT = 2

# ANSI colors
GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
MAGENTA = "\033[95m"
CYAN = "\033[96m"
RESET = "\033[0m"


def run_test(round_num, prob):
    round_dir = f"Round{round_num}"
    cpp_file = os.path.join(round_dir, f"{prob}.cpp")
    exe_file = os.path.join(round_dir, f"{prob}.out")
    tc_dir = os.path.join(round_dir, "tests", prob)

    if not os.path.exists(cpp_file):
        print(f"{RED}Source file not found: {cpp_file}{RESET}")
        return
    if not os.path.exists(tc_dir):
        print(f"{RED}No testcases found: {tc_dir}{RESET}")
        return

    print(f"{CYAN}[Compiling] {cpp_file}{RESET}")
    res = subprocess.run(["g++", "-std=c++17", "-O2", "-o", exe_file, cpp_file])
    if res.returncode != 0:
        print(f"{RED}Compilation failed.{RESET}")
        return

    in_files = sorted(glob.glob(os.path.join(tc_dir, "*.in")))
    if not in_files:
        print(f"{RED}No input testcases.{RESET}")
        return

    for infile in in_files:
        base = os.path.splitext(os.path.basename(infile))[0]
        outfile = os.path.join(tc_dir, base + ".out")

        with open(infile, "r") as fin:
            try:
                proc = subprocess.run(
                    [exe_file],
                    stdin=fin,
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,
                    timeout=TIME_LIMIT,
                )
            except subprocess.TimeoutExpired:
                print(f"Test {base}: {MAGENTA}TLE{RESET}")
                continue

        if proc.returncode != 0:
            print(f"Test {base}: {YELLOW}RTE{RESET} (stderr: {proc.stderr.strip()})")
            continue

        if os.path.exists(outfile):
            with open(outfile, "r") as fexp:
                expected = fexp.read().strip()
            got = proc.stdout.strip()
            if got == expected:
                print(f"Test {base}: {GREEN}OK{RESET}")
            else:
                print(f"Test {base}: {RED}WA{RESET}")
                print(f"{CYAN}Expected:{RESET}")
                print(expected)
                print(f"{CYAN}Got:{RESET}")
                print(got)
        else:
            print(f"Test {base}: {YELLOW}No expected output file{RESET}")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"{CYAN}Usage: tester.py <round_num> <problem>{RESET}")
        sys.exit(1)

    run_test(sys.argv[1], sys.argv[2])
