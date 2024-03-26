#include <iostream>
#include <iomanip>
using namespace std;
// Función para crear una matriz dinámica de tamaño 'n' x 'n'


int** crearMatriz(int n) {
    int** matriz = new int*[n];
    for (int i = 0; i < n; ++i) {
        matriz[i] = new int[n];
    }
    return matriz;
}

void Rotar90Grados(int **matriz,int TamanoMatriz){

    int **TemporalMatriz = crearMatriz(TamanoMatriz);
    for (int i = 0; i < TamanoMatriz; ++i) {
        for (int j = 0; j < TamanoMatriz; ++j) {
            TemporalMatriz[j][TamanoMatriz - i - 1] = matriz[i][j];
        }
    }

    for (int i = 0; i < TamanoMatriz; ++i) {
        for (int j = 0; j < TamanoMatriz; ++j) {
            matriz[i][j] = TemporalMatriz[i][j];
        }
    }

    for (int i = 0; i < TamanoMatriz; ++i)
        delete[] TemporalMatriz[i];
    delete[] TemporalMatriz;

}




void imprimirMatriz(int** matriz, int n) {

    int AnchoMaximo= to_string(n*n).length()+1;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            if(matriz[i][j]==-1){

                cout<<setw(AnchoMaximo)<<" ";

            }
            else{

                cout <<setw(AnchoMaximo)<< matriz[i][j];

            }

        }
        cout << std::endl;
    }
    cout << std::endl; // Espacio entre matrices
}

// Función para eliminar una matriz dinámica
void eliminarMatriz(int** matriz, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

// Función para crear un número ilimitado de matrices
void crearMatrices() {
    int n;
    // Lista para almacenar los tamaños de las matrices
    int* tamanos = new int[100]; // Asumimos un límite práctico de 100 matrices para este ejemplo
    int contador = 0;

    std::cout << "Ingrese los tamanios de las matrices (0 para terminar): "<<endl;
    while (std::cin >> n && n != 0) {
        if (contador < 100) {
            tamanos[contador++] = n;
        } else {
            std::cout << "Limite de matrices alcanzado." << std::endl;
            break;
        }
    }

    // Crear, almacenar e imprimir las matrices
    int*** matrices = new int**[contador];
    for (int i = 0; i < contador; i++) {
        matrices[i] = crearMatriz(tamanos[i]);
        // Inicializar la matriz con valores (ejemplo: llenar con ceros)
        int Sumador=1;
        for (int j = 0; j < tamanos[i]; j++) {
            for (int k = 0; k < tamanos[i]; k++) {

                if(j==tamanos[i]/2&&k==tamanos[i]/2){

                    matrices[i][j][k]=-1;

                }
                else{

                    matrices[i][j][k]=Sumador++;



                }


            }
        }



    }
    imprimirMatriz(matrices[0], tamanos[0]);
    int opcion;
    cout << "Elija el grado de rotacion (1=270 grados, 2=180 grados, 3=90 grados, 4=0 grados): ";
    cin >> opcion;

    switch (opcion) {
    case 1: // Rotar 270 grados
        Rotar90Grados(matrices[0], tamanos[0]);
        Rotar90Grados(matrices[0], tamanos[0]);
        Rotar90Grados(matrices[0], tamanos[0]);
        break;
    case 2: // Rotar 180 grados
        Rotar90Grados(matrices[0], tamanos[0]);
        Rotar90Grados(matrices[0], tamanos[0]);
        break;
    case 3: // Rotar 90 grados
        Rotar90Grados(matrices[0], tamanos[0]);
        break;
    case 4://Rotar 0 gradros
        Rotar90Grados(matrices[0], tamanos[0]);
        Rotar90Grados(matrices[0], tamanos[0]);
        Rotar90Grados(matrices[0], tamanos[0]);
        Rotar90Grados(matrices[0], tamanos[0]);
        break;
    default:
        cout << "Opción no válida." << endl;
        break;
    }

    cout << "Matriz rotada:" << endl;



    imprimirMatriz(matrices[0], tamanos[0]);


    int fila = 0,columna = 0,celda=0;
    matrices[0][fila][columna];
    cout<<"Ingresar el numero de la fila: "<<endl;
    cin>>fila;
    cout<<"Ingresar el numero de la columna:"<<endl;
    cin>>columna;
    celda=matrices[0][fila-1][columna-1];
    cout<<"La celda intersecta es: "<<celda<<endl;



    int count=1;
    while (count<contador) {

        imprimirMatriz(matrices[count], tamanos[count]);

        int opcion;
        cout << "Elija el grado de rotacion (1=270 grados, 2=180 grados, 3=90 grados, 4=0 grados): ";
        cin >> opcion;

        switch (opcion) {
        case 1: // Rotar 270 grados
            Rotar90Grados(matrices[count], tamanos[count]);
            Rotar90Grados(matrices[count], tamanos[count]);
            Rotar90Grados(matrices[count], tamanos[count]);
            break;
        case 2: // Rotar 180 grados
            Rotar90Grados(matrices[count], tamanos[count]);
            Rotar90Grados(matrices[count], tamanos[count]);
            break;
        case 3: // Rotar 90 grados
            Rotar90Grados(matrices[count], tamanos[count]);
            break;
        case 4://Rotar 0 gradros
            Rotar90Grados(matrices[count], tamanos[count]);
            Rotar90Grados(matrices[count], tamanos[count]);
            Rotar90Grados(matrices[count], tamanos[count]);
            Rotar90Grados(matrices[count], tamanos[count]);
            break;
        default:
            cout << "Opción no válida." << endl;
            break;
        }

        cout << "Matriz rotada:" << endl;


        imprimirMatriz(matrices[count], tamanos[count]);


        celda=matrices[count][fila-1][columna-1];
        cout<<celda<<endl;

        count++;

    }






    // Eliminar las matrices y liberar la memoria
    for (int i = 0; i < contador; ++i) {
        eliminarMatriz(matrices[i], tamanos[i]);
    }
    delete[] matrices;
    delete[] tamanos;
}

int main() {
    crearMatrices();
    return 0;
}
