#ifndef __VM__
#define __VM__

#include <vector>
#include <stack>
#include "utility.h"

using namespace std;

    typedef enum {
        PUSH,
        ADD,
        MULTIPLY
    } OpCode_t;


    class Code {
    public:
        OpCode_t kind;
        int val;

        //Nullary VM code (PLUS, MULT)
        Code(OpCode_t o) : kind(o) {}

        //Unary VM code (Push i)
        Code(OpCode_t o, int i) : kind(o), val(i) {}
    };

    Code newPush(int i);

    Code newPlus();

    Code newMult();

    class VM {
        vector<Code> code;
        stack<int> s;
    public:
        VM(vector<Code> c) : code(c) {}

        Optional<int> run();

    };


#endif // __VM__
