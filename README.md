# DynArray: Basic dynamic array (list/vector) implementation

Why? Why not.

## How to use?

```cpp
#include "dynarray.hpp"

// And then later in code

DynArray<int> arr;
arr << 5;
// Classic for:
for (int i = 0; i < arr.size(); i++) {
    // Do stuff with arr[i]
}
// Range based for:
for (auto elem : arr) {
    // Do stuff with elem
}
```

## How to run example?

### Got make?

```shell
make run
```

### No make?

```shell
g++ example.cpp -o example
./example
```

### Windows?

```powershell
g++ example.cpp -o example.exe
.\example.exe
```

### Windows without `g++`?

I never compiled something using `msvc` from the terminal. I guess make a new Visual Studio project, copy-paste the files in there and have fun, idk.
