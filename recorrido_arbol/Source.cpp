#include<iostream>
#include <tuple>
template <class T>
struct CbinNode {
	T valor;
	CbinNode* nodes[2];
	CbinNode(T val) {
		valor = val;
		nodes[0] = 0;
		nodes[1] = 0;
	}
};
template <class S>
class arbol {
public:
	CbinNode<S> root;
	bool find(int v ,CbinNode<S>**& ptr);
	void insert(int v);
	void recorrido(CbinNode<S>**& ptr);
};
template <class T>
bool arbol<T>::find(int v, CbinNode<T>**& ptr) {
	CbinNode<T>** rec= &root;
	for (; (*rec) && (*rec)->valor != v; (*rec)->nodes[(*rec)->valor < v]);
	return (*rec) && (*rec)->valor == v;
}
template<class T>
void arbol<T>::insert(int v) {
	CbinNode<T>** rec;
	if (!find(v, rec)) {
		(*rec) = new CbinNode(v);
	}
	else
		return;
}
int main() {
	return 0;
}