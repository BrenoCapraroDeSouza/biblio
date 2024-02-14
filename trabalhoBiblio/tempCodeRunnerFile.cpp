#include <iostream>
#include <stdlib.h>
using namespace std;
int contadorUsuario = 0;
int contadorLivros = 0;
int contadorRevista = 0;
int contadorAutores = 0;
int contadorEditora = 0;


struct Livro
{
    int id = 100;
    string nome;
    string nomeAutor;
    string nomeEditora;
    string assunto;
};

struct Revista
{
    int id = 200;
    string nome;
    string nomeEditora;
    string assunto;
};

struct Autor
{
    int id = 300;
    string nome;
};

struct Editora
{
    int id = 400;
    string nome;
};

struct Usuario
{
    int id = 0;
    string nome;
};

struct Data
{
    int dia;
    int mes;
    int ano;
};

template <typename T>
void mostrarTodoVetor(T *vetor, int tam, char tipo)
{
    for(int i=0; i<tam; i++)
    {
        if(tipo == 'L' && vetor[i].id != 100)
        {
            mostrar(vetor[i]);
        }
        else if(tipo == 'R' && vetor[i].id != 200)
        {
            mostrar(vetor[i]);
        }
        else if (tipo == 'A' && vetor[i].id != 0 && vetor[i].id !=300 && vetor[i].id != 400)
        {
            mostrar(vetor[i], vetor[i].id);
        }
        
    }
}

//AUMENTAR LIMITE DE ELEMENTOS EM UM VETOR
template <typename T>
T *aumentarVetor(T *vetor, int &tam) 
{
    tam=tam+5;
    T *res = new T[tam];
    if(res==NULL) return NULL;
    for(int i=0; i<tam-5; i++)
    {
        res[i] = vetor[i];
    }

    delete []vetor;
    return res;
}

//MOSTRAR NA TELA USUARIO, AUTOR, EDITORA
template <typename T>
void mostrar(T a, int id)
{   
    cout << " -----------------------------------------------------\n";
    cout << "|                                                      |\n";
    cout << "|                "<< "ID: " << a.id <<"\n";
    cout << "|                "<< "Nome: " << a.nome <<"\n";
    cout << "|                                                      |\n";
    cout << " -----------------------------------------------------\n";
    cout << endl;
}

//MOSTRAR NA TELA LIVROS
void mostrar (Livro a)
{
    cout << " -----------------------------------------------------\n";
    cout << "|                       LIVRO                           |\n";
    cout << "|                                                       |\n";
    cout << "|                                                       |\n";
    cout << "|                "<< "ID: " << a.id <<"\n";
    cout << "|                "<< "Nome: " << a.nome <<"\n";
    cout << "|                "<< "Assunto: " << a.assunto <<"\n";
    cout << "|                "<< "Autor: " << a.nomeAutor <<"\n";
    cout << "|                "<< "Editora: " << a.nomeEditora <<"\n";
    cout << "|                                                       |\n";
    cout << " -----------------------------------------------------\n";
    cout << endl;
}

//MOSTRAR NA TELA REVISTA
void mostrar(Revista a)
{
    cout << " -----------------------------------------------------\n";
    cout << "|                       REVISTA                         |\n";
    cout << "|                                                       |\n";
    cout << "|                                                       |\n";
    cout << "|                "<< "ID: " << a.id <<"\n";
    cout << "|                "<< "Nome: " << a.nome <<"\n";
    cout << "|                "<< "Assunto: " << a.assunto <<"\n";
    cout << "|                "<< "Editora: " << a.nomeEditora <<"\n";
    cout << "|                                                       |\n";
    cout << " -----------------------------------------------------\n";
    cout << endl;
}

// VERIFICAÇÃO SE JÁ ESTÁ CADASTRADO
template <typename T>
bool ja_cadastrado(T *vetor, int tam, string pesquisa) 
{  
    for (int i = 0; i < tam; i++)
    {
        if (pesquisa == vetor[i].nome) 
        {
            cout << "Ja cadastrado!" << endl;
            return true; // já cadastrado
        }
    }
    return false; // ainda não foi cadastrado
}

