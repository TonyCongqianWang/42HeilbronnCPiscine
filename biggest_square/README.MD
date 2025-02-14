# biggest_square

Compile with `make`, the name of the C compiler is expected to be `cc` if your compiler is named differently please change the Makefile.

Program expects file names as arguments. If no arguments are given, the program reads from stdin. The input files are expected to be rectangular maps of the following form:

```
<#lines><empty_character><obstacle_character><square_character>
[Map with #lines lines and arbitrary number of columns containing only <empty_character> and <obstacle_character>]
```

The output will be printed to stdout and contains will display the map with the a biggest possible square filled in with the <square_character>. Ties in size are decided by first y coordinate and then x coordinate.
 
Examples of valid maps:

```
3abc
aaa
aab
abb
```

```
3123
111
111
222
```

Outputs:

 ```
3abc
cca
ccb
abb
```

```
3123
331
331
222
```
 
Examples of invalid maps (duplicate character in first line; forbidden character in map):

```
3122
111
111
222
```
```
3abc
aac
aab
abb
```

 
