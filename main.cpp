#include <iostream>
#include <string>

using namespace std;

struct Categoria {
  unsigned int codigo;
  string descricao;
};

struct Produto {
  unsigned int codigo;
  string descricao;
  unsigned int codigoCategoria;
  unsigned int quantEstoque;
  unsigned int estoqueMin;
  unsigned int estoqueMax;
  float precoUnit;
};

struct Cliente{
  unsigned int codigo;
  string nome;
  string endereco;
  string telefone;
};

struct Vendedor{
  unsigned int codigo;
  string nome;
  string telefone;
};

struct Venda{
  unsigned int codigo;
  unsigned int codigoCliente;
  unsigned int codigoVendedor;
  string data;
};

struct ItemVenda{
  unsigned int codigo_venda;
  unsigned int codigo_produto;
  int quantidade;
};

// ===============  FUNCAO PARA VALIDAR OS CODIGOS  ======================
// USAMOS ESSE TEMPLATE POIS ELE ATUA COMO UM TIPO GENERICO, JA QUE TODAS AS STRUCTS TEM A MESMA VARIAVEL CODIGO
// ENTAO NAO É NECESSARIO CRIAR OUTRA FUNÇÃO IGUAL PARA VALIDAR OS CODIGOS
template <typename T>
bool validarCodigo(T lista[], const int contador, int codigo){
  for(int l = 0; l < contador; l++){
    if(lista[l].codigo == codigo){
      return true;
    }
  }
  return false;
}

template <typename T>
void ordenarLista(T lista[], const int contador) {
  for (int i = 0; i < contador - 1; i++) {
    for (int j = 0; j < contador - i - 1; j++) {
      if (lista[j].codigo > lista[j + 1].codigo) {
        T auxiliar = lista[j];
        lista[j] = lista[j + 1];
        lista[j + 1] = auxiliar;
      }
    }
  }
}

template <typename T>
int buscaBinaria(T lista[], const int contador, unsigned int codigoBusca) {
  int inicio = 0;
  int fim = contador - 1;
  while (inicio <= fim) {
    int meio = inicio + (fim - inicio) / 2;
    if (lista[meio].codigo == codigoBusca) {
      return meio;
    } else if (lista[meio].codigo < codigoBusca) {
      inicio = meio + 1;
    } else {
      fim = meio - 1;
    }
  }
  return -1;
}

/* Início das Funções para o Exercício 1 */
int lerCategoria(Categoria c[], const int n) {
  cout << "\n\n=-=-=- Iniciando leitura da Categoria -=-=-=\n\n";
  for (int i = 0; i < n; i++) {
    cout << "\n" << i+1 <<  "˚ Categoria";
    cout << "\nInsira o Código (0 para sair da leitura): ";
    cin >> c[i].codigo;

    if (c[i].codigo == 0) {
      cout << "\nEncerrando a leitura!\n\n";
      ordenarLista<Categoria>(c, i);
      return i;
    }
    cout << "\nInsira a Descrição: ";
    getline(cin >> ws, c[i].descricao);
  }
  cout << "\nLimite máximo de categorias atingido!\n\n";
  ordenarLista<Categoria>(c, n);
  return n;
}

int lerProduto(Produto p[], const int n) {
  cout << "\n\n=-=-=- Iniciando leitura dos Produtos -=-=-=\n\n";
  for (int i=0; i < n; i++) {
    cout << "\n" << i+1 << "˚ Produto";
    cout << "\nInsira o Código (0 para sair da leitura): ";
    cin>> p[i].codigo;

    if (p[i].codigo == 0) {
      cout << "Encerrando a leitura!\n\n";
      ordenarLista<Produto>(p, i);
      return i;
    }

    cout << "\nInsira a Descrição: ";
    getline(cin >> ws, p[i].descricao);

    cout << "\nInforme o Código da Categoria: ";
    cin >> p[i].codigoCategoria;

    cout << "\nInforme a Quantidade do Estoque: ";
    cin >> p[i].quantEstoque;

    cout << "\nInforme a quantidade Mínima do Estoque: ";
    cin >> p[i].estoqueMin;

    cout << "\nInforme a quantidade Máxima do Estoque: ";
    cin >> p[i].estoqueMax;

    cout << "\nInforme o Preço Unitário: ";
    cin >> p[i].precoUnit;
  }
  cout << "\nLimite de Produtos atingido!\n";
  ordenarLista<Produto>(p, n);
  return n;
}
/* Fim das Funções do Exercício 1 */

