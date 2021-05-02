# Sorting-Algorithm-Visualizer <img src="https://i.imgur.com/GKvKjT0.png" align="right" width=250px></img>

Visualize sorting algorithms in SFML

## Supported Algorithms
- Bubblesort
- Selectionsort
- Insertionsort
- Mergesort
- Quicksort
- Heapsort

## Loop Cycle
By default, the program will follow these algorithm transitions:

Bubblesort->Selectionsort->Insertionsort->Mergesort->Quicksort->Heapsort->Bubblesort->...
 
## Installation
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

## Demonstrations

| Sorting Algorithms  | Visualizer |
| ------------- | ------------- |
| Bubblesort | <img src="https://i.imgur.com/BmiVVL1.gif" width=500px></img>|
| Selectionsort | <img src="https://i.imgur.com/aWzCH08.gif" width=500px></img>|
| Insertionsort  | <img src="https://i.imgur.com/gYPV2h0.gif" width=500px></img>|
| Mergesort  | <img src="https://i.imgur.com/Op6K0GS.gif" width=500px></img>|
| Quicksort  | <img src="https://i.imgur.com/Zvk0p2K.gif" width=500px></img> |
| Heapsort  | <img src="https://i.imgur.com/tvu9R3h.gif" width=500px></img> |
