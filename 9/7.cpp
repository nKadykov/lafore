#include <iostream>
using namespace std;

class Counter {
protected:
    unsigned int count;
public:
    Counter(): count() {}
    Counter(int c): count(c) {}
    unsigned int get_count() const {
        return count;
    }
    Counter operator++() {
        return Counter(++count);
    }
};

class CountDn: public Counter {
public:
    CountDn(): Counter() {}
    CountDn(int c): Counter(c) {}
    CountDn operator--() {
        return CountDn(--count);
    }
};

class Count: public CountDn {
public:
    Count(): CountDn() {}
    Count(int c): CountDn(c) {}
    Count operator++(int) {
        return Count(count++);
    }
    Count operator--(int) {
        return Count(count--);
    }
    using CountDn::operator++;
    using CountDn::operator--;
};

int main() {
    CountDn c1;
    CountDn c2(100);

    cout << "c1 = " << c1.get_count() << endl;
    cout << "c2 = " << c2.get_count() << endl;

    ++c1;
    ++c1;
    ++c1;

    cout << "c1 = " << c1.get_count() << endl;

    --c2;
    --c2;

    cout << "c2 = " << c2.get_count() << endl;

    CountDn c3 = --c2;
    cout << "c3 = " << c3.get_count() << endl;

    Count c(1);
    c++;
    cout << c.get_count() << endl;
    c--;
    cout << c.get_count() << endl;
    ++c;
    cout << c.get_count() << endl;
    --c;
    cout << c.get_count();

    return 0;
}