// ===============  INSERÇÃO DE CLIENTES E VENDEDORES  ======================
void inserirCliente(struct Cliente lista[], int &contador, int tamanho){
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
    if (contador >= tamanho) {
      cout << "\nLimite de Clientes atingido!\n";
      break;
    }
    cout << "Deseja cadastrar um novo cliente?(0 - Nao / 1 - Sim): ";
    cin >> loop;
  }
  contador = cont;
  ordenarLista<Cliente>(lista, contador);
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
      getline(cin >> ws, lista[cont].telefone);
      cont++;
    }
    if (cont >=tamanho) {
      cout << "\nLimite de Vendedores atingido!\n";
      break;
    }
    cout << "Deseja cadastrar um novo vendedor?(0 - Nao / 1 - Sim): ";
    cin >> loop;
  }
  contador = cont;

  ordenarLista<Vendedor>(lista,contador);
}

//4˚ PASSO -> REGISTRO DE VENDA
void registrarVenda(Venda v[], int &qtdVendas, int maxVendas,
                    Cliente c[], int qtdClientes,
                    Vendedor vendedor[], int qtdVendedores,
                    ItemVenda itens[], int &qtdItens, int maxItens) {
  cout << "\n\n-=-=- Registro de Nova Venda -=-=-\n\n";

  if (qtdVendas >= maxVendas) {
    cout << "\nLimite de Vendas atingido no sistema!\n";
    return;
  }

  unsigned int codigoVenda;
  cout << "\nInsira o Código da Venda: ";
  cin >> codigoVenda;

  if (validarCodigo<Venda>(v, qtdVendas, codigoVenda)) {
    cout << "\n[ERRO]: A Venda de código '" << codigoVenda << "' já foi registrada!\n";
    return;
  }

  // ================= DEBUG =================
  cout << "\n--- DEBUG: Lista de Clientes Vistos pela Funcao ---\n";
  cout << "Quantidade de clientes (qtdClientes): " << qtdClientes << "\n";
  for(int i = 0; i < qtdClientes; i++) {
    cout << "Posicao " << i << " -> Codigo: " << c[i].codigo << " | Nome: " << c[i].nome << "\n";
  }
  cout << "---------------------------------------------------\n";
  // =========================================

  //4.1 -> Busca do Cliente
  unsigned int codCliente;
  cout << "\nInsira o Código do Cliente: ";
  cin >> codCliente;

  int indiceCliente = buscaBinaria<Cliente>(c, qtdClientes, codCliente);
  if (indiceCliente == -1) {
    cout << "\n[ERRO]: Cliente de código '" << codCliente << "' não foi encontrado!\n";
    return;
  }
  cout<< "\nCliente selecionado: " << c[indiceCliente].nome << "\n";

  //4.2 -> Busca do Vendedor
  unsigned int codVendedor;
  cout << "\nInsica o Código do Vendedor: ";
  cin >> codVendedor;

  int indiceVendedor = buscaBinaria<Vendedor>(vendedor, qtdVendedores, codVendedor);
  if (indiceVendedor == -1) {
    cout << "\n[ERRO]: Vendedor de código '" << codVendedor << "' não foi encontrado!\n";
    return;
  }
  cout << "\nVendedor selecionado: " << vendedor[indiceVendedor].nome << "\n";

  v[qtdVendas].codigo = codigoVenda;
  v[qtdVendas].codigoCliente = codCliente;
  v[qtdVendas].codigoVendedor = codVendedor;

  cout << "\nInsira a Data da Venda (DD/MM/AAAA): ";
  getline(cin >> ws, v[qtdVendas].data);

  qtdVendas++;

  //4.3 -> Inclusão de Itens da Venda
  int opcao = 1;
  cout << "\n-=-=- Adição de Itens na Venda " << codigoVenda << " -=-=-";

  do {
    if (qtdItens >= maxItens) {
      cout << "\nLimite de itens atingido no sistema!\n";
      break;
    }

    itens[qtdItens].codigo_venda = codigoVenda;

    cout << "\nCódigo do Produto: ";
    cin >> itens[qtdItens].codigo_produto;

    cout << "\nQuantidade Vendida: ";
    cin >> itens[qtdItens].quantidade;

    qtdItens++;

    cout << "\nDeseja adicionar outro produto a esta venda? (1 - Sim / 0 - Não): ";
    cin >> opcao;
  } while (opcao != 0);

  cout << "\nVenda concluída com sucesso!\n";
}

