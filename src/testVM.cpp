
#include <iostream>
#include <string>
#include "ast.h"
#include "vm.h"

using namespace std;

void showVMRes(Optional<int> r) {
    if(r.isNothing())
        cout << "\nVM stack (top): empty";

    cout << "\nVM stack (top):" << r.fromJust();


}

void testVM() {

    {
        vector<Code> vc{
                newPush(1),
                newPush(2),
                newPush(3),
                newMult(),
                newPlus() };

        Optional<int> res = VM(vc).run();

        showVMRes(res);
    }

    {
        vector<Code> vc{
                newPush(2),
                newPush(3),
                newPush(5),
                newPlus(),
                newMult() };

        Optional<int> res = VM(vc).run();

        showVMRes(res);
    }

    auto tree = newPlus(newInt(1),newMult(newInt(2),newInt(3)));    // 1 + 2 * 3
    vector<Code> code = tree->translate();                                             //1 + 2 * 3 = 7

    Optional<int> res = VM(code).run();
    showVMRes(res);

    auto tree1 = newPlus(newInt(2), newMult(newInt(2), newInt(2))); // 2 + 2 * 2
    vector<Code> code1 = tree1->translate();                                            // 2 + 2 * 2 = 6
    Optional<int> res1 = VM(code1).run();
    showVMRes(res1);

    auto tree2 = newMult(newInt(2), newPlus(newInt(0), newInt(2))); // 2 * (0 + 2)
    vector<Code> code2 = tree2->translate();                                            // 2 * 2 = 4
    Optional<int> res2 = VM(code2).run();
    showVMRes(res2);

    auto tree3 = newPlus(newMult(newPlus(newInt(2),newInt(1)),newInt(0)),newMult(newInt(2),newInt(2))); // (2 + 1) * 0 + 2 * 2
    vector<Code> code3 = tree3->translate();                                                                                              // 3 * 0 + 4 = 4
    Optional<int> res3 = VM(code3).run();
    showVMRes(res3);

    auto tree4 = newPlus(newInt(2), newMult(newInt(0), newInt(2))); // 2 + 0 * 2
    vector<Code> code4 = tree4->translate();                                             // 2
    Optional<int> res4 = VM(code4).run();
    showVMRes(res4);
}


int main() {

    testVM();

    return 0;
}
