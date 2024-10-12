# Corner Grocer Item-Tracking Program

This project is an item-tracking program for the Corner Grocer. It analyzes text records of items purchased throughout the day to help the store rearrange their produce section based on item frequency.

## Features

- **Set Input File Path**: Allows the user to specify the file path for the input file.
- **Search for an Item**: Prompts the user to input the item or word they wish to look for and returns the frequency of the specific word.
- **Print Frequency of All Items**: Prints a list with numbers representing the frequency of all items purchased.
- **Print Histogram of Item Frequencies**: Prints the frequency information for all items in the form of a histogram.
- **Backup Frequency Results**: Backs up the frequency results in an output `.dat` file.
- **Exit the Program**: Allows the user to exit the program.

## Classes

### App

Manages the application flow, including printing menus, handling user input, and managing documents.

### Document

Base class for different types of documents, including common attributes and methods for managing document content.

### InputDocument

Inherits from `Document` and represents an input document.

### OutputDocument

Inherits from `Document` and represents an output document.

### Product

Represents a product with a name and quantity.

### Validation

Includes methods for validating user input and checking the operating system type.
