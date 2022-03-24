# Poker-sim
simulate poker

**How to use**

**Seeds**-
Input a seed and amount of poker hands.

Seed example

```.\poker.exe -s 100 100000```
```
Hand Name                Dealt         Chance
Royal Flush                  0       0.000000%
Straight Flush               2       0.002000%
Four of a Kind              28       0.028000%
Full House                 163       0.163000%
Flush                      203       0.203000%
Straights                  392       0.392000%
Three of a Kind           2029       2.029000%
Two Pair                  4690       4.690000%
Two of a kind            42565      42.565000%
High Card                49928      49.928000%

Total Hands Dealt       100000
```

```.\Poker.exe -s [seed] [number of hands drawn]```

**Files**-
Input a file of numbers between 0 and 51 with 5 number on each line.
Example

```.\poker.exe -f file1.txt file1out.txt```
```
Hand Name                Dealt         Chance
Royal Flush                  1       0.000100%
Straight Flush              14       0.001400%
Four of a Kind             232       0.023200%
Full House                1478       0.147800%
Flush                     1906       0.190600%
Straights                 3919       0.391900%
Three of a Kind          20918       2.091800%
Two Pair                 47567       4.756700%
Two of a kind           422909      42.290900%
High Card               501056      50.105600%
Total Hands Dealt      1000000
```
```.\Poker.exe -f [input file] [output file]```
