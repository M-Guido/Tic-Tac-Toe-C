# Tic-Tac-Toe-C
Simple tic tac toe implementation in C


# Tic-Tac-Toe in C

A simple console-based Tic-Tac-Toe game written in C. This project was created for educational purposes and includes basic game logic, win/draw condition checking, and a simple computer opponent.

## 🎮 Features
* **Two game modes:** * Player vs Player (Local multiplayer)
  * Player vs Bot (Simple opponent making random valid moves)
* **Screen clearing:** The game continuously refreshes the board in the console for a clean UI.
* **Input validation:** Protection against overwriting an already taken spot or entering invalid characters.

## ⌨️ How to play
The board fields are mapped to numbers from `1` to `9` on your keyboard. Each key corresponds to a specific spot on the board as follows:

 1 | 2 | 3 
-----------
 4 | 5 | 6 
-----------
 7 | 8 | 9 

During your turn, simply type the corresponding number and press `Enter`. Typing `0` exits the game.

## 🛠️ Build and Run (VS Code)

This project is set up for quick building in **Visual Studio Code**.

### Requirements:
* An installed C compiler (e.g., GCC / MinGW).
* A configured `tasks.json` and `lounch.json` file in the `.vscode` folder of your workspace.

### How to build the project:
1. Open the project folder in VS Code.
2. Press **`Ctrl + Shift + B`** to compile the code (this relies on your configured `tasks.json`).
3. After a successful build, open the integrated terminal in VS Code (`Ctrl + ~`) and run the file with `./twodim.c` command in your terminal
