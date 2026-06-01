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

void incluirItens(unsigned int codigoVenda, ItemVenda itens[], int &qtdItens, int maxItens, Produto produtos[], int qtdProdutos);

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
                    ItemVenda itens[], int &qtdItens, int maxItens,
                    Produto prod[], int qtdProd) {
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

  //4.1 -> Busca do Cliente
  // 4.1 - Busca do Cliente com Loop de Repetição
  unsigned int codCliente;
  int indiceCliente; // Declaramos fora do loop para o while conseguir enxergar

  do {
    cout << "\nInsira o Codigo do Cliente: ";
    cin >> codCliente;

    indiceCliente = buscaBinaria<Cliente>(c, qtdClientes, codCliente);

    if (indiceCliente == -1) {
      cout << "[ERRO]: Cliente de codigo '" << codCliente << "' nao foi encontrado! Tente novamente.\n";
    }

  } while (indiceCliente == -1); // Repete enquanto o cliente não for achado

  // Se saiu do loop, é porque achou!
  cout << "-> Cliente selecionado: " << c[indiceCliente].nome << "\n";

  //4.2 -> Busca do Vendedor
  unsigned int codVendedor;
  int indiceVendedor;
  do {
    cout << "\nInsira o Código do Vendedor: ";
    cin >> codVendedor;

    indiceVendedor = buscaBinaria<Vendedor>(vendedor, qtdVendedores, codVendedor);

    if (indiceVendedor == -1) {
      cout << "\n[ERRO]: Vendedor de código '" << codVendedor << "' não foi encontrado!\n";
    }
  } while (indiceVendedor == -1);

  cout << "->Vendedor selecionado: " << vendedor[indiceVendedor].nome << "\n";

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
    incluirItens(codigoVenda, itens, qtdItens, maxItens, prod, qtdProd);

    cout << "\nDeseja adicionar outro produto a esta venda? (1 - Sim / 0 - Não): ";
    cin >> opcao;
  } while (opcao != 0);

  cout << "\nVenda concluída com sucesso!\n";
}

//5˚ Passo -> Permitir a inclusão de itens em uma venda
void incluirItens(unsigned int codigoVenda,
                  ItemVenda itens[], int &qtdItens, int maxItens,
                  Produto produtos[], int qtdProdutos) {
  if (qtdItens >= maxItens) {
    cout << "\nLimite de Itens na Venda atingido no sistema!";
    return;
  }

  //5.1 -> Busca do Produto
  unsigned int codProduto;
  int indiceProduto;

  do {
    cout << "\nInsira o Código do Produto que deseja inserir um novo item: ";
    cin >> codProduto;

    indiceProduto = buscaBinaria<Produto>(produtos, qtdProdutos, codProduto);
    if (indiceProduto == -1) {
      cout << "\n[ERRO]: Produto de código '" << codProduto << "' não foi encontrado!\n";
    }
  } while (indiceProduto == -1);

  cout << "\n-> Produto: " << produtos[indiceProduto].descricao;
  cout << "\n\t|-> Preço unitário: R$ " << produtos[indiceProduto].precoUnit;
  cout << "\n\t|-> Estoque disponível: " << produtos[indiceProduto].quantEstoque << "\n";

  //5.2 -> Validação de Quantidade e do Estoque
  int qtdDesejada;
  bool qtdValida = false;

  do {
    cout << "\nInforme a quantidade desejada: ";
    cin >> qtdDesejada;
    if (qtdDesejada <= 0) cout << "\n[ERRO]: A quantidade dev ser maior que zero!\n";
    else if(qtdDesejada > produtos[indiceProduto].quantEstoque){
      cout << "\n[ERRO]: A Quantidade desejada excede a quantidade disponível no estoque!";
      cout << "\nApenas " << produtos[indiceProduto].quantEstoque << " unidade(s) disponíveis.\n";
    } else {
      qtdValida = true;
    }
  } while (!qtdValida);

  itens[qtdItens].codigo_venda = codigoVenda;
  itens[qtdItens].codigo_produto = codProduto;
  itens[qtdItens].quantidade = qtdDesejada;

  qtdItens++;

  //5.3 -> Subtração na quantidade do estoque
  produtos[indiceProduto].quantEstoque -= qtdDesejada;
  cout << "\nItem adicionado com sucesso!";
  cout << "\nEstoque atualizado para '" << produtos[indiceProduto].quantEstoque << "' unidade(s).";
}

