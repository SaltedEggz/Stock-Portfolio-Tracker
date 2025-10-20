# Learning Journey - Entry 2

## What I Worked On
- Implemented a menu system to display, add, and remove stocks in my portfolio tracker
- Created separate functions: displayPortfolio() and addStock()
- Learned to use ofstream with ios::app to append new stocks to a file
- Practiced local vs. global variables, realizing total should be local to avoid incorrect accumulation
- Debugged file reading when multiple stocks appeared on the same line

## Challenges
- Understanding why my portfolio total was doubling after multiple displays (b/c of gloabal variables)
- Making sure each stock is written to a new line in the file
- Avoiding overwriting variables between functions
- Structuring the menu with do-while, switch, and case statements

## Key Takeaways
- Functions with local variables are safer and easier to maintain
- ios::app ensures data is appended rather than overwritten in a file
- do-while loops allow the menu to **repeat until the user chooses to exit**, ensuring smooth program flow
- switch statements make it easier to **select actions based on user input**, keeping the menu logic clean and readable
- Menu-driven programs allow for easier user interaction and future feature expansion


