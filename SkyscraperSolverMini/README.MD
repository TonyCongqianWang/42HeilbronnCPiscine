## Simpler Solver for the Skyscraper puzzle game

Made after the weekend as a more simpler and readable version using the same concepts. Compile and use as following;

```
cc -Wall -Wextra -Werror -o rush-01 *.c
./rush-01 '4 1 2 2 1 4 2 2 2 3 2 1 2 1 2 3'
./rush-01 "1 4 2 2 3 1 2 3 1 2 3 2 2 1 2 3"
./rush-01 "1 2 4 2 3 3 4 2 2 1 1 2 4 2 4 3 2 2 3 1"
./rush-01 "5 3 2 1 3 4 1 2 4 2 2 3 4 3 2 3 2 1 3 4 2 1 2 3"
```

Accepts grids up to size 9. Constraints are in order top (l->r) bottom (l->r) left (t->b) right (t->b).

Due to lack of optimizations, this version can not solve anything above 6x6 in reasonable time.