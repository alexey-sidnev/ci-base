#include "CNode.h"
#include "MyList.h"
#include "iostream"

using namespace std;
/*
CNode* CreateList(int count, const int* vals) {
  if (count <= 0) return 0;
  CNode *head = new CNode;
  head->val = vals[0];
  CNode *prev = head;
  for (int i = 1; i < count; ++i) {
    CNode *node = new CNode;
    node->val = vals[i];
    prev->next = node;
    prev = node;
  }
  prev->next = 0;
  return head;
}

void print(CNode *t)
{
    CNode *T=t;
	do
	{   
		cout<<t->val<<endl;
		t=t->next;
	}
	while (t!=T);
}

bool Cycle(CNode *t)
{
	CNode *F, *S;
	F=S=t;
	if (t == NULL) return false;
	if (F->next == NULL) return false;
	else F = F->next;
	while (true) {
    if (F->next == NULL || F->next->next == NULL)
      return false;
    if (F->next == S || F->next->next == S)
      return true;
    F = F->next->next;
    S = S->next;
	}
}

int size(CNode *pf) {
  int Size = 0;
  while (pf != 0) {
    pf = pf->next;
    Size++;
  }
  return Size;
}

bool compare(CNode *pf1, CNode *pf2) {
  if (size(pf1) != size(pf2))
    return false;
  else
    while (pf1 != 0 && pf2 != 0) {
      if ((pf1->val) != (pf2->val))
        return false;
      pf1 = pf1->next;
      pf2 = pf2->next;
    }
  return true;
}
void sort(CNode **t)
{
  if ((*t) == 0)
    throw std::exception("NULL");
  if ((*t)->next == 0)
    return;
  if ((*t)->next->next == 0) {
    if ((*t)->val > (*t)->next->val) {
      CNode *t1 = (*t)->next;
      (*t)->next->next = *t;
      (*t)->next = 0;
      (*t) = t1;
    }
   return;
  }
  CNode *tmp;
  int flag = 0;
  while (flag == 0) {
    flag = 1;
    tmp = (*t);
    if (tmp->val > tmp->next->val) {
      flag = 0;
      CNode *t1 = (*t)->next;
      CNode *t2 = (*t)->next->next;
      (*t)->next->next = (*t);
      (*t)->next = t2;
      (*t) = t1;
    }
    while (tmp->next->next != 0) {
      if (tmp->next->val > tmp->next->next->val) {
        CNode *t1 = tmp->next;
		CNode *t2 = tmp->next->next;
		CNode *t3 = tmp->next->next->next;
        flag = 0;
        t2->next = t1;
        t1->next = t3;
        tmp->next = t2;
      }
      tmp = tmp->next;
    }
  }
}

//Для списка на массивах
List::List(int n) {
  if (n <= 0)
    throw std::exception("Wrong size");
  data = new double[n + 2];
  index = new int[n + 2];
  current = 0;
  index[0] = 0;
  for (int i = 1; i < n + 1; i++)
    index[i] = i + 1;
  index[n + 1] = 1;
}

List::~List() {
	delete[]data;
	delete[]index;
}

void List::Movenext() {
	current = index[current];
}

void List::print() {
	int i = index[0];
	while (i != 0) {
		cout<<data[i]<<endl;
		i = index[i];
	}
}

void List::DelFreeNode(int i) {
  int tmp = index[i];
  index[i] = index[tmp];
  index[tmp] = -1;
}

void List::AddNewNode(int i, int j) {
  int tmp = index[i];
  index[i] = j;
  index[j] = tmp;
}

void List::Add(double l) {
  if (index[1] == 1)
    throw std::exception("Full List");
  int tmp = index[1]; 
  this->DelFreeNode(1);
  this->AddNewNode(current, tmp);
  data[tmp] = l;
}

void List::Del() {
  if (index[0] == 0)
    throw std::exception("No elements in list");
  if (index[current] == 0)
    this->Movenext();
  int tmp = index[current]; 
  this->DelFreeNode(current);
  this->AddNewNode(1, tmp);
}*/

	
template <class Tp>
List<Tp>::List() {
	pFirst = 0;
}

template <class Tp>
List<Tp>::~List() {
  Node<Tp> *tmp = pFirst;
	while (pFirst) {
		pFirst = pFirst->Next;
		delete tmp;
		tmp = pFirst;
	}
}

template <class Tp>
List<Tp>::List(const List<Tp> &L) {
  pFirst = 0;
  Node<Tp>* tmp = L.pFirst;
  while (tmp != 0) {
    InSertLast(tmp->val);
    tmp = tmp->Next;
  }
}

template <class Tp>
Node<Tp>* List<Tp>::GetFirst() const {
	return pFirst;
}

template <class Tp>
void List<Tp>::InSertLast(Node<Tp> *n) {
	if (pFirst == 0) {
		pFirst == n;
		pFirst->Next;
	}
	Node<Tp> *tmp = pFirst;
	while (tmp != 0)
		tmp = tmp->next;
	tmp->next = n;
	tmp->next->next = 0;
}

template <class Tp>
void List<Tp>::InSertFirst(Node<Tp> *n) {
	n->Next = pFirst;
	pFirst = n;
}

template <class Tp>
void List<Tp>::InSert(Node<Tp> *n, Tp t) {
	try {
		Search(t);
	}
	catch(...) {
		throw exception("No element");
	}
	Node<Tp> *tmp = Search(t);
	n->Next = tmp->Next;
	tmp->Next = n;
}

template <class Tp>
Node<Tp>* List<Tp>::Search(Tp t) {
  if (pFirst == 0)
    throw exception("List is empty");
  Node<Tp>* tmp = pFirst;
  while ((tmp != 0) && (tmp->val != t))
    tmp = tmp->Next;
  if (tmp == 0)
    throw exception("No element");
    //return 0;
  return tmp;
}

template <class Tp>
void List<Tp>::print() {
  if (pFirst == 0) {
    cout << "List is empty" << endl;
    return;
  }
  Node<Tp> *tmp = pFirst;
  while(tmp != 0) {
    cout << tmp->val << " ";
    tmp = tmp->Next;
  }
  cout << endl;
}

template <class Tp>
Node<Tp>* List<Tp>::Delete(Tp t) {
	if (pFirst == 0)
	  throw exception("List is empty");
	Node<Tp> *tmp = pFirst;
	if (pFirst->val == t) {
		pFirst = tmp->Next;
		tmp->Next = 0;
		return tmp;
	}
	while ((tmp->Next != 0)&&(tmp->Next->val != t))
		tmp = tmp->Next;
	if (tmp->Next == 0)
      throw exception ("No element");
	//return 0;
	Node<Tp> *tmp1 = tmp->Next;
	tmp->Next = tmp1->Next;
	tmp1->Next = 0;
	return tmp1;
}


