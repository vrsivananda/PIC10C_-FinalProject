# PIC10C_-FinalProject

This is the final project for PIC10C. It is a random dots stimuli generator.

In psychology, these generators are used in psychophysics experiments to test motion tracking of the eyes.
Some dots will move in a lateral direction(left or right, all together in one direction), and others will move randomly.
These moving dots are shown very briefly on the screen.
The user will then test if they can spot whether it goes left or right.

In this project, the user will first select the parameters of the trial. 
These include the size of the screen, the number of dots that will move in the same direction,
the number of fdots that will move in different directions, the speed of the dots, the size
of the dots, etc.

Once the user clicks "start trial", then a new window will pop up that displays the generated
dots and the user will have to see if they can spot the direction of the dots.

------------------

This project conforms to RAII because all the heap memory is handed to a Qt object. Qt objects conform to RAII as they treat their acquired memory as if they were initialized with it. They will delete the memory once the pointer to them goes out of scope. Thus a call to new does not necessitate a call to delete.

Thus smart pointers are not necessary as raw pointers handed to Qt Objects will handle the memory like smart pointers do.

2 clases are used: MainWindow and DisplayWindow

MainWindow is where the user sets the type of settings that they want, and DisplayWindow is where the dots are displayed.
Since they are friends of each other, then can access each other's private variables.

-----------------

Open the pro file, run the application, set your parameters, click "Start trials", and have fun!
