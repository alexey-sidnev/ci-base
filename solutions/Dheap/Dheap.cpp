#include "Dheap.h"

Dheap::Dheap(int _s, int _d) {
	size = _s;
	keys = new int [size];
	for(int i = 0; i < size; i++)
		keys[i] = rand()%100;
	d = _d;
}

Dheap::~Dheap() {
	delete []keys;
}

void Dheap::Swap(int i, int j) {
	int tmp = keys[i];
	keys[i] = keys[j];
	keys[j] = tmp;
}

void Dheap::Up(int i) {
	int p = (i-1) / d;
	while (p > 0 && keys[p] > keys[i]) {
		Swap(i,p);
		i = p;
		p = (i-1) / d;
	}
}

void Dheap::Down(int i) {
	int c = MinChild(i);
	while(c != -1 && keys[c] < keys[i]) {
		Swap(c,i);
		i = c;
		c = MinChild(i);
	}
}

int Dheap::MinChild(int i) {
	int f = i * d + 1;
	if (f > size - 1)
		return -1;
	int l = min(i * d + d, size - 1);
	int minc = f;
	for(int k = f; k <= l; k++)
		if (keys[minc] > keys[k])
			minc = k;
	return minc;
}

void Dheap::DoHeap() {
	for (int i = 0; i < size; i++)
    Up(i);
}

void Dheap::Add(int n) {
	keys[size] = n;
	Up(size);
	size++;
}

void Dheap::Psort() {
	DoHeap();
	int n = size;
	while (size > 0) {
		Swap(0, size-1);
		size--;
		Down(0);
	}
	size = n;
}



