#ifndef QUEUELI_H_
#define QUEUELI_H_

template<class Object>
class Queue
{
	public:
		Queue();
		~Queue();
		
		bool isEmpty() const;
		const Object & getFront() const;
		void enqueue(const Object & x);
		Object dequeue();
		void makeEmpty();
	
	private:
		struct ListNode
		{
			Object element;
			ListNode *next;
			
			ListNode(const Object & theElement,ListNode *n=0)
			        :element(theElement),next(n){
			        	
					}
		};
		
		ListNode *front;
		ListNode *back;
};

//构造函数
template<class Object>
Queue<Object>::Queue()
{
	front=back=0;
} 

//析构函数
template<class Object>
Queue<Object>::~Queue()
{
	makeEmpty(); 
}

//清空元素
template<class Object>
void Queue<Object>::makeEmpty()
{
	while(!isEmpty())
	  dequeue();
} 

//判空 
template<class Object>
bool Queue<Object>::isEmpty() const
{
	return front==0;
}

//取队首
template<class Object>
const Object & Queue<Object>::getFront() const
{
	if(isEmpty())
	  throw "Queue is empty";
	return front->element; 
}

//入队
template<class Object>
void Queue<Object>::enqueue(const Object &x)
{
	if(isEmpty())
	  back=front=new ListNode(x);
	else
	  back=back->next=new ListNode(x);
} 

//出队
template<class Object>
Object Queue<Object>::dequeue()
{
	Object frontItem=getFront();
	ListNode *old=front;
	front=front->next;
	delete old;
	
	return frontItem;
} 


#endif
