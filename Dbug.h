#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

#define debug_header

#ifdef _WIN32
#include <windows.h> // for win32 API functions
enum Color
{
    BLACK, RESET = 7, GREY, BLUE, GREEN, CYAN, RED, PURPLE, LIGHT_YELLOW, WHITE
};
void setTextColor(Color color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
#else // For Linux
enum Color
{
    RED = 31, GREEN, BLUE = 34, RESET = 37, CYAN= 96, WHITE = 97
};
void setTextColor(Color color)
{
    string s = "\033[0;" + to_string(color) + "m";
    cerr << s;
}
#endif

void show_val(string s) { cerr << "\"" << s << "\""; }
void show_val(char c) { cerr << "\'" << c << "\'"; }
void show_val(unsigned char c) { cerr << "\'" << c << "\'"; }
void show_val(int i) { cerr << i; }
void show_val(bool i) { cerr << i; }
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
template <typename T>
void show_val(set<T> t);
template <typename T>
void show_val(unordered_set<T> t);
template <typename T>
void show_val(multiset<T> t);
template <typename K, typename V>
void show_val(map<K, V> t);
template <typename K, typename V>
void show_val(multimap<K, V> t);
template <typename K, typename V>
void show_val(unordered_map<K, V> t);
template <typename T>
void show_val(deque<T> t);
template <typename T>
void show_val(vector<T> t);
template <typename T, size_t N>
void show_val(array<T,N> t);
template <typename T>
void show_val(valarray<T> t);
template<class T>
void show_val(tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> t);

void print_opening()
{
    setTextColor(CYAN);
    cerr << "[";
    setTextColor(WHITE);
}
void print_closing()
{
    setTextColor(CYAN);
    cerr << "]";
    setTextColor(WHITE);
}

//! Complex
template <typename T>
void show_val(complex<T> c)
{
    cerr << "";
    show_val(c.real());
    setTextColor(RED);
    cerr << "+";
    setTextColor(WHITE);
    show_val(c.imag());
    cerr << "i";
}

//! Tuple
template <typename Tuple, std::size_t N>
struct TuplePrinter
{
    static void print(Tuple t)
    {
        TuplePrinter<Tuple, N - 1>::print(t);
        std::cerr << ", ";
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
    print_opening();
    TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
    print_closing();
}

//! Range based
template <typename T, size_t N>
void show_val(const T (&t)[N])
{
    print_opening();
    for (size_t i = 0; i < N; i++)
    {
        show_val(t[i]);
        if (i + 1 < N)
            cerr << ", ";
    }
    print_closing();
}
//! "foreach" loop
template <typename T>
void show_val(set<T> t)
{
    print_opening();
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    print_closing();
}
template <typename T>
void show_val(unordered_set<T> t)
{
    print_opening();
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    print_closing();
}
template <typename T>
void show_val(multiset<T> t)
{
    print_opening();
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    print_closing();
}
template <typename K, typename V>
void show_val(map<K, V> t)
{
    print_opening();
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    print_closing();
}
template <typename K, typename V>
void show_val(multimap<K, V> t)
{
    print_opening();
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    print_closing();
}
template <typename K, typename V>
void show_val(unordered_map<K, V> t)
{
    print_opening();
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    print_closing();
}
template <typename T>
void show_val(deque<T> t)
{
    print_opening();
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    print_closing();
}
template <typename T>
void show_val(vector<T> t)
{
    print_opening();
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    print_closing();
}
template <typename T, size_t N>
void show_val(array<T,N> t)
{
    print_opening();
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    print_closing();
}
template <typename T>
void show_val(valarray<T> t)
{
    print_opening();
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    print_closing();
}
template<class T>
void show_val(tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> t)
{
    print_opening();
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    print_closing();
}

//! Pair
template <typename T, typename V>
void show_val(pair<T, V> p)
{
    print_opening();
    show_val(p.first);
    cerr << ", ";
    show_val(p.second);
    print_closing();
};

//! queue
template <typename T>
void show_val(queue<T> q)
{
    print_opening();
    for (; q.size();)
    {
        show_val(q.front());
        q.pop();
        if (q.size())
            cerr << ", ";
    }
    print_closing();
}

//! stack
template <typename T>
void show_val(stack<T> q)
{
    print_opening();
    for (; q.size();)
    {
        show_val(q.top());
        q.pop();
        if (q.size())
            cerr << ", ";
    }
    print_closing();
}
//! Priority Queue
template <typename T>
void show_val(priority_queue<T> q)
{
    print_opening();
    for (; q.size();)
    {
        show_val(q.top());
        q.pop();
        if (q.size())
            cerr << ", ";
    }
    print_closing();
}

//! Other types
template<typename T>
void show_val(T t)
{
    t = t;
    setTextColor(RED);
    cerr << "Unsupported-type";
    setTextColor(WHITE);
}

int extract_comma_after_first_variable(string s)
{
    stack<char> stk;
    int i = 0;
    while(i < (int)s.size())
    {
        if(stk.empty() and s[i] == ',') return i;
        if(s[i] == '(' or s[i] == '{' or s[i] == '[') stk.push(s[i]);
        if(s[i] == ')' or s[i] == '}' or s[i] == ']') stk.pop();
        i++;
    }
    return i;
}

//! dbg
void dbo(string s) {s = s;/* Getting rid of warnings*/}
template <typename T, typename... Args>
void dbo(string s, T &t, Args &...args)
{
    // auto it = remove(s.begin(), s.end(), ' ');
    // s.erase(it, s.end());
    int c_pos = extract_comma_after_first_variable(s);
    setTextColor(CYAN);
    string out = s.substr(0, c_pos);
    while(out.back() == ' ') out.pop_back();
    cerr << "\t";
    if(out.size() == 0 or out[0] != '"' or out.back() != '"')
    {
        cerr << out;
        setTextColor(WHITE);
        cerr << " = ";
    }
    setTextColor(WHITE);
    while((size_t)c_pos+1 < s.size() and s[c_pos+1] == ' ') c_pos++;
    s = s.substr(c_pos + (c_pos < (int)s.size()));
    show_val(t);
    cerr << endl;
    if (sizeof...(args))
        dbo(s, args...);
}
template <typename T, typename... Args>
void dbo(string s, T &&t, Args &&...args)
{
    // auto it = remove(s.begin(), s.end(), ' ');
    // s.erase(it, s.end());
    int c_pos = extract_comma_after_first_variable(s);
    setTextColor(CYAN);
    string out = s.substr(0, c_pos);
    while(out.back() == ' ') out.pop_back();
    cerr << "\t";
    if(out.size() == 0 or out[0] != '"' or out.back() != '"')
    {
        cerr << out;
        setTextColor(WHITE);
        cerr << " = ";
    }
    setTextColor(WHITE);
    while((size_t)c_pos+1 < s.size() and s[c_pos+1] == ' ') c_pos++;
    s = s.substr(c_pos + (c_pos < (int)s.size()));
    show_val(t);
    cerr << endl;
    if (sizeof...(args))
        dbo(s, args...);
}

#ifdef debug_header
#define dbg(_param...)                               \
    {setTextColor(GREEN);                        \
    cerr << "Line " << __LINE__ << ":" << endl; \
    setTextColor(WHITE);                        \
    dbo(#_param, _param);                                 \
    setTextColor(RESET);}
#else
#define dbg(_param...)
#endif