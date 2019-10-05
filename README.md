PaperScissorsRockGame

## PURPOSE
PaperScissorsRock (PSR) is a hand-game of symbols where you can play versus the computer. Some of the features:
1. Language support. Currently offers English, Spanish, and Filipino
2. Option for level of difficulty. Currently offers Easy, Average, and Hard
    * Technically, this controls the probability of the computer chossing the symbol that beats the user
3. Randomized nature
    1. Number of games per run are randomized
    2. Computer chosen symbols are randomized
4. Open for new symbols. Implementation is ready to be extended to more symbols.
5. Game can be compiled as a standalone static library (.a)
    * It can be linked to executables using the IGameController inerface, just provide the dependencies (constructor inputs)
6. Project has been compiled using CMake on a GNU/Linux environment
    * If CMake is not available, I have written a manual ./Tools/Make/Makefile which just requires GNU Make. However, it is only for src codes, because test codes require googletest library which I have linked specifically through CMake only.
    * Compilation on other operating systems (Windows, Mac, etc.) or through IDE has not been tried, might need more setup
7. Optional: When running tests, I wrote a script to display the target testcase.
    * Script is in ./Tools/GoogleTestResultReader/readgtest
8. There are 2 options available when running the compiled ./build/src/psr_src particularly --help and --play
9. Classes and files that are either straight forward (ex. those returning const values) or just controls the flow (Controller files) are not tested to avoid creating change-detector tests (tests that do not test logic but rather tests what you have written on the src code line by line).

## REQUIREMENTS
1. GNU/Linux environment
    * Either:
        1. Full operating system
        2. Virtual machine (as a guest OS)
        3. Cygwin
        4. etc.
2. Git (due to dependency to googletest in GitHub)
    ~~~
    sudo apt install git
    ~~~
3. GNU Toolchain
    ~~~
    sudo apt install build-essential
    ~~~
4. CMake
    ~~~
    sudo apt install cmake
    ~~~
5. Boost (optional, for future development)
    ~~~
    sudo apt install libboost-all-dev
    ~~~

## BUILDING
Using CMake
~~~
cd PaperScissorsRockGame
mkdir -p build && cd build
cmake ..
make
~~~
Using GNU Make only
~~~
cd PaperScissorsRockGame
cp Tools/Make/Makefile .
make
~~~

## RUNNING
Using CMake
~~~
cd PaperScissorsRockGame
build/src/psr_src --help
build/src/psr_src --play
~~~
Using GNU Make only
~~~
cd PaperScissorsRockGame
bin_manual/a.out --help
bin_manual/a.out --play
~~~

## TESTING
~~~
cd PaperScissorsRockGame
build/test/psr_test
~~~
To display result of specific testcase
~~~
cd PaperScissorsRockGame
Tools/GoogleTestResultReader/readgtest build/test/psr_test
Tools/GoogleTestResultReader/readgtest build/test/psr_test --all
Tools/GoogleTestResultReader/readgtest build/test/psr_test --test TestName
~~~

## EXAMPLE RUN
~~~
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs$ 
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs$ cd PaperScissorsRockGame/
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame$ mkdir build
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame$ cd build/
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ cmake ..
... trimmed prints ...
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ make
... trimmed prints ...
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ src/psr_src 

[main] Start of execution
[main] Input to main is src/psr_src
[MainController] Unsupported message src/psr_src
[MainController] Try with --help to display usage, sample command: ./psr_src --help
[main] End of execution
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ 
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ src/psr_src --help

[main] Start of execution
[main] Input to main is --help
[HelpController] 
[HelpController] PaperScissorsRock (PSR) is a hand-game of symbols where you can play versus the computer.
[HelpController] The winner is determined by the following schema:
[HelpController]     paper beats (wraps) rock,
[HelpController]     rock beats (blunts) scissors,
[HelpController]     scissors beats (cuts) paper.
[HelpController] 
[HelpController] Postfix the following commands upon running <./psr_src>
[HelpController] 
[HelpController]    --help
[HelpController]        Display the information about this project.
[HelpController]        Guides you with the available commands to move through what the project can offer.
[HelpController] 
[HelpController]    --play
[HelpController]        Access the game! Different languages are supported such as English, Spanish, and Filipino
[HelpController]        Si no lo entiendes, lo que estoy diciendo es Espanol esta disponible en este app!
[HelpController]        Oo pati Filipino! At posibleng marami pang iba!
[HelpController]        Different modes of difficulty can also be chosen such as easy, average, and hard
[HelpController]        The question now is, are you lucky enough to win? Vamos a jugarlo, mi amigo!
[HelpController] 
[HelpController]        Good luck predicting the computer's next move! :)
[main] End of execution
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ src/psr_src --play

