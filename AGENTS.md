# AGENTS.md

C++ solutions for the CEDT *Computer Programming* course (Chulalongkorn). Contest-style code, one program per file, read from stdin, print to stdout. No build system, test framework, CI, or formatter — an agent must not assume any exist. Verification is manual: compile to a sibling `.bin` and run with sample input.

## Layout

- `Grader/<NN-Topic>/` — weekly grader problems (`01-String`, `02-Condition`, ..., `09-Recur`, `104-exam`). Bulk of the code.
- `Midterm/<year>/`, `Midterm/<year>-Mock-Exam/`, `Final/<year>/` — past exams.
- `TestFolder/` — scratch area, **gitignored**. The active session dir (`TestFolder/ryw-mock`) lives here; treat as throwaway, never commit it.
- `.cph/` — CPH (VS Code "Competitive Programming Helper") test metadata, gitignored. The grader runs these saved tests.

## Git rules

- Only `*.cpp` is tracked (104 files). `*.bin`, `.swap`/`.swp`, `.DS_Store`, `TestFolder/`, `.cph/` are ignored — don't force-add or commit them.
- `.gitignore`'s trailing lines (`09-Recur/`, `Midterm-03-Grader/`) are a local uncommitted edit; preserve them.
- Commit style: very short, lowercase topic+problem summaries (e.g. `2024 Final 03,04`, `vector update`). Small one-line bodies. One-off manual commits, not structured workflow.

## Conventions

- Naming: `NN-ProblemTitle.cpp` in `Grader/`; `YYYY-Midterm-NN.cpp` / `YYYY-Final-NN.cpp` / `YYYY-Mock-Exam-NN.cpp` in exam dirs. Each solved program has a sibling `<name>.bin` compile artifact.
- Style varies by file. Grader files mostly use explicit headers (`<iostream>`…); exam files often `#include<bits/stdc++.h>` + `using namespace std;`. Match the neighboring file; never reformat.
- Nearly every program starts `main` with `std::cin.tie(nullptr)->sync_with_stdio(0);` for fast I/O.
- No comments, no explanations — minimal single-purpose contest solutions. Don't "improve" style when asked to fix logic.
- Compile with default `g++`/`clang++` (found on PATH); `-std=c++11` features and `bits/stdc++.h` are both fine.