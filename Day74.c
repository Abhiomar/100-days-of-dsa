#include <stdio.h>
#include <string.h>

#define MAX 1000

struct Candidate {
    char name[50];
    int count;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Candidate candidates[MAX];
    int size = 0;

    char vote[50];

    for (int i = 0; i < n; i++) {
        scanf("%s", vote);

        int found = 0;

        // Check if candidate already exists
        for (int j = 0; j < size; j++) {
            if (strcmp(candidates[j].name, vote) == 0) {
                candidates[j].count++;
                found = 1;
                break;
            }
        }

        // New candidate
        if (!found) {
            strcpy(candidates[size].name, vote);
            candidates[size].count = 1;
            size++;
        }
    }

    // Find winner
    char winner[50];
    int maxVotes = 0;

    for (int i = 0; i < size; i++) {
        if (candidates[i].count > maxVotes) {
            maxVotes = candidates[i].count;
            strcpy(winner, candidates[i].name);
        }
        else if (candidates[i].count == maxVotes) {
            if (strcmp(candidates[i].name, winner) < 0) {
                strcpy(winner, candidates[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
