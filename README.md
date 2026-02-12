# So Long

A small 2D game where the player collects items and escapes through an exit. Built with MiniLibX graphics library.

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![MiniLibX](https://img.shields.io/badge/MiniLibX-000000?style=for-the-badge&logo=42&logoColor=white)

## 📋 Description

**So Long** is a 42 School project that introduces to game development fundamentals using the MiniLibX graphics library. The goal is to create a simple 2D game with sprites, textures, and basic gameplay mechanics.

This project demonstrates:

- **2D graphics rendering** with MiniLibX
- **Sprite management** and texture loading
- **Event handling** (keyboard input)
- **Game loop** implementation
- **Map parsing** and validation
- **Pathfinding** algorithms (flood fill)

The player must navigate through a map, collect all collectibles, and reach the exit to win. Movement count is displayed in the terminal.

**This project was completed as part of the 42 School curriculum.**

<br>
<img width="1128" height="692" alt="so_long" src="https://github.com/user-attachments/assets/68647fbe-a213-403a-ade3-78b9f35a35b4" />
<br>

## ✨ Features

### Mandatory Part
- **2D top-down view** - Simple orthogonal perspective
- **Player movement** - W/A/S/D or arrow keys
- **Collectibles** - Player must collect all items
- **Exit** - Player can leave when all collectibles are gathered
- **Move counter** - Displays movement count in terminal
- **Map validation** - Checks map format and validity
- **Texture rendering** - Sprites for walls, floor, player, items, exit

### Bonus Features
- **Sprite animation** - Animated player and collectibles
- **Enemy patrols** - Enemies that end the game on contact
- **On-screen counter** - Movement count displayed in-game

## 🗺️ Map Format

Maps are defined in `.ber` files with the following characters:

| Character | Description |
|-----------|-------------|
| `0` | Empty space (walkable floor) |
| `1` | Wall (not walkable) |
| `C` | Collectible item |
| `E` | Exit (unlocked after collecting all items) |
| `P` | Player starting position |

### Map Rules

- Map must be rectangular
- Map must be surrounded by walls (`1`)
- Map must contain exactly **one** exit (`E`)
- Map must contain exactly **one** player starting position (`P`)
- Map must contain at least **one** collectible (`C`)
- Map must have a valid path from player to all collectibles and exit

### Example Map

```
1111111
1P0C001
1000001
1C00E01
1111111
```

This creates a 7x5 map with:
- Player at starting position (P)
- Two collectibles (C)
- One exit (E)
- Walls around the border (1)

## 🔧 Installation

### Prerequisites

- GCC or Clang compiler
- Make
- MiniLibX library
- X11 (Linux) or macOS graphics libraries
- XPM image support

**On Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

**On macOS:**
```bash
# MiniLibX is usually pre-installed
xcode-select --install
```

### Compilation

Clone the repository and compile:
```bash
git clone https://github.com/clothildesc/42_so_long.git
cd 42_so_long
make
```

This generates the `so_long` executable.

**Bonus version:**
```bash
make bonus
```

### Make Commands
- `make` or `make all` - Compile mandatory version
- `make bonus` - Compile bonus version
- `make clean` - Remove object files
- `make fclean` - Remove object files and executables
- `make re` - Recompile everything from scratch

## 💻 Usage

### Running the Game

```bash
./so_long maps_valid/map.ber
```

Replace `map.ber` with any valid map file.

### Controls

**Movement:**
- `W` or `↑` - Move up
- `A` or `←` - Move left
- `S` or `↓` - Move down
- `D` or `→` - Move right

**Exit:**
- `ESC` - Close the game
- Click `X` on window - Close the game

### Gameplay

1. Start the game with a map file
2. Move the player using keyboard controls
3. Collect all collectibles (items) on the map
4. Once all collectibles are gathered, go to the exit
5. The exit will allow you to leave and win the game
6. Movement count is displayed in the terminal (or on-screen in bonus)

## 🧪 Testing

### Valid Maps

Test with provided valid maps:
```bash
./so_long maps_valid/simple.ber
./so_long maps_valid/medium.ber
./so_long maps_valid/large.ber
```

### Invalid Maps

The program should gracefully handle errors:
```bash
# Not rectangular
./so_long maps_err/not_rectangular.ber

# No exit
./so_long maps_err/no_exit.ber

# Unreachable collectible
./so_long maps_err/unreachable.ber
```

## 👥 Author

**Clothilde** (cscache)
- GitHub: [@clothildesc](https://github.com/clothildesc)

## 📖 References

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Flood Fill Algorithm](https://en.wikipedia.org/wiki/Flood_fill)

## 📄 License

This project is part of the 42 School curriculum.

---

*Built with 🎮 at 42 School*
