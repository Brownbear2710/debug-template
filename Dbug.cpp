#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
using ll = long long;

#define debug_header

#ifdef _WIN32
#include <windows.h>    // for win32 API functions
enum Color { BLACK, GREY = 8, BLUE , GREEN, CYAN, RED, PURPLE, LIGHT_YELLOW, WHITE };
void setTextColor(Color color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
#else // For Linux
enum Color { RED = 31, GREEN, BLUE = 34, WHITE = 37 };
void setTextColor(Color color)
{
    string s = "\033[0;" + to_string(color) + "m";
    cerr << s;
}
#endif

void show_val(string s) { cerr << "\"" << s << "\""; }
void show_val(char c) { cerr << "\'" << c << "\'"; }
void show_val(int i) { cerr << i; }
void show_val(long long i) { cerr << i; }
void show_val(unsigned long long i) { cerr << i; }
template<typename T, typename V> void show_val(pair<T,V> p);
template<typename T> void show_val(stack<T> q);
template<typename T> void show_val(queue<T> q);
template<typename T> void show_val(T t);
template<class... Args> void show_val(const std::tuple<Args...>& t);

//!Tuple
template<class Tuple, std::size_t N>
struct TuplePrinter {
    static void print(Tuple t) {TuplePrinter<Tuple, N-1>::print(t);std::cout << ", ";show_val(get<N-1>(t));}
};
template<class Tuple>
struct TuplePrinter<Tuple, 1> {static void print(const Tuple& t) { show_val(get<0>(t)); }};
template<class... Args>
void show_val(const std::tuple<Args...>& t) 
{ cerr << "{"; TuplePrinter<decltype(t), sizeof...(Args)>::print(t); cerr << "}";}

//!Range based
template<typename T> void show_val(T t)
{ cerr << "{"; int f = t.size(); for(auto &x : t) {show_val(x); if(--f) cerr << ", ";} cerr << "}";}

//!Pair
template<typename T, typename V>
void show_val(pair<T,V> p) { cerr << "{"; show_val(p.first); cerr << ", "; show_val(p.second); cerr << "}"; };

//!queue
template<typename T>
void show_val(queue<T> q) {
    cerr << "{";
    for(;q.size();) { show_val(q.front()); q.pop(); if(q.size()) cerr << ", "; }
    cout << "}";
}

//!stack
template<typename T>
void show_val(stack<T> q) {
    cerr << "{";
    for(;q.size();) { show_val(q.top()); q.pop(); if(q.size()) cerr << ", "; }
    cout << "}" << endl;
}

void dbo(string s) {}
template<typename T, typename... Args>
void dbo(string s,T t, Args... args)
{
    auto it = remove(s.begin(), s.end(), ' ');
    s.erase(it, s.end());
    cerr << "\t" <<s.substr(0,s.find(',')) << " = ";
    s = s.substr(s.find(',')+1);
    show_val(t);
    cerr << endl;
    if(sizeof...(args)) dbo(s, args...);
}


#ifdef debug_header
#define dbg(x...) setTextColor(RED); cerr << "Line " << __LINE__ << ":" << endl; setTextColor(WHITE); dbo(#x, x);
#else
#define dbg(x...)
#endif

// int main()
// {
//     // int i;
//     // cin >> i;
//     // queue<int> q1;
//     // q1.push(i);
//     // q1.push(3);
//     // q1.push(10);
//     // q1.push(8);
//     // queue<int> q2 = q1;
//     // pair<queue<int>, queue<int>> qq = {q1,q2};
//     // // db(qq);
//     // // show_val(qq);

//     // vector< pair< queue<int>, queue<int> > > v = {qq,qq};
//     // db(qq,v);
//     // set<long long> st;
//     // st.insert(1);
//     // st.insert(2);
//     // st.insert(3);
//     // db(st);
//     tuple<tuple<int,int>, pair<int,int>, char> t = {{1,2},{3,4},'a'};
//     tuple<int,int,int> tpl = {1,2,3};
//     const int sz = tuple_size<decltype(tpl)>::value-1;
//     // cout << sz;
//     dbg(tpl,t);
//     return 0;
// }