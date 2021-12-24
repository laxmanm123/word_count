#word_count_lite

Hello! This program is created in C to process a number of text files, and 
create an output text file that displays information on each text file, and across
all files, such as number of words, characters, numbers, etc.

When running the program, the following flags produce the following outputs:
-n: Count the number of numbers
-c: Count the number of characters
-w: Count the number of words
-l: Count the number of lines
-o (file_name): writes to output file called (file_name).txt
-f (length: number of spaces (for formatting)

If none of the first 4 flags are given, then the program by default will execute as if
the flags -w -c and -l are given. If any one is present, then only that one will be included
in the ouput file. -o and -f are both optional flags, and will default to stdout.txt and 20 spaces
respectivley.

Here are some example uses of the program.
./word_count_lite -n -w foo.txt bar.txt

foo.txt          :    12     7
bar.txt          :    31     8
total            :    43    15

if no flags are given and only file names:
./wc_lite_app foo.txt bar.txt baz.txt

foo.txt          :    47    12     4
bar.txt          :   139    31     8
baz.txt: No such file or directory
total            :   186    43    12

If any files cannot be found, the program accounts for that. 
The order in which they are printed is always the same: 
char count, word count, num count, line count. 