int main() {
    // =========================================================================
    // 1. CONFIGURAÇÃO DE LIMITES E ARRAYS
    // =========================================================================
    const int MAX_CLIENTES = 10;
    const int MAX_VENDEDORES = 10;
    const int MAX_PRODUTOS = 10;
    const int MAX_VENDAS = 20;
    const int MAX_ITENS = 50;

    Cliente listaClientes[MAX_CLIENTES];
    int qtdClientes = 0;

    Vendedor listaVendedores[MAX_VENDEDORES];
    int qtdVendedores = 0;

    Produto listaProdutos[MAX_PRODUTOS];
    int qtdProdutos = 0;

    Venda listaVendas[MAX_VENDAS];
    int qtdVendas = 0;

    ItemVenda listaItens[MAX_ITENS];
    int qtdItens = 0;

    // =========================================================================
    // 2. MOCK DATA (Carga Inicial de Dados para Testes)
    // =========================================================================

    listaClientes[0] = {12, "Aang", "Templo do Ar do Sul", "18 99999-1111"};
    listaClientes[1] = {8, "Zuko", "Nacao do Fogo", "18 88888-2222"};
    listaClientes[2] = {99, "Katara", "Tribo da Agua do Sul", "18 77777-3333"};
    qtdClientes = 3;
    ordenarLista<Cliente>(listaClientes, qtdClientes);

    listaVendedores[0] = {7, "Lee Sin", "18 44444-4444"};
    listaVendedores[1] = {4, "Shen", "18 66666-5555"};
    listaVendedores[2] = {5, "Rakan", "18 22222-2222"};
    qtdVendedores = 3;
    ordenarLista<Vendedor>(listaVendedores, qtdVendedores);

    listaProdutos[0] = {50, "Planador de Ar", 1, 5, 1, 10, 1500.00f};
    listaProdutos[1] = {10, "Gume do Infinito", 2, 2, 1, 5, 3400.00f}; // Apenas 2 no estoque!
    listaProdutos[2] = {30, "Pocao de Vida", 3, 50, 10, 100, 50.00f};
    qtdProdutos = 3;
    ordenarLista<Produto>(listaProdutos, qtdProdutos);

    // =========================================================================
    // 3. LAÇO PRINCIPAL DO SISTEMA
    // =========================================================================

    int opcao = 0;
    do {
        cout << "\n\n===================================================\n";
        cout << "   SISTEMA DE GERENCIAMENTO - LOJA MULTIVERSO\n";
        cout << "===================================================\n";
        cout << "1 - Inserir Cliente\n";
        cout << "2 - Inserir Vendedor\n";
        cout << "3 - Registrar Nova Venda (Inclui Itens)\n";
        cout << "0 - Sair\n";
        cout << "===================================================\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "\n[Funcao de Inserir Cliente]\n";
                break;
            case 2:
                // Sua funcao de inserir vendedor aqui
                cout << "\n[Funcao de Inserir Vendedor]\n";
                break;
            case 3:
                // Chamada principal que conecta tudo (Passo 4, que chama o 5)
                registrarVenda(listaVendas, qtdVendas, MAX_VENDAS,
                               listaClientes, qtdClientes,
                               listaVendedores, qtdVendedores,
                               listaItens, qtdItens, MAX_ITENS,
                               listaProdutos, qtdProdutos);
                break;
            case 0:
                cout << "\nEncerrando o sistema. Ate mais!\n";
                break;
            default:
                cout << "\nOpcao invalida. Tente novamente!\n";
        }
    } while (opcao != 0);

    return 0;
}