// Problem link: https://leetcode.com/problems/implement-queue-using-stacks/
// This problem is pretty tedious and I don't see much learning value in it, don't waste too much time on it

class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;

    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        return x;
    }
    
    bool empty() {
        if(s1.empty()) { return s2.empty(); }
        else { return false; }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
