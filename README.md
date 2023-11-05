# MakerRoboticsAStar
 A* pathfinding for Maker Robotics Competition

## The Map

![Map](D:\DOCUMENT\GitHub\MakerRoboticsAStar\map.png)

## A* modifications
We added a `r(n)` which is a turning factor
![Turn](D:\DOCUMENT\GitHub\MakerRoboticsAStar\function.png)

Which adds a cost `k` (this case is `10`), If the direction changes.
![](D:\DOCUMENT\GitHub\MakerRoboticsAStar\turn.png)