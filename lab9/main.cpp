#include <iostream>

template <class Type> class MyList{
	public:
		explicit MyList();
		explicit MyList(Type _element);
		~MyList();

		void pushBack();
		void pushBack(Type _element);

		bool push(Type _element, const int &_position = 0);

//		void pushMiddle();
		void show();

	protected:
		void setNext(MyList *_next);
		void setPrevious(MyList *_previous);

		void setID(const unsigned int &_id);

		void changeID(const unsigned int _id);


	private:
		Type element;
		int id;
		int size;
		MyList *next;
		MyList *previous;
};

template <class Type> MyList<Type>::MyList(){
	next = NULL;
	previous = NULL;
	element = 0;
	size = 1;
	id = 0;
}

template <class Type> MyList<Type>::MyList(Type _element){
	next = NULL;
	previous = NULL;
	element = _element;
	size = 1;
	id = 0;
}

template <class Type> MyList<Type>::~MyList(){
	if(next != NULL){
		delete next;
	}
}

template <class Type> void MyList<Type>::pushBack(){
	size++;
	if(next==NULL){
		MyList<Type> *newElement = new MyList();
		newElement->setID(id + 1);
		newElement->setPrevious(this);
		next = newElement;
	}
	else{
		next->pushBack();
	}
}

template <class Type> void MyList<Type>::pushBack(Type _element){
	size++;
	if(next==NULL){
		MyList<Type> *newElement = new MyList(_element);
		newElement->setID(id + 1);
		newElement->setPrevious(this);
		next = newElement;
	}
	else{
		next->pushBack(_element);
	}
}

template <class Type> bool MyList<Type>::push(Type _element, const int &_position){
	if(id == _position){

		MyList<Type> *newElement = new MyList(_element);
		newElement->setID(id);
		newElement->setNext(this);
		newElement->setPrevious(previous);
		
//		std::cout<<"created\n";

		if(previous!=NULL){
			previous->setNext(newElement);
		}


		setPrevious(newElement);

//		std::cout<<"links set\n";

		this->changeID(id + 1);

//		std::cout<<"id changed\n";

		return true;
	}
	else{
		if(next != NULL){
			return next->push(_element, _position);
		}
		else{
			return false;
		}
	}
}

template <class Type> void MyList<Type>::setPrevious(MyList *_previous){
	previous = _previous;
}

template <class Type> void MyList<Type>::setNext(MyList *_next){
	next = _next;
}

template <class Type> void MyList<Type>::changeID(const unsigned int _id){
	
//	std::cout<<id<<"\n";

	id = _id;

//	std::cout<<"id = _id;\n";
	if(next != NULL){
		next->changeID(_id + 1);
	}
}

template <class Type> void MyList<Type>::setID(const unsigned int &_id){
	id = _id;
}

template <class Type> void MyList<Type>::show(){
	std::cout<<element;
	if(next!=NULL){
		next->show();
	}
	else{
		std::cout<<"\n";
	}
}


int main(){
	MyList<double> list(1.0);
	//std::cout<<"init\n";
	list.pushBack();
	//std::cout<<"pushBack\n";
	list.push(2.0, 1);
	list.push(3.0, 1);
	list.push(4.0, 1);
	list.show();
	//std::cout<<"push\n";
	return 0;
}