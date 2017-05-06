class MinStack {
public:
    void push(int x) {
        //first push in actual stack
        realStack.push(x);
        //Next check if it is larger than current stack head if so push and pop it
        if(smallStack.empty())
        {
            smallStack.push(x);
        }
        else
        {
            int smStackHead = smallStack.top();
            if(x<=smStackHead)
             {
                smallStack.push(x);
            }
        }
        
    }

    void pop() {
        if(!realStack.empty())
        {
            int poppedElem = realStack.top();
            realStack.pop();
            //Now modify the small stack value accordingly
            int smStackHead = smallStack.top();
            if(poppedElem==smStackHead)
            {
                smallStack.pop();
            }
        }
    }

    int top() {
        return realStack.top();
    }

    int getMin() {
        return smallStack.top();
    }
    std::stack<int> realStack;
    std::stack<int> smallStack;
};