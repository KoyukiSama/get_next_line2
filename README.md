*This project has been created as part of the 42 curriculum by kaclaes.*

## Description

The get next line function is a custom C function build as part of the 42 curriculum.  
The goal of this project was to create function, that takes a file, reads it, and returns a line when it is called, basically a file reader. It reads line by line until it reached EOF (end of file.)
The lines are dynamically allocated.
It can also be used to read input from stdin.

## Instructions

### Usage

prototype:
	
	char	*get_next_line(int fd);

The function accepts and fd, which you can open with open() or fopen(), depending on your preference.
It returns the next found new line or line at end of file. NULL if none is found or on error.

example:

	// open fd
	int fd = open(dir/file.txt);

	// get first line
	char *line = get_next_line(fd);
	if (!line)
		return (1);

	// initiate variables
	int lines_in_file = 1;
	int	letters_in_file = 0;

	// count chars and lines
	while (line != NULL)
	{
		letters_in_file += strlen(line);
		free(line);						// <-- the lines must be freed
		line = get_next_line(fd);
		lines_in_file++;
	}
	
	// print lines
	printf(line_count: %i, lines_in_file);
	printf(char_count: %i, letters_in_file);

	return (0);

## Resources

- https://man7.org/linux/man-pages/
- https://www.gnu.org/software/libc/manual/
- https://en.cppreference.com/
- 42 intra documentation and subject PDFs

### AI Usage

AI was used as a learning assistant to:
- clarify edge cases in C standard library functions
- help debug pointer and memory-related issues
- review and verify edge-case handling in functions
- understand correct behavior of edge cases defined in man pages

No AI-generated code was copied; all implementations were written and tested manually.

## Technical Choices

- Used 1024 for defining fd max, this should be able to open 1024 files at once. and that is the max my function will handle.
- restricted to only using malloced regions for the buffer, I would normally choose a buffer on the stack, but for this evaluation the evaluater could try and get a stack overflow and fail me from there. So it wouldn't be a great choice for that reason.