# 🧮 Radiciação Matemática

Um jogo educacional 2D desenvolvido com **Unity e C#**, combinando elementos de plataforma com desafios de matemática relacionados à radiciação.

O projeto foi desenvolvido com o objetivo de aplicar conceitos de programação e desenvolvimento de jogos em uma experiência interativa, utilizando perguntas matemáticas como parte da progressão do jogador.

## 🎮 Sobre o projeto

Em **Radiciação Matemática**, o jogador controla um personagem que percorre o cenário enquanto resolve desafios matemáticos.

O progresso é diretamente relacionado ao desempenho nas perguntas: ao responder corretamente, o personagem pode avançar pelo cenário; erros e obstáculos podem consumir vidas e levar o jogador a uma condição de derrota.

O jogo também conta com diferentes níveis de dificuldade, sistema de vidas, diálogos, feedback das respostas, pausa, ajuda e condições de vitória e derrota.

## ✨ Principais funcionalidades

### 🎯 Sistema de perguntas e respostas

* Perguntas organizadas por níveis de dificuldade.
* Carregamento das perguntas a partir de arquivos externos.
* Seleção aleatória de perguntas.
* Validação das respostas inseridas pelo jogador.
* Feedback visual para respostas corretas e incorretas.
* Progressão para a próxima etapa após responder.
* Entrada de respostas através da interface do jogo.

As perguntas são carregadas em tempo de execução e convertidas para objetos de pergunta contendo o enunciado e a resposta esperada. O sistema utiliza diferentes arquivos para os níveis **Fácil, Médio e Difícil**.

### 🕹️ Movimentação e interação

O personagem possui um sistema de movimentação baseado no `Rigidbody2D`, com controle de velocidade e integração com o sistema de animação.

A movimentação é controlada pelo estado do personagem e executada através do ciclo de física do Unity.

O personagem também interage com diferentes elementos do cenário através de `Collider2D` e Tags, incluindo:

* Pontos de parada;
* Espinhos;
* Área de vitória.

Essas interações comunicam-se com o controlador principal para atualizar o estado do jogo.

### ❤️ Sistema de vidas

O jogo possui um sistema de **3 vidas**.

Ao entrar em contato com os obstáculos:

1. Uma vida é perdida;
2. A interface é atualizada;
3. Caso ainda existam vidas, o personagem retorna à última posição segura;
4. Caso as vidas acabem, o jogador entra no estado de derrota.

O sistema também permite reiniciar a partida e restaurar o estado inicial do personagem.

### 💬 Sistema de diálogos

O jogo possui uma introdução baseada em caixas de diálogo e um efeito de texto sendo exibido gradualmente.

O sistema utiliza **Coroutines** para controlar a velocidade de digitação e permite completar o texto ou avançar para o próximo diálogo através da interação do jogador.

### 📋 Interface e HUD

A interface utiliza componentes do Unity UI e **TextMeshPro**, incluindo:

* Perguntas;
* Campo para respostas;
* Botões;
* Contador de vidas;
* Feedback das respostas;
* Menus;
* Tela de pausa;
* Tela de ajuda;
* Tela de vitória;
* Tela de derrota.

Esses elementos são controlados pelo `GameController`, que coordena as diferentes interfaces de acordo com o estado atual do jogo.

### ⏸️ Sistema de pausa

O jogo possui um sistema de pausa que utiliza `Time.timeScale` para interromper a execução das animações e da lógica temporal enquanto o menu de pausa está aberto.

Também é possível acessar uma tela de ajuda relacionada ao nível de dificuldade selecionado.

### 🗺️ Gerenciamento de cenas

O projeto utiliza o sistema de gerenciamento de cenas do Unity para separar o menu principal da aventura.

O `MenuController` realiza a transição para a cena `"Aventura"` e também possui a função de encerramento do aplicativo.

---

## 🛠️ Tecnologias e ferramentas

### Engine

* **Unity**

### Linguagem

* **C#**

### Unity APIs e sistemas utilizados

* Unity UI
* TextMeshPro
* Rigidbody2D
* Animator
* Collider2D / Trigger
* Scene Management
* Coroutines
* Time Scale
* Resources
* Unity Input System tradicional (`Input.GetKeyDown`)

### Bibliotecas / namespaces utilizados

* `UnityEngine`
* `UnityEngine.UI`
* `UnityEngine.SceneManagement`
* `TMPro`
* `System.Collections`
* `System.Collections.Generic`
* `System.Linq`
* `System.IO`

### Controle de versão

* Git
* GitHub

---

## 🧠 Conceitos de programação aplicados

O projeto foi utilizado para colocar em prática conceitos como:

* Lógica de programação;
* Programação Orientada a Objetos;
* Classes e objetos;
* Encapsulamento através de campos públicos e privados;
* Estruturas condicionais;
* Estruturas de repetição;
* Listas e coleções;
* Manipulação e processamento de strings;
* Conversão e validação de dados;
* Eventos e callbacks da interface;
* Coroutines;
* Gerenciamento de estados;
* Comunicação entre componentes;
* Manipulação de cenas;
* Interação baseada em colisões;
* Organização de dados externos.

Um exemplo disso é o fluxo de perguntas, no qual os dados são carregados, separados em níveis, transformados em objetos `Question` e posteriormente selecionados de forma aleatória para apresentação ao jogador.

---

## 📁 Estrutura principal

```text
Radicia-o-matematica/
│
├── Assets/
│   └── Recursos do projeto Unity
│
├── Packages/
│   └── Dependências e pacotes do Unity
│
├── ProjectSettings/
│   └── Configurações do projeto
│
├── Blind.cs
├── GameController.cs
├── MenuController.cs
├── Question.cs
│
├── .gitignore
└── .gitattributes
```

### Principais scripts

**`GameController.cs`**

Controlador central responsável pelo fluxo da partida, perguntas, respostas, vidas, diálogos, interfaces, pausa, ajuda, vitória, derrota e reinício.

**`Blind.cs`**

Controla o personagem, incluindo movimentação, animação, colisões, pontos de parada, obstáculos, respawn e interação com o controlador do jogo.

**`MenuController.cs`**

Responsável pelas ações do menu principal e pelo carregamento da cena de aventura.

**`Question.cs`**

Representa uma pergunta do jogo através de uma classe serializável contendo o enunciado e sua resposta.

---

## 🎓 Objetivo do projeto

O projeto foi desenvolvido como uma forma prática de estudar e aplicar conceitos de **programação e desenvolvimento de jogos**, utilizando a Unity como engine e C# como linguagem de programação.

Além da implementação de mecânicas de jogo, o projeto explora a utilização de programação para criar uma experiência educacional interativa.

---

## 🚧 Possíveis melhorias

Algumas melhorias que podem ser exploradas em versões futuras:

* Refatoração do controlador principal em componentes menores;
* Expansão do sistema de perguntas;
* Criação de mais fases;
* Sistema de pontuação;
* Persistência de progresso;
* Melhor separação entre dados e lógica de jogo;
* Expansão das mecânicas de gameplay;
* Melhorias na acessibilidade e feedback visual.

---

## 👨‍💻 Autor

**Alan Farias Lopes**

Estudante de Ciência da Computação e desenvolvedor em formação.

GitHub: [Lobibun](https://github.com/Lobibun)
