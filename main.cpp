#include <iostream>
#include <string>

using namespace std;

struct Categoria {
  int codigo;
  string descricao;
};

struct Produto {
  int codigo;
  string descricao;
  Categoria* codigoCategoria;
  int quantEstoque;
  int estoqueMin;
  int estoqueMax;
  float precoUnit;
};

struct Clientes{
  int codigo;
  string nome;
  string endereco;
  string telefone;
};

struct Vendedor{
  int codigo;
  string nome;
  string telefone;
};

struct Vendas{
  int codigo;
  Clientes* codigoCliente;
  Vendedor* codigoVendedo;
  string data;
};

struct ItensVenda{
  Vendas* codigo_venda;
  Produto* codigo_produto;
  int quantidade;
};

// ===============  INSERÇÃO DE CLIENTES E VENDEDORES  ======================
void inserirCliente(struct Clientes lista[], int &contador, int tamanho){
  int codigo = 0;
  int loop = 1;
  int cont = contador;
  while(cont < tamanho && loop != 0){
    cout << "Insira do código do cliente"<< (cont + 1) <<": ";
    cin >> codigo;
    if(validarCodigo(lista, cont, codigo)){
      cout << "Codigo ja cadastrado"<< endl;
    }else{
      lista[cont].codigo = codigo;
      cout << "Insira o nome do cliente: ";
      getline(cin >> ws, lista[cont].nome);
      cout << "Insira o endereco do cliente: ";
      getline(cin >> ws, lista[cont].endereco);
      cout << "Insira o telefone do cliente: ";
      cin >> lista[cont].telefone;
      cont++;
    }
    cout << "Deseja cadastrar um novo cliente?(0 - Nao / 1 - Sim): ";
    cin >> loop;
  }
  contador = cont;
}

void inserirVendedor(struct Vendedor lista[], int &contador, int tamanho){
  int codigo = 0;
  int loop = 1;
  int cont = contador;
  while(cont < tamanho && loop != 0){
    cout << "Insira do código do vendedor"<< (cont + 1) <<": ";
    cin >> codigo;
    if(validarCodigo(lista, cont, codigo)){
      cout << "Codigo ja cadastrado"<< endl;
    }else{
      lista[cont].codigo = codigo;
      cout << "Insira o nome do vendedr: ";
      getline(cin >> ws, lista[cont].nome);
      cout << "Insira o telefone do vendedor: ";
      cin >> lista[cont].telefone;
      cont++;
    }
    cout << "Deseja cadastrar um novo vendedor?(0 - Nao / 1 - Sim): ";
    cin >> loop;
  }
  contador = cont;
}

// ===============  FUNCAO PARA VALIDAR OS CODIGOS  ======================
// USAMOS ESSE TEMPLATE POIS ELE ATUA COMO UM TIPO GENERICO, JA QUE TODAS AS STRUCTS TEM A MESMA VARIAVEL CODIGO
// ENTAO NAO É NECESSARIO CRIAR OUTRA FUNÇÃO IGUAL PARA VALIDAR OS CODIGOS
template <typename T>
bool validarCodigo(T lista[], int contador, int codigo){
  for(int l = 0; l < contador; l++){
    if(lista[l].codigo == codigo){
      return true;
    }
  }
  return false;
}


int main(){
  int n = 10;
  Clientes listaCliente[n];
  int contClientes = 0;


}