# Project: Tchuka Ruma Interactive Game

## Overview
Welcome to the Tchuka Ruma Interactive Game project! The primary objective of this assignment was to gain a solid foundation in programming with C and utilizing various development tools including Git, CMake, and VS Code. The project entails implementing a child's solitaire game called Tchuka Ruma.

## Game Description
Tchuka Ruma is a solitaire game that involves a board with sections and counters. The game challenges the player to move the counters according to specific rules, with the goal of achieving a winning state.

## Project Goals
- Develop a simple interactive game in C.
- Utilize Git for source code management.
- Employ CMake for building the executable.
- Use CodeGrade for automated testing and grading.
- Gain proficiency in using VS Code for coding, building, and debugging.

## Implemented Functionality
- Input and Output: Use scanf for input and printf for output.
- Game State Display: Show as #_#_#_#_|_#, with counters in sections 1-4 and the Ruma.
- Prompt Message: Prompt Choose a section (1-4):_ without a newline. Update and display the game state after a valid section is chosen.
- Error Message: For invalid choices, prompt Invalid choice. Choose a section (1-4):_ without a newline. Update and display the game state after a valid section is chosen.
- Winning Message: Display 'You won!'
- Losing Message: Display 'You lost' because the last counter fell into section #. with the correct section number.
- Continue Sowing Seeds Message: If the last piece lands in a section with counters, display 'Last piece landed in section #. Continue sowing seeds!' with the correct section number. Update the game state after sowing seeds.

## Sample Gameplay #1
2 2 2 2 | 0
Choose a section (1-4): 3
2 2 0 3 | 1
Choose a section (1-4): 2
2 0 1 4 | 1
Last piece landed in section 4. Continue sowing seeds!
3 1 2 0 | 2
Last piece landed in section 3. Continue sowing seeds!
3 1 0 1 | 3
Choose a section (1-4): 2
3 0 1 1 | 3
You lost because the last counter fell into section 3.

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
