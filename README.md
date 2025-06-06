# Circle Game

This is a simple terminal-based board game implemented in C.

## How to Play

- The game is played on a 10x10 board.
- Player (`P`) starts at top-left corner (0,0).
- Computer (`C`) starts at bottom-right corner (9,9).
- Both move around the outer edge of the board (clockwise).
- First player is selected by rolling the dice.

## Game Rules

- Each turn, both player and computer roll a dice and move forward.
- Each player sets a trap on the board edge at the start of the game.
- If a player lands on a trap, they move backward by a trap value.
- The first player to complete one full cycle around the board wins.

## How to Run

1. Compile the game:
    ```bash
    gcc -o circle_game circle_game.c
    ```

2. Run the game:
    ```bash
    ./circle_game
    ```

## Features

- Simple board display for both player and computer.
- Randomized dice rolls.
- Random and player-selected traps.
- Option to play again after game ends.

Enjoy the game! 🎲
