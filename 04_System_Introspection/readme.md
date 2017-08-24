# 1. New Function
## 1.1. check_function_exists
In the "CmakeLists.txt":
```
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)
```

In the "TutorialConfig.h.in"
```
// does the platform provide exp and log functions?
#cmakedefine HAVE_LOG
#cmakedefine HAVE_EXP
```

In the "mysqrt.cpp"
```
    // if we have both log and exp then use them
#if defined (HAVE_LOG) && defined (HAVE_EXP)
    return exp(log(inputValue)*0.5);
#else
    return sqrt(inputValue);
#endif
```

"CMakeLists.txt"中的`check_function_exists`必须要在`configure_file`之前

# 2. Experiments
## 2.1. Run `cmake ../04_System_Introspection/`
```
......
Not HAVE_LOG
USE_MYMATH
......
```
