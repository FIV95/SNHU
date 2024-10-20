# Corner Grocer Item-Tracking Program
## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [UML Diagram](#uml-diagram)
4. [Classes](#classes)
   - [App](#app)
   - [Document](#document)
   - [InputDocument](#inputdocument)
   - [OutputDocument](#outputdocument)
   - [Product](#product)
   - [Validation](#validation)
   - [DocumentProcessor](#documentprocessor)
5. [Usage](#usage)
   - [Setting Up](#setting-up)
   - [Running the Program](#running-the-program)
   - [Menu Options](#menu-options)
6. [Code Structure](#code-structure)
7. [Compilation and Execution](#compilation-and-execution)
8. [Testing](#testing)

## Introduction

This project is designed to handle document-related operations, including reading item purchase records, processing them, and generating output documents with sorted product data.

## Features

- Read and process input documents containing item purchase records.
- Generate output documents with sorted product data.
- Validate user input and file paths.
- Provide a user-friendly menu for interacting with the program.

## UML Diagram

![UML Diagram](path/to/uml-diagram.png)

## Classes

### `App`

- Manages the overall application flow and user interactions.
- Attributes:
  - `_running`: Indicates whether the application is running.
  - `_hasDocument`: Indicates whether a document is loaded.
  - `_currentDocument`: Pointer to the currently loaded document.
  - `_input`: Stores user input.
  - `_option1Results`: Stores results for option 1.
- Methods:
  - `printMenu()`: Displays the main menu.
  - `setInput(const char &input)`: Sets the user input.
  - `promptForQuery()`: Prompts the user for a query.
  - `promptForInput()`: Prompts the user for input.
  - `setCurrentDocument(InputDocument* inputDocument)`: Sets the current document.
  - `setHasDocument(bool hasDocument)`: Sets the document loaded status.
  - `setRunning(bool running)`: Sets the running status.
  - `setQuery(const std::string &query)`: Sets the query.
  - `setQueryComplete(bool queryComplete)`: Sets the query completion status.
  - `promptForQueryComplete()`: Prompts the user for query completion.
  - `setOption1Results(int result)`: Sets the results for option 1.
  - `printOption1Results(std::string query)`: Prints the results for option 1.
  - `printOption2Results(std::vector<Product> products)`: Prints the results for option 2.
  - `printOption3Results(std::vector<Product> products)`: Prints the results for option 3.

### `Document`

- The base class for handling document-related operations. It provides common attributes such as:
  - `_path`: The file path of the document.
  - `_title`: The document's title.
  - `_products`: A collection of products in the document (represented by `Product` objects).
- Defines methods to manage document content, such as retrieving and setting both a vector of products and a hashtable (mapping product names to their quantities).

### `InputDocument` (inherits from `Document`)

- Represents the input document, responsible for reading item purchase records.
- Contains both a vector and a hashtable to store `Product` data.
- Inherits the document manipulation methods from `Document` and implements them specifically for input operations.

### `OutputDocument` (inherits from `Document`)

- Represents the output document, used for saving item frequencies or sorted product data.
- Provides additional functionality for sorting products by name or quantity frequency before saving.
- Inherits all the document handling features from the base `Document` class.

### `Product`

- Represents an item purchased at the store.
- Attributes:
  - `_name`: The name of the product.
  - `_qty`: The quantity purchased.
- Provides getter and setter methods for managing product data.

### `Validation`

- A utility class that includes **static methods** for validating user input. These methods include:
  - `intIsInMenuRange()`: Ensures that integer input is within the valid menu range.
  - `isValidChar()`, `isValidInt()`: Validates character and integer inputs, respectively.
  - `isValidPath()`, `isValidWindowsPath()`, and `isValidUnixPath()`: Validate the file paths based on the operating system.
  - `osCheck()`: Checks the operating system type to adjust path validation rules accordingly.

### `DocumentProcessor`

- Another utility class with **static methods** used for processing documents. These methods include:
  - `calculateOption1()`: Processes a query by calculating the frequency of a specific item from an `InputDocument`.
  - `readDocument()`: Reads the content of an `InputDocument`.
  - `setOption2()` and `setOption3()`: Generate specific sets of `Product` data for different program options.


1. **Set input file path**: Allow the user to specify the file path for the input file.
2. **Search for an item**: Prompt a user to input the item, or word, they wish to look for. Return a numeric value for the frequency of the specific word.
3. **Print frequency of all items**: Print the list with numbers that represent the frequency of all items purchased.
4. **Print histogram of item frequencies**: Print the same frequency information for all the items in the form of a histogram.
5. **Exit the program**: Exit the application.

