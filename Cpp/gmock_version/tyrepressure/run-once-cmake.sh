#!/bin/bash

if [[ ! -d build ]]; then
    mkdir -p build
fi

cd build
cmake .. -DCMAKE_BUILD_TYPE=DEBUG && cmake --build . && env CTEST_OUTPUT_ON_FAILURE=1 cmake --build . --target tyrepressure_html_coverage