[main] Start of execution
[main] Input to main is --play
[IOutputter::selectLanguage] Select your language, me entiendes?
[IOutputter::selectLanguage]     0 English
[IOutputter::selectLanguage]     1 Espanol
[IOutputter::selectLanguage]     2 Filipino
[UserInputHandler] Input:0

[EnglishOutputter] Hi there! Let's play Paper Scissors Rock!
[EnglishOutputter] Select difficulty:
[EnglishOutputter]     0 Easy
[EnglishOutputter]     1 Average
[EnglishOutputter]     2 Hard
[UserInputHandler] Input:2

[EnglishOutputter] The game will be played for 5 rounds
[EnglishOutputter] 
[EnglishOutputter] Countdown: Battle #5
[EnglishOutputter] Select your symbol:
[EnglishOutputter]     0 Paper
[EnglishOutputter]     1 Rock
[EnglishOutputter]     2 Scissors
[UserInputHandler] Input:1

[EnglishOutputter] You:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EnglishOutputter] versus
[EnglishOutputter] Computer:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EnglishOutputter] Draw for this round!
[EnglishOutputter] Rock neither beats nor lose to Rock
[EnglishOutputter] 
[EnglishOutputter] Countdown: Battle #4
[EnglishOutputter] Select your symbol:
[EnglishOutputter]     0 Paper
[EnglishOutputter]     1 Rock
[EnglishOutputter]     2 Scissors
[UserInputHandler] Input:0

[EnglishOutputter] You:
             _____
       _____ |   | _____
       |   | |   | |   |
       |   | |   | |   |
       |   | |   | |   | ____
       |   | |   | |   | |  |
       |   | |   | |   | |  |
       |   | |   | |   | |  |
       |   | |   | |   | |  |
_____  |   | |   | |   | |  |
|   |  |   | |   | |   | |  |
|   |  |   |_|   |_|   |_|  |
|   | /                     |
|   |/                      |
\                           |
 \                          |
  \                         |
   \                        |
    \                       |
     \                     /
      \                   /

[EnglishOutputter] versus
[EnglishOutputter] Computer:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EnglishOutputter] You win this round
[EnglishOutputter] Paper beats Rock
[EnglishOutputter] 
[EnglishOutputter] Countdown: Battle #3
[EnglishOutputter] Select your symbol:
[EnglishOutputter]     0 Paper
[EnglishOutputter]     1 Rock
[EnglishOutputter]     2 Scissors
[UserInputHandler] Input:2

[EnglishOutputter] You:
                _____
        _____   |   | 
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   | _____
  ____  |   |   |   | |   | ____
 /   /  |   |   |   | |   | |  |
/   /  /    |___|   |_|   |_|  |
|   | /               |   | |  |
|   |/                |   | |__|
\                     |___| \__/
 \                    \___/    |
  \                            |
   \                           |
    \                          |
     \                        /
      \                      /

[EnglishOutputter] versus
[EnglishOutputter] Computer:
                _____
        _____   |   | 
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   | _____
  ____  |   |   |   | |   | ____
 /   /  |   |   |   | |   | |  |
/   /  /    |___|   |_|   |_|  |
|   | /               |   | |  |
|   |/                |   | |__|
\                     |___| \__/
 \                    \___/    |
  \                            |
   \                           |
    \                          |
     \                        /
      \                      /

[EnglishOutputter] Draw for this round!
[EnglishOutputter] Scissors neither beats nor lose to Scissors
[EnglishOutputter] 
[EnglishOutputter] Countdown: Battle #2
[EnglishOutputter] Select your symbol:
[EnglishOutputter]     0 Paper
[EnglishOutputter]     1 Rock
[EnglishOutputter]     2 Scissors
[UserInputHandler] Input:2

[EnglishOutputter] You:
                _____
        _____   |   | 
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   | _____
  ____  |   |   |   | |   | ____
 /   /  |   |   |   | |   | |  |
/   /  /    |___|   |_|   |_|  |
|   | /               |   | |  |
|   |/                |   | |__|
\                     |___| \__/
 \                    \___/    |
  \                            |
   \                           |
    \                          |
     \                        /
      \                      /

