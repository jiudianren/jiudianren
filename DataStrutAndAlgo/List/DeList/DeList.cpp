/*
 * DeList.cpp
 *
 *  Created on: 2018年10月21日
 *      Author: Administrator
 */


#include<iostream>
using std::cout;
using std::endl;

template<typename T> class Node{  //节点的定义
public:
	Node(T t):item(t),previous(0),next(0){}
	T item;
	Node* previous;
	Node* next;
};

template<typename T> class TwoWayLinkedList{  //双向链表的定义
public:
	TwoWayLinkedList():length(0),head(0),tail(0){};
	~TwoWayLinkedList();
	int getLength(){return length;}
	void add(T t);
	T get(int i);
	void insert(int i,T t);
	void del(int i);
	void display();
private:
	Node<T>* head;
	Node<T>* tail;
	int length;
};

template <typename T> void TwoWayLinkedList<T>::add(T t){  //在链表的结尾添加新元素
	if(head==0){  //如果链表为空
		head=new Node<T>(t);
		tail=head;
	}
	else {
		Node<T>* q=new Node<T>(t);  //新建一个节点储存新元素
		tail->next=q;  //加到当前链表的结尾
		q->previous=tail;  //它的前者为当前的结尾
		tail=tail->next;  //把结尾移到这个新元素
	}
	length++;
}

template<typename T> T TwoWayLinkedList<T>::get(int i){  //返还下标为i的元素
	if(i>=length||i<0) return 0;  //如果没有这个下标返还0
	int j=0;
	Node<T>* p=head;
	while(j<i){  //找到下标所指的节点
		p=p->next;
		j++;
	}
	T item=(p->T);
	return item;
}

template<typename T> void TwoWayLinkedList<T>::insert(int i, T t){  //在下标为i处插入一个新元素
	if(i<=0){  //如果下标小于等于0，插在最前面
		Node<T>* p=new Node<T>(t);
		p->next=head;
		head->previous=p;
		head=p;
		length++;
	}
	else if(i>=length) add(t);  //如果下标大于最大下标加在最后面
	else{
		Node<T>* n=new Node<T>(t);
		int j=0;
		Node<T>* t=head;
		while(j<i-1){  //找到所插位置前面的元素
			t=t->next;
			j++;
		}
		n->next=t->next;
		n->previous=t;
		(t->next)->previous=n;
		t->next=n;
		length++;
	}
}

template<typename T> void TwoWayLinkedList<T>::del(int i){  //删除下标为i的元素
	if(i<0||i>=length) return; // 如果没有这个下标直接退出
	else{
		if(length==0) return;  //如果链表为空推出
		else if(length==1){  //如果只有一个元素
			delete head;
			head=0;
			tail=0;
		}
		else if(i==0){ // 如果要删除第一个元素
			Node<T>* t=head;
			head=head->next;  //把第一个移至下一个
			head->previous=0;
			delete t;
		}
		else if(i==length-1){  //如果要删除最后一个元素
			Node<T>* t=tail;
			tail=tail->previous;  //把最后一个往前移动一位
			tail->next=0;
			delete t;
		}
		else{
			Node<T>* t=head;
			while(i>1){  //找到要删除元素的前一个
				t=t->next;
				i--;
			}
			Node<T>* p=t->next;
			t->next=p->next;
			(p->next)->previous=t;
			delete p;
		}
		length--;
	}
}

template<typename T> TwoWayLinkedList<T>::~TwoWayLinkedList(){  //拆构函数
	Node<T>* t=head;
	Node<T>* p;
	while(t!=0){  //清理每一个节点的空间
		p=t;
		t=t->next;
		delete p;
	}
}

template<typename T> void TwoWayLinkedList<T>::display(){  //按顺序显示全部元素
	T item;
	int i=0;
	while(i<length){
		item=this->get(i);
		i++;
		cout<<item<<" ";
	}
	cout<<endl;
}
