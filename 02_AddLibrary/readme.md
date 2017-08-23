# 1. New Function
## 1.1. option
In the "CmakeLists.txt"
- `option (USE_MYMATH "Use tutorial provided math implementation" ON)`  
This will show up in the CMake GUI with a default value of ON that the user can change as desired. 

## 1.2. cmakedefine
In the "TutorialConfig.h"
- `#cmakedefine USE_MYMATH`  
如果`USE_MYMATH`选项在"CMakeLists.txt"中为ON，那么`USE_MYMATH`将会以宏定义出现在"TutorialConfig.h"中

# 2. Experiments
## 2.1. `-DUSE_MYMATH=ON`
`cmake ../02_AddLibrary/` or  
`cmake -DUSE_MYMATH=OFF ../02_AddLibrary/`

CMake Config Log:
```
...
USE_MYMATH
-- Configuring done
-- Generating done
...
```

In the "TutorialConfig.h":
```
#define USE_MYMATH
```

## 2.2. `-DUSE_MYMATH=OFF`
`rm -rf * && cmake -DUSE_MYMATH=OFF ../02_AddLibrary/`

CMake Config Log:
```
...
Not USE_MYMATH
-- Configuring done
-- Generating done
...
```

In the "TutorialConfig.h":
```
/* #undef USE_MYMATH */
```