[EnglishOutputter] versus
[EnglishOutputter] Computer:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EnglishOutputter] You lose this round
[EnglishOutputter] Scissors loses to Rock
[EnglishOutputter] 
[EnglishOutputter] Countdown: Battle #1
[EnglishOutputter] Select your symbol:
[EnglishOutputter]     0 Paper
[EnglishOutputter]     1 Rock
[EnglishOutputter]     2 Scissors
[UserInputHandler] Input:1

[EnglishOutputter] You:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EnglishOutputter] versus
[EnglishOutputter] Computer:
             _____
       _____ |   | _____
       |   | |   | |   |
       |   | |   | |   |
       |   | |   | |   | ____
       |   | |   | |   | |  |
       |   | |   | |   | |  |
       |   | |   | |   | |  |
       |   | |   | |   | |  |
_____  |   | |   | |   | |  |
|   |  |   | |   | |   | |  |
|   |  |   |_|   |_|   |_|  |
|   | /                     |
|   |/                      |
\                           |
 \                          |
  \                         |
   \                        |
    \                       |
     \                     /
      \                   /

[EnglishOutputter] You lose this round
[EnglishOutputter] Rock loses to Paper
[EnglishOutputter] Tally: You 1 vs Computer 2
[EnglishOutputter] You didn't win. Better luck next time!
[main] End of execution
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ 
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ src/psr_src --play

[main] Start of execution
[main] Input to main is --play
[IOutputter::selectLanguage] Select your language, me entiendes?
[IOutputter::selectLanguage]     0 English
[IOutputter::selectLanguage]     1 Espanol
[IOutputter::selectLanguage]     2 Filipino
[UserInputHandler] Input:1

[EspanolOutputter] Hola mi amigo, como estas! Vamos a jugar Paper Scissors Rock!
[EspanolOutputter] Elige dificultad:
[EspanolOutputter]     0 Easy
[EspanolOutputter]     1 Average
[EspanolOutputter]     2 Hard
[UserInputHandler] Input:1

[EspanolOutputter] El juego se jugara 10 veces
[EspanolOutputter] 
[EspanolOutputter] Cuenta regresiva: Batalla #10
[EspanolOutputter] Elige tu simbolo:
[EspanolOutputter]     0 Paper
[EspanolOutputter]     1 Rock
[EspanolOutputter]     2 Scissors
[UserInputHandler] Input:0

[EspanolOutputter] Tu:
             _____
       _____ |   | _____
       |   | |   | |   |
       |   | |   | |   |
       |   | |   | |   | ____
       |   | |   | |   | |  |
       |   | |   | |   | |  |
       |   | |   | |   | |  |
       |   | |   | |   | |  |
_____  |   | |   | |   | |  |
|   |  |   | |   | |   | |  |
|   |  |   |_|   |_|   |_|  |
|   | /                     |
|   |/                      |
\                           |
 \                          |
  \                         |
   \                        |
    \                       |
     \                     /
      \                   /

[EspanolOutputter] contra
[EspanolOutputter] Computadora:
                _____
        _____   |   | 
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   | _____
  ____  |   |   |   | |   | ____
 /   /  |   |   |   | |   | |  |
/   /  /    |___|   |_|   |_|  |
|   | /               |   | |  |
|   |/                |   | |__|
\                     |___| \__/
 \                    \___/    |
  \                            |
   \                           |
    \                          |
     \                        /
      \                      /

[EspanolOutputter] Tu pierdes esta ronda
[EspanolOutputter] Paper pierde a Scissors
[EspanolOutputter] 
[EspanolOutputter] Cuenta regresiva: Batalla #9
[EspanolOutputter] Elige tu simbolo:
[EspanolOutputter]     0 Paper
[EspanolOutputter]     1 Rock
[EspanolOutputter]     2 Scissors
[UserInputHandler] Input:0

[EspanolOutputter] Tu:
             _____
       _____ |   | _____
       |   | |   | |   |
       |   | |   | |   |
       |   | |   | |   | ____
       |   | |   | |   | |  |
       |   | |   | |   | |  |
       |   | |   | |   | |  |
       |   | |   | |   | |  |
_____  |   | |   | |   | |  |
|   |  |   | |   | |   | |  |
|   |  |   |_|   |_|   |_|  |
|   | /                     |
|   |/                      |
\                           |
 \                          |
  \                         |
   \                        |
    \                       |
     \                     /
      \                   /

[EspanolOutputter] contra
[EspanolOutputter] Computadora:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EspanolOutputter] Tu ganas esta ronda
[EspanolOutputter] Paper vencio Rock
[EspanolOutputter] 
[EspanolOutputter] Cuenta regresiva: Batalla #8
[EspanolOutputter] Elige tu simbolo:
[EspanolOutputter]     0 Paper
[EspanolOutputter]     1 Rock
[EspanolOutputter]     2 Scissors
[UserInputHandler] Input:2

[EspanolOutputter] Tu:
                _____
        _____   |   | 
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   | _____
  ____  |   |   |   | |   | ____
 /   /  |   |   |   | |   | |  |
/   /  /    |___|   |_|   |_|  |
|   | /               |   | |  |
|   |/                |   | |__|
\                     |___| \__/
 \                    \___/    |
  \                            |
   \                           |
    \                          |
     \                        /
      \                      /

[EspanolOutputter] contra
[EspanolOutputter] Computadora:
             _____
       _____ |   | _____
       |   | |   | |   |
       |   | |   | |   |
       |   | |   | |   | ____
       |   | |   | |   | |  |
       |   | |   | |   | |  |
       |   | |   | |   | |  |
       |   | |   | |   | |  |
_____  |   | |   | |   | |  |
|   |  |   | |   | |   | |  |
|   |  |   |_|   |_|   |_|  |
|   | /                     |
|   |/                      |
\                           |
 \                          |
  \                         |
   \                        |
    \                       |
     \                     /
      \                   /

[EspanolOutputter] Tu ganas esta ronda
[EspanolOutputter] Scissors vencio Paper
[EspanolOutputter] 
[EspanolOutputter] Cuenta regresiva: Batalla #7
[EspanolOutputter] Elige tu simbolo:
[EspanolOutputter]     0 Paper
[EspanolOutputter]     1 Rock
[EspanolOutputter]     2 Scissors
[UserInputHandler] Input:1

[EspanolOutputter] Tu:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EspanolOutputter] contra
[EspanolOutputter] Computadora:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EspanolOutputter] Empate para esta ronda!
[EspanolOutputter] Rock tampoco vencio ni pierde a Rock
[EspanolOutputter] 
[EspanolOutputter] Cuenta regresiva: Batalla #6
[EspanolOutputter] Elige tu simbolo:
[EspanolOutputter]     0 Paper
[EspanolOutputter]     1 Rock
[EspanolOutputter]     2 Scissors
[UserInputHandler] Input:1

[EspanolOutputter] Tu:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EspanolOutputter] contra
[EspanolOutputter] Computadora:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EspanolOutputter] Empate para esta ronda!
[EspanolOutputter] Rock tampoco vencio ni pierde a Rock
[EspanolOutputter] 
[EspanolOutputter] Cuenta regresiva: Batalla #5
[EspanolOutputter] Elige tu simbolo:
[EspanolOutputter]     0 Paper
[EspanolOutputter]     1 Rock
[EspanolOutputter]     2 Scissors
[UserInputHandler] Input:2

[EspanolOutputter] Tu:
                _____
        _____   |   | 
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   | _____
  ____  |   |   |   | |   | ____
 /   /  |   |   |   | |   | |  |
/   /  /    |___|   |_|   |_|  |
|   | /               |   | |  |
|   |/                |   | |__|
\                     |___| \__/
 \                    \___/    |
  \                            |
   \                           |
    \                          |
     \                        /
      \                      /

[EspanolOutputter] contra
[EspanolOutputter] Computadora:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EspanolOutputter] Tu pierdes esta ronda
[EspanolOutputter] Scissors pierde a Rock
[EspanolOutputter] 
[EspanolOutputter] Cuenta regresiva: Batalla #4
[EspanolOutputter] Elige tu simbolo:
[EspanolOutputter]     0 Paper
[EspanolOutputter]     1 Rock
[EspanolOutputter]     2 Scissors
[UserInputHandler] Input:0

[EspanolOutputter] Tu:
             _____
       _____ |   | _____
       |   | |   | |   |
       |   | |   | |   |
       |   | |   | |   | ____
       |   | |   | |   | |  |
       |   | |   | |   | |  |
       |   | |   | |   | |  |
       |   | |   | |   | |  |