// CADASTRO USUARIO, AUTOR, EDITORA
template <typename T> 
void cadastrar (T *vetor, int &tam, string nome)  
{

    if(!ja_cadastrado(vetor, tam, nome))
    {
        if (vetor[contadorUsuario].id >= 0 && vetor[contadorUsuario].id < 100)
        {
            vetor[contadorUsuario].nome = nome;
            vetor[contadorUsuario].id += contadorUsuario+1;
            contadorUsuario ++;
            cout << "\nUsuario cadastrado\n" << endl;
        }

        if (vetor[contadorAutores].id >= 300 && vetor[contadorAutores].id < 400)
        {
            vetor[contadorAutores].nome = nome;
            vetor[contadorAutores].id += contadorAutores+1;
            contadorAutores ++;
            cout << "\nAutor cadastrado\n" << endl;
        }

        if (vetor[contadorEditora].id >= 400 && vetor[contadorEditora].id < 500)
        {
            vetor[contadorEditora].nome = nome;
            vetor[contadorEditora].id += contadorEditora+1;
            contadorEditora ++;
            cout << "\nEditora cadastrada\n" << endl;
        }
    }
}

// CADASTRO DE LIVRO
Livro cadastrar (Livro *Livros, int &tam_L, Autor *Autores, int &tam_A, Editora *Editoras, int &tam_E) 
{
    Livro a;
    cin.ignore();
    do
    {
        cout << "Insira o nome do livro: " << endl;
        getline(cin,a.nome);

    }while(ja_cadastrado(Livros, tam_L, a.nome));

    if(Livros[contadorLivros].id >= 100 && Livros[contadorLivros].id < 200)
    {
        a.id += contadorLivros+1;
        contadorLivros ++;
    }

    cout << "Insira o nome do autor: " << endl;
    getline(cin, a.nomeAutor);
    cadastrar(Autores, tam_A, a.nomeAutor); 

    cout << "Insira o nome da editora: " << endl;
    getline(cin, a.nomeEditora);
    cadastrar(Editoras, tam_E, a.nomeEditora);

    cout << "Insira o assunto abordado: " << endl;
    getline(cin, a.assunto);
    cout << endl;

    return a;
}

// CADASTRO DE REVISTA
Revista cadastrar (Revista *Revistas, int &tam_R, Editora *Editoras, int &tam_E, char R)
{
    Revista a;
    cin.ignore();
    do
    {
        cout << "Insira o nome da revista: " << endl;
        getline(cin,a.nome);

    }while(ja_cadastrado(Revistas, tam_R, a.nome));
    
    if (Revistas[contadorRevista].id >= 200 && Revistas[contadorRevista].id < 300)
    {
        a.id += contadorRevista+1;
        contadorRevista ++;
    }

    cout << "Insira o nome da editora: " << endl;
    getline(cin, a.nomeEditora);
    cadastrar(Editoras, tam_E, a.nomeEditora);

    cout << "Insira o assunto abordado: " << endl;
    getline(cin,a.assunto);
    cout << endl;
        
    return a;

}

