#ifndef STCKP1_H_
#define STCKP1_H_

//这是在做一个模板类


template <class t>
class stack
{
private:
	enum {size=10};
	int stacksize;
	t *items;
	int top;
public:
	stack(int ss=size);
	stack(const stack &st);
	~stack(){delete []items;}
	bool isempty(){return top==0;}
	bool isfull(){return top==stacksize;}
	bool push(const t &item);
	bool pop(t &item);
	stack & operator=(const stack &st);

};

template <class t>
stack<t>::stack(int ss):stacksize(ss),top(0)
{
	items=new t[stacksize];
}

template <class t>
stack<t>::stack(const stack &st)
{
	stacksize=st.stacksize;
	top=st.top;
	items=new t[stacksize];
	for(int i=0;i<top;i++)
		items[i]=st.items[i];
}

template<class t>
bool stack<t>::push(const t &item)
{
	if(top<stacksize)
	{
		items[top++]=item;
		return true;
	}
	else
		return false;
}

#endif
