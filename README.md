# CLAP4-Wordle-Clone-in-C
A very simple clone of Wordle made using C. The main purpose of this project was to explore file manipulation and understand how different concepts in C interact with each other. The project compiles in VS Code and Code::Blocks and runs in DOS.

## About Wordle:
Wordle is a web-based word game created and developed by Welsh software engineer Josh Wardle, and owned and published by The New York Times Company.

### Rules:
 - A 5-letter word has to be guessed within 6 tries.
 - Answers are not usually plurals.
 - Alphabets can be repeated.
 - After each guess, the color of the letters will change to show how close your guess was to the word.
 
 ### Letter Clues:
  - If an alphabet turns green, the letter is in the word and in the right spot.
  - If an alphabet turns red, the letter is in the word but in the wrong spot.
  - If an alphabet turns white, the letter is not in the word.

The application is intelligent when it comes to double letter guesses. If the guess is 'bluff' and the word is 'facet', only ONE of the f's will display in red. 
The program will not allow you to include numbers or special characters in your guesses. It will also check to see if your guess has the required number of letters.

A word solution is pulled randomly from a pool of 2315 words in the "WORDS.txt" file. The "ALLWORDS.txt" file contains the list of all accepted words. These are the same sets of words used in the official Wordle game by The New York Times.

If the player wishes to add to the game's vocabulary, the code provides a way to do so. The feature is mostly redundant, but I have added it just to understand how strings can be printed to files.

## Usage:
Download the executable file and the two text files from the releases section. Make sure all three files are at the same file location.
You should be presented with the 'title screen' of the game when the application is launched.
The code has been written to run on most terminals. It has been tested on Windows 10.
