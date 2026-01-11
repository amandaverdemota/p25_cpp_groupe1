#include <iostream>
#include <stdexcept>

// vr: appelez plutôt votre argument avec un nom de pile genre stack
void print(int *stack, int taille, int nb)
{
    // vr: affichez '[' pour voir l'affichage même si la pile est vide
    std::cout << '[';
    // vr: utilisez plutôt un for (pour apprendre le for et c'est ce qui convient ici)
    for (int i= 0; i< nb;i++);
    {
        std::cout << stack[i] << " ";
    }
    // vr: affichez '['
    std::cout << '[' << std::endl;
}

bool is_empty(int *argv, int taille, int nb)
{
    return nb == 0;
}

bool is_full(int *argv, int taille, int nb)
{
    return nb == taille;
}

// vr: testez cette fonction et essayez de comprendre pourquoi elle ne fonctionne pas
void push(int *stack, int taille, int &nb, int valeur)
{
    if (is_full(stack, taille, nb))
    {
        throw std::overflow_error(
            "On ne peut pas rajouter l'élément" + std::to_string(valeur) +
            ": la pile est pleine");
    }
    stack[nb] = valeur;
    nb++;
}
// vr: même erreur
int top(int *stack, int taille, int nb) // (cette fonction ne dépile pas)
{
    if (is_empty(stack, taille, nb))
    {
        throw std::underflow_error(
            "La pile est vide, on ne peut rien renvoyer. ");
        }
     return stack[nb - 1];   

}

// vr: même erreur
int pop(int *stack, int taille, int nb) // (cette fonction dépile)
{
    if (is_empty(stack, taille, nb))
    {
        throw std::underflow_error(
            "La pile est vide.");
    }
    int value = stack[nb - 1];
    nb--;
    return value;
}

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