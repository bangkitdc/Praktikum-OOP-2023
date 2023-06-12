#ifndef __BINARY_TREE
#define __BINARY_TREE

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class BinaryTree {
    private:
        T value;
        std::vector<BinaryTree<T>> children;
        int numChildren;

    public:
        // Default constructor, set numChildren = 0
        BinaryTree() {
            this->numChildren = 0;
        }
        // Copy constructor
        BinaryTree(const BinaryTree<T>& other) {
            this->value = other.value;
            this->numChildren = other.numChildren;
            this->children = other.children;
        }
        // Destruktor
        ~BinaryTree() {}

        // Setter untuk value
        void setValue(const T & value) {
            this->value = value;
        }

        /*
        Menambahkan anak binary tree dengan value tertentu.
        Fungsi ini membuat sebuah BinaryTree baru dan menambahkannya ke list of children.
        BinaryTree yang baru dibuat kemudian dikembalikan sebagai return value dari fungsi ini.
        Jika jumlah children sudah lebih dari dua, lemparkan exception "Tidak bisa memiliki lebih dari dua children\n".
        */
        BinaryTree<T>& addChild(T value) {
            if (this->numChildren == 2) {
                throw "Tidak bisa memiliki lebih dari dua children\n";
            }

            BinaryTree<T> newChild;
            newChild.setValue(value);
            this->children.push_back(newChild);
            numChildren++;

            return children[numChildren-1];
        }

        /*
        Operator overloading untuk mencetak isi tree ke ostream.
        Format : <value>(<binary_tree_1>)(<binary_tree_2>)
        Tidak perlu ada newline di akhir.
        Berbagai contoh pencetakan binary tree :
        - Binary tree of integer tanpa children : 5()()
        - Binary tree of integer dengan satu children : 5(7()())()
        - Binary tree of integer dengan dua children : 5(7()())(6()())
        */
        friend ostream& operator<<(ostream& c, BinaryTree<T> tree) {
            if (tree.numChildren == 0) {
                return c << tree.value << "()()";
            }

            if (tree.numChildren == 1) {
                return c << tree.value << "(" << tree.children[0] << ")()";
            }

            return c << tree.value << "(" << tree.children[0] << ")(" << tree.children[1] << ")";
        }

};

#endif