# Titanic Survival Analysis (C++)

Reads Titanic passenger data from a CSV file and produces summary tables of
survival rates grouped by passenger class, port of embarkation, and fare.

## Structure
| File | Purpose |
|------|---------|
| `CSVFile.h` / `CSVFile.cpp` | Generic CSV reader with a callback interface. |
| `DataCollectorCallback.h` | Callback contract for consuming CSV rows. |
| `Passenger.h` / `Passenger.cpp` | Passenger model (name, class, embarkation, fare, survived). |
| `PassengerDatabase.h` / `.cpp` | Loads and queries passengers by class/embarkation. |
| `OutputTableRow.*`, `PassengerOutputTable.*` | Formatted summary-table output. |
| `Settings.h`, `Enums.h` | Data-file paths and enumerations. |
| `main.cpp` | Loads the data and prints the summary tables. |

## Build & Run
```bash
g++ -std=c++17 *.cpp -o titanic
./titanic
```

## Known issues / to-do
- `main.cpp` references `ExampleDataCollector.h`, which is not in the repo — add
  it (or remove the include) so the project compiles.
- Data-file paths in `Settings.h` are hard-coded; make them relative or configurable.
