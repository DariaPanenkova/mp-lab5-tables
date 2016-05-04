#pragma once
#include <iostream>

template <class T>
class Node
{
	private:
	
	T data;
	Node<T> *next;

	public:

	Node()
	{
		SetData(T());
		SetNext(NULL);
	}

	Node(T d)
	{
		SetData(d);
		SetNext(NULL);
	}

	Node(T d, Node<T> *n)
	{
		SetData(d);
		SetNext(n);		
	}
	void SetData(T d)
	{
		data = d;
	}
	void SetNext(Node<T> *n)
	{
		next = n;
	}
	T GetData()
	{
		return data;
	}
	Node<T> * GetNext()
	{
		return next;
	}
};


template <class T>
class List
{
	private:
	

	Node<T> *head;
	Node<T> *fhead;
	Node<T> *tail;


	int size;

	public:
	
	List()
	{
		fhead = new Node<T>;
		head = fhead;
		tail = fhead;
		size = 0;	
	}
	Node<T>* GetHead()
	{
		return head;
	}
	int GetSize()
	{
		return size;
	}
	void AddToHead(T d)
	{
		Node<T>*temp;
		
		if(size == 0)
		{	
			temp = new Node<T>(d,NULL);
			tail = temp;
		}
		else
		{
			temp = new Node<T>(d,head);
		}
		fhead->SetNext(temp);
		head = temp;
		size++;
	}

	void AddToTail(T d)
	{
		Node<T>*temp = new Node<T>(d,NULL);
			
		tail->SetNext(temp);
		tail = temp;

		if(size == 0)
			head = tail;
		size++;
	}
	void AddSortElem(T d)
	{
		Node<T>*temp =  new Node<T>(d) ;

		if(size==0)
		{
			AddToTail(d);
			return;
		}
		if(d > head->GetData() ) //if=
		{	
			AddToHead(d);
			return;
		}
		if( d < tail->GetData())
		{
			AddToTail(d);
			return;
		}

		Node<T> *curr = head;
		Node<T> *prevcur = head;

		while ( d < curr->GetData()) 
		{
			prevcur=curr;
			curr = curr->GetNext();
			if(curr == NULL)
				break;
		}

		prevcur->SetNext(temp);
		temp->SetNext(curr);
	}

	Node<T> *GetElm(int pos)
	{
	
		if((pos>size) || (pos<0)) 
			throw("выход за границы списка");

		Node<T> *curr = head;		
		for(int i=0; i<pos; i++)
		{
			curr = curr->GetNext();
		}
		return curr;
	}

	bool IsEmpty()
	{
		if ( size == 0 )
			return true;

		return false;
	}

	void DeleteElem(Node<T> *n)
	{
		if ( !(IsEmpty()) )
		{
			Node<T> *curr = head;
			Node<T> *prevcurr = fhead;
			Node<T> *temp=curr;


			while(( curr != NULL))
			{
				if( n == curr)
				{
					temp = curr;
					curr=curr->GetNext();
					prevcurr->SetNext(curr);
					delete temp;
					break;
				}
				prevcurr = curr;
				curr = curr->GetNext();

			}

		}
		size--;
	}
};