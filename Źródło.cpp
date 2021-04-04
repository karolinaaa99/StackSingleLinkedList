#include <iostream>

using namespace std;

class Elem 
{
private:
	int v; //key, data
	Elem* next_elem; //wskaznik na element nastepny
public:
	Elem(int x, Elem* n); //konstruktor, tworzy element przechwujacy x i posiadajacy wskaznik na element nastepny
	int value(); //return key
	Elem* next(); //return next_elem
	void setNext(Elem* p); //set next_elem
};

Elem::Elem(int x, Elem* n)
{
	v = x;
	next_elem = n;
}

int Elem::value()
{
	return v;
}

Elem* Elem::next()
{
	return next_elem;
}

void Elem::setNext(Elem* p)
{
	next_elem = p;
}

class LStos 
{
private:
	Elem* head; //wskaznik na szczyt stosu
public:
	LStos(); //konstruktor, tworzy pusta liste, pusty stos
	bool empty(); //zwraca true, jesli stos jest pusty, false w przeciwnym razie
	void push(int x); //dodaje element na szczyt stosu
	int pop();		//zdejmuje i zwraca daną ze stosu, usuwa element
	void clear();   //usuwa cala liste
	friend ostream& operator<<(ostream& out, LStos& s); //wyswietla stos na ekranie konsoli
};

LStos::LStos()
{
	head = NULL;
}

bool LStos::empty()
{
	if (head == NULL)
		return true;
	return false;
}

void LStos::push(int x)
{
	if (empty())
	{
		Elem* p = new Elem(x, NULL);
		head = p;
	}
	else
	{
		Elem* p = new Elem(x, head);
		head = p;
	}
}

int LStos::pop()
{
	if (empty())
		return NULL;
	else
	{
		Elem* p = head;
		int wartosc = head->value();
		head = head->next();
		delete p;
		return wartosc;
	}
}


void LStos::clear()
{
	int a = pop();
	while (a != NULL)
	{
		pop();
		a = pop();
	}
}

ostream& operator<<(ostream& out, LStos& s)
{
	Elem* temp = s.head;
	while (temp != NULL)
	{
		out << temp->value() << " ";
		temp = temp->next();
	}
	return out;
}

int main()
{
	LStos stos = LStos();

	stos.push(1);
	stos.push(2);
	stos.push(3);
	stos.push(4);
	stos.push(5);
	cout << stos << endl;

	stos.pop();
	cout << stos << endl;

	stos.clear();
	cout << stos;

	return 0;
}