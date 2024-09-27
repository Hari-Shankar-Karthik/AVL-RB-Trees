#include <iostream>
#include "AVLTree.h"
#include "RBTree.h"

int main()
{
    // Instantiate AVL Tree
    AVLTree avl;
    std::cout << "Inserting elements into AVL Tree" << std::endl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(5);
    avl.insert(15);

    std::cout << "AVL Tree after insertions:" << std::endl;
    avl.describe();

    std::cout << "Erasing element 10 from AVL Tree" << std::endl;
    avl.erase(10);

    std::cout << "AVL Tree after deletion:" << std::endl;
    avl.describe();

    // Instantiate RB Tree
    RBTree rb;
    std::cout << "Inserting elements into RB Tree" << std::endl;
    rb.insert(30);
    rb.insert(40);
    rb.insert(25);
    rb.insert(35);

    std::cout << "RB Tree after insertions:" << std::endl;
    rb.describe();

    return 0;
}
