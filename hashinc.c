
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 15
#define MAX_CHAIN_SIZE 20

int** create_ele(int);
void insert(int,int);
int hash_func(int );
void search(int);
void delete_ele(int);

//3d array to handle collisions with chaining
int ***hash_arr;

//creates arrays of keys and data
int** create_ele(int num_of_ele_for_each_cell)
{
    int** temp = (int**)calloc(num_of_ele_for_each_cell,sizeof(int*));

    for(int i=0;i<num_of_ele_for_each_cell;i++)
    {
        temp[i]= (int*)calloc(2,sizeof(int));
    }
    return temp;

}

int hash_func(int key)
{
    return key % MAX_SIZE;
}

void insert(int key, int data)
{
    int index = hash_func(key);
    int ele=0;


    while(1)
    {
        if(ele >= MAX_CHAIN_SIZE)
        {
            return;
        }
        if(hash_arr[index][ele][0] == 0)
        {
            hash_arr[index][ele][0] = key;
            hash_arr[index][ele][1] = data;
            break;
        }
        ele++;
    }

    //printf("index value %d\n", index);
    //printf("ele value %d\n", ele);
    //printf("inside array value key %d\n", hash_arr[index][ele][0]);
    //printf("inside array value value %d\n", hash_arr[index][ele][1]);

}

void search(int key)
{
    int index = hash_func(key);
    int ele=0;
    int item = 0;


    //printf("index value %d\n", index);
    while(1)
    {
        if(ele >= MAX_CHAIN_SIZE)
        {
            break;
        }
        else if(key == hash_arr[index][ele][0])
        {
            //printf("ele value %d\n", ele);
            item = hash_arr[index][ele][1];
        }

        ele++;
    }

    if(NULL != item)
    {
        printf("Item value at key %d is %d\n",key,item);
    }
    else
    {
        printf("Key %d not found\n",key);
    }

}

void delete_ele(int key)
{
    int index = hash_func(key);
    int ele=0;

    while(1)
    {
        if(ele >= MAX_CHAIN_SIZE)
        {
            return;
        }
        else if(key == hash_arr[index][ele][0])
        {
            hash_arr[index][ele][0] = 0;
            hash_arr[index][ele][1] = 0;
            printf("Key %d and it's value is deleted\n", key);
            return;
        }

        ele++;
    }
}

int main()
{
    hash_arr = (int***)calloc(15,sizeof(int**));

    for(int i=0;i<16;i++)
    {
        hash_arr[i] = create_ele(20);
    }
    /**
    In contrast we can use hash_arr[15][20][2] to create above
    hash_arr in stack instead of heap
    key  is at 0th index of each element ex: hash_arr[0][0][0]
    data is at 1st index of each element ex: hash_arr[0][0][1]
    **/

    //printf("%d\n",hash_arr[15][19][0]);


    insert(50,10);
    insert(25,1);
    insert(16,2);
    insert(19,3);
    insert(32,5);
    insert(64,326);

    search(25);
    search(64);
    search(46);

    delete_ele(64);

    search(64);

}
