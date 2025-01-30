# Question link: https://leetcode.com/problems/course-schedule/

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        # edge case
        if not prerequisites:
            return True
        
        visited = set()
        processed = set()
        courseGraph = defaultdict(list)

        # build out our adjency lists
        for course, prereq in prerequisites:
            courseGraph[course].append(prereq)
        
        def dfs(course):

            # Check if the course we are on already has been visited
            if course in visited:
                return False
            
            # Check if course we are on has already been processed
            # This is to skip redundant work since we know we can fulfill it's prereqs already
            if course in processed:
                return True

            visited.add(course)
            for prereq in courseGraph[course]:
                if not dfs(prereq):
                    return False

            visited.remove(course)
            processed.add(course)

            return True
        
        for course in range(numCourses):
            if not dfs(course):
                return False
        
        return True

        # 0, 1, 2
