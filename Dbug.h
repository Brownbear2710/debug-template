#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define debug_header

#ifdef _WIN32
#include <windows.h> // for win32 API functions
enum Color
{
    BLACK, RESET = 7, GREY = 8, BLUE, GREEN, CYAN, RED, PURPLE, LIGHT_YELLOW, WHITE
};
void setTextColor(Color color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
#else // For Linux
enum Color
{
    RED = 31, GREEN, BLUE = 34, RESET = 37, WHITE = 97
};
void setTextColor(Color color)
{
    string s = "\033[0;" + to_string(color) + "m";
    cerr << s;
}
#endif

void show_val(string s) { cerr << "\"" << s << "\""; }
void show_val(char c) { cerr << "\'" << c << "\'"; }
void show_val(int i) { cerr << i; }
void show_val(unsigned int i) { cerr << i; }
void show_val(double i) { cerr << i; }
void show_val(float i) { cerr << i; }
void show_val(long double i) { cerr << i; }
void show_val(long long i) { cerr << i; }
void show_val(unsigned long long i) { cerr << i; }
void show_val(const char *p) { cerr << "\"" << p << "\""; }
void show_val(char *p) { cerr << "\"" << p << "\""; }
template <typename T, typename V>
void show_val(pair<T, V> p);
template <typename T>
void show_val(stack<T> q);
template <typename T>
void show_val(queue<T> q);
template <typename T, size_t N>
void show_val(const T (&t)[N]);
template <typename T>
void show_val(T t);
template <typename... Args>
void show_val(const std::tuple<Args...> &t);
template <typename T>
void show_val(complex<T> c);
template <typename T>
void show_val(priority_queue<T> q);

//! Complex
template <typename T>
void show_val(complex<T> c)
{
    cerr << "{";
    show_val(c.real());
    cerr << ", ";
    show_val(c.imag());
    cerr << "}";
}

//! Tuple
template <typename Tuple, std::size_t N>
struct TuplePrinter
{
    static void print(Tuple t)
    {
        TuplePrinter<Tuple, N - 1>::print(t);
        std::cout << ", ";
        show_val(get<N - 1>(t));
    }
};
template <typename Tuple>
struct TuplePrinter<Tuple, 1>
{
    static void print(const Tuple &t) { show_val(get<0>(t)); }
};
template <typename... Args>
void show_val(const std::tuple<Args...> &t)
{
    cerr << "{";
    TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
    cerr << "}";
}

//! Range based
template <typename T, size_t N>
void show_val(const T (&t)[N])
{
    cerr << "{";
    for (int i = 0; i < N; i++)
    {
        show_val(t[i]);
        if (i + 1 < N)
            cerr << ", ";
    }
    cerr << "}";
}

template <typename T>
void show_val(T t)
{
    cerr << "{";
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    cerr << "}";
}

//! Pair
template <typename T, typename V>
void show_val(pair<T, V> p)
{
    cerr << "{";
    show_val(p.first);
    cerr << ", ";
    show_val(p.second);
    cerr << "}";
};

//! queue
template <typename T>
void show_val(queue<T> q)
{
    cerr << "{";
    for (; q.size();)
    {
        show_val(q.front());
        q.pop();
        if (q.size())
            cerr << ", ";
    }
    cout << "}";
}

//! stack
template <typename T>
void show_val(stack<T> q)
{
    cerr << "{";
    for (; q.size();)
    {
        show_val(q.top());
        q.pop();
        if (q.size())
            cerr << ", ";
    }
    cout << "}" << endl;
}
//! Priority Queue
template <typename T>
void show_val(priority_queue<T> q)
{
    cerr << "{";
    for (; q.size();)
    {
        show_val(q.top());
        q.pop();
        if (q.size())
            cerr << ", ";
    }
    cout << "}";
}

//! dbg
void dbo(string s) {}
template <typename T, typename... Args>
void dbo(string s, T &t, Args &...args)
{
    auto it = remove(s.begin(), s.end(), ' ');
    s.erase(it, s.end());
    cerr << "\t" << s.substr(0, s.find(',')) << " = ";
    s = s.substr(s.find(',') + 1);
    show_val(t);
    cerr << endl;
    if (sizeof...(args))
        dbo(s, args...);
}
template <typename T, typename... Args>
void dbo(string s, T &&t, Args &&...args)
{
    auto it = remove(s.begin(), s.end(), ' ');
    s.erase(it, s.end());
    cerr << "\t" << s.substr(0, s.find(',')) << " = ";
    s = s.substr(s.find(',') + 1);
    show_val(t);
    cerr << endl;
    if (sizeof...(args))
        dbo(s, args...);
}

#ifdef debug_header
#define dbg(x...)                               \
    {setTextColor(GREEN);                        \
    cerr << "Line " << __LINE__ << ":" << endl; \
    setTextColor(WHITE);                        \
    dbo(#x, x);                                 \
    setTextColor(RESET);}
#else
#define dbg(x...)
#endif