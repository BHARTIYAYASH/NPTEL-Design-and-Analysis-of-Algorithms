# Siruseri Sports Stadium

## Problem Description

The bustling town of Siruseri has just one sports stadium. There are a number of schools, colleges, sports associations, etc. that use this stadium as the venue for their sports events.

Anyone interested in using the stadium has to apply to the Manager of the stadium indicating both the starting date (a positive integer S) and the length of the sporting event in days (a positive integer D) they plan to organize. Since these requests could overlap it may not be possible to satisfy everyone.

It is the job of the Manager to decide who gets to use the stadium and who does not. The Manager, being a genial man, would like to keep as many organizations happy as possible and hence would like to allocate the stadium so that maximum number of events are held.

## Example

Suppose the Manager receives the following 4 requests:

| Event No. | Starting Date | Length |
|-----------|---------------|--------|
| 1         | 2             | 5      |
| 2         | 9             | 7      |
| 3         | 15            | 6      |
| 4         | 9             | 3      |

He would allot the stadium to events 1, 4 and 3. Event 1 begins on day 2 and ends on day 6, event 4 begins on day 9 and ends on day 11 and event 3 begins on day 15 and ends on day 20. You can verify that it is not possible to schedule all the 4 events (since events 2 and 3 overlap and only one of them can get to use the stadium).

## Task

Your task is to help the manager find the best possible allotment (i.e., the maximum number of events that can use the stadium).

## Input Format

- The first line of the input will contain a single integer N (N ≤ 100000) indicating the number of events for which the Manager has received a request.
- Lines 2,3,...,N+1 describe the requirements of the N events.
- Line i+1 contains two integer Si and Di indicating the starting date and the duration of event i.
- You may assume that 1 ≤ Si ≤ 1000000 and 1 ≤ Di ≤ 1000.

## Output Format

Your output must consist of a single line containing a single integer M, indicating the maximum possible number of events that can use the stadium.

## Constraints

- The range of values over which your program is to be tested is mentioned above.
- In addition, 50% of the test cases will also satisfy N ≤ 10000.

## Sample Input
```
4
2 5
9 7
15 6
9 3
```

## Sample Output
```
3
```

## Solution Approach

This is a classic interval scheduling problem. The optimal strategy is the greedy approach:

1. Calculate the end date for each event (start date + duration - 1)
2. Sort all events based on their end dates (earliest end date first)
3. Iterate through the sorted list of events:
   - Select the first event
   - Skip any events that overlap with the last selected event
   - Select the next non-overlapping event

By always choosing the event that ends earliest, we maximize the remaining time for other events.

## Time and Space Complexity

### Time Complexity
- Reading input: O(N)
- Calculating end dates: O(N)
- Sorting events: O(N log N)
- Selecting events: O(N)
- Overall: **O(N log N)** where N is the number of events

### Space Complexity
- Storage for events: O(N)
- Overall: **O(N)** where N is the number of events

The solution is efficient even for the maximum constraints where N can be up to 100,000.