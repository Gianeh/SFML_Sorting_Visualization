# SFML_Sorting_Visualization
This is the definitive version (Presented as final project) of a small modular application that applies basic sorting algorithms to an array
and shows the process through Simple Fast Multimedia Library (SFML).
Cmake file work in progress, working compilation is made trough the following command:
g++ main.cpp Dataset.cpp Array.cpp sorting.cpp -I /mnt/c/Users/pietr/OneDrive/Desktop/C++/PROGETTO/SFML-2.5.1/include -l sfml-system -l sfml-graphichs -l sfml-window -o exe  

Gif of the resulting application/executable:
![Alt text](https://github.com/Gianeh/SFML_Sorting_Visualization/blob/main/sorting_gif.gif "Demonstration")

Few algorithms implemented untill now, fully modular implementation.
Commands:
F1 --> Change number of elements
F2 --> Change time in ms between comparison
^/v --> Change algorithm
ENTER/SPACEBAR --> Start Sorting
BACKSPACE --> Stop Sorting
