#include "outputDocument.h"
#include "product.h"
#include <iostream>
#include <vector>
#include <cassert>

// Helper function to print the vector (for debugging purposes)
void printVector(const std::vector<Product>& products) {
    for (const auto& product : products) {
        std::cout << "Name: " << product.getName() << ", Qty: " << product.getQty() << std::endl;
    }
}

// Test the OutputDocument constructor and sorting functions
void testOutputDocument() {
    // Create a vector of products
    std::vector<Product> products = {
        Product("Garlic", 8),
        Product("Apples", 4),
        Product("Pears", 1),
        Product("Spinach", 5),
        Product("Yams", 5),
        Product("Onions", 4),
        Product("Radishes", 3),
        Product("Limes", 1),
        Product("Potatoes", 5),
        Product("Beets", 3),
        Product("Broccoli", 7),
        Product("Pumpkins", 2),
        Product("Celery", 6),
        Product("Peaches", 5),
        Product("Cauliflower", 6),
        Product("Peas", 8),
        Product("Cranberries", 10),
        Product("Cucumbers", 9),
        Product("Zucchini", 10),
        Product("Cantaloupe", 2)
    };

    // Create an OutputDocument object
    OutputDocument outputDoc("test_path", 0, products);

    // Test sorting by quantity frequency
    outputDoc.sortProductsByQtyFrequency();
    std::vector<Product> sortedByQty = outputDoc.getVectorContent();
    std::cout << "Sorted by quantity frequency:" << std::endl;
    printVector(sortedByQty);

    // Verify the sorting by quantity frequency
    assert(sortedByQty[0].getQty() == 10);
    assert(sortedByQty[1].getQty() == 10);
    assert(sortedByQty[2].getQty() == 9);
    assert(sortedByQty[3].getQty() == 8);
    assert(sortedByQty[4].getQty() == 8);
    assert(sortedByQty[5].getQty() == 7);
    assert(sortedByQty[6].getQty() == 6);
    assert(sortedByQty[7].getQty() == 6);
    assert(sortedByQty[8].getQty() == 5);
    assert(sortedByQty[9].getQty() == 5);
    assert(sortedByQty[10].getQty() == 5);
    assert(sortedByQty[11].getQty() == 5);
    assert(sortedByQty[12].getQty() == 4);
    assert(sortedByQty[13].getQty() == 4);
    assert(sortedByQty[14].getQty() == 3);
    assert(sortedByQty[15].getQty() == 3);
    assert(sortedByQty[16].getQty() == 2);
    assert(sortedByQty[17].getQty() == 2);
    assert(sortedByQty[18].getQty() == 1);
    assert(sortedByQty[19].getQty() == 1);

    // Test sorting by name
    outputDoc.sortProductsByName();
    std::vector<Product> sortedByName = outputDoc.getVectorContent();
    std::cout << "Sorted by name:" << std::endl;
    printVector(sortedByName);

    // Verify the sorting by name
    assert(sortedByName[0].getName() == "Apples");
    assert(sortedByName[1].getName() == "Beets");
    assert(sortedByName[2].getName() == "Broccoli");
    assert(sortedByName[3].getName() == "Cantaloupe");
    assert(sortedByName[4].getName() == "Cauliflower");
    assert(sortedByName[5].getName() == "Celery");
    assert(sortedByName[6].getName() == "Cranberries");
    assert(sortedByName[7].getName() == "Cucumbers");
    assert(sortedByName[8].getName() == "Garlic");
    assert(sortedByName[9].getName() == "Limes");
    assert(sortedByName[10].getName() == "Onions");
    assert(sortedByName[11].getName() == "Peaches");
    assert(sortedByName[12].getName() == "Peas");
    assert(sortedByName[13].getName() == "Pears");
    assert(sortedByName[14].getName() == "Potatoes");
    assert(sortedByName[15].getName() == "Pumpkins");
    assert(sortedByName[16].getName() == "Radishes");
    assert(sortedByName[17].getName() == "Spinach");
    assert(sortedByName[18].getName() == "Yams");
    assert(sortedByName[19].getName() == "Zucchini");

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testOutputDocument();
    return 0;
}