int main() {
    // 1. Variáveis de controle e Arrays (Tamanhos reduzidos para testes)
    const int MAX_CLIENTES = 5;
    const int MAX_VENDEDORES = 5;
    const int MAX_VENDAS = 10;
    const int MAX_ITENS = 20;

    Cliente listaClientes[MAX_CLIENTES];
    int qtdClientes = 0;

    Vendedor listaVendedores[MAX_VENDEDORES];
    int qtdVendedores = 0;

    Venda listaVendas[MAX_VENDAS];
    int qtdVendas = 0;

    ItemVenda listaItens[MAX_ITENS];
    int qtdItens = 0;

    Produto listaProdutos[10]; // Tamanho reduzido
    int qtdProdutos = 0;

    // =========================================================================
    // 2. MOCK DE DADOS (Área de testes com personagens)
    // Inseridos fora de ordem para validar a nossa função ordenarLista!
    // =========================================================================

    // Clientes (League of Legends)
    listaClientes[0] = {15, "Jinx", "Zaun", "18 99999-0001"};
    listaClientes[1] = {3, "Yasuo", "Ionia", "18 88888-0002"};
    qtdClientes = 2;
    ordenarLista<Cliente>(listaClientes, qtdClientes); // Ordena: 3 (Yasuo), depois 15 (Jinx)

    // Vendedores (Overwatch)
    listaVendedores[0] = {10, "Tracer", "18 77777-0003"};
    listaVendedores[1] = {5, "Genji", "18 66666-0004"};
    qtdVendedores = 2;
    ordenarLista<Vendedor>(listaVendedores, qtdVendedores); // Ordena: 5 (Genji), depois 10 (Tracer)

    // =========================================================================
    // 3. MENU PRINCIPAL
    // =========================================================================

    int opcao = 0;
    do {
        cout << "\n\n=-=-=- SISTEMA DE GERENCIAMENTO DE VENDAS -=-=-=\n";
        cout << "1 - Inserir Cliente (Passo 2)\n";
        cout << "2 - Inserir Vendedor (Passo 3)\n";
        cout << "3 - Registrar Nova Venda (Passo 4)\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "\n[Funcao de Cliente em construcao...]\n";
                break;
            case 2:
                inserirVendedor(listaVendedores, qtdVendedores, MAX_VENDEDORES);
                break;
            case 3:
                registrarVenda(listaVendas, qtdVendas, MAX_VENDAS,
                               listaClientes, qtdClientes,
                               listaVendedores, qtdVendedores,
                               listaItens, qtdItens, MAX_ITENS);
                break;
            case 0:
                cout << "\nSaindo do sistema... Ate logo!\n";
                break;
            default:
                cout << "\nOpcao invalida!\n";
        }
    } while (opcao != 0);

    return 0;
}