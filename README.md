# Integrantes

- Bruno Lauand Ferrão - 32217994
- Raul Vilhora Cardoso Matias - 32267274

# Utilizados

- Servidor <code>AWS</code>
- Repositório <code>git</code>
- Compilador <code>gcc</code>
- Código <code>.c</code>

# Passo-a-passo

- Acessar o servidor <code>AWS</code>
- Instalar o compilador <code>gcc</code>
- Criar uma pasta <code>mkdir</code> para clonar o repositório git
- Entrar na pasta <code>cd</code> e iniciar o git na pasta <code>git init</code>
- Clonar o repositório <code>git clone</code>
- Acessar a pasta do repositório clonado <code>cd</code>
- Compilar o arquivo <code>.c</code> utilizando o gcc <code>gcc -o</code>
- Executar o arquivo compilado <code>./"nome-do-arquivo"</code>


# Exercícios

- Item A) O que mudou foi a utilização do mutex para fazer exclusão mútua e assim evitar a concorrência entre threads que estavam tentando acessar e modificar a variável 'sum' ao mesmo tempo o que estava fazendo a versão anterior gerar resultados inconsistentes e imprecisos.

- Item B) No código orgininal, não havia controle do acesso a variável 'sum' o que estava causando modificações não corretas no valor da variável e, consequentemente, no valor do resultado também. Esse problema foi solucionado na segunda versão do código usando um mutex, que elimina as condições de corrida entre as threads.


# Print da execução


<img src="/Prints/execucao.jpeg">

<img src="/Prints/execucao2.jpeg">
