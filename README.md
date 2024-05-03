# Calculator Application

This is a simple calculator application built using Qt and the muParser library.

## Features

- Basic arithmetic operations: addition, subtraction, multiplication, and division.
- Supports parentheses to alter the precedence of operations.
- Clear function to reset the calculator.

## Code Structure

The application is structured into a single `Calculator` class that inherits from `QWidget`. The `Calculator` class handles the creation of the user interface and the calculation logic.

### User Interface

The user interface is created in the `Calculator` constructor. It consists of a `QLabel` that displays the current input or result, and a grid of `QPushButton` objects for the digits, arithmetic operations, parentheses, decimal point, equals sign, and clear function.

### Calculation Logic

The calculation logic is handled by the `calculateResult` method. This method uses the muParser library to parse and evaluate the current input string.

### Button Click Handling

The `buttonClicked` method is connected to the `clicked` signal of each button. When a button is clicked, this method updates the display based on the button's text.

## Building and Running

To build and run the application, you need to have Qt and the muParser library installed on your system. You can then use the Qt Creator IDE to open the `.pro` file and build the application.

Please note that you need to adjust the include and library paths in the `.pro` file to match the locations of the Qt and muParser installations on your system.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
