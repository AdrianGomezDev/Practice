#include <iostream>
using namespace std;


class Data {
public:
	Data(int val) :ivalue(val), bvalue(0), fvalue(0), dvalue(0), cvalue(0) {}
	Data(bool val) :bvalue(val), ivalue(0), fvalue(0), dvalue(0), cvalue(0) {}
	Data(double val):dvalue(val), bvalue(0), fvalue(0), ivalue(0), cvalue(0) {}
	Data(float val):fvalue(val), bvalue(0), ivalue(0), dvalue(0), cvalue(0) {}
	Data(char val):cvalue(val), bvalue(0), fvalue(0), dvalue(0), ivalue(0) {}
	~Data() {}
	void Show();
	int Compare(const Data& data);
private: 
	int ivalue;
	bool bvalue;
	float fvalue;
	double dvalue;
	char cvalue;
};

void Data::Show() {
	
	if (ivalue != NULL) {
		cout << ivalue << endl;
	}
	else if (bvalue != NULL) {
		cout << bvalue << endl;
	}
	else if (bvalue == NULL && ivalue==NULL && dvalue == NULL && fvalue == NULL && cvalue == NULL) {
		cout << bvalue << endl;
	}
	else if (fvalue != NULL) {
		cout << fvalue << endl;
	}
	else if (dvalue != NULL) {
		cout << dvalue << endl;
	}
	else if (cvalue != NULL) {
		cout << cvalue << endl;
	}
	
}

int Data::Compare(const Data& data) {
	// 1 or 2?
	return 2; 
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
	double value;
	bool bv = true;
	char cv = 'y';
	char ccv = 'z';
	float fv = 77.77;
	bool bbv = false;
	int iv = 22222;
	int iiv = 4;
	float ffv = 3.333;

	LinkedList el;

	value = 3.2; 
	pData = new Data(value);

	el.Insert(pData);

	value = 7.8;
	Data* pDataTwo = new Data(value);

	el.Insert(pDataTwo);

	value = 8.9;
	Data* pDataThree = new Data(value);

	el.Insert(pDataThree);

	Data* bvData = new Data(bv);
	Data* cvData = new Data(cv);
	Data* ccvData = new Data(ccv);
	Data* fvData = new Data(fv);
	Data* bbvData = new Data(bbv);
	Data* ivData = new Data(iv);
	Data* iivData = new Data(iiv);
	Data* ffvData = new Data(ffv);

	el.Insert(bvData);
	el.Insert(cvData);
	el.Insert(ccvData);
	el.Insert(fvData);
	el.Insert(bbvData);
	el.Insert(ivData);
	el.Insert(iivData);
	el.Insert(ffvData);

	el.ShowList();


	return 0;
}