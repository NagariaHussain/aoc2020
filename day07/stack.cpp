#include <iostream>
#include <list>

using namespace std;

template<class T>
class Stack 
{
    private:
        list<T> data;

    public:
        void push(T item) { data.push_front(item); }
        T pop() { 
            T ele = top();
            data.pop_front();
            return ele; 
        }
        T top() { return *data.begin(); }
        bool isEmpty() const { return data.size() == 0; }
        int size() const { return data.size(); }
        void clear() { data.clear(); }
        void print() {
            for (const auto& d: data) {
                cout << d << "\n";
            }
        }
};


int main() {
    Stack<string> s{};

    s.push("apple");
    s.push("ball");
    s.push("cat");

    s.print();

    s.pop();
    s.print();

    return 0;
}
