#include <stdio.h>
#include <stdlib.h>

typedef struct HashNode {
    int value;
    int index;
    struct HashNode* next;
} HashNode;

typedef struct HashMap {
    HashNode** buckets;
    int size; // num of buckets
} HashMap;

HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    map->buckets = (HashNode**)malloc(size * sizeof(HashNode*));
    for (int i = 0; i < size; ++i) {
        map->buckets[i] = NULL;
    }
    return map;
}

void deleteHashMap(HashMap* map) {
    for (int i = 0; i < map->size; ++i) {
        HashNode* currentNode = map->buckets[i];
        while (currentNode != NULL) {
            HashNode* temp = currentNode;
            currentNode = currentNode->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

void insert(HashMap* map, int key, int value) {
    int index = abs(key) % map->size;
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->value = value;
    newNode->index = key;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
    printf("new node (k, v) at buckets[%d]: (%d, %d)\n", index, key, value);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    HashMap* map = createHashMap(numsSize);

    for (int i = 0; i < numsSize; ++i) {
        int complement = target - nums[i];
        int index = abs(complement) % numsSize;

        printf("complement: %d, index: %d\n", complement, index);

        // Check if the complement exists in the hash table
        HashNode* currentNode = map->buckets[index];
        while (currentNode != NULL) {
            if (currentNode->index == complement) {
                result[0] = i;
                result[1] = currentNode->value;

                deleteHashMap(map);

                return result;
            }
            currentNode = currentNode->next;
        }

        // Insert the current number into the hash table
        insert(map, nums[i], i);
    }

    deleteHashMap(map);

    // If no solution is found, return an empty result
    result[0] = -1;
    result[1] = -1;
    return result;
}

int main() {
    // inputs
    int target = 9;
    int nums[] = {2, 7, 11, 15};

    // outputs
    int returnSize = 0;
    int* result = twoSum(nums, 4, target, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }

    free(result);

    return 0;
}
