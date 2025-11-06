#include <iostream>
#include <string>  // pour std::stoi

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "not enough arguments" << std::endl;
        return -1;
    }
// c'est inferieur strict à 2 car le premier terme de commande est aussi inclus dans le argv
//initialisons la somme 
    int somme = 0;

    // Addition de tous les arguments
    for (int i = 1; i < argc; ++i) { //ne pas depasser le nombre d'arguments
        try {
            somme += std::stoi(argv[i]);  // raduire une chaîne de caractère en un entier avec les focntions données dans le mail
        } catch (const std::invalid_argument& e) {
            std::cerr << "invalid argument: " << argv[i] << std::endl;//commande aux qui renvoie erreur si l'arg n'est pas un int 
            return -1;
        } 
    }

    std::cout << "le résultat est: " << somme << std::endl;
    return 0;
}