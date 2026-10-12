/*
 * Course: COEN 2220 - Programming 2
 * Name: Eduardo Vega
 * Lab: Lab 8 - Big-O / Time Complexity
 * Description: Resolved code for time-complexity analysis
 * Due date: 10/12/2026
 */

#include <iostream>
using namespace std;

/* Returns the ID stored at a valid position already known by the caller. */
int getActivityIdAt(const int activityIds[], int activityIndex)
{
    return activityIds[activityIndex]; // Read one known array position.
}

/* Returns how many activities have an active status. */
int countActiveActivities(const bool isActive[], int activityCount)
{
    int activeCount = 0;

    for (int index = 0; index < activityCount; index++)
    {
        if (isActive[index])
        {
            activeCount++;
        }
    }

    return activeCount;
}

/*
 * Returns how many middle IDs binary search compares before finding targetId.
 * Precondition: activityIds is sorted in ascending order and contains targetId.
 */
int countBinaryComparisons(const int activityIds[], int activityCount, int targetId)
{
    int first = 0;
    int last = activityCount - 1;
    int comparisons = 0;

    while (first <= last)
    {
        int middle = (first + last) / 2;
        comparisons++;

        if (activityIds[middle] == targetId)
        {
            break;
        }
        else if (activityIds[middle] < targetId)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }

    return comparisons;
}

/* Returns how many times a positive count can be reduced by half before reaching 1. */
int countHalvingSteps(int itemCount)
{
    int steps = 0;

    while (itemCount > 1)
    {
        itemCount = itemCount / 2; // Remove approximately half of the remaining items.
        steps++;
    }

    return steps;
}

/* Returns the number of distinct activity pairs visited by two nested loops. */
int countPossiblePairs(int activityCount)
{
    int pairCount = 0;

    for (int first = 0; first < activityCount; first++)
    {
        for (int second = first + 1; second < activityCount; second++)
        {
            pairCount++; // One distinct pair would be compared here.
        }
    }

    return pairCount;
}

int main()
{
    // These activity IDs are sorted so binary search is valid.
    int activityIds[] = {101, 104, 108, 115, 130, 136, 140, 155};
    bool isActive[] = {true, false, true, true, false, false, true, false};
    int activityCount = 8;

    cout << "Activity at index 2: "
         << getActivityIdAt(activityIds, 2) << endl;
    cout << "Active activities: "
         << countActiveActivities(isActive, activityCount) << endl;
    cout << "Binary comparisons for 140: "
         << countBinaryComparisons(activityIds, activityCount, 140) << endl;
    cout << "Halving steps for 8: " << countHalvingSteps(8) << endl;
    cout << "Halving steps for 16: " << countHalvingSteps(16) << endl;
    cout << "Halving steps for 32: " << countHalvingSteps(32) << endl;
    cout << "Possible pairs for 4 activities: " << countPossiblePairs(4) << endl;
    cout << "Possible pairs for 8 activities: " << countPossiblePairs(8) << endl;

    return 0;
}

/*
 * Analysis Answers
 *
 * C1 — Direct access
 * Answer:
 * In this function n is the number of activities in the list.
 * The operation that is done is to search for an ID using its position.
 * Its complexity is O(1) because it does not need to check the entire list.
 * For example, the program finds the ID 108 in position 2
 * directly. It does not matter if the list has more elements,
 * only a single access is always performed.
 * 
 * C2 — Count active activities
 * Answer:
 *Here n represents the total number of activities.
 * The operation is to check if each activity is active or not.
 * Its complexity is O(n) because the loop has to go through
 * all the activities to count them.
 * In this case, it checks 8 activities and finds 4 active.
 * If the list were twice as big, it would have to check
 * twice as many activities.
 * 
 * C3 — Binary search
 * Answer:
 * In this function, n is the number of IDs in the list.
 * The operation is to compare the middle ID with the one we are looking for.
 * Its complexity is O(log n) because each time it compares,
 * it eliminates approximately half of the remaining IDs.
 * In the program, it finds the ID 140 in 3 comparisons.
 * The IDs must be ordered from smallest to largest
 * for the search to work correctly.
 * This is important because the program needs to know
 * in which half of the list it should continue searching.
 * 
 * C4 — Halving steps
 * Answer:
 * When itemCount starts at 16, the values are:
 * 16 -> 8 -> 4 -> 2 -> 1
 * The operation that repeats is dividing the number by 2.
 * With 16 elements, 4 steps are taken and with 32, 5 steps are taken.
 * This means that when doubling the elements, only
 * one additional step is needed.
 * Its complexity is O(log n) because the steps increase
 * slowly even though the number of elements is greater.
 * 
 * C5 — Distinct pairs
 * Answer:
 * The second loop starts at first + 1 to avoid comparing
 * an activity with itself or repeating the same pairs.
 * If it started at 0, it would count repeated pairs and also
 * compare an activity with itself.
 * Its complexity is O(n^2) because it uses two loops,
 * one inside the other, to count the pairs.
 * With 4 activities there are 6 pairs and with 8 there are 28.
 * This shows that the pairs increase quite quickly
 * when the list gets bigger.
 * 
 * C6 — Compare the observed patterns
 * Answer:
 * The results show that each function works differently.
 * Direct access is O(1) because it finds ID 108
 * without having to go through the list.
 * Counting activities is O(n) because it checks the 8 activities
 * to find the 4 that are active.
 * Dividing in half is O(log n) because with 8 elements
 * it takes 3 steps, with 16 it takes 4, and with 32 it takes 5.
 * Counting pairs is O(n^2) because with 4 activities there are
 * 6 pairs, and with 8 activities there are 28.
 * This shows that some functions need much
 * more work than others when the list grows.
 * 
 * C7 — Sorting decision
 * Answer:
 * I would use Linear Search when the list is unordered
 * and I only need to search for one or a few IDs.
 * That way I don't have to waste time sorting the whole list.
 * But if I have to search for many IDs multiple times,
 * it would be better to sort the list first and use Binary Search.
 * This allows searches to be done with fewer comparisons.
 * Although sorting also takes time, for example,
 * Selection Sort has complexity O(n^2) because it has
 * to check the elements multiple times to sort them.
 * That's why sorting first is worthwhile when I am
 * going to perform many searches in the same list.
 */