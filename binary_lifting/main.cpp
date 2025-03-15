#include "binary_lifting.h"
#include <iostream>

int main()
{
    int n = 9; // Number of employees (nodes)
    BinaryLifting company(n);

    // Building the corporate hierarchy (tree)
    company.addEdge(0, 1);
    company.addEdge(0, 2);
    company.addEdge(1, 3);
    company.addEdge(1, 4);
    company.addEdge(2, 5);
    company.addEdge(2, 6);
    company.addEdge(3, 7);
    company.addEdge(3, 8);

    company.preprocess(0); // CEO is at node 0

    std::cout << "2nd-level manager of employee 8: " << company.getKthAncestor(8, 2) << std::endl;                   // CEO (0)
    std::cout << "Lowest common manager of employee 7 and 8: " << company.getLowestCommonManager(7, 8) << std::endl; // 3
    std::cout << "Lowest common manager of employee 4 and 8: " << company.getLowestCommonManager(4, 8) << std::endl; // 1
    std::cout << "Lowest common manager of employee 5 and 6: " << company.getLowestCommonManager(5, 6) << std::endl; // 2
    std::cout << "Lowest common manager of employee 7 and 5: " << company.getLowestCommonManager(7, 5) << std::endl; // 0 (CEO)

    return 0;
}
