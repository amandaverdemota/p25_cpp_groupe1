#include <iostream>

// Nous allons implémenter une pile d'entiers de manière très basique.
// Nous la complexifierons par la suite.

// La pile est constituée:
//    - d'un tableau d'entier, avec sa taille et son nombre d'éléments empilés
//    - des quatre fonctions: push, pop, top, print, is_empty et is_full
//      (qui testent si la pile est resp. vide ou pleine)
//      il faut les utiliser dans votre code de push et pop

//on cree une stucture de tableau qui garde tt les infos sur le tableau qu'on veut en argument


// cette fonction affiche les entiers empilés
void print(int *argv, int taille, int nb)//j'ai cherché et cette fonction permet de referencer la pile que l'on veut utiliser sans la modifier
{
    int i = 0; 
    while (i < nb) 
    {
      std::cout << argv[i] <<std::endl;
      i = i + 1;
    }
}

// renvoie true si la pile est vide, false sinon
bool is_empty(int *argv, int taille, int nb)
{
     return nb == 0;
}

// renvoie true si la pile est pleine, false sinon
bool is_full(int *argv, int taille, int nb)
{
    return nb == taille;
}

void push(int *argv, int taille, int &nb, int valeur)
// cette fonction ajoute un entier à la pile passé en argument
// elle doit s'assurer que la pile n'est pas pleine avant d'empiler
// elle lance une exception si problème
{
    if (! is_full(argv,taille,nb)){
        argv[nb]= valeur;
        nb= nb + 1;
    }
    throw std::overflow_error(std::string("we throw an exception of type: overflow_error ") + std::to_string(i));
}

int top(int *argv, int taille, int nb) // (cette fonction ne dépile pas)
// cette fonction retourne l'entier en haut de la pile (le dernier empilé)
// à la sortie de cette fonction l'élément retourné reste dans la pile
// elle doit s'assurer que la pile n'est pas vide avant de la dépiler
// elle lance une exception si problème
{
    if (! is_empty(argv,  taille,  nb)) {
        std::cout << argv[nb-1] << std::endl;
        return argv[nb-1];
        }
    throw std::underflow_error(std::string("we throw an exception of type: underflow_error ") + std::to_string(i));
}

int pop(int *argv, int taille, int nb) // (cette fonction dépile)
// cette fonction retourne l'entier en haut de la pile (le dernier empilé)
// à la sortie de cette fonction l'élément retourné n'est plus compté dans la pile
// elle doit s'assurer que la pile n'est pas vide avant de la dépiler
// elle lance une exception si problème
{
    if (! is_empty(argv,  taille,  nb) ) {
         top(argv, taille, nb);
         nb=nb-1;
        }
    throw std::overflow_error(std::string("we throw an exception of type: overflow_error ") + std::to_string(i));
}

#include <stdexcept>
// https://en.cppreference.com/w/cpp/header/stdexcept.html
// pour un exemple d'exception voir le fichier exception.cpp

int main()
{

    // on définit les 3 variables constituant la pile
    int size = 5;
    int stack[size];
    int nb = 0;

    // rajoutez aux blocks catch les erreurs
    // pouvant être déclenchées par les opérations sur la pile
    try
    {
        print(stack, size, nb); // affiche [ [
        push(stack, size, nb, -17);

        // on affiche l'élément en haut de pile
        std::cout << top(stack, size, nb) << std::endl; // affiche -17

        print(stack, size, nb); // affiche [-17 90 [

        int e = pop(stack, size, nb);
        std::cout << e << std::endl;
        print(stack, size, nb); // affiche [-17 [

        push(stack, size, nb, 20);
        push(stack, size, nb, -78);
        push(stack, size, nb, -9);
        push(stack, size, nb, -56);
        push(stack, size, nb, -9);
        push(stack, size, nb, 68);
    }
    catch (...)
    {
        // ce catch ramasse toutes les exceptions...
    }
}