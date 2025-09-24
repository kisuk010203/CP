#!/usr/bin/env python3
import os, re, requests, sys
from bs4 import BeautifulSoup
import cloudscraper

TEMPLATE = r"""#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        // TODO
    }
    return 0;
}
"""


def setup_contest(contest_id: int):
    # API call
    api_url = f"https://codeforces.com/api/contest.standings?contestId={contest_id}&from=1&count=1"
    r = requests.get(api_url)
    data = r.json()
    if data["status"] != "OK":
        raise RuntimeError("API error")

    contest = data["result"]["contest"]
    problems = data["result"]["problems"]

    # round number
    m = re.search(r"Round\s+(\d+)", contest["name"])
    round_num = m.group(1) if m else str(contest_id)
    round_dir = f"Round{round_num}"
    os.makedirs(round_dir, exist_ok=True)

    testcase_root = os.path.join(round_dir, "tests")
    os.makedirs(testcase_root, exist_ok=True)
    scraper = cloudscraper.create_scraper()

    for prob in problems:
        idx = prob["index"]  # A, B, ...
        # template cpp
        cpp_file = os.path.join(round_dir, f"{idx}.cpp")
        if not os.path.exists(cpp_file):
            with open(cpp_file, "w") as f:
                f.write(TEMPLATE)

        # problem page
        prob_url = f"https://codeforces.com/contest/{contest_id}/problem/{idx}"
        r = scraper.get(prob_url)
        soup = BeautifulSoup(r.text, "html.parser")

        # parse samples
        case_dir = os.path.join(testcase_root, idx)
        os.makedirs(case_dir, exist_ok=True)

        sample_divs = soup.select("div.sample-test")
        tc_id = 1
        for s in sample_divs:
            inputs = s.select("div.input pre")
            outputs = s.select("div.output pre")
            for inp, out in zip(inputs, outputs):
                in_text = inp.get_text("\n").strip() + "\n"
                out_text = out.get_text("\n").strip() + "\n"
                with open(os.path.join(case_dir, f"{tc_id}.in"), "w") as f:
                    f.write(in_text)
                with open(os.path.join(case_dir, f"{tc_id}.out"), "w") as f:
                    f.write(out_text)
                tc_id += 1

    print(f"Setup complete: {round_dir}")


if __name__ == "__main__":
    setup_contest(sys.argv[1])
