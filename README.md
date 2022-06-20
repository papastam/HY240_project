# Among Us *(Data Structures Project)*
For the [HY240](https://www.csd.uoc.gr/~hy240/current/) course we recreated the functionalith of the game Among Us using different kinds of data structures we were teached in the course

The assignment details can be found in the [assignment PDF](https://github.com/papastam/HY240_project/blob/master/HY240_project_Phase2.pdf)

## Directory structure
    
+ `./src` *contains the source files of the project.*
    + `./src/main.c` *contains the main function that runs the project.*
    + `./src/among_us.h` *contains the function declaration's needed by main.c as well as the structure definitions.*
    + `./src/among_us.c` *contains the function definitions for the functions declared in among_us.h*s
+ `./testfiles` *contains some example testfiles used to test the project in its developement stage*

## Project Compilation 

+ To compile the project, execute the `make` command in the root directory
+ `make clean` command is also implemented to clean the directory from compiled files

## Project Execution

Run the project using the following format:
<br>
```bash 
./among_us <input file>
```

## Input file Format

The input file must contain __single line events__ of format `<Event code> <Options>`. The implemented events are the following:
<br>
+ `P <pid> <is_alien>` *(Insert Player with id=\<pid>)*
+ `T <tid> <difficulty>` *(Insert Task with task_id=\<pid> and difficulty=\<difficulty>)*
+ `D` *(Distribute tasks to players using round robbin algorithm)*
+ `I <pid> <tid>` *(Implement Task=\<tid> from player=\<pid>)*
+ `E <pid> <pid2>` *(Eject player=\<pid> alien_player=\<pid2>)*
+ `W <pid1> <pid2> <pida> <number_witnesses>` *(Player=\<pid1> is ejected by player=\<pida> and his tasks are assigned to player=\<pid2>. The event is witnessed by \<number_witnesses>)*
+ `S <number_of_tasks> <pid>` *(An alien sabotages and removes \<number_of_tasks> tasks from the completed tasks. These tasks are assigned to players based on player \<pid>)* 
+ `V <pid1> <pid2> <vote_evidence>` *(Player=\<pid1> gains \<vote_evidence> of evidence and the player with the most evidence is ejected. His tasks are assigned to player=\<pid2>)*
+ `G <pid1> <pid2>` *(Half of the tasks of player=\<pid1> are assigned to player=\<pid2>)*
+ `F` *(Finish the game. Checks also if one of the two teams has won the game)*
+ `X` *(Prints all the players)*
+ `Y` *(Prints all the tasks)*
+ `Z` *(Prints all the tasks that are completed)*
+ `U` *(Prints all players and their tasks)*
