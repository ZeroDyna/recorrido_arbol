#include<iostream>
#include<stack>
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
	CbinNode<S>* root = 0;
	bool find(int v ,CbinNode<S>**& ptr);
	bool insert(int v);
	void recorrido(CbinNode<S>**& ptr);
	void printin(CbinNode<S>* rt);
	void recorrido_pila();
};
template<class T>
void arbol<T>::printin(CbinNode<T>* rt){
	if (rt == 0) {
		return;
	}
	printin(rt->nodes[0]);
	std::cout << rt->valor << " ";
	printin(rt->nodes[1]);
}
template <class T>
bool arbol<T>::find(int v, CbinNode<T>**& ptr) {
	for (ptr = &root; (*ptr) && (*ptr)->valor != v; ptr = &((*ptr)->nodes[(*ptr)->valor < v]));
	return (*ptr) && (*ptr)->valor == v;
}
template<class T>
bool arbol<T>::insert(int v) {
	CbinNode<T>** rec;
	if (find(v, rec)) return 0;
	else
		(*rec) = new CbinNode<T>(v);
}
template<class T>
void arbol<T>::recorrido_pila() {
	if (root == 0) {
		std::cout << "no hay elementos";
		return;
	}
	std::stack<std::tuple<CbinNode<T>*, int>> obj;
	obj.push(std::make_tuple(root, 0));
	while (!obj.empty()) {
		std::tuple<CbinNode<T>*, int> sub_obj = obj.top();
		obj.pop();
		CbinNode<T>* node = std::get<0>(sub_obj);
		int estado = std::get<1>(sub_obj);
		if (node == 0) {
			continue;
		}
		if (estado == 0) {
			obj.push(std::make_tuple(node->nodes[1], 0));//no olvidar que al momento de hacer una tupla
			obj.push (std::make_tuple(node, 1));			// se usa el std::make_tuple
			obj.push(std::make_tuple(node->nodes[0], 0));
		}
		else if (estado == 1) {
			std::cout << node->valor << " ";
		}
	}
	

}
int main() {
	arbol<int> test;
	test.insert(7);
	test.insert(4);
	test.insert(2);
	test.insert(10);
	test.insert(8);
	test.insert(11);
	test.insert(6);
	test.insert(5);
	test.insert(15);
	test.printin(test.root);
	test.recorrido_pila();
	return 0;
}