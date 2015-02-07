/************************************
 * Implement a queue using an array *
 * Author: Sanket Patel				*
 ************************************/

#include <iostream>
using namespace std;

const int max_size = 5;

class QueueOverFlowException { 
	public: 
	QueueOverFlowException() { cout << "Queue overflow" << endl; }
};

class QueueEmptyException { 
	public: 
	QueueEmptyException() { cout << "Queue empty" << endl; }
};

template <class T>
class queue{
	
	private:
		int size, first, last;
		T arr[max_size];
	
	public:
		queue(){ size = 0, first = 0, last = 0;	}
		
		void enqueue(T value) throw (QueueOverFlowException){
			if(size == max_size) throw QueueOverFlowException();
			arr[last] = value;
			last = (last + 1) % max_size;
			size++;
		}
		
		T dequeue() throw (QueueEmptyException) {
			if (size == 0) throw QueueEmptyException();
			T ans = arr[first];
			first = (first + 1) % max_size;
			size--;
			return ans;
		}
		
		void print(){
			// cout << "Size: " << size << ";\tFirst: " << first << ";\tLast: " << last << ';' << endl;
			cout << '{';
			for (int i=0; i<size-1; i++) cout << arr[(i+first) % max_size] << ", ";
			if(size>0) cout << arr[(first+size-1) % max_size];
			cout << '}' << endl;
		}
};

int main() {
	// your code goes here
	
	queue<int> q;
	int x;
	
	try{
		q.print();
		q.enqueue(1);
		q.print();
		q.enqueue(2);
		q.print();
		q.enqueue(3);
		q.print();
		q.enqueue(4);
		q.print();
		q.enqueue(5);
		q.print();
		x = q.dequeue();
		q.print();
		x = q.dequeue();
		q.print();
		x = q.dequeue();
		q.print();
		x = q.dequeue();
		q.print();
		x = q.dequeue();
		q.print();
		// x = q.dequeue();
	}
	
	catch (...){ cout << "Terminating" << endl; }
	
	return 0;
}