_____  |   | |   | |   | |  |
|   |  |   | |   | |   | |  |
|   |  |   |_|   |_|   |_|  |
|   | /                     |
|   |/                      |
\                           |
 \                          |
  \                         |
   \                        |
    \                       |
     \                     /
      \                   /

[EspanolOutputter] contra
[EspanolOutputter] Computadora:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EspanolOutputter] Tu ganas esta ronda
[EspanolOutputter] Paper vencio Rock
[EspanolOutputter] 
[EspanolOutputter] Cuenta regresiva: Batalla #3
[EspanolOutputter] Elige tu simbolo:
[EspanolOutputter]     0 Paper
[EspanolOutputter]     1 Rock
[EspanolOutputter]     2 Scissors
[UserInputHandler] Input:2

[EspanolOutputter] Tu:
                _____
        _____   |   | 
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   | _____
  ____  |   |   |   | |   | ____
 /   /  |   |   |   | |   | |  |
/   /  /    |___|   |_|   |_|  |
|   | /               |   | |  |
|   |/                |   | |__|
\                     |___| \__/
 \                    \___/    |
  \                            |
   \                           |
    \                          |
     \                        /
      \                      /

[EspanolOutputter] contra
[EspanolOutputter] Computadora:
                _____
        _____   |   | 
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   | _____
  ____  |   |   |   | |   | ____
 /   /  |   |   |   | |   | |  |
/   /  /    |___|   |_|   |_|  |
|   | /               |   | |  |
|   |/                |   | |__|
\                     |___| \__/
 \                    \___/    |
  \                            |
   \                           |
    \                          |
     \                        /
      \                      /

[EspanolOutputter] Empate para esta ronda!
[EspanolOutputter] Scissors tampoco vencio ni pierde a Scissors
[EspanolOutputter] 
[EspanolOutputter] Cuenta regresiva: Batalla #2
[EspanolOutputter] Elige tu simbolo:
[EspanolOutputter]     0 Paper
[EspanolOutputter]     1 Rock
[EspanolOutputter]     2 Scissors
[UserInputHandler] Input:1

[EspanolOutputter] Tu:
             _____
       ____  |   | _____
       |   | |   | |   | ____
   ____|   | |   | |   | |  |
  /   /|   | |   | |   | |  |
 /   / |   | |   | |   | |  |
/   /  |   |_|   |_|   |_|  |
|   | /|   | |   | |   | |__|
|   |/ |   | |   | |   | \__/
\      |___| |   | |___|    |
 \     \___/ |___| \___/    |
  \          \___/          |
   \                        |
    \                       |
     \                     /
      \                   /

[EspanolOutputter] contra
[EspanolOutputter] Computadora:
                _____
        _____   |   | 
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   | _____
  ____  |   |   |   | |   | ____
 /   /  |   |   |   | |   | |  |
/   /  /    |___|   |_|   |_|  |
|   | /               |   | |  |
|   |/                |   | |__|
\                     |___| \__/
 \                    \___/    |
  \                            |
   \                           |
    \                          |
     \                        /
      \                      /

[EspanolOutputter] Tu ganas esta ronda
[EspanolOutputter] Rock vencio Scissors
[EspanolOutputter] 
[EspanolOutputter] Cuenta regresiva: Batalla #1
[EspanolOutputter] Elige tu simbolo:
[EspanolOutputter]     0 Paper
[EspanolOutputter]     1 Rock
[EspanolOutputter]     2 Scissors
[UserInputHandler] Input:2

[EspanolOutputter] Tu:
                _____
        _____   |   | 
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   | _____
  ____  |   |   |   | |   | ____
 /   /  |   |   |   | |   | |  |
/   /  /    |___|   |_|   |_|  |
|   | /               |   | |  |
|   |/                |   | |__|
\                     |___| \__/
 \                    \___/    |
  \                            |
   \                           |
    \                          |
     \                        /
      \                      /

[EspanolOutputter] contra
[EspanolOutputter] Computadora:
                _____
        _____   |   | 
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   |
        |   |   |   | _____
  ____  |   |   |   | |   | ____
 /   /  |   |   |   | |   | |  |
/   /  /    |___|   |_|   |_|  |
|   | /               |   | |  |
|   |/                |   | |__|
\                     |___| \__/
 \                    \___/    |
  \                            |
   \                           |
    \                          |
     \                        /
      \                      /

