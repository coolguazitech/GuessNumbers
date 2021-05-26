# GuessNumbers

## Abstract
In a well-known game, Bulls & Cows, two players each hold a set of digits to their chests, after logically reasoning with from-turn-to-turn queries, their guesses match the confidential digits. The winner is presumably set to be the one who uses the fewest chances to guess. In this paper, we propose an arithmetic (way to guess) and prove how good it is, which is compared to the other one usually used by most of people, by both mathematical derivation and experimental statistics. We are also interested in the statistical distribution of numbers of guesses in winner's manner, in particular, the mean of them.

## Introduction to Bulls & Cows

In our study, the classic game *Bulls & Cows* is converted to a simple version which has a folk name in my living area, by its direct meaning, called GuessNumbers. First and foremost, each players set 4 secret digits and bear them in mind, for each turn, one takes a guess in order to match the opponent's digits, and then the other does the same vise versa. Once a guess (said to be a query) is given, the opponent must give a corresponding response that has a pattern of xAyB (x and y are numbers between 0 and 4), which means that there are x digits appearing in the target pattern and being located in the right positions, and y digits appearing in the target pattern but in the wrong positions. The aim is to see who correctly guesses the opponent's digits first, or with the fewest number of chances. One can assume that the key to winning the game is to choose a better method of guessing, or arithmetic.

## Method
Those who have no idea how to choose a guessing strategy...

## Results
### Our arithmetic
```
How many trials will be run in total (increment by 1000 recommended, max 65000): 10000

Inferring ...

Done in 81.4 s. The statistics has been gathered and resulted as below:

Amongst overall 10000 trials,
There are [    0 (  0 %) ] trials going through [  1 ] guess(es).
There are [    0 (  0 %) ] trials going through [  2 ] guess(es).
There are [  131 (  1 %) ] trials going through [  3 ] guess(es).
There are [  630 (  6 %) ] trials going through [  4 ] guess(es).
There are [ 4843 ( 48 %) ] trials going through [  5 ] guess(es).
There are [ 2929 ( 29 %) ] trials going through [  6 ] guess(es).
There are [ 1467 ( 14 %) ] trials going through [  7 ] guess(es).
There are [    0 (  0 %) ] trials going through [  8 ] guess(es).
There are [    0 (  0 %) ] trials going through [  9 ] guess(es).
There are [    0 (  0 %) ] trials going through [ 10 ] guess(es).
There are [    0 (  0 %) ] trials going through [ 11 ] guess(es).
There are [    0 (  0 %) ] trials going through [ 12 ] guess(es).
There are [    0 (  0 %) ] trials going through [ 13 ] guess(es).
There are [    0 (  0 %) ] trials going through [ 14 ] guess(es).
There are [    0 (  0 %) ] trials going through [ 15 ] guess(es).

Furthermore, the mean equals to 5.5 (times).
```
### Other's arithmetic
```
How many trials will be run in total (increment by 1000 recommended, max 65000): 10000

Inferring ...

Done in 82.1 s. The statistics has been gathered and resulted as below:

Amongst overall 10000 trials,
There are [    0 (  0 %) ] trials going through [  1 ] guess(es).
There are [    0 (  0 %) ] trials going through [  2 ] guess(es).
There are [  253 (  2 %) ] trials going through [  3 ] guess(es).
There are [  763 (  7 %) ] trials going through [  4 ] guess(es).
There are [ 3051 ( 30 %) ] trials going through [  5 ] guess(es).
There are [ 4458 ( 44 %) ] trials going through [  6 ] guess(es).
There are [ 1250 ( 12 %) ] trials going through [  7 ] guess(es).
There are [  225 (  2 %) ] trials going through [  8 ] guess(es).
There are [    0 (  0 %) ] trials going through [  9 ] guess(es).
There are [    0 (  0 %) ] trials going through [ 10 ] guess(es).
There are [    0 (  0 %) ] trials going through [ 11 ] guess(es).
There are [    0 (  0 %) ] trials going through [ 12 ] guess(es).
There are [    0 (  0 %) ] trials going through [ 13 ] guess(es).
There are [    0 (  0 %) ] trials going through [ 14 ] guess(es).
There are [    0 (  0 %) ] trials going through [ 15 ] guess(es).

Furthermore, the mean equals to 5.6 (times).