void pesquisar (Usuario *Usuarios, int &tam_U, Livro *Livros, int &tam_L, Revista *Revistas, int &tam_R, Autor *Autores, int &tam_A, Editora *Editoras, int &tam_E, string pesquisa, int pesquisaID = -1)
{
    for(int i=0; i<tam_L; i++)
    {
    if(pesquisa==Livros[i].nome || pesquisa ==Livros[i].nomeAutor || pesquisa == Livros[i].nomeEditora || 
    pesquisa == Livros[i].assunto || pesquisaID == Livros[i].id)
        {
            mostrar(Livros[i]);
        }
    }

    for(int i=0; i<tam_R; i++)
    {
        if(pesquisa==Revistas[i].nome || pesquisa == Revistas[i].nomeEditora || pesquisa == Revistas[i].assunto ||
        pesquisaID == Revistas[i].id)
        {
            mostrar(Revistas[i]);
        }
    }

    for(int i=0; i<tam_U; i++)
    {
        if(pesquisa==Usuarios[i].nome || pesquisaID == Usuarios[i].id)
        {
            mostrar(Usuarios[i], Usuarios[i].id);
        }
    }

    for(int i=0; i<tam_A; i++)
    {
        if(pesquisa==Autores[i].nome || pesquisaID == Autores[i].id)
        {
            mostrar(Autores[i], Autores[i].id);
        }
    }

    for(int i=0; i<tam_E; i++)
    {
        if(pesquisa==Editoras[i].nome || pesquisaID == Editoras[i].id)
        {
            mostrar(Editoras[i], Editoras[i].id);
        }
    }

    
    
}
//FUNÇÃO SECUDÁRIA
void cadastrar(Usuario *Usuarios, int &tam_U, Livro *Livros, int &tam_L, Revista *Revistas, int &tam_R, Autor *Autores, int &tam_A, Editora *Editoras, int &tam_E)
{
    cin.ignore();
    system("cls");
    string nomeAutor;
    string nomeEditora;
    string nomeUsuario;
    char escolha_menu;
    char revista = 'r';
    while(escolha_menu!='7')
    {
        cout << " -----------------------------------------------------\n";
        cout << "|                 ABA DE CADASTROS                    |\n";
        cout << "|                                                     |\n";
        cout << "|                                                     |\n";
        cout << "|                1- CADASTRAR LIVRO                   |\n";
        cout << "|                2- CADASTRAR REVISTA                 |\n";
        cout << "|                3- CADASTRAR AUTOR                   |\n";
        cout << "|                4- CADASTRAR EDITORA                 |\n";
        cout << "|                5- CADASTRAR USUARIO                 |\n";
        cout << "|                6- ALTERAR                           |\n";
        cout << "|                7- SAIR                              |\n";
        cout << "|                                                     |\n";
        cout << "|                                                     |\n";
        cout << " -----------------------------------------------------\n";
        escolha_menu = getchar();
        switch(escolha_menu)
        {
                        //CADASTRO LIVROS
            case '1':

                if (contadorLivros == tam_L-1)
                {
                    cout << "Memoria aumentada" << endl;
                    Livros = aumentarVetor(Livros,tam_L);
                }

                Livros[contadorLivros]= cadastrar(Livros, tam_L, Autores, tam_A, Editoras, tam_E);
                mostrar(Livros[contadorLivros]);
                system ("pause");
            break;
                        //CADASTRO REVISTAS
            case '2':

                if (contadorRevista == tam_R-1)
                {
                    cout << "Memoria aumentada" << endl;
                    Revistas = aumentarVetor(Revistas,tam_R);
                }

                Revistas[contadorRevista]= cadastrar(Revistas, tam_R, Editoras, tam_E, revista);
                mostrar(Revistas[contadorRevista]);
                system ("pause");
            break;

            case '3':
                        //CADASTRO AUTORES
                if (contadorAutores == tam_A-1)
                {
                    cout << "Memoria aumentada" << endl;
                    Autores = aumentarVetor(Autores,tam_A);
                }

                cout << "Insira o nome do autor: " << endl;
                cin.ignore();
                getline(cin, nomeAutor);                                  
                cadastrar(Autores, tam_A, nomeAutor);
                mostrar(Autores[contadorAutores-1], Autores[contadorAutores-1].id);
                system ("pause");
            break;
                        //CADASTRO EDITORAS
            case '4':

                if (contadorEditora == tam_E-1)
                {
                    cout << "Memoria aumentada" << endl;
                    Editoras = aumentarVetor(Editoras,tam_E);
                }

                cout << "Insira o nome da Editora: " << endl;
                cin.ignore();
                getline(cin, nomeEditora);                                   
                cadastrar(Editoras, tam_E, nomeEditora);
                mostrar(Editoras[contadorEditora-1], Editoras[contadorEditora-1].id);
                system ("pause");
            break;
                        //CADASTRO USUARIOS
            case '5':
                        
                if (contadorUsuario == tam_U-1)
                {
                    cout << "Memoria aumentada" << endl;
                    Usuarios = aumentarVetor(Usuarios,tam_U);
                }

                cout << "Insira o nome da Usuario: " << endl;
                cin.ignore();
                cin.clear();
                getline(cin,nomeUsuario);                                   
                cadastrar(Usuarios, tam_U, nomeUsuario);
                mostrar(Usuarios[contadorUsuario-1], Usuarios[contadorUsuario-1].id);
                system ("pause");
            break;

            case '6':
                //ALTERAR
            break;

            case '7':
            break;

            default:
                cout << "Escolha uma opcao valida." << endl;
        }
    }
}

