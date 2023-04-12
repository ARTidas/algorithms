#include <iostream>
#include <string>
#include <set>

std::set<std::string> polinomial_set;

void doStringMultiplicationStep(std::string polinomials) {
    if (polinomials.length() == 0) {
        return;
    }
    
    std::string first_character(1, polinomials[0]);
    polinomials.erase(0, 1);
    
    polinomial_set.insert(first_character);
    
    std::set<std::string> tmp_polinomial_set;
    for (const auto& set_element : polinomial_set) {
        std::string new_set_element = set_element + first_character;
        if (set_element.find(first_character) == std::string::npos) {
            tmp_polinomial_set.insert(new_set_element);
        }
    }
    
    for (const auto& new_set_element : tmp_polinomial_set) {
        polinomial_set.insert(new_set_element);
    }
    
    doStringMultiplicationStep(polinomials);
}

int main() {
    std::cout << "--- START -------------------------------------" << std::endl;
    
    std::string polinomials = "abcdefghi";
    doStringMultiplicationStep(polinomials);
    
    std::cout << std::endl;
    std::cout << "--- START PRINT RESULT ------------------------" << std::endl;
    int i = 0;
    for (const auto& set_element : polinomial_set) {
        std::cout << set_element << " ";
    }
    std::cout << std::endl;
    std::cout << "--- END PRINT RESULT --------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "--- END ---------------------------------------" << std::endl;
    return 0;
}

