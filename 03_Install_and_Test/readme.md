# 1. New Function
## 1.1. CMAKE_INSTALL_PREFIX and install
In the "CmakeLists.txt":
- `set(CMAKE_INSTALL_PREFIX  ${PROJECT_SOURCE_DIR}/install)`  
- `install(...)`
```
# add the install targets
install (
  TARGETS Tutorial
  DESTINATION bin
)
install (
  FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"        
  DESTINATION include
)
```
Install directory used by install.  
但是注意只能放在Top-level的“CMakeLists.txt”中

## 1.2 ctest
In the "CmakeLists.txt":
- `add_test`
```
include(CTest)

# does the application run
add_test (TutorialRuns Tutorial 25)
```

- `macro`
```
#define a macro to simplify adding tests, then use it
macro (do_test arg result)
  add_test (TutorialComp${arg} Tutorial ${arg})
  set_tests_properties (TutorialComp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)
 
# do a bunch of result based tests
do_test (25 "25 is 5")
```

# 2. Experiments
## 2.1. Run "make install"
```
......
[100%] Built target Tutorial
Install the project...
-- Install configuration: ""
-- Up-to-date: /media/psf/Home/ubuntu/cpp_test/CmakeTutorial/03_Install_and_Test/install/bin/Tutorial
-- Up-to-date: /media/psf/Home/ubuntu/cpp_test/CmakeTutorial/03_Install_and_Test/install/include/TutorialConfig.h
-- Up-to-date: /media/psf/Home/ubuntu/cpp_test/CmakeTutorial/03_Install_and_Test/install/bin/libMathFunctions.a
-- Up-to-date: /media/psf/Home/ubuntu/cpp_test/CmakeTutorial/03_Install_and_Test/install/include/MathFunctions.h
```

## 2.2 Run "ctest"
```
Test project /media/psf/Home/ubuntu/cpp_test/CmakeTutorial/build
    Start 1: TutorialRuns
1/6 Test #1: TutorialRuns .....................   Passed    0.00 sec
    Start 2: TutorialComp25
2/6 Test #2: TutorialComp25 ...................   Passed    0.01 sec
    Start 3: TutorialNegative
3/6 Test #3: TutorialNegative .................   Passed    0.00 sec
    Start 4: TutorialSmall
4/6 Test #4: TutorialSmall ....................   Passed    0.01 sec
    Start 5: TutorialUsage
5/6 Test #5: TutorialUsage ....................   Passed    0.00 sec
    Start 6: TutorialComp4
6/6 Test #6: TutorialComp4 ....................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 6

Total Test time (real) =   0.05 sec
```