#include <Dheap/Dheap.h>

Dheap::Dheap(int _s, int _d) {
    size = _s;
    keys = new int[size];
    d = _d;
}

Dheap::~Dheap() {
    delete []keys;
}

void Dheap::Swap(int i, int j) {
    if ((i < 0)  || (j < 0) || (i > size) || (j > size))
        throw std::exception("wrong index");
    int tmp = keys[i];
    keys[i] = keys[j];
    keys[j] = tmp;
}

void Dheap::Up(int i) {
    if ((i < 0)  || (i > size))
        throw std::exception("wrong index");
    int p = (i - 1) / d;
    while ((i != 0) && (keys[p] > keys[i])) {
        Swap(i, p);
        i = p;
        p = (i-1) / d;
    }
}

void Dheap::Down(int i) {
    if ((i < 0)  || (i > size))
        throw std::exception("wrong index");
    int c = MinChild(i);
    while ((c != -1) && (keys[c] < keys[i])) {
        Swap(c, i);
        i = c;
        c = MinChild(i);
    }
}

int Dheap::min(int n, int m) {
    return ((n < m)? n : m);
}

int Dheap::MinChild(int i) {
    if ((i < 0)  || (i > size))
        throw std::exception("wrong index");
    int f = i * d + 1;
    if (f >= size)
        return -1;
    int l = min(i * d + d, size - 1);
    int minc = f;
    for (int k = f + 1; k <= l; k++)
        if (keys[minc] > keys[k])
            minc = k;
    return minc;
}

void Dheap::DoHeap() {
    int s = size;
    for (int i = s - 1; i >= 0; i--)
    Down(i);
}

void Dheap::Psort() {
    DoHeap();
    int s = size;
    while (size > 0) {
        Swap(0, size-1);
        size--;
        Down(0);
    }
    size = s;
}
