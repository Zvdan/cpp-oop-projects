# Rock Paper Scissors (OOP)

A simple Object-Oriented Programming (OOP) implementation of the classic Rock-Paper-Scissors game in C++.

## Features

* Player vs Computer gameplay
* Random computer choices using `rand()` and `srand(time(0))`
* OOP design using classes
* Clear separation of responsibilities between classes
* Simple and beginner-friendly code structure

## Project Structure

```
RockPaperScissors/
│
├── Player.h
├── Player.cpp
├── Game.h
├── Game.cpp
├── main.cpp
├── README.md
└── .gitignore
```

## Class Design

### Player

Responsible for storing a player's choice.

Functions:

* `setChoice(int choice)`
* `getChoice()`

### Game

Responsible for game logic.

Functions:

* `getPlayerChoice()`
* `generateComputerChoice()`
* `displayChoices()`
* `determineWinner()`
* `play()`

## How to Run

1. Open the solution in Visual Studio.
2. Build the project.
3. Run the application.
4. Choose:

   * 0 = Rock
   * 1 = Paper
   * 2 = Scissors

## Sample Output

```
Choose:
0. Rock
1. Paper
2. Scissors

Enter your choice: 0

You chose: Rock
Computer chose: Scissors

You Win!
```

## Concepts Practiced

* Classes and Objects
* Encapsulation
* Header and Source Files
* Random Number Generation
* Conditional Statements
* Function Design
* Basic OOP Architecture

## Future Improvements

* Multiple rounds
* Score tracking
* Input validation
* Best-of-three mode
* Save scores to a file
* Use enums instead of integers
* Inheritance for HumanPlayer and ComputerPlayer

```
```
