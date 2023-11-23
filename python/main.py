
class Node:
    """A node class for A* Pathfinding"""

    def __init__(self, parent=None, position=None):
        self.parent = parent
        self.position = position

        self.g = 0
        self.h = 0
        self.t = 0
        self.f = 0

    def __eq__(self, other):
        return self.position == other.position

    def __sub__(self, other):
        return self.position[0] - other.position[0], self.position[1] - other.position[1]


def astar(maze, start, end):
    """Returns a list of tuples as a path from the given start to the given end in the given maze"""

    # Create start and end node
    start_node = Node(None, start)
    start_node.g = start_node.h = start_node.f = start_node.t = 0
    end_node = Node(None, end)
    end_node.g = end_node.h = end_node.f = start_node.t = 0

    # Initialize both open and closed list
    open_list = []
    closed_list = []

    # Add the start node
    open_list.append(start_node)

    # Loop until you find the end
    while len(open_list) > 0:

        # Get the current node
        current_node = open_list[0]
        current_index = 0
        for index, item in enumerate(open_list):
            if item.f < current_node.f:
                current_node = item
                current_index = index

        # Pop current off open list, add to closed list
        open_list.pop(current_index)
        closed_list.append(current_node)

        # Found the goal
        if current_node == end_node:
            path = []
            current = current_node
            while current is not None:
                path.append(current.position)
                current = current.parent
            return path[::-1] # Return reversed path

        # Generate children
        children = []
        # (0, -1),
        for new_position in [(0, 1), (-1, 0), (1, 0), (0, -1)]: # Adjacent squares

            # Get node position
            node_position = (current_node.position[0] + new_position[0], current_node.position[1] + new_position[1])

            # Make sure within range
            if node_position[0] > (len(maze) - 1) or node_position[0] < 0 or node_position[1] > (len(maze[len(maze)-1]) -1) or node_position[1] < 0:
                continue

            # Make sure walkable terrain
            if maze[node_position[0]][node_position[1]] != 0:
                continue

            # Create new node
            new_node = Node(current_node, node_position)

            # Append
            children.append(new_node)

        # Loop through children
        for child in children:

            # Child is on the closed list
            for closed_child in closed_list:
                if child == closed_child:
                    continue

            # Create the f, g, and h values
            child.g = current_node.g + 1
            child.h = abs(child.position[0] - end_node.position[0]) + abs(child.position[1] - end_node.position[1])
            try:
                child.t = ((current_node - current_node.parent) != (child - current_node)) * 8
                # print(child.t, (current_node - current_node.parent), (child - current_node))
            except AttributeError:
                child.t = 0
            child.f = child.g + child.h + child.t

            # Child is already in the open list
            for open_node in open_list:
                if child == open_node and child.g > open_node.g:
                    continue

            # Add the child to the open list
            open_list.append(child)


def get_path_str(path_list):
    directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    direction_string = ''
    direction = list(map(lambda x: x[1] - x[0], zip(path_list[0], path_list[1])))
    direction_index = directions.index(direction)
    direction_string += str(direction_index)
    delta_path = [list(map(lambda x: x[1] - x[0], zip(path_list[i], path_list[i+1]))) for i in range(len(path_list)-1)]
    for i in delta_path:
        if i == direction:
            direction_string += 'f'
        elif i == directions[direction_index-1]:
            direction_string += 'lf'
            direction_index = direction_index - 1 if direction_index != 0 else 3
            direction = directions[direction_index]
        elif i == directions[(direction_index+1) % 4]:
            direction_string += 'rf'
            direction_index = (direction_index + 1) % 4
            direction = directions[direction_index]
        else:
            direction_string += 'f'
            direction_index = (direction_index + 2) % 4
            direction = directions[direction_index]
    return direction_string



def main():
    maze = [
        [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0],
        [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1],
        [1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1],
        [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1],
        [1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1],
        [1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1],
        [1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1],
        [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1],
        [1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    ]

    start_points = [
        (3, 1), (5, 1), (6, 2), (7, 3), (8, 4), (7, 5),
        (6, 6), (5, 7), (4, 8), (3, 9), (2, 10), (1, 11), (0, 12)
    ]
    end_points = [
        (5, 1), (6, 2), (7, 3), (8, 4), (7, 5),
        (6, 6), (5, 7), (4, 8), (3, 9), (2, 10), (1, 11), (0, 12), (4, 1)
    ]
    ix = 144
    points = []
    paths = []
    for start in start_points:
        for end in end_points:
            if start == end: continue
            path = astar(maze, start, end)
            points.append([start, end])
            paths.append(get_path_str(path))
    print(
        str(points).replace('(', '{')
              .replace('[', '{')
              .replace(')', '}')
              .replace(']', '}')
    )
    print(
        str(paths).replace('[', '{')
             .replace(']', '}')
             .replace("'", '"')
    )
    print(len(paths))


if __name__ == '__main__':
    main()
