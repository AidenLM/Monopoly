# Monopoly Man

This is a simple terminal-based board game called **Monopoly Man**, written in C.

## How to Play

- The game is played on a 10x10 board.
- Player (`P`) starts at top-left corner (0,0).
- Computer (`C`) starts at bottom-right corner (9,9).
- Both move around the edge of the board in a clockwise path.
- The first player to finish one full loop around the board wins.

## Game Rules

- At the beginning, each player places one trap on the board edges.
- In each round, both the player and the computer roll a dice and move forward.
- If a player lands on a trap, they move backward depending on the trap value.
- After more than 5 rounds, players can win by completing a full cycle.

## How to Run

1. Compile the game:
    ```bash
    gcc -o monopoly_man monopoly_man.c
    ```

2. Run the game:
    ```bash
    ./monopoly_man
    ```

## Features

- Dice rolls for each player.
- Traps that can reverse movement.
- Clear board display after each turn.
- Option to replay the game after winning.

Enjoy playing **Monopoly Man**! 🎲
