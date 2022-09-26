#include <stdio.h>

template <typename T> class Singly_Linked_List{
	public:
		int length;
		bool empty;
	
	Singly_Linked_List(){
		length=0;
		empty=true;
	}
	
	~Singly_Linked_List(){
		Node* curr= head;
		
		while(curr->ptr!=NULL){
			Node* last= curr;
			delete last;
			curr= curr->ptr;
		}
		
		delete curr;
	}
	
	struct Node{
		T value;
		T* ptr;
	};
	
	private:
		Node* last;
		Node* head;
	
	int push(T val){
		Node* node= new Node;
		node->value=val;
		node->ptr=NULL;
		
		if(!this.empty){
			last->ptr= node;
		}
		else{
			head= node;
		}
		last= node;
		
		return this.length++; //returns the index of the node
	}
	
	T pop(){
		Node* curr= head;
		Node* prev= NULL;
		
		while(curr->ptr!=NULL){
			prev= curr;
		}
		
		T tval= curr->value;
		
		delete curr;
		prev->ptr= NULL;
		
		this.length--;
		
		return tval;
	}
	
	T get(int index){
		Node* curr= head;
		for(int i=0; i<index; i++){
			curr= curr->ptr;
		}
		return curr->value;
	}
	
	T remove(int index){
		Node* curr= head;
		Node* prev= NULL;
		for(int i=0; i<index; i++){
			prev->ptr= curr;
			curr= curr->ptr;
		}
		T tval= curr->value;
		prev->ptr= curr->ptr;
		
		delete curr;
		
		return tval;
	}
	
	void add(int index, T value){
		Node* curr= head;
		for(int i=0; i<index-1; i++){
			curr= curr->ptr;
		}
		
		Node* node= new Node();
		node->ptr= curr->ptr;
		curr->ptr= node;
	}
	
	int search(T val){
		Node* curr= head;
		for(int i=0; i<length; i++){
			if(curr->value==val){return i;}
			curr= curr->ptr;
		}
		return -1;
	}
	
	bool contains(T val){
		Node* curr= head;
		for(int i=0; i<length; i++){
			if(curr->value==val){return true;}
			curr= curr->ptr;
		}
		return false;
	}
};
