#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 15

void insert(int key, int data);
int hash_func(int key);
void search_ele(int key);
void delete_ele(int key);

typedef struct dataitem{

    int key;
    int data;
    struct dataitem* next;

}Dataitem;

Dataitem* hash_arr[MAX_SIZE] = {0};

int hash_func(int key)
{
    return key % MAX_SIZE;
}

void insert(int key, int data)
{
    int index = 0;
    index = hash_func(key);
    Dataitem* temp = (Dataitem*)calloc(1,sizeof(Dataitem));
    temp->data = data;
    temp->key = key;
    temp->next = NULL;

    if(hash_arr[index]== NULL)
    {
        //1st element
        hash_arr[index] = temp;
    }
    else
    {
        Dataitem* root = hash_arr[index];
        while(root->next !=NULL)
        {
            root= root->next;
        }
        root->next= temp;
    }

    Dataitem* traverse = hash_arr[index];

    while(traverse != NULL)
    {
        printf("Key is %d, value is %d\n",traverse->key, traverse->data);
        traverse= traverse->next;
    }

}

void search_ele(int key)
{
    int index = 0;
    index = hash_func(key);

    if(hash_arr[index]== NULL)
    {
        printf("Element not found1\n");
    }
    else
    {
        //key found at index
        if(key == hash_arr[index]->key)
        {
            printf("Element found with Key %d is %d\n",hash_arr[index]->key, hash_arr[index]->data);
        }
        else
        {
            //traversing through linked list
            Dataitem* traverse = hash_arr[index]->next;
            while(traverse != NULL)
            {
                if(key == traverse->key)
                {
                    printf("Element found with Key %d is %d\n",traverse->key, traverse->data);
                    break;
                }
                else
                {
                    traverse= traverse->next;
                }
            }

            if(NULL == traverse)
            {
                printf("Element not found2\n");
            }
        }

    }
}

void delete_ele(int key)
{
    int index = 0;
    index = hash_func(key);
    Dataitem* del_temp;

    if(hash_arr[index]== NULL)
    {
        printf("Element not found3\n");
    }
    else
    {
        del_temp = hash_arr[index];
        if(key == del_temp->key)
        {
            del_temp->key  = 0;
            del_temp->data = 0;
            hash_arr[index] = hash_arr[index]->next;
            del_temp->next = NULL;
            free(del_temp);
            printf("Deleted 1\n");
        }
        else
        {
            Dataitem* prev;
            while(del_temp != NULL)
            {
                if(key == del_temp->key)
                {
                    prev->next = del_temp->next;
                    del_temp->key  = 0;
                    del_temp->data = 0;
                    del_temp->next = NULL;
                    free(del_temp);
                    printf("Deleted 2\n");
                    break;

                }
                else
                {
                    prev = del_temp;
                    del_temp= del_temp->next;
                }
            }

            if(NULL == del_temp)
            {
                printf("Element not found4\n");
            }

        }
    }
}
int main()
{
    insert(15,10);
    insert(30,15);
    insert(33,26);
    insert(1,7);

    search_ele(30);
    search_ele(15);
    search_ele(1);

    delete_ele(45);
    delete_ele(30);
    delete_ele(33);
    delete_ele(48);


    search_ele(30);
    search_ele(33);



}
