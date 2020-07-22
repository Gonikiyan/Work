/*
    HW7A - LinkedList.
    Author - Abhishek Kumbhar.
    CITE - Class Notes and Banish deep ojha.

*/

#include <iostream>

using namespace std;


class LinkedList2 {
private:
	class Node { // LinkedList2::Node
	public:
		int val;
		Node* next;

		Node():next(nullptr){}
	};
	Node* head;
	Node* tail;
public:
	LinkedList2():head(nullptr), tail(nullptr){}

	~LinkedList2(){
        Node* temp=new Node();
        for(Node* p=head; p!=nullptr; p=p->next){
            temp= p;
            delete temp;
        }
	}

	LinkedList2(const LinkedList2& orig){

        for(Node* p=orig.head; p!=nullptr; p=p->next){
            this->addEnd(p->val);
        }
	};/*
	LinkedList2& operator =(const LinkedList2& orig);
	// move constructor
	LinkedList2(LinkedList2&& orig) { // steal orig data while it's dying (nice)

	}*/
	void addStart(int v){
	Node* headtemp= new Node();
	headtemp->val = v;
	if(tail==nullptr){
        headtemp->next=nullptr;
        head=headtemp;
        tail=headtemp;
	}
	else{
        headtemp->next=head;
        head=headtemp;
	}
	}


	void addEnd(int v){
	Node* tailtemp= new Node();
	tailtemp->val = v;
	if(tail==nullptr){
        tailtemp->next=nullptr;
        head=tailtemp;
        tail=tailtemp;
	}
	else{
        tail->next=tailtemp;
        tailtemp->next=nullptr;
        tail=tailtemp;
	}

	}

	void removeStart(){
	Node* temp=head;
    if(head==nullptr){
        cout<<"Deletion not possible"<<'\n';
    }
    else{
        head=head->next;
    }
    delete temp;
	}


	void removeEnd(){
	if(tail==nullptr){
        cout<<"Deletion not possible"<<'\n';
    }
    else{
        Node* i = head;
        for (; i->next->next != nullptr; i=i->next);
        delete tail;
        i->next=nullptr;
        tail=i;
        }
    }


	friend ostream& operator <<(ostream& s, const LinkedList2& g) {

		for (Node* i = g.head; i != nullptr; i=i->next)
			s << i->val << ' ';
		return s;
	}

};
/**
  head --> nullptr

  head --> [ val=3 next= nullptr  ]

  head -->  [val=1 next= ---->  [ val=3 next= nullptr  ]



 */
int main() {
	LinkedList2 a;
	a.addStart(3); // 3 is the first element in the list
	a.addStart(1); // 1 3
	a.addStart(4); // 4 1 3
	for (int i = 1; i <= 5; i++)
		a.addEnd(i);        // 4 1 3 1 2 3 4 5
	a.removeStart();
	a.removeEnd();
	cout << a << '\n'; // print out the list, separated by spaces or commas

	LinkedList2 b = a;
  	cout << b << '\n';
/*
	LinkedList2 c;
	c.addStart(5);
	c = b; // wipe out c, copy in b
  	cout << c << '\n';*/
}

