# MazeCli
Command line interface for maze creation and resolve.
## Build:
Using following command, docker container will build solution (CMake + C++17 compiler), run examples and remain open bash to try more options:
```
git clone git@github.com:omarekik/MazeCli.git && cd MazeCli
cd Maze && docker run --rm -it $(docker build -q .)
```
## Example of execution:
Remain in the build directory and run the following commands:
```console
$ ./maze -h
Program options:
  -h [ --help ]             display help menu
  -c [ --create ]           output a solvable maze to the terminal containing 
                            both start and end points
  -w [ --width ] arg (=10)  width of the maze to be created
  -t [ --height ] arg (=10) height of the maze to be created
  -s [ --seed ] arg (=10)   seed of the maze to be created
  -x [ --solve ]            parse the input maze from the terminal and print it
                            back solved. If an impossible maze is given, 
                            impossible message will be printed

Either create or solve option should be called
```

```console
$ ./maze --create --width 10 --height 10 --seed 10
S ███████████████████
    █     █         █
█ ███ █ █████ ███████
█   █ █ █ █ █ █     █
█ █████ █ █ █ █ ███ █
█   █   █ █ █ █ █   █
█ █ █ █ █ █ █ █████ █
█ █ █ █   █   █     █
█ █ █ █████ ███ █ █ █
█ █             █ █ █
███ ███ █ █████ █ ███
█     █ █     █ █ █ █
█████████ ███████ █ █
█       █   █ █     █
█ ███████ █ █ ███████
█     █   █       █ █
█ ███ █ █████ █ ███ █
█ █         █ █     █
█████ █ ███████████ █
█     █ █
███████████████████ E
```
The short form of this same command is `./maze -c -w 10 -t 10 -s 10` or `./maze -c`

```console
$ ./maze -c | ./maze --solve
Sx███████████████████
 x  █     █         █
█x███ █ █████ ███████
█x  █ █ █ █ █ █     █
█x█████ █ █ █ █ ███ █
█xxx█   █ █ █ █ █   █
█ █x█ █ █ █ █ █████ █
█ █x█ █   █   █     █
█ █x█ █████ ███ █ █ █
█ █xxxxxxx      █ █ █
███ ███ █x█████ █ ███
█     █ █x    █ █ █ █
█████████x███████ █ █
█       █xxx█ █     █
█ ███████ █x█ ███████
█     █   █xxxxx  █ █
█ ███ █ █████ █x███ █
█ █         █ █xxxxx█
█████ █ ███████████x█
█     █ █          xx
███████████████████ E
```
The short form of this same command is `./maze -x`

## Open items to improve performance:

* Package the CLI as a Conan module
