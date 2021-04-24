# Sorting-Algorithm-Visualizer (WIP)

Visualize sorting algorithms in SFML

## Current Feature (v1.0)
Currently, only bubblesort has been fully implemented. The program will just loop through this algorithm forever.


# Branches
- Master
  * Main branch for official releases and builds
  
- Beta
  * Experimental branch
  
- Bubblesort_forever
  * The program will only show the bubblesort alogorithm with increasing sample size.
  * Great for a screen saver

# Installation
You will need to install the **SFML library** to run this program.

1. Clone this repository

3. Install SFML

5. Run these commands to compile

```
g++ -c main.cpp
g++ main.o -o visualizer -lsfml-graphics -lsfml-window -lsfml-system
```

4. Run the program

```
./visualizer
```

## Version
1.0

## Version 1.0 (Bubblesort)
<img src="https://i.imgur.com/TE6hX5h.gif" width=500px></img>
