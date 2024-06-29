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
private: 
	CbinNode<S> root;
public:
	bool find(int v ,CbinNode**& ptr);
	void insert(int v);
	void recorrido(CbinNode**& ptr);
};
template <class T>
bool arbol<T>::find(int v, CbinNode<T>**& ptr) {
	CbinNode<T>** = &root;
}
int main() {
	return 0;
}