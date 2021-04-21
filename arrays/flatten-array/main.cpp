#include <iostream>
#include <vector>
#include "nested_iterator.h"
#include "flatten_array.h"


int main() {
    vector<int> x{4, 5};
    NestedInteger a(x);
    NestedInteger b(1);
    NestedInteger c(2);
    NestedInteger d(3);
    NestedInteger e(6);

    vector<NestedInteger> f{d, a};
    NestedInteger g(f);
    vector<NestedInteger> h{b, c, g, e};
    NestedInteger test(h);

    vector<int> result = flat(test);
    cout << " -> ";

    for (int i : result) {
        cout << i << " ";
    }

    cout << endl << endl;

    NestedIterator it(h);

    while (it.hasNext()) cout << it.next() << " ";

    cout << endl << endl;

    vector<int> emptyVec;
    NestedInteger emptyNestedInteger(emptyVec);
    vector<NestedInteger> emptyNestedVec{emptyNestedInteger};
    NestedInteger emptyTest(emptyNestedVec);

    result = flat(emptyTest);
    cout << " -> ";

    for (int i : result) {
        cout << i << " ";
    }

    cout << endl << endl;

    it = NestedIterator(emptyNestedVec);

    while (it.hasNext()) cout << it.next() << " ";

    cout << endl << endl;

    vector<int> ones {1, 1};
    NestedInteger y(vector<int>{1, 1});
    NestedInteger z(2);
    vector<NestedInteger> ex {y, z, y};

    it = NestedIterator(ex);

    while (it.hasNext()) cout << it.next() << " ";

    cout << endl;
}