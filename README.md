# Chess Engine (C++)

### Description
A modular chess application developed in C++ using Object-Oriented Programming. The project is split into a dedicated UI and a logical backend engine to handle piece movements and game rules.

### Core Features
Move Validation: Implements strict logic for all piece paths and capture rules.  

Game State Logic: Real-time detection of check, checkmate, and stalemate.  

Architecture: Decoupled design separating the graphical interface from the core engine.  


### How to Run
To ensure the game initializes correctly, you must launch the components in the following order:  

Start the UI: Run the chessGraphics.exe file to initialize the game window.  

Start the Backend: Run the engine by compiling and executing Source.cpp.  

Note: The UI must be active before the engine starts to allow the backend to hook into the graphical display successfully.  


### Technical SetupCompiler:
g++ (or any standard C++ compiler)  

Execution Order: UI (.exe) $\rightarrow$ Engine (Source.cpp)  

