#include<iostream>
using namespace std;
class Node {
public:
	int deger;
	Node* next;
	Node(int deger) {
		this->deger = deger;
		next = NULL;
	}
};
class queue {
private:
	Node* head;
	Node* tail;
	int count;
public:
	queue(int deger) {
		Node* node = new Node(deger);
		head = node;
		tail = node;
		count = 1;
	}
	~queue() {// Destructor
		Node* tmp = head;
		while (head) {
			head = head->next;
			delete tmp;
			tmp = head;
		}
	}
	void printAll() {
		Node* tmp = head;
		while (tmp != NULL) {
			cout << tmp->deger << ", ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	int getHeadValue() {
		if (head != NULL)
			cout << "Head: " << head->deger << endl;
		else if (head == NULL) {
			cout << "Hicbir deger olmadigi icin deger yazdirilamadi!" << endl;
			return INT_MIN;
		}

	}
	int getTailValue() {
		if (tail != NULL)
			cout << "Tail: " << tail->deger << endl;
		
		else if (tail == NULL) {
			cout << "Hicbir deger olmadigi icin deger yazdirilamadi!" << endl;
			return INT_MIN;
		}

	}
	int getCount() {
		cout << "Count: " << count << endl;
		return count;

	}
	void enqueue(int deger) {
		Node* node = new Node(deger); 
		if (count == 0) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
		count++;
		
	}
	int dequeue() {
		if (count == 0)
			return INT_MIN;
		Node* tmp = head;
		int deger = head->deger;
		 if (count == 1) {
			 head = NULL;
			 tail = NULL;
		 }
		 else {
			 head = head->next;
		 }
		 cout << "tailden cikan node degeri: " << tmp->deger << endl;
		 delete tmp;
		 count--;
		 return deger;

	}
	bool isEmpty() {
		if (count == 0)
			return true;
		else
			return false;
	}
};
int main() {
	cout << "------------------------------" << endl;
	cout << "queue veri yapisi" << endl;
	cout << "------------------------------" << endl;
	queue* queue1 = new queue(1);
	queue1->printAll();
	queue1->getHeadValue();
	queue1->getTailValue();
	queue1->getCount();
	cout << "------------------------------" << endl;
	cout << "enqueue metodu ile deneme" << endl;
	cout << "------------------------------" << endl;
	queue1->enqueue(2);
	queue1->enqueue(3);
	queue1->enqueue(4);
	queue1->enqueue(5);
	queue1->printAll();
	queue1->getHeadValue();
	queue1->getTailValue();
	queue1->getCount();
	cout << "------------------------------" << endl;
	cout << "dequeue metodu ile deneme" << endl;
	cout << "------------------------------" << endl;
	queue1->dequeue();
	queue1->printAll();
	queue1->getHeadValue();
	queue1->getTailValue();
	queue1->getCount();
	cout << "------------------------------" << endl;
}