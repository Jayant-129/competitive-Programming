#include <bits/stdc++.h>
using namespace std;
#define ll long long

void calculateRanks() {
    ll numParticipants, numProblems;
    cin >> numParticipants >> numProblems;
    
    // Input participants' ratings
    vector<ll> participantRatings(numParticipants);
    for(auto &rating : participantRatings) cin >> rating;
    
    // Input problems' difficulties
    vector<ll> problemDifficulties(numProblems);
    for(auto &difficulty : problemDifficulties) cin >> difficulty;
    
    // Extract Kevin's rating
    ll kevinRating = participantRatings[0];
    
    // Gather ratings of participants who surpass Kevin's rating
    vector<ll> superiorRatings;
    for(int i = 1; i < numParticipants; ++i){
        if(participantRatings[i] > kevinRating){
            superiorRatings.push_back(participantRatings[i]);
        }
    }
    sort(superiorRatings.begin(), superiorRatings.end());
    
    // Arrange problem difficulties in ascending order
    sort(problemDifficulties.begin(), problemDifficulties.end());
    
    // Vector to store the aggregate rank for each contest size k
    vector<ll> aggregateRanks;
    
    for(int k = 1; k <= numProblems; ++k){
        ll numberOfContests = numProblems / k;
        ll cumulativeRank = 0;
        
        for(int contest = 0; contest < numberOfContests; ++contest){
            int leftIndex = contest * k;
            int rightIndex = leftIndex + k;
            
            // Determine how many problems Kevin can solve in the current contest
            int solvableProblems = upper_bound(problemDifficulties.begin() + leftIndex, 
                                              problemDifficulties.begin() + rightIndex, 
                                              kevinRating) - 
                                   (problemDifficulties.begin() + leftIndex);
            
            if(solvableProblems == k){
                // Kevin masters all problems in this contest
                cumulativeRank += 1;
            }
            else{
                // Identify the difficulty level required to solve an additional problem
                ll requiredDifficulty = problemDifficulties[leftIndex + solvableProblems];
                
                // Count the number of participants who exceed this required difficulty
                ll higherCount = superiorRatings.end() - upper_bound(superiorRatings.begin(), 
                                                                     superiorRatings.end(), 
                                                                     requiredDifficulty);
                
                // Update Kevin's rank based on the count
                cumulativeRank += (1 + higherCount);
            }
        }
        aggregateRanks.push_back(cumulativeRank);
    }
    
    // Output the cumulative ranks for all contest sizes
    for(auto &rank : aggregateRanks){
        cout << rank << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll testCases;
    cin >> testCases;
    while(testCases--){
        calculateRanks();
    }
}