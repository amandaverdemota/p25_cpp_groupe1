#include <iostream>
#include <stdexcept>

class Stack
{
private:
    int* tab;
    int nb;
    int size;   
     

public:
    Stack(int size)
        : size(size), nb(0)
    {
        std::cout << "Stack::Stack(int)\n";
        tab = new int[size];//on crée de la place pour un nombre size d'entiers dans le tableau 
    }

//Constructeur de copie de l'exercice
Stack(const Stack& other) // on veut copier le tableau stack 
    : size(other.size), nb(other.nb)// on utlise les meme size et meme nb mais avec other pour que la copie soit inddépendante
{
    tab = new int[size];//on crée le nouveua tableau mais vec la mm place
    for (int i = 0; i < nb; i++)
        tab[i] = other.tab[i];//mtn il suffit de parcourir le tableau et de copier une par une les valuers du tableau orignal 
}


Stack(int size)
{
    tab = new int[size];
}

~Stack()
{
    delete[] tab;
}


void print()
{
    std::cout << "[ ";
    for (int i = 0; i < nb; i++)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << "]" << std::endl;
}

bool is_empty()
{
    return nb == 0;
}

bool is_full()
{
    return nb == size;
}

void push(int x)
{
    if (is_full())
    {
        throw std::invalid_argument("pilepleine");
    }
    tab[nb] = x;
    nb = nb + 1;
}

int top()
{
    if (is_empty())
    {
        throw std::invalid_argument("pile vide");
    }
    return tab[nb - 1];
}

int pop()
{
    if (is_empty())
    {
        throw std::invalid_argument("pile vide");
    }
    nb = nb - 1;
    return tab[nb];
}
};


int main()
{
    try
    {
        Stack s1(5);
        s1.push(10);
        s1.push(20);
        s1.print();

        Stack s2(s1);   // constructeur de copie
        s2.push(30);
        s2.print();

        Stack s3(3);
        s3 = s1;        // opérateur d'affectation
        s3.print();
    }
    
    return 0;
}