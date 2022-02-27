<h1 align="center">
  Jungle Run
</h1>

# Overview

A Ladder & Snake game enhanced with Monoply-like features. It is implemented in C++ depending on OOP paradigm. Some of the Monopoly features included are cards for punishing and rewarding players.

# Features

## Design Mode Operations

<div align="center">
<img src="./image/README/1645937060796.png" style="Width: 650px" alt="">
</div>
<div align="center">
  <b>An example of a simple level shown in the Design mode</b>
</div>
<br/>

The purpose of this mode is to design the Grid of the game that you will play later. You specify in this mode the location of the snakes, ladders, and cards. You also specify each cards needed values. Supported Operations are:

- Add Ladder & Add Snake
- Add Card & Edit Card
- Copy, Cut & Paste Card
- Delete Game Object
- Save & Open Grid
- Switching between Play mode & Design mode

## Play Mode Operations

<div align="center">
<img src="./image/README/1645937958635.png" style="Width: 650px" alt="">
</div>
<div align="center">
  <b>An example of a simple level shown in the Play mode</b>
</div>
<br/>

Supported Operations are:

- Roll Dice
- Manually Input Dice Value
- New Game

## Special Attacks

Each player has 4 special attacks that he can use throughout the game. A player can choose during his “recharge the wallet” turn to launch a special attack instead of recharging his wallet. Attacks are:

- Ice: Choose a player to prevent from rolling the next turn.
- Fire: Choose a player to burn. Deduct 20 coins from his wallet for his next 3 turns (total 60).
- Poison: Choose a player to poison. For 5 turns, deduct 1 number from his dice roll.
- Lightning: Deduct 20 coins from all other players.

## Game Logic

<div align="center">
<img src="./image/README/1645937310473.png" style="Width: 650px" alt="">
</div>
<div align="center">
  <b>An example of a level with some shown cards</b>
</div>
<br/>

This includes handling:

- Player movement
- Adding money after 3 turns
- Taking Ladders & Snakes
- Cards:
  - Card 1 & 2: Decrements/Increments the value of the passing player’s wallet.
  - Card 3 & 4: Moves the player forward to the start of the next ladder/snake.
  - Card 5 & 6: Move forward/backward the same number of steps that you just rolled.
  - Card 7: Extra dice roll.
  - Card 8: Prevent next dice roll.
  - Card 9: Instructs the player to go to a specific cell specified during grid design.
  - Cards [10-14]: Monopoly like cells, i.e. buy cells to make them stations and get rent from passing players.

# Concept Art

Below are some examples of the game art we worked on for this game. We may work on integrating it into the game in a future release.

## Character Art

<div align="center">
<img src="./image/README/1645943612909.png" style="Width: 220px" alt="">
<img src="./image/README/1645943623847.png" style="Width: 220px" alt="">
<img src="./image/README/1645943618653.png" style="Width: 220px" alt="">
</div>
<div align="center">
<img src="./image/README/1645944302753.png" style="Width: 220px" alt="">
<img src="./image/README/1645943630807.png" style="Width: 220px" alt="">
<img src="./image/README/Animation.gif" style="Width: 220px" alt="">
</div>
<br/>

## Card Art

<div align="center">
<img src="./image/README/1645944668260.png" style="Width: 180px" alt="">
<img src="./image/README/1645944671178.png" style="Width: 180px" alt="">
<img src="./image/README/1645944674023.png" style="Width: 180px" alt="">
</div>
<div align="center">
<img src="./image/README/1645944676888.png" style="Width: 180px" alt="">
<img src="./image/README/1645944679672.png" style="Width: 180px" alt="">
<img src="./image/README/1645944683842.png" style="Width: 180px" alt="">
</div>
<div align="center">
<img src="./image/README/1645944686976.png" style="Width: 180px" alt="">
<img src="./image/README/1645944689844.png" style="Width: 180px" alt="">
<img src="./image/README/1645944693093.png" style="Width: 180px" alt="">
</div>
<br/>
