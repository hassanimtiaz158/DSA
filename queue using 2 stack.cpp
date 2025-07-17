#include <iostream>
#include <stack>
using namespace std;

class queue{
	private:
		stack<int> stack1;
		stack<int> stack2;
	public:
		void enqueue(int x){
			stack1.push(x);
		}
		void dequeue(){
			if(stack2.empty()){
				while(!stack1.empty()){
					stack2.push(stack1.top());
					stack1.pop();
				}
			}
			if(!stack2.empty()){
				cout<<stack2.top()<<" ";
				stack2.pop();
			}
		}
		
};

int main(){
	queue q;
	q.enqueue(2);
	q.enqueue(4);
	q.enqueue(1);
	q.enqueue(7);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	
	return 0;
}
