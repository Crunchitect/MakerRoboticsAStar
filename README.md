# MakerRoboticsAStar
 A* pathfinding for Maker Robotics Competition

## The Map

![Map](imgs/map.png)

## A* modifications
We added a `r(n)` which is a turning factor
![Func](imgs/function.png)

Which adds a cost `k` (this case is `10`), If the direction changes.
![Turn](imgs/turn.png)

And change `h(n)` from Euclidean Distance to Manhattan Distance
![Dist](https://uploads-cdn.omnicalculator.com/images/manhattan_distance.png?width=748&enlarge=0&format=webp)

## Notation
![Write](imgs/temp.png)