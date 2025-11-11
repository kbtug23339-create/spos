#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void firstFit(vector<int> blockSize, vector<int> processSize) {
    int m = blockSize.size(), n = processSize.size();
    vector<int> allocation(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "\nFirst Fit Allocation:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " -> ";
        if (allocation[i] != -1)
            cout << "Block " << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated\n";
    }
}

void bestFit(vector<int> blockSize, vector<int> processSize) {
    int m = blockSize.size(), n = processSize.size();
    vector<int> allocation(n, -1);

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\nBest Fit Allocation:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " -> ";
        if (allocation[i] != -1)
            cout << "Block " << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated\n";
    }
}

void worstFit(vector<int> blockSize, vector<int> processSize) {
    int m = blockSize.size(), n = processSize.size();
    vector<int> allocation(n, -1);

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    cout << "\nWorst Fit Allocation:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " -> ";
        if (allocation[i] != -1)
            cout << "Block " << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated\n";
    }
}

void nextFit(vector<int> blockSize, vector<int> processSize) {
    int m = blockSize.size(), n = processSize.size();
    vector<int> allocation(n, -1);
    int j = 0;  // starting position

    for (int i = 0; i < n; i++) {
        int count = 0;
        while (count < m) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
            j = (j + 1) % m;
            count++;
        }
    }

    cout << "\nNext Fit Allocation:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " -> ";
        if (allocation[i] != -1)
            cout << "Block " << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated\n";
    }
}

int main() {
    vector<int> blockSize = {100, 500, 200, 300, 600};
    vector<int> processSize = {212, 417, 112, 426};

    // Make copies since each method modifies blockSize
    vector<int> b1 = blockSize;
    vector<int> b2 = blockSize;
    vector<int> b3 = blockSize;
    vector<int> b4 = blockSize;

    firstFit(b1, processSize);
    bestFit(b2, processSize);
    worstFit(b3, processSize);
    nextFit(b4, processSize);

    return 0;
}
// 1. First Fit algorithm/pseudo code
// o Read all required input
// o FOR i&lt;-0 to all jobs ‘js’
// ▪ FOR j&lt;-0 to all blocks ‘bs’
// o IF block[j]&gt;=jobs[i]

// ▪ Check j th block is already in use or free
// ∙ Continue and search next free block
// ▪ Otherwise allocate j th block to i th job

// o Display all job with allocated blocks and fragmentation
// 2. First Fit algorithm/pseudo code
// o Read all required input
// o FOR i&lt;-0 to all jobs ‘js’
// ▪ SET BestInd�� -
// ▪ FOR j&lt;-0 to all blocks ‘bs’
// o IF block[j]&gt;=jobs[i]

// ▪ IF Block is free and BestInd==-1 THEN SET
// BestInd��
// ▪ ELSEIF Block is free and block[BestInd]&gt;block[j]
// THEN SET BestInd��
// ▪ ELSE continue with next block

// ∙ Continue and search next free block

// ▪ IF BestInd!=-1 THEN allocate j th block to i th job

// o Display all job with allocated blocks and fragmentation
// 3. Worst Fit Algorithm/Pseudo code
// o Read all required input
// o FOR i&lt;-0 to all jobs ‘js’
// ▪ SET WstInd�� -
// ▪ FOR j&lt;-0 to all blocks ‘bs’
// o IF block[j]&gt;=jobs[i]

// Department of Computer Engineering, KBTCOE

// ▪ IF Block is free and WstInd==-1 THEN SET
// WstInd��
// ▪ ELSEIF Block is free and block[WstInd]&lt;block[j]
// THEN SET WstInd��
// ▪ ELSE continue with next block
// ∙ Continue and search next free block
// ▪ IF WstInd!=-1 THEN allocate j th block to i th job

// o Display all job with allocated blocks and fragmentation
// 4. As above write algorithm of Next Fit strategies