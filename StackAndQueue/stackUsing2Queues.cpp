#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class stack{
public:
	queue<T> * q1, q2;

	stack(){
		q1 = new queue<T>();
		q2 = new queue<T>();
	}

	int getSize(){
		return q1 -> size();
	}

	void push(T data){
		q1->push(data);
	}

	T pop(){
		while(q1->size() > 1){
			q2->push(q1->front());
			q1->pop();
		}
		T ans = q1->front();
		q1->pop();
		queue<T> * temp = q1;
		q1 = q2;
		q2 = temp;
		return ans;
	}

	T top(){
		while(q1->size() > 1){
			q2->push(q1->front());
			q1->pop();
		}
		T ans = q1->front();
		q1->pop();
		q2->push(ans);
		queue<T> *temp = q1;
		q1 = q2;
		q2 = temp;
		return ans;
	}
};