# Minesweeper
Minesweeper in C++

vocabulary:
flag         (verb,noun) refers to flags placed by user, not flag variables
q_mark       (verb,noun) refers to question marks by user
mine         (noun) an explosive device
sweep        (verb) the act of checking for mines
tile         (noun) a unit of the Table
Minefield    (noun) area of game, collection of tiles

Coordinate system:
Upper right corner is (0,0)
General co-ordinate is (i,j)
i increases in downward direction
j increases in rightward direction

User commands:
S - sweep from given tile
F - flag given tile
Q - q_mark given tile
C - clear given tile of q_marks and flags
co-ordinates of tile under consideration entered like so: <<command>> <<i>> <<j>>
