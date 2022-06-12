# CLAP4-Wordle-Clone-in-C
A very simple clone of wordle made using C. This is a mini-project for our CLAP4 component at my university. The main purpose of this project was to explore file manipulation and understand how different concepts in C interact with each other. 
The project compiles in VS Code and Code::Blocks and runs in DOS.

## About Wordle:
Wordle is a web-based word game created and developed by Welsh software engineer Josh Wardle, and owned and published by The New York Times Company.

### Rules:
 - A 5 letter word has to be guessed within 6 tries.
 - Answers are not usually plurals.
 - Alphabets can be repeated.
 - After each guess, the color of the letters will change to show how close your guess was to the word.
 
 ### Letter Clues:
  - If an alphabet turns green, the letter is in the word and in the right spot.
  - If an alphabet turns red, the letter is in the word but in the wrong spot.
  - If an alphabet turns white, the letter is not in the word.

The application is intelligent when it comes to double letter guesses. If the guess is 'Abyss' and the word is 'Space', only one of the s' will display in red. 

Since the aim of this project was to explore file manipulation, I have not added an extensive list of 5-letter words. If the player wishes to add to the game's vocabulary, the code provides a way to do so.

## Usage:
Download the executable file and text file from the releases section. Make sure both the files are at the same location.
You should be presented with the 'title screen' of the game when the application is launched.
The code has been written to run on most terminals. It has been tested on Windows 10.

