# Project: Tchuka Ruma Interactive Game

## Overview
Welcome to the Tchuka Ruma Interactive Game project! The primary objective of this assignment was to gain a solid foundation in programming with C and utilizing various development tools including Git, CMake, and VS Code. The project entails implementing a child's solitaire game called Tchuka Ruma.

## Project Goals
- Develop a simple interactive game in C.
- Utilize Git for source code management.
- Employ CMake for building the executable.
- Use CodeGrade for automated testing and grading.
- Gain proficiency in using VS Code for coding, building, and debugging.

## Game Description
Tchuka Ruma is a solitaire game that involves a board with sections and counters. The game challenges the player to move the counters according to specific rules, with the goal of achieving a winning state.

## Learning Outcomes
1. Implement a simple interactive game using loops and arrays in C.
2. Use VS Code within GitHub Codespaces to write and debug C code.
3. Build the project using CMake.
4. Manage source code effectively with Git.
5. Test the program using CodeGrade to ensure correct functionality.

## Getting Started
To get started, follow these steps:
1. Clone the repository to your local machine.
2. Create a Codespace for the repository.
3. Configure the build environment using CMake.
4. Write, test, and debug the code using VS Code.
5. Push your changes to GitHub regularly to track progress and run automated tests.

## Building and Running the Game
To build and run the game, execute the following commands:
```sh
# Configure the code to build (run only once)
cmake -S . -B build

# Build the code after making changes
cmake --build build

# Run the program to play Tchuka Ruma
./build/hw0_main
