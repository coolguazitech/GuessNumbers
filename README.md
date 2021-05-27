# GuessNumbers

If you want to play the game directly, check your C++ environment, compiler (MinGW, g++...), compile the file `main.cpp`, and then start the game! Please note that when you enter your guess, separate your input with spaces, e.g. "1 2 3 4" or it will crash. The game will run like this:

>please select a number of digits you'd like to guess (3 or 4): 4 <br><br>
please take a guess (10 chances left): 0 1 2 3 <br>
0 1 2 3 >> 0 A 1 B <br>
please take a guess (9 chances left): 1 4 5 6 <br>
1 4 5 6 >> 0 A 1 B <br>
please take a guess (8 chances left): 5 7 3 9 <br>
5 7 3 9 >> 0 A 2 B <br>
please take a guess (7 chances left): 7 3 4 8 <br>
7 3 4 8 >> 0 A 1 B <br>
please take a guess (6 chances left): 9 5 8 2 <br>
9 5 8 2 >> 4 A 0 B <br><br>
You win!


## Abstract
In a well-known game, Bulls & Cows, two players each hold a set of digits to their chests, after logically reasoning with from-turn-to-turn queries, their guesses match the confidential digits. The winner is presumably set to be the one who uses the fewest chances to guess. In this paper, we propose an arithmetic (way to guess) and prove how good it is, which is compared to the other one usually used by most of people, by both mathematical derivation and experimental statistics. We are also interested in the statistical distribution of numbers of guesses in winner's manner, in particular, the mean of them.

## Introduction to Bulls & Cows

In our study, the classic game *Bulls & Cows* is converted to a simple version which has a folk name in my living area, by its direct meaning, called GuessNumbers. First and foremost, each players set 4 secret digits and bear them in mind, for each turn, one takes a guess in order to match the opponent's digits, and then the other does the same vise versa. Once a guess (said to be a query) is given, the opponent must give a corresponding response that has a pattern of xAyB (x and y are numbers between 0 and 4), which means that there are x digits appearing in the target pattern and being located in the right positions, and y digits appearing in the target pattern but in the wrong positions. The aim is to see who correctly guesses the opponent's digits first, or with the fewest number of chances. One can assume that the key to winning the game is to choose a better method of guessing, or arithmetic.

## Method
Since the states of the game are volatile, and that the methods of guessing each turn are not independent in probability, it's not practical to calculate all the correctly guessing probabilities on what situations happen to the circumstances when players guess their digits by the current clue the opponent gave and by the previous one and the previous previous one, etc. Alternatively, we give two arithmetics, one is the widely used method of guessing, called Method B, the other is the mainly proposed arithmetic in our paper, called Method A. Then we code a simulation program and gather the statistics to see how these two methods go through quantitatively large-scale trials, the most important indicator is the guessing times for matching the correct digits. Why we select Method B on our control group is because of that we believe that those who have no idea how to choose a guessing strategy will take our advice if we tell them the pros about this method, no doubt here it's a reasonable method for this game.

## Algorithms
#### *Method A*
On the very beginning turn, we pick "0 1 2 3", for each turn, according to the previous response, we dispose of all the combinations of the digits that impossibly match up the form of "4 A 0 B" and also get rid of the previous guess, repeat this way, then we will inevitably get the right digits.
#### *Method B*
It's all similar to _Method A_, only except for first two turns, first turn we pick "0 1 2 3", if the response is of the form "xAyB" and x + y = 4, then we choose one of all permutations among "0 1 2 3" for each in the subsequent guesses, otherwise, it's forced to choose "4 5 6 7" at the second guess.

## Results
As we can obviously see, even though the mean of _Method A_ is leading by the narrowest of margins, the pivotal figures determining on who to win  frequently occur between 5 guesses and 6 guesses, the following report shows that you have higher probability fully matching up the digits at your 5th guess using _Method A_, interestingly, it's worth mentioning that if you win in 4 guesses, you are more likely to choose _Method B_ for your guessing strategy, this may cause a misjudgment that you think _Method B_ would be better if you've never considered _Method A_.
#### *Method A*
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

#### *Method B*
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
