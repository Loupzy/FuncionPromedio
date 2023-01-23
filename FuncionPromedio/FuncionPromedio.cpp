#include <iostream> 
#include <fstream>
#define MAXSIZE 128

void ejercioApuntadores()
{
    std::cout << "ejercicio de apuntadores\n";
    int valor = 66;
    int* ref2 = &valor; //operador de referencia
    *ref2 = 128;
    printf("Valor: %i  Mem:%#010x \n", *ref2, ref2);
    std::cout << "valor = " << valor << std::endl;
}

void acumular(float& a, float b)
{
    a += b;
}
int main()
{
    float valor = 0;
    int num_vals = 0;

    std::cout << "Leyendo archivo" << std::endl;

    std::ifstream file;
    file.open("datos.txt", std::ifstream::in);

    if (file.is_open())
    {
        std::cout << "archivo abierto\n";

        char buffer[MAXSIZE];

        while (!file.eof())
        {
            file.getline(buffer, MAXSIZE);
            acumular(valor, atof(buffer));

            std::cout << "El valor acumulado es : " << valor << std::endl;
            num_vals++;
        }
        valor /= num_vals;

        std::ofstream file_o("datos.txt", std::ofstream::app);
        file_o << "\nEl promedio es: " << valor << std::endl;
    }
    else
    {
        std::cout << "No se encontró el documento\n";
    }
}