#include <iostream>
using namespace std;


class Data {
public:

	Data(int val):value(val) {}
	~Data() {}
	void Show() { cout << value << endl; }
	int Compare(const Data& data);
private: 
	int value;
};

int Data::Compare(const Data& data) {
	// 1 or 2?
	return 1; 
}

class Node;
class InternalNode;
class TailNode;
class HeadNode;


class Node {
public:
	Node() {}
	~Node() {}
	virtual Node* Insert(Data * data) = 0;
	virtual void Show() = 0;
private:
};

class InternalNode : public Node {
public:
	InternalNode(Data * data, Node * next);
	virtual ~InternalNode() { delete myData, delete next; }
	virtual Node* Insert(Data* theData);
	virtual void Show() { myData->Show(); next->Show(); }
	
private:
	Data *myData;
	Node* next;
};

InternalNode::InternalNode(Data* pData, Node * pNext) {
	myData = pData; 
	next = pNext;
}

Node* InternalNode::Insert(Data* theData) {
	int result = myData->Compare(*theData);

	if (result == 1) {
		// code next puts the data at the end of the list. 
		next = next->Insert(theData);
		return this;
		
		
	}
	else if (result == 2) {
		// code below puts the data in the front of the list
		InternalNode* newNode = new InternalNode(theData, this);
		return newNode;
	}
	return this;
}



class TailNode : public Node {
public:
	TailNode() {}
	virtual ~TailNode(){}
	virtual Node* Insert(Data* theData);
	virtual void Show(){}
private:
};

Node* TailNode::Insert(Data* theData) {
	InternalNode* inNode = new InternalNode(theData,this);
	return inNode;
}

class HeadNode : public Node {
public:
	HeadNode() { next = new TailNode; }
	virtual ~HeadNode() { delete next; }
	virtual Node* Insert(Data* theData);
	virtual void Show() { next->Show(); }
private:
	Node* next;
};

Node* HeadNode::Insert(Data* theData) {
	next = next->Insert(theData);
	return this;
}

class LinkedList{
public:
	LinkedList() { hNode = new HeadNode; }
	~LinkedList() { delete hNode; }
	void Insert(Data* theData);
	void ShowList() { hNode->Show(); }
private:
	HeadNode* hNode;
};

void LinkedList::Insert(Data* theData) {

	hNode->Insert(theData);

}



int main()
{
	Data* pData; 
	int value;
	LinkedList el;

	value = 3; 
	pData = new Data(value);

	el.Insert(pData);

	value = 7;
	Data* pDataTwo = new Data(value);

	el.Insert(pDataTwo);

	value = 8;
	Data* pDataThree = new Data(value);

	el.Insert(pDataThree);

	el.ShowList();


	return 0;
}