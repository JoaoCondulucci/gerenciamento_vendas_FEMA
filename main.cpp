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

