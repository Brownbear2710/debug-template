# debug-template

## Description

A `C++` header file to easily print the varibles with one function.

## How to use
download the `Dbug.h` file and place it in the desired folder. Include `Dbug.h` in file where you want to use it. If you want to print a variable `v`, write `dbg(v)` where you want to print it. <br>
<b>Sample Code:</b><br>

```cpp
#include<bits/stdc++.h>
#include "Dbug.h"

int main()
{
    vector<int> v = {1,2,3,1,9};
    int n = 2;
    dbg(v, n);

    char c = 'a';
    string s = "Bangladesh";
    vector<pair<int,int>> vp = {{1,2}, {3,4}, {5,6}};
    dbg(c,s,vp);
    
    return 0;
}
```

<b>Output:</b><br>

```txt
Line 8:
        v = {1, 2, 3, 1, 9}
        n = 2
Line 13:
        c = 'a'
        s = "Bangladesh"
        vp = {{1, 2}, {3, 4}, {5, 6}}
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
10. const T []
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
26. valarray<T>
27. pair<T1,T2>
+ Any datatype<T> that supports foreach loop.
```