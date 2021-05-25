# GuessNumbers

## Abstract
In a well-known game, Bulls & Cows, two players each hold a set of digits to their chests, after logically reasoning with from-turn-to-turn queries, their guesses match the confidential digits. The winner is presumably set to be the one who uses the fewest chances to guess. In this paper, we propose an arithmetic (way to guess) and prove how good it is, which is compared to the other one usually used by most of people, by both mathematical derivation and experimental statistics. We are also interested in the statistical distribution of numbers of guesses in winner's manner, in particular, the mean of them.

## Introduction to Bulls & Cows

In our study, the classic game *Bulls & Cows* is converted to a simple version which has a folk name in my living area, by its direct meaning, called GuessNumbers. First and foremost, each players set 4 secret digits and bear them in mind, for each turn, one takes a guess in order to match the opponent's digits, and then the other does the same vise versa. Once a guess (said to be a query) is given, the opponent must give a corresponding response that has a pattern of xAyB (x and y are numbers between 0 and 4), which means that there are x digits appearing in the target pattern and being located in the right positions, and y digits appearing in the target pattern but in the wrong positions. The aim is to see who correctly guesses the opponent's digits first, or with the fewest number of chances. One can assume that the key to winning the game is to choose a better method of guessing, or arithmetic.

## Method


Those who have no idea how to choose a guessing strategy
