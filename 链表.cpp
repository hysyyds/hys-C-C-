#include<iostream>
using namespace std;
template <class T>
class Node{
public:
	T data;
	Node* next;
};
template <class T>
class List{
	Node<T>* head;
	Node<T>* tail;
public:
	List(){head=NULL;tail=NULL;};
	void Push_Back(T data);
	void Show();
	void DeleteOne(int index);
	void DeleteAll(T data);
	void ListCl();
	int Src(T v1);
};
template <class T>
inline void List<T>::Push_Back(T data){
	Node<T>* temp=new Node<T>;
	temp->data=data;
	temp->next=NULL;
	if(this->head){
		tail->next=temp;
	}else this->head=temp; 
	this->tail=temp;
}
template <class T>
void List<T>::Show(){
	Node<T>* temp;
	for(temp=this->head;temp;temp=temp->next){
		cout<<temp->data;
		if(temp->next){
			cout<<" ";
		}
	}
	cout<<endl;
}
template <class T>
void List<T>::DeleteOne(int index){
	if (head) {
		int i;
		Node<T>* temp = head, * temp1;
		for (temp = head, i = 0; i < index && temp != NULL; i++) {
			temp1 = temp;
			temp = temp->next;
		}
		if (temp == head) {
			head = head->next;
		}
		else {
			if (temp) {
				temp1->next = temp->next;
			}
			if (temp && temp->next == NULL) {
				tail = temp1;
			}
		}
		delete temp;
	}
}
template<class T>
int List<T>::Src(T v1){
	int i;
	Node<T>* temp;
	if(head){
	   for(temp=head,i=0;temp->data!=v1;i++,temp=temp->next){
		 if(temp->next==NULL){
			i=-1;
			break;
		 }
	   }
	}else {
	i=-2;
	}
	return i;
}
template<class T>
void List<T>::ListCl(){
	Node<T>* temp=head;
	Node<T>* temp1;
	while(temp){
	temp1=temp;
	temp=temp->next;
	delete temp1;
	}
	head=NULL;
	tail=NULL;
}
template<class T>
void List<T>::DeleteAll(T data){
//	while(Src(data)>-1){
//		DeleteOne(Src(data));
//	}
   Node<T>* temp=head,*temp1=head;
   while (temp) {
	   if (temp->data == data) {
		   if (temp == head) {
			   temp = head->next;
			   temp1 = head->next;
			   delete head;
			   head = temp;
		   }
		   else {
			   temp1->next = temp->next;
			   delete temp;
			   temp = temp1->next;
		   }
	   }
	   else {
		   temp1 = temp;
		   temp = temp1->next;
	   }
   }
   tail = temp1;
}
int main(){
    List<int> L1;
	int i;
	for (i = 0; i < 10000; i++) {
		L1.Push_Back(i);
	}
    L1.Show();
    L1.ListCl();
	return 0;
}