//FUNÇÃO PRINCIPAL, MENU DO SISTEMA
void menu(Usuario *Usuarios, int &tam_U, Livro *Livros, int &tam_L, Revista *Revistas, int &tam_R, Autor *Autores, int &tam_A, Editora *Editoras, int &tam_E)
{
    system("cls");
    char escolha_menu;
    int escolha_pesquisa, pesquisaID;
    string pesquisa;
    while(escolha_menu!='4')
    {
        system("cls");
        cout << " -----------------------------------------------------\n";
        cout << "|                 BEM VINDO A BIBLIOTECA              |\n";
        cout << "|                                                     |\n";
        cout << "|                                                     |\n";
        cout << "|                1- CADASTRAR                         |\n";
        cout << "|                2- PESQUISAR                         |\n";
        cout << "|                3- RETIRAR LIVRO                     |\n";
        cout << "|                4- SAIR                              |\n";
        cout << "|                                                     |\n";
        cout << "|                                                     |\n";
        cout << " -----------------------------------------------------\n";
        escolha_menu = getchar();
        switch(escolha_menu)
        {
            case '1':
                cadastrar(Usuarios, tam_U, Livros, tam_L, Revistas, tam_R, Autores, tam_A, Editoras, tam_E);
            break;

            case '2':
                system("cls");
                do
                {
                    cout << "1- Pesquise qualquer coisa, por Titulo, Assunto, Nomes: " << endl;
                    cout << "2- Pesquise qualquer coisa, por ID: " << endl;
                    cout << "3- SAIR" << endl;
                    cin >> escolha_pesquisa;
                }while(escolha_pesquisa != 1 && escolha_pesquisa != 2 && escolha_pesquisa != 3);

                if(escolha_pesquisa==1)
                {
                    cout << "Insira a palavra chave para a busca: " << endl;
                    getline(cin, pesquisa);
                    pesquisar(Usuarios, tam_U, Livros, tam_L, Revistas, tam_R, Autores, tam_A, Editoras, tam_E, pesquisa);
                }
                else if(escolha_pesquisa==2)
                {
                    cout << "Insira o ID para a busca: " << endl;
                    cin >> pesquisaID;
                    pesquisar(Usuarios, tam_U, Livros, tam_L, Revistas, tam_R, Autores, tam_A, Editoras, tam_E,"ç", pesquisaID);
                }
                else break;
                
            break;

            case '3':
                mostrarTodoVetor(Revistas, tam_R, 'R');
                system("pause");
            break;
                
            case '4':
                exit;
            break;

            default:
                cout << "Escolha uma opcao valida." << endl;
        }
        cin.ignore();
    }
}


int main()
{
    int tam_U =5, tam_L = 5, tam_R = 5, tam_A = 5, tam_E = 5; 
    Usuario *Usuarios = new Usuario[tam_U];
    Livro *Livros = new Livro[tam_L];
    Revista *Revistas = new Revista[tam_R];
    Autor *Autores = new Autor[tam_A];
    Editora *Editoras = new Editora[tam_E];

    menu(Usuarios, tam_U, Livros, tam_L, Revistas, tam_R, Autores, tam_A, Editoras, tam_E);

    delete []Usuarios;
    delete []Livros;
    delete []Revistas;
    delete []Autores;
    delete []Editoras;
}