// Testfile
// Author: Andreas Sagen
// Mandatory assigment in IN1910

#include <iostream>
#include "array_list.cpp"
#include "linked_list.cpp"
#include "circular_linked_list.cpp"

bool is_prime(int);
int last_man_standing(int, int);

int main(int argc, char **argv)
{
    // oppgave 1
    ArrayList Primes;
    int count = 0; int iteration = 2;
    while (count < 15) {
        if (is_prime(iteration) == true) {
            Primes.append(iteration);
            count++;
        }
        ++iteration;
    }
    std::cout << "Primes: "; Primes.print();

    std::cout << "-----------------" << std::endl;
    
    // Oppgave 2
    LinkedList Link({2, 3, 5, 6, 7});
    Link.append(1);
    std::cout << "Length: " << Link.length() << std::endl;
    Link.print();
    Link.insert(3, 5);
    Link.print();
    std::cout << "Length: " << Link.length() << std::endl;
    Link.remove(2);
    Link.print();
    std::cout << "pop(2) = " << Link.pop(2) << std::endl;
    Link.print();
    std::cout << "pop() = " << Link.pop() << std::endl;
    Link.print();
    int n = 1;
    std::cout << "Element " << n << ": " << Link[n] << std::endl;
    std::cout << "Length: " << Link.length() << std::endl;

    std::cout << "-----------------" << std::endl;

    // Oppgave 4
    int l = last_man_standing(68, 7);
    std::cout <<  l << std::endl;

    
    //std::cout << last_man_standing(68, 7) << std::endl;

    //system("pause");
}

bool is_prime(int n){
    if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0) {
        return true;
    } else if (n == 2 || n == 3) {
        return true;
    } else {
        return false;
    }
}

int last_man_standing(int n, int k) {
    CircLinkedList problem(n);
    problem.print();
    std::vector<int> list = problem.josephus_sequence(k);
    int l = list.back();
    std::cout << l << std::endl;
    return l;
    
}
