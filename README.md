# debug-template

## Description

A `C++` header file to easily print the variables with one function.

## How to use
Download the `Dbug.h` file and place it in the desired folder. Include `Dbug.h` in the file where you want to use it. If you want to print a variable `v`, write `dbg(v)` where you want to print it. The variable will be printed in `stderr` buffer. <br>
<b>Sample Code:</b><br>

```cpp
#include<bits/stdc++.h>
#include "Dbug.h"

class MyClass{
    public:
        int n;
    private:
        void foo(){}
};

int main()
{
    vector<int> v = {1,2,3,1,9};
    int n = 2;
    dbg(v, n);

    char c = 'a';
    string s = "Bangladesh";
    vector<pair<int,int>> vp = {{1,2}, {3,4}, {5,6}};
    dbg(c,s,vp);
    
    pair<int, MyClass> p = {1, MyClass{2}};
    dbg(p);
    return 0;
}
```

<b>Output:</b><br>

```txt
Line 15:
        v = [1, 2, 3, 1, 9]
        n = 2
Line 20:
        c = 'a'
        s = "Bangladesh"
        vp = [[1, 2], [3, 4], [5, 6]]
Line 23:
        p = [1, Unsupported-type] 
```

> Note: `dbg(...)` supports variable number of arguments. Some classes might not be supported. It does not support custom class and structure.<br>

## Supported Types

The following types are supported where `T`, `K` and `V` can be replaced with any other supported type<br>

```cpp
1. int
2. unsigned int
3. long long
4. unsigned long long
5. double
6. long double
7. float
8. char
9. unsigned char
10. __int128_t, __uint128_t
11. const char []
12. const T []
13. map<K,V>
14. multimap<K,V>
15. set<T>
16. queue<T>
17. stack<T>
18. unordered_set<K,V>
19. unordered_map<K,V>
20. priority_queue<T>
21. deque<T>
22. complex<T>
23. tuple<T1,T2,...>
24. string
25. array<T>
26. vector<T>
27. valarray<T>
28. pair<T1,T2>
29. multiset<T>
30. bitset<N>
31. tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> [a.k.a ordered_set<T>]
```
