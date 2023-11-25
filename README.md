# debug-template

## Description

A `C++` header file to easily print the varibles with one function.

## How to use
download the `Dbug.h` file and place it in the desired folder. Include `Dbug.h` in file where you want to use it. If you want to print a variable `v`, write `dbg(v)` where you want to print it. <br>
Sample Code:<br>

```cpp
#include<bits/stdc++.h>
#include "Dbug.h"

int main()
{
    vector<int> v = {1,2,3,1,9};
    int n = 2;
    dbg(v, n);
    return 0;
}
```

Output:<br>

```txt
Line 7:
        v = {1, 2, 3, 1, 9}
        n = 2
```

> Note: `dbg(...)` supports variable number of arguments. Some classes might not be supported. It does not support custom class and structure.<br>

## Supported Types

The following types are supported where `T`, `K` and `V` can be replaced with with any other supported type<br>

```cpp
1. int
2. unsigned int
3. long long
4. unsigned long long
5. double
6. long double
7. float
8. char
9. const char []
10. const int []
11. set<T>
12. multiset<T>
13. map<K,V>
14. multimap<K,V>
15. stack<T>
16. queue<T>
17. unordered_map<K,V>
18. unordered_set<K,V>
19. priority_queue<T>
20. deque<T>
21. complex<T>
22. tuple<T1,T2,...>
23. string
24. array<T>
25. vector<T>
26. Any datatype<T> that supports range-based for loop & has .size() member function.
```