# Shell-Tokenizer
A hardcoded version of Shell Tokenizer

My shell tokenizer reads single line shell commands, splits them into a sequence of tokens, reverses the sequence, and prints out one token per line
There are three kinds of tokens: Command names, Command arguments, Shell operators. Spaces that appear in a command are not tokens, although they may separate tokens.
Example interaction:
bash$ ./tokens
tokens$ echo one; echo two
two
echo
;
one
echo
tokens$ sort foo.txt | uniq
uniq
|
foo.txt
sort
tokens$ ^D
bash$
In the above interaction "^D" means the user has pressed Ctrl+D to send the End-of-File event to the terminal.
