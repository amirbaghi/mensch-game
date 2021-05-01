# mensch-game
Main structure and logic for Mensch (no render implementation), written in C++. A project done to implement and use some game development design patterns in action. 

Also includes a "profiling execution mode" where the game is run 120 times, and some game dynamic metrics are measured and written to a text file and plotted out (in cumulative and interval manners). 

The game dynamic metrics measured for each player are: Wait Duration, Gained Score, Lost Score, Number of Starts, Covered Distance.

Cumulative plot for the covered distance of each player, in 120 runs, time is in seconds (Hitting pieces allowed):
![alt text](blob:https://imgur.com/e193daeb-3280-4477-90b7-07e33e458068)

Cumulative plot for the covered distance of each player, in 120 runs, time is in seconds (Hitting pieces not allowed):
![alt text](blob:https://imgur.com/66f84ba4-0d40-4775-964a-7e5410a93139)

Interval plot for the covered distance of each player, in 120 runs, time is in seconds (Hitting pieces allowed, 60 second intervals):
![alt text](blob:https://imgur.com/1f30ee9a-db36-4b8e-87d8-a7f0e69157bf)
