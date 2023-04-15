# Word Search Solver

This project is an implementation of a word search solver in C++. The program takes a 2D array of characters as input and searches for all the possible words in the 2D array. 

## Usage

To use this program, you need to provide a text file containing the 2D array of characters to be searched. The file should have the following format:

- The first line of the file should contain the number of rows and columns in the array, separated by a space.
- The next lines should contain the characters in the array, row by row.


To run the program, simply compile the source code and run the executable, passing the filename of the array as an argument:


The program will then output a list of all the words found in the array.

## Implementation

The program uses a recursive approach to search for words in the array. For each position in the array, it checks all possible directions for each word in a given dictionary of words. If a match is found, the program continues searching recursively in that direction until the entire word is found or it is determined that the word cannot be found.

## Future Improvements

- Improve performance by using a more efficient data structure to store the dictionary of words.
- Add functionality to handle arrays with irregular dimensions.
- Implement a graphical user interface to allow users to input arrays and view results.

Feel free to contribute to this project by submitting issues or pull requests on the GitHub repository.
