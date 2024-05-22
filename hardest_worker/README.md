# README

## Hardest Worker Calculation

### Problem Description

The goal is to determine the worker who has worked the longest continuous time based on a series of logs. Each log entry records the worker's ID and the cumulative time they have worked up to that point. We need to identify the worker who has had the longest single session of continuous work.

### Solution

This solution processes the log entries and calculates the time each worker spent on their tasks. It then determines the worker with the longest continuous work session. If there are multiple workers with the same longest session duration, it returns the worker with the smallest ID.

### Code Explanation

Here is the C++ code to solve the problem:

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int hardestWorker(int n, std::vector<std::vector<int>>& logs) {
        // Initialize longest worker as the first entry ID and the longest time worked as the first entry time.
        int longest_worker = logs[0][0];
        int longest_time = logs[0][1];

        // Loop through the logs to calculate time differences and determine the hardest worker.
        for (int i = 1; i < logs.size(); i++) {
            int now = logs[i][1] - logs[i-1][1];

            if (now > longest_time) {
                longest_worker = logs[i][0];
                longest_time = now;
            } else if (now == longest_time) {
                longest_worker = std::min(logs[i][0], longest_worker);
                longest_time = now;
            }
        }

        // Return the ID of the hardest worker.
        return longest_worker;
    }
};
```

### Detailed Explanation

1. **Initialization**:
   - `longest_worker` is initialized to the ID of the first worker (`logs[0][0]`).
   - `longest_time` is initialized to the duration of the first worker's log (`logs[0][1]`).

2. **Processing Logs**:
   - The loop starts from the second log entry (index 1).
   - For each log entry, calculate the duration (`now`) by subtracting the previous log's cumulative time from the current log's cumulative time.
   - Compare the calculated duration (`now`) with `longest_time`:
     - If `now` is greater than `longest_time`, update `longest_worker` and `longest_time`.
     - If `now` is equal to `longest_time`, update `longest_worker` to the smaller ID between the current log's worker ID and the current `longest_worker`.

3. **Return**:
   - The function returns the ID of the worker who has the longest single continuous work session.

### Example Usage

To use this solution, you can create an instance of the `Solution` class and call the `hardestWorker` method with the number of workers and the logs:

```cpp
#include <iostream>
#include <vector>

int main() {
    Solution solution;
    std::vector<std::vector<int>> logs = {
        {1, 3}, {2, 5}, {3, 9}, {4, 10}
    };
    int n = 4;
    int hardest_worker = solution.hardestWorker(n, logs);
    std::cout << "The hardest worker ID: " << hardest_worker << std::endl;
    return 0;
}
```

### Constraints

- `1 <= n <= 10^3`
- `1 <= logs.length <= 10^4`
- `logs[i].length == 2`
- `0 <= logs[i][0] <= n - 1`
- `1 <= logs[i][1] <= 10^6`
- `logs[i][1]` is strictly increasing.

### Conclusion

This solution efficiently processes the logs to determine the worker with the longest continuous work session by iterating through the log entries and keeping track of the maximum session duration. The algorithm ensures that in case of a tie, the worker with the smallest ID is chosen.

---

This README provides a comprehensive explanation of the problem, the solution, and how to use the code. It includes example usage and details about the constraints, ensuring clarity for anyone who wants to understand or use the solution.
