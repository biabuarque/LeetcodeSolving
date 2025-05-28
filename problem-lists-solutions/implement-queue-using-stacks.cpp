// problem link: https://leetcode.com/problems/implement-queue-using-stacks/

// USE TWO STACKS FOR QUEUES LOGIC
// idea: 
// time complexity:
// space complexity:

class MyQueue {
public:
		stack<int> input, output; 
    MyQueue() {}
    
    void push(int x) {
	    input.push(x);
    }
    
    int pop() {
	    int currPeak = peak();
	    output.pop();
    }
    
    int peek() {
	    if(output.empty()){
		    while(!input.empty()){
			    output.push(input.top());
			    input.pop();
		    }
	    }
	    return output.top();
    }
    
    bool empty() {
	    return (input.empty() && output.empty());
    }
};
