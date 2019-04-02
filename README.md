# Tutorial - Começando

## Passo 1: Baixando o projeto codeblocks

Faça o download o projeto codeblocks. Ele contém o diretório codeblocks-project, que contém três diretórios.

* sfml-game
  * codeblocks-project
    * MinGW
    * SFML-2.5.1
    * sfml-game

## Passo 2: Abrindo o projeto do game com o codeblocks

1. Abra o codeblocks.
2. Clique no menu File >> Open...
3. Selecione o arquivo sfml-game.cbp dentro do diretório codeblocks-project/sfml-game
4. Abra o arquivo main.cpp existente no projeto que você acabou de abrir

## Passo 3: Compilando e executando o projeto

1. Clique no menu Settings >> Compiler
2. Selecione a aba Toolchain executables
3. Na seção "Compiler's installation directory", clique no botão com "..." (três pontos)
4. Selecione o diretório codeblocks-project/MinGW
5. Na aba "Program Files", certifique-se que os campos abaixo possuam os seguintes valores
   - **C compiler**: gcc.exe
   - **C++ compiler**: g++.exe
   - **Linker for dynamic libs**: g++.exe
   - **Linker for static libs**: ar.exe

## Passo 4: Compilando o projeto

Clique no menu Run >> Build and Run. Ou você pode pressionar f9 como atalho. Se você seguiu todos os passos anteriores  corretamente, você deverá ver a imagem abaixo.




