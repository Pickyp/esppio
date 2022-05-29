# Tests

Tests are split into two directories
- `test_embedded` Tests that will be run against the embedded hardware
- `test_native` Tests that will be run on a local machine

## Embedded Tests

Embedded tests are run via pio.
Test reports are not currently generated for these.

## Native Tests

Native tests are run via ceedling.These tests generate the following.

- `gcov report` This report displays the coverage of your code by your unit tests.
- `junit report` This report displays which tests have passed and failed as well as their execution time.

## Reports
To generate a test report run the following.
```bash
ceedling test:all
```
The reports will be found under `build/artifacts/test`
- `report_junit.xml`: A report in the junit schema.
- `report.xml`: An xml based test report used by the ceedling test explorer.

## Tools
- [Ruby 3.0.4](https://www.ruby-lang.org/en/) Used by ceedling.
- [Platformio](): Used for building/debugging embedded firmware.
- [Ceedling](http://www.throwtheswitch.org/ceedling): Used for project generation, unit-testing(unity) and mocking(cMock).
- [GDB](https://sourceforge.net/projects/mingw/): Used for debugging tests.This can be install on windows by using mingw.
- [GCC](https://sourceforge.net/projects/mingw/): Used for building tests.This can be installed on windows by using mingw.
## Example Ceedling debug config
The following config must be added to your launch.json file in order for the ceedling test explorer to allow debugging.
```json
{
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceRoot}/build/test/out/${fileBasenameNoExtension}.out",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "Set Disassembly Flavor to Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ]
}
```
## Testing reporting in CI

The following tools will need to be installed on your CI machine
- [pio-cli](https://docs.platformio.org/en/latest/core/installation.html)
- [Ruby 3.0.4](https://www.ruby-lang.org/en/)
- [Ceedling](http://www.throwtheswitch.org/ceedling)

### Step 1
Retrieve pio dependencies
```bash
pio run
```
### Step 2
Run tests and generate reports
```bash
ceedling test:all
```
### Step 3
Retrieve the junit test report.<br>
`build/artifacts/test/report_junit.xml`