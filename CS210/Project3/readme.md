# Corner Grocer Item-Tracking Program

## Introduction

This project is designed to handle document-related operations, including reading item purchase records, processing them, and generating output and documents with sorted product data.

## Features

- Read and process input documents containing item purchase records.
- Generate output documents with sorted product data.
- Validate user input and file paths.
- Provide a user-friendly menu for interacting with the program.

## UML Diagram

![UML Diagram](Lawrence_Francis_Project3_UML.png)

## Classes

### `App`

- Manages the overall application flow and user interactions.

### `Document`

- The base class for handling document-related operations.
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

## CS210 Week 8 Journal Response

### Question 1
See the Introduction section of this readme.

### Question 2
This was the first project where I created a UML diagram before writing any code. It helped me blueprint the classes and visualize how the application's flow would develop. I felt my organization weakened toward the end, as small adjustments required refactoring other classes, but my initial start was strong. Moving forward, I will continue using the UML-first approach.

### Question 3
I think the `App` class could be debloated by creating a `User` class to store query results as the app progresses. Currently, the `App` class handles too much responsibility. I’d also consider introducing **smart pointers** to ensure automatic memory management, reducing the risk of memory leaks.  
(Reference: [Smart Pointers in C++](https://www.geeksforgeeks.org/smart-pointers-cpp/))

### Question 4
I initially struggled to detect the operating system on which the program was running. This was necessary to implement a valid path-checking function. After finding the resource below, I was able to create the function I needed:  
Koley, A. (2024, April 15). *How to detect operating system using C++*. CodersPacket.  
(Reference: [CodersPacket](https://coderspacket.com/posts/how-to-detect-operating-system-using-c))

Later, I discovered that I could have used `std::filesystem::path::make_preferred`.  
(Reference: [cppreference](https://en.cppreference.com/w/cpp/filesystem/path/make_preferred))

### Question 5
I hadn’t utilized the `// FIXME` comment style before, but I found it extremely useful for marking areas to revisit later. Along with my UML-first approach, `FIXME` comments will be a tool I continue using in future projects.

### Question 6
By adhering to standard object-oriented programming (OOP) practices, I’ve left the project in good shape. The functionality is clearly defined within their respective classes, and anyone reading the `main()` function can easily understand the application flow. Additionally, I put significant effort into writing documentation and creating the UML diagram, making the project easier for others to understand if they collaborate with me in the future.