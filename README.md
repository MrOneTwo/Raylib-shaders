# Raylib tests

In order to compile with _g++_ I had to modify _raylib.h_ like so:

From:

```cpp
264 // NOTE: MSC C++ compiler does not support compound literals (C99 feature)
265 // Plain structures in C++ (without constructors) can be initialized from { } initializers.
266 #ifdef __cplusplus
267     #define CLITERAL
268 #else
269     #define CLITERAL    (Color)
270 #endif
```

To:

```cpp
To:
264 // NOTE: MSC C++ compiler does not support compound literals (C99 feature)
265 // Plain structures in C++ (without constructors) can be initialized from { } initializers.
266 #ifdef __cplusplus
267     #define CLITERAL    (Color)
268 #else
269     #define CLITERAL    (Color)
270 #endif
```

Compiling with _-E_ flag allowed me to see how macros were expanded and CLITERAL lacked
_(Color)_ (which makes sense looking at the macro but it didn't compile without it in _g++_.

Comment says it's prepared for MSC C++ compiler so compiling with it might be problematic
after this mod.
