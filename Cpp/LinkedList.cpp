#include <stdio.h>

/**
* class for instances of Singly Linked List, Templated for any type name
* @tparam T the type of variable to be stored in the Linked List
*/
template <typename T> class Singly_Linked_List{
	public:
		/// length of the linked list (number of nodes)
		int length;
		/// if the linked list has no nodes, this variable is true
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
	
	/// Struct for creation of nodes
	struct Node{
		T value;  ///< value stored in the node
		T* ptr;  ///< pointer to the next node
	};
	
	private:
		Node* last;  ///< the tail node of the list
		Node* head;  ///< the first node of the list
	
	/**
	* push a value to the end of the linked list
	* adds another node linked to the current tail node in constant time
	* @param val the value to be pushed into the list
	* @returns the index of the node that the value is stored in
	*/
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
		
		return this.length++; 
	}
	
	/**
	* link another list to the end of the linked list
	* adds another node linked to the current tail node in constant time
	* @param List the Singly_Linked_List instance to be pushed into the list
	*/
	void push(Singly_Linked_List List){
		this.tail->ptr= List.head;
		this.tail= List.tail;
		this.length+=List.length;
	}
	
	/**
	* pop the last node from the linked list
	* this removes the last value in O(n) time
	* @returns the value of the popped node
	*/
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
		if(this.length==0){empty=true;}  //marking the list as empty
		
		return tval;
	}
	
	/**
	* get the value stored at given index of the linked list
	* @param index of the value(node) required
	* @returns value stored in given index
	*/
	T get(int index){
		Node* curr= head;
		for(int i=0; i<index; i++){
			curr= curr->ptr;
		}
		return curr->value;
	}
	
	/**
	* remove the node at given index and adjust the links accordingly
	* @param index of the node to remove
	* @returns value of the removed node
	*/
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
		this.length--;
		if(this.length==0){empty=true;}
		
		return tval;
	}
	
	/**
	* add a node with a value to the list at a given index
	* @param index of the new node to be added
	* @param value to be stored
	*/
	void add(int index, T value){
		Node* curr= head;
		for(int i=0; i<index-1; i++){
			curr= curr->ptr;
		}
		
		Node* node= new Node();
		node->ptr= curr->ptr;
		curr->ptr= node;
	}
	
	/**
	* search for the first appearance of a value in the list
	* @param val the value to be searched
	* @returns the index of the first occurance of val, -1 if not found
	*/
	int search(T val){
		Node* curr= head;
		for(int i=0; i<length; i++){
			if(curr->value==val){return i;}
			curr= curr->ptr;
		}
		return -1;
	}
	
	/** 
	* search if the list contains a given value
	* @param val the value to be searched for
	* @returns true if the list contains the value, false otherwise
	*/
	bool contains(T val){
		Node* curr= head;
		for(int i=0; i<length; i++){
			if(curr->value==val){return true;}
			curr= curr->ptr;
		}
		return false;
	}
};
