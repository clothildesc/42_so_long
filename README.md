# so_long Game Documentation

## Description
so_long is a simple 2D game where players navigate through a series of levels to collect items and reach the exit. The game is designed to help players understand the basics of game mechanics and coding.

## Features
- Simple yet engaging gameplay
- Collectible items scattered throughout the levels
- Multiple levels with increasing difficulty
- Basic enemy AI that players must avoid
- A visually appealing interface with sound effects

## Installation Instructions
1. Clone the repository:  
   ```bash  
   git clone https://github.com/clothildesc/42_so_long.git  
   ```  
2. Navigate to the project directory:  
   ```bash  
   cd 42_so_long  
   ```  
3. Compile the game:  
   ```bash  
   make  
   ```  
4. Run the game:  
   ```bash  
   ./so_long  
   ```  

## Map Format
- The game map is defined in a simple text file format, where:
  - `1` represents walls  
  - `0` represents empty spaces  
  - `C` represents collectible items  
  - `E` marks the exit

Example of a simple map:  
```
111111
100001
10C001
100E01
111111
```

## Usage
- Navigate using the arrow keys.
- Collect all items to open the exit.
- Avoid enemies at all costs.

## Technical Implementation
- The game is built using [insert programming language or framework here].
- The main loop handles player input, updates game state, and renders graphics.
- Collision detection is implemented to manage interactions between the player and the game environment.

## Testing Guidelines
- Ensure to run unit tests provided in the `tests` directory to validate the logic of the game modules.
- Play through each level to assess difficulty and gameplay mechanics.
- Report any bugs to the issue tracker on GitHub.