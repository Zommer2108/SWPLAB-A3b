
#include "vm.h"
#include "utility.h"

Code newPush(int i) {
    return Code(PUSH, i);
}

Code newPlus() {
    return Code(ADD);
}

Code newMult() {
    return Code(MULTIPLY);
}


Optional<int> VM::run() {

    stack<int> d;
    s.swap(d);

    for(unsigned int i = 0; i < code.size(); i++) {
        switch(code[i].kind) {
            case PUSH:
                s.push(code[i].val);
                break;

            case MULTIPLY: {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left * right);
                break;
            }

            case ADD: {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                s.push(left + right);
                break;
            }
        }
    }

    if(s.empty())
        return nothing<int>();

    return just<int>(s.top());
}
