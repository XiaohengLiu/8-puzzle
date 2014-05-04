The code has been tested in VS2012, under win7 or win8 systems.

There are two implementations in my code.

first is IDA code: We run the IDA Algorithm on the project.
second is BFS&A* code: We compare the BFS and A* Algorithm in the project.


1.For IDA.cpp:
  a.you can run it directly, there is only one .cpp file here.
  b.after you run the .cpp, you need to input the start configuration for the Eight Puzzle.

Sample input(start configuration):
	3 6 5
	7 0 2
	1 4 8
If you want to change the target configuration, you can edit in the source code where 
the target board has been defined.





2.For The Project file BFS_A*:
  a. There are 4 .h files and 4 .cpp files. You should put them into one project. 
  b. Copy the "eight.txt", "Eight_result.txt" into the project file.
  c. We have already give a sample start and target configuration in "eight.txt", which the shortest path are 8 steps.
  d. Run the project directly after finish all the steps above.
Note: 
  If you want to change the start and target configuration yourself, open the "eight.txt". The first 8 numbers is the start configuration, and the last 8 numbers is target configuration. The single number in between is the postion of the "0" of the start configuration.
  In order to simplify the operation, it is better to only change the target configuration(that is only change the last 8 numbers). Thus, you don't need to consider the postion of "0" of start configuration.
  