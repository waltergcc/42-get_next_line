# get_next_line
This project is an implementation of a function named get_next_line, which reads and returns a line from a file descriptor each time it is called, until it reaches the end of the file.

## How it Work

The get_next_line function reads one line from the file descriptor fd each time it is called.
The function returns a pointer to a string containing the line that was read, without the newline character `\n`.
The function returns `NULL` when the end of file is reached or an error occurs.
The function uses a `static variable` to store the remaining characters from the previous call, if any.

## Buffer size
The size of the buffer used to read from the file descriptor. If not specified, the default value is 42.
To set your own buffer size in the files, use the flag `-D BUFFER_SIZE=n` at time to compile de functons.

## Bonus

The project includes a bonus version of get_next_line, which can read from multiple file descriptors at the same time.

## Grade: 125 / 100

## Used Tests
- Francinette: https://github.com/xicodomingues/francinette
- gnlTester: https://github.com/Tripouille/gnlTester