[EspanolOutputter] Empate para esta ronda!
[EspanolOutputter] Scissors tampoco vencio ni pierde a Scissors
[EspanolOutputter] Cuenta: Tu 4 vs Computadora 2
[EspanolOutputter] Tu ganaste en este concurso. Debes estar lleno de suerte!
[main] End of execution
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ 
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ test/psr_test 
[==========] Running 14 tests from 4 test suites.
[----------] Global test environment set-up.
[----------] 5 tests from RandomGeneratorTest
[ RUN      ] RandomGeneratorTest.DecideOnCasesThatShouldBeYes
[       OK ] RandomGeneratorTest.DecideOnCasesThatShouldBeYes (0 ms)
[ RUN      ] RandomGeneratorTest.DecideOnCasesThatShouldBeNo
[       OK ] RandomGeneratorTest.DecideOnCasesThatShouldBeNo (0 ms)
[ RUN      ] RandomGeneratorTest.GenerateRandomDecisions
[       OK ] RandomGeneratorTest.GenerateRandomDecisions (0 ms)
[ RUN      ] RandomGeneratorTest.GenerateRandomNumbers
[       OK ] RandomGeneratorTest.GenerateRandomNumbers (1 ms)
[ RUN      ] RandomGeneratorTest.NotExceedLimit
[       OK ] RandomGeneratorTest.NotExceedLimit (6 ms)
[----------] 5 tests from RandomGeneratorTest (7 ms total)

[----------] 3 tests from PaperSymbolTest
[ RUN      ] PaperSymbolTest.CheckName
[       OK ] PaperSymbolTest.CheckName (0 ms)
[ RUN      ] PaperSymbolTest.CheckSymbolState
[       OK ] PaperSymbolTest.CheckSymbolState (0 ms)
[ RUN      ] PaperSymbolTest.CheckBattleResults
[       OK ] PaperSymbolTest.CheckBattleResults (0 ms)
[----------] 3 tests from PaperSymbolTest (0 ms total)

[----------] 3 tests from RockSymbolTest
[ RUN      ] RockSymbolTest.CheckName
[       OK ] RockSymbolTest.CheckName (0 ms)
[ RUN      ] RockSymbolTest.CheckSymbolState
[       OK ] RockSymbolTest.CheckSymbolState (0 ms)
[ RUN      ] RockSymbolTest.CheckBattleResults
[       OK ] RockSymbolTest.CheckBattleResults (0 ms)
[----------] 3 tests from RockSymbolTest (0 ms total)

[----------] 3 tests from ScissorsSymbolTest
[ RUN      ] ScissorsSymbolTest.CheckName
[       OK ] ScissorsSymbolTest.CheckName (0 ms)
[ RUN      ] ScissorsSymbolTest.CheckSymbolState
[       OK ] ScissorsSymbolTest.CheckSymbolState (0 ms)
[ RUN      ] ScissorsSymbolTest.CheckBattleResults
[       OK ] ScissorsSymbolTest.CheckBattleResults (0 ms)
[----------] 3 tests from ScissorsSymbolTest (0 ms total)

[----------] Global test environment tear-down
[==========] 14 tests from 4 test suites ran. (7 ms total)
[  PASSED  ] 14 tests.
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ 
nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ ../Tools/GoogleTestResultReader/readgtest test/psr_test --test RandomGene
[----------] 5 tests from RandomGeneratorTest
[ RUN      ] RandomGeneratorTest.DecideOnCasesThatShouldBeYes
[       OK ] RandomGeneratorTest.DecideOnCasesThatShouldBeYes (0 ms)
[ RUN      ] RandomGeneratorTest.DecideOnCasesThatShouldBeNo
[       OK ] RandomGeneratorTest.DecideOnCasesThatShouldBeNo (0 ms)
[ RUN      ] RandomGeneratorTest.GenerateRandomDecisions
[       OK ] RandomGeneratorTest.GenerateRandomDecisions (1 ms)
[ RUN      ] RandomGeneratorTest.GenerateRandomNumbers
[       OK ] RandomGeneratorTest.GenerateRandomNumbers (1 ms)
[ RUN      ] RandomGeneratorTest.NotExceedLimit
[       OK ] RandomGeneratorTest.NotExceedLimit (6 ms)
[----------] 5 tests from RandomGeneratorTest (9 ms total)

nponcian@nponcian-VirtualBox-Ubuntu:~/Documents/Programs/PaperScissorsRockGame/build$ 
~~~
