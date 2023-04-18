# Pipex
Programming a well known UNIX mechanism from scratch
# Objectives
Our objective is to code the Pipex program. It should be executed in this way:

`$> ./pipex file1 cmd1 cmd2 file2`

file1 and file2 are file names, cmd1 and cmd2 are shell commands with their parameters.

The execution of the pipex program should do the same as the next shell command:

`$> < file1 cmd1 | cmd2 > file2`

## Examples 
`$> ./pipex infile ``ls -l'' ``wc -l'' outfile`

should be the same as `< infile ls -l | wc -l > outfile`

`$> ./pipex infile ``grep a1'' ``wc -w'' outfile`

should be the same as `< infile grep a1 | wc -w > outfile`

## Bonus
• Handle multiple pipes : 

`$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`

Must be equivalent to :

`< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`

• Support « and »

# Allowed Functions
◦ open

◦ close

◦ read

◦ write

◦ malloc

◦ waitpid 

◦ wait

◦ free

◦ pipe

◦ dup

◦ dup2

◦ execve

◦ fork

◦ perror

◦ strerror 

◦ exit

# Evaluation
## Preliminaries
- Norme
## General Instructions
- If the main program puts an error use the flag crash
- The Makefile compiles executables and has the required rules
- The executable is named pipex
- No prohibited functions
## Mandatory part
The command ./pipex file1 cmd1 cmd2 file2 must behave like this command: <file1 cmd1 | cmd2> file2
### Error and arguments management
- The program takes 4 arguments, no more, no less (except for bonus part) and only in the right order.
- Error management is correct: existing files, files rights, the binary of the command exists etc.

### The program
- The program does what is requested, without displaying any additional information/steps against the shell command
- Run your own tests et compare the results of shell exit and of shell output and that of the program.
- If you haven't any idea, look at the subject examples.
- If no error is detected, check 'Yes' and continue.
