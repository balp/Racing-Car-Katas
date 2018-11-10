C++ Version
===========
Needed tools
------------

 C++ compiler supporting C++-14 reconized by CMake > 3.5:ish
 gcovr - to collect coverage from tests


Quick start
-----------

'''sh
  ./run-once-cmake.sh
'''
Coverage report in build/test_coverage/index.html

Tested on
---------

 Ununtu 18.04 - CMake 3.10
 macOS Mojave - Cmake 3.12


Random notes
------------

Will download and use googletest (including googlemock)
bash-script for convinience build and test


Nice things to solve in future
------------------------------

*  Possibly use lcov in place of gcovr if gcovr is missing
*  Possibility for using XCode unit test and coverage

