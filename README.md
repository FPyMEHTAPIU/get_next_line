# get_next_line

## Mandatory part

In this project, I created a function that allows the user to read from a file one line at a time. This function reads characters from the given file descriptor until it reaches a newline character '\n' or the end of the file (terminating null character '\0'). After that, it allocates memory, copies the line, and returns a string containing that line. It is possible to use this function in a loop to retrieve as many lines as the file contains and as needed. **Attention:** You must free each string returned by the get_next_line function after it has been used.

You can also define the size of the buffer **BUFFER_SIZE** by using the command -D BUFFER_SIZE=42 (you can replace 42 with any number). **Be careful with the buffer size** because using a very large buffer (e.g., 50000000) can slow down your program.

## Bonus part
This is the same program except the bonus part **can work with different file descriptors at the same time.**

### Grade

![Grade](https://github.com/user-attachments/assets/b35be22d-cafa-4471-9079-d87eb5dff335)
