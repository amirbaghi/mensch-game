# mensch-game
Main structure and logic for Mensch (no render implementation), written in C++. A project done to implement and use some game development design patterns in action. 

Also includes a "profiling execution mode" where the game is run 120 times, and some game dynamic metrics are measured and written to a text file and plotted out (in cumulative and interval manners). 

The game dynamic metrics measured for each player are: Wait Duration, Gained Score, Lost Score, Number of Starts, Covered Distance.

Cumulative plot for the covered distance of each player, in 120 runs, time is in seconds (Hitting pieces allowed):
![alt text](https://imgur.com/7ndYLe2.png)

Cumulative plot for the covered distance of each player, in 120 runs, time is in seconds (Hitting pieces not allowed):
![alt text](https://imgur.com/Nz0pdH4.png)

Interval plot for the covered distance of each player, in 120 runs, time is in seconds (Hitting pieces allowed, 60 second intervals):
![alt text](https://imgur.com/W2f7xKK.png)
