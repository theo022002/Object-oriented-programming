# Object-oriented-programming Overview:  
## 1. Library Simulation: 
In the library simulation, the program aims to manage the internal 
structure and operations of a library, which consists of:  
•	A base (structural only),  
•	A cabinet (containing two shelves),  
•	Three external shelves.    
  
Each shelf can hold a certain number of books, denoted by the variable NMax, 
which is the same for all shelves. A book is represented by a simple data structure containing:  
•	Title (string),  
•	Author (string),  
•	ISBN (an integer).    

The library allows:  
•	Placing a book on a specific shelf or cabinet shelf, increasing the total number of books.    
•	Removing a book from a shelf, decreasing the total number of books.   
•	Printing the state of the library, which includes the books on all the shelves.  
  
The simulation must output specific messages during the creation and destruction of the library, 
shelves, and cabinet, as well as when books are placed or removed. The program should handle the following cases:  
•	Preventing placing books on full shelves and removing books from empty shelves, returning false and printing error messages.  
•	If an action is successful, return true and print the appropriate message.  
  
The program should include a main function that:  
•	Initializes a library,  
•	Creates a given number of books (L),  
•	Randomly places (K1) and removes (K2) books,  
•	Prints the library's state.  
  
The parameters NMax, L, K1, and K2 are read from the command line.  

## 2. Bank Service Simulation:  
This simulation models a bank serving customers through its cashiers. The bank has:    
•	A priority system where customers receive a number (last_customer) when they enter,   
•	A current service indicator showing the number of the customer being served (curr_serving).  
  
The bank contains five cashiers, each having:  
•	An "open/closed" status,  
•	A "serving/free" status,  
•	A counter for how many customers they’ve served.    
  
The bank supports the following operations:  
•	Entering a customer: Increases the customer count, possibly opens more cashiers if needed, and prints relevant messages.   
•	Serving a customer: Selects an available cashier in a cyclic manner and serves the next customer.  
•	Exiting a customer: Updates the current serving number and checks if any cashier should close to avoid overuse.  
  
Additionally, the simulation must handle:  
•	Opening and closing cashiers based on the number of waiting customers,  
•	Printing the current number of customers waiting and open cashiers.    
  
The main function should:
•	Create a bank,  
•	Simulate customer arrivals and services,  
•	Handle multiple rounds (M) of customer entries and services,  
•	Ensure all customers are served.    
  
The parameters K, M, N, and L are passed from the command line.
  
## 3. Creatute Simulation:  
The scenario involves a simulation of a community of creatures, which can either be good or bad. 
Each creature lives in a specific position within the community and exhibits certain behaviors.  
  
### Key Features of the Creatures:  
1.	Common Attributes:  
  o	Each creature has a name.  
  o	Each creature has an expected lifespan which starts at a value L (common for all creatures, where L > 0).  
  o	When the creature’s lifespan reaches zero, it becomes a zombie. Any further actions on zombies have no effect.  
  o	Creatures can be cloned. Cloning replaces one creature with a copy of another.  
  o	Creatures can either be blessed or beaten:  
 &emsp;   •	Blessing increases a creature's lifespan by 1 (if it is not a zombie).  
 &emsp;   •	Beating decreases a creature's lifespan by 1 (if it is not a zombie).    
2.	Good Creatures:  
&emsp;  o	A good creature can clone itself into the next position in the community if blessed and if its lifespan exceeds a given threshold (good thrsh). 
3.	Bad Creatures:  
&emsp;  o	A bad creature, when blessed and healthy (above a threshold bad thrsh), can clone itself into consecutive positions that are occupied by zombies.
  
### Simulation Overview:  
•	At each step in the simulation, a random creature is selected, and either a bless or beat action is applied to it.  
•	This process is repeated M times.  
•	After these operations, the simulation will check the state of the community:  
&emsp;  o	If the community consists only of good creatures, it prints "Good Dominates in the World!".  
&emsp;  o	If all creatures are in the zombie state, it prints "This is a dead society".  
&emsp;  o	Otherwise, it prints "Try again to improve the world".  

### Class Structure:  
1.	Creature Class:  
&emsp;  o	Stores the name and lifespan.  
&emsp;  o	Handles common behaviors like checking if a creature is a zombie (isZombie()), blessing or beating the creature, and cloning it.  
&emsp;  o	Defines virtual functions for handling specific behavior of good or bad creatures.  
2.	GoodCreature and BadCreature Classes:  
&emsp;  o	These classes inherit from Creature and specialize the behavior for good and bad creatures.  
&emsp;  o	GoodCreature clones itself to the next position if blessed and healthy.  
&emsp;  o	BadCreature clones itself to all consecutive zombie positions.  
3.	Society Class:  
&emsp;  o	Manages the community of creatures.  
&emsp;  o	Tracks the positions of creatures and their statuses (whether they are good, bad, or zombies).  
&emsp;  o	Provides functions to bless, beat, or clone creatures in the community, and checks the overall state of the community.

