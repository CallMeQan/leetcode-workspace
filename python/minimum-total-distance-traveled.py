from typing import List


class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()

        factories_pos = []
        for fac in factory:
            for i in range(fac[1]):
                factories_pos.append(fac[0])
        robot_count = len(robot)
        factory_count = len(factories_pos)
        next_dist = [0 for _ in range(factory_count + 1)]
        current = [0 for _ in range(factory_count + 1)]

        # Fill DP table using two rows for optimization
        for i in range(robot_count - 1, -1, -1):
            # No factories left case
            if i != robot_count - 1:
                next_dist[factory_count] = 1e12

            # Initialize current row
            current[factory_count] = 1e12

            for j in range(factory_count - 1, -1, -1):
                # Assign current robot to current factory
                assign = (
                    abs(robot[i] - factories_pos[j]) + next_dist[j + 1]
                )

                # Skip current factory for this robot
                skip = current[j + 1]
                # Take the minimum option
                current[j] = min(assign, skip)

            # Move to next robot
            next_dist = current[:]

        # Return minimum distance starting from the first robot
        return current[0]
    
if __name__ == '__main__':
    robot = [0,4,6]
    factory = [[2,2],[6,2]]
    solution = Solution()
    print(solution.minimumTotalDistance(robot, factory)) #4

    robot = [1,-1]
    factory = [[-2,1],[2,1]]
    print(solution.minimumTotalDistance(robot, factory)) #2