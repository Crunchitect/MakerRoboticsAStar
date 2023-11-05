# MakerRoboticsAStar
 A* pathfinding for Maker Robotics Competition

## The Map

![Map](map.png)

## A* modifications
We added a `r(n)` which is a turning factor
![Func](function.png)

Which adds a cost `k` (this case is `10`), If the direction changes.
![](turn.png)