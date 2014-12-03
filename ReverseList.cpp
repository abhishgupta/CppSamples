#include<iostream>

using namespace std;

struct node{
	string value;
	node* next;
};

class mList{
private:
	node* head;

public:
	mList(){
		head = NULL;
	}

	void add(string v){
		node *n = new node();
		n->value = v;
		n->next = NULL;
		if(head != NULL){
			node* temp = head;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = n;
		}else{
			head = n;
		}
	}

	void print(){
		node* temp = head;
		cout<<"list: ";
		while(temp != NULL){
			cout<<temp->value<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}

	void reverse(){
		node* temp1 = head;
		node* temp2 = NULL;
		node* temp3 = NULL;
		
		while(temp1 != NULL){
			head = temp1;
			temp2 = temp1->next;
			temp1->next = temp3;
			
			temp3 = temp1;
			temp1 = temp2;
		}

	}

	~mList(){
		node* temp = head;
		while(temp != NULL){
			node* temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
	}


};

int main(int argc, char** argv){	
	mList *ml = new mList();
	ml->add("this");	
	ml->add("is");	
	ml->add("a");	
	ml->add("reverse");	
	ml->add("test.");	

	ml->print();
	ml->reverse();

	ml->print();

}