### Execution Flow:  
•	The program begins by creating a community of N creatures.  
•	Random actions (bless or beat) are applied M times.  
•	Finally, it checks the status of the community and prints one of the three outcomes.  

### Additional Considerations:  
•	Names of creatures are stored in two arrays (one for good and one for bad creatures), and they become unique by appending their position index.  
•	N, M, L, good thrsh, and bad thrsh are input parameters given via the command line.  
•	Output messages should be printed from key functions like bless, beat, clone, constructors, and destructors for debugging and transparency.  

## 4. Artifact Hierarchy Implementation  
In this project, we have implemented a hierarchy of artifacts in Java. Each artifact has a unique set of attributes 
and behavior, and the structure follows an inheritance model where different types of artifacts exhibit 
specialized properties. The main goal is to manage various types of artifacts, including masterpieces,
paintings, and sculptures, with specific features and operations related to each type.
### Artifact Hierarchy
  
##### 1.	Artifact Class  :
o	Attributes:   
&emsp;  •	index: A unique identifier for each artifact.    
&emsp;  •	creator: The name of the creator of the artifact.    
&emsp;  •	year: The year the artifact was created.    
o	Methods:  
&emsp;  •	getInfo(): Prints the creator and year of the artifact.  
&emsp;  •	getIndex(): Prints the unique identifier of the artifact.  
o	These attributes are set when the artifact is created and remain constant throughout its lifetime.  

##### 2.	Masterpiece Class (inherits from Artifact):  
o	Additional Attributes:  
&emsp;  •	movement: The artistic movement the masterpiece belongs to. It can be one of impressionism, expressionism, or naturalism.  
&emsp;  •	condition: The condition of the masterpiece, which can be bad, good, or excellent. This attribute can be modified after creation.  
o	Methods:  
&emsp;  •	getInfo(): Extends the behavior of the base class getInfo() by printing the movement and condition of the masterpiece, along with the basic artifact information.  

##### 3.	Painting Class (inherits from Masterpiece):    
o	Additional Attributes:    
&emsp;  •	length: The length of the painting.  
&emsp;  •	width: The width of the painting.  
&emsp;  •	technique: The painting technique, which can be oil, aquarelle, or tempera.  

o	Methods:    
&emsp;  •	getInfo(): Extends the getInfo() method from Masterpiece to include the dimensions, technique, and the surface area of the painting.  
&emsp;  •	evaluate(String movement, String condition): Determines if the painting is acceptable based on the provided movement and condition.   
If no condition is provided, it defaults to good. Excellent condition is acceptable when the input condition is good.  

##### 4.	Sculpture Class (inherits from Masterpiece):  
o	Additional Attributes:  
&emsp;  •	volume: The volume of the sculpture.  
&emsp;  •	material: The material of the sculpture, which can be iron, stone, or wood.  
o	Methods:   
&emsp;  •	getInfo(): Extends the getInfo() method from Masterpiece to include the volume and material.  
&emsp;  •	evaluate(String movement, String condition): Similar to Painting, this method determines if the sculpture is acceptable.  
  If no condition is provided, it defaults to excellent. If good is provided, excellent condition is not accepted.  
  
### Auction Function  
The auction function processes an array of artifacts, along with given movement and condition criteria. For each artifact, the function performs the following tasks:  
1.	Print the index of the artifact using the getIndex() method.  
2.	Print the artifact’s full information using the getInfo() method, which varies based on the artifact type.  
3.	Evaluate the artifact’s acceptability using its respective evaluate() method, based on the provided movement and condition.  
   
### Main Function  
The main function drives the program by:  
•	Creating N random artifacts from the classes you implemented (either Painting or Sculpture).  
•	Assigning random values to the attributes like the creator, year, movement, dimensions (for paintings), or volume and material (for sculptures).  
•	Calling the auction function with the set of created artifacts and the movement and condition criteria provided via command-line arguments.  

### Additional Requirements  
•	Each constructor of the implemented classes should print a message in the format: "Creating an instance of <class>...".  
•	The names of the creators should follow the format CreatorI, where I is an integer identifier for the creator.  
•	The program should be able to handle different values for the number of artifacts (N), the movement, and the condition, which will be passed as command-line arguments.  
  
