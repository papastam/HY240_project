/***************************************************
 *                                                 *
 * file: among_us.c                                *
 *                                                 *
 * @Author  Skerdi Basha                           *
 * @Version 1-12-2020                              *
 * @email   sbash@csd.uoc.gr                       *
 *                                                 *
 * @brief   Implementation of among_us.h           *
 *                                                 *
 ***************************************************
 */

#include "among_us.h"
#include <time.h>
#include <time.h>
#include <math.h>

unsigned int primes_g[650] = { 
                                 179,    181,    191,    193,    197,    199,    211,    223,    227,    229, 
                                 233,    239,    241,    251,    257,    263,    269,    271,    277,    281, 
                                 283,    293,    307,    311,    313,    317,    331,    337,    347,    349, 
                                 353,    359,    367,    373,    379,    383,    389,    397,    401,    409, 
                                 419,    421,    431,    433,    439,    443,    449,    457,    461,    463, 
                                 467,    479,    487,    491,    499,    503,    509,    521,    523,    541, 
                                 547,    557,    563,    569,    571,    577,    587,    593,    599,    601, 
                                 607,    613,    617,    619,    631,    641,    643,    647,    653,    659, 
                                 661,    673,    677,    683,    691,    701,    709,    719,    727,    733, 
                                 739,    743,    751,    757,    761,    769,    773,    787,    797,    809, 
                                 811,    821,    823,    827,    829,    839,    853,    857,    859,    863, 
                                 877,    881,    883,    887,    907,    911,    919,    929,    937,    941, 
                                 947,    953,    967,    971,    977,    983,    991,    997,   1009,   1013, 
                                1019,   1021,   1031,   1033,   1039,   1049,   1051,   1061,   1063,   1069, 
                                1087,   1091,   1093,   1097,   1103,   1109,   1117,   1123,   1129,   1151, 
                                1153,   1163,   1171,   1181,   1187,   1193,   1201,   1213,   1217,   1223, 
                                1229,   1231,   1237,   1249,   1259,   1277,   1279,   1283,   1289,   1291, 
                                1297,   1301,   1303,   1307,   1319,   1321,   1327,   1361,   1367,   1373, 
                                1381,   1399,   1409,   1423,   1427,   1429,   1433,   1439,   1447,   1451, 
                                1453,   1459,   1471,   1481,   1483,   1487,   1489,   1493,   1499,   1511, 
                                1523,   1531,   1543,   1549,   1553,   1559,   1567,   1571,   1579,   1583, 
                                1597,   1601,   1607,   1609,   1613,   1619,   1621,   1627,   1637,   1657, 
                                1663,   1667,   1669,   1693,   1697,   1699,   1709,   1721,   1723,   1733, 
                                1741,   1747,   1753,   1759,   1777,   1783,   1787,   1789,   1801,   1811, 
                                1823,   1831,   1847,   1861,   1867,   1871,   1873,   1877,   1879,   1889, 
                                1901,   1907,   1913,   1931,   1933,   1949,   1951,   1973,   1979,   1987, 
                                1993,   1997,   1999,   2003,   2011,   2017,   2027,   2029,   2039,   2053, 
                                2063,   2069,   2081,   2083,   2087,   2089,   2099,   2111,   2113,   2129, 
                                2131,   2137,   2141,   2143,   2153,   2161,   2179,   2203,   2207,   2213, 
                                2221,   2237,   2239,   2243,   2251,   2267,   2269,   2273,   2281,   2287, 
                                2293,   2297,   2309,   2311,   2333,   2339,   2341,   2347,   2351,   2357, 
                                2371,   2377,   2381,   2383,   2389,   2393,   2399,   2411,   2417,   2423, 
                                2437,   2441,   2447,   2459,   2467,   2473,   2477,   2503,   2521,   2531, 
                                2539,   2543,   2549,   2551,   2557,   2579,   2591,   2593,   2609,   2617, 
                                2621,   2633,   2647,   2657,   2659,   2663,   2671,   2677,   2683,   2687, 
                                2689,   2693,   2699,   2707,   2711,   2713,   2719,   2729,   2731,   2741, 
                                2749,   2753,   2767,   2777,   2789,   2791,   2797,   2801,   2803,   2819, 
                                2833,   2837,   2843,   2851,   2857,   2861,   2879,   2887,   2897,   2903, 
                                2909,   2917,   2927,   2939,   2953,   2957,   2963,   2969,   2971,   2999, 
                                3001,   3011,   3019,   3023,   3037,   3041,   3049,   3061,   3067,   3079, 
                                3083,   3089,   3109,   3119,   3121,   3137,   3163,   3167,   3169,   3181, 
                                3187,   3191,   3203,   3209,   3217,   3221,   3229,   3251,   3253,   3257, 
                                3259,   3271,   3299,   3301,   3307,   3313,   3319,   3323,   3329,   3331, 
                                3343,   3347,   3359,   3361,   3371,   3373,   3389,   3391,   3407,   3413, 
                                3433,   3449,   3457,   3461,   3463,   3467,   3469,   3491,   3499,   3511, 
                                3517,   3527,   3529,   3533,   3539,   3541,   3547,   3557,   3559,   3571, 
                                3581,   3583,   3593,   3607,   3613,   3617,   3623,   3631,   3637,   3643, 
                                3659,   3671,   3673,   3677,   3691,   3697,   3701,   3709,   3719,   3727, 
                                3733,   3739,   3761,   3767,   3769,   3779,   3793,   3797,   3803,   3821, 
                                3823,   3833,   3847,   3851,   3853,   3863,   3877,   3881,   3889,   3907, 
                                3911,   3917,   3919,   3923,   3929,   3931,   3943,   3947,   3967,   3989, 
                                4001,   4003,   4007,   4013,   4019,   4021,   4027,   4049,   4051,   4057, 
                                4073,   4079,   4091,   4093,   4099,   4111,   4127,   4129,   4133,   4139, 
                                4153,   4157,   4159,   4177,   4201,   4211,   4217,   4219,   4229,   4231, 
                                4241,   4243,   4253,   4259,   4261,   4271,   4273,   4283,   4289,   4297, 
                                4327,   4337,   4339,   4349,   4357,   4363,   4373,   4391,   4397,   4409, 
                                4421,   4423,   4441,   4447,   4451,   4457,   4463,   4481,   4483,   4493, 
                                4507,   4513,   4517,   4519,   4523,   4547,   4549,   4561,   4567,   4583, 
                                4591,   4597,   4603,   4621,   4637,   4639,   4643,   4649,   4651,   4657, 
                                4663,   4673,   4679,   4691,   4703,   4721,   4723,   4729,   4733,   4751, 
                                4759,   4783,   4787,   4789,   4793,   4799,   4801,   4813,   4817,   4831, 
                                4861,   4871,   4877,   4889,   4903,   4909,   4919,   4931,   4933,   4937, 
                                4943,   4951,   4957,   4967,   4969,   4973,   4987,   4993,   4999,   5003, 
                                5009,   5011,   5021,   5023,   5039,   5051,   5059,   5077,   5081,   5087, 
                                5099,   5101,   5107,   5113,   5119,   5147,   5153,   5167,   5171,   5179, 
                            };
int p,a,b, aliencount, playercount, curralien, currcrew, currchain, distributedtaskcount;
struct HT_Task *currnode;
struct Player *playersentinel, *maxevidence;

void distribute_rec(struct Player *node);
void print_players_rec(struct Player *tree);
void print_dl_players(struct Player *tree);
void print_dl_tasks(struct Task *tree);
struct HT_Task* retnexttask();
struct Task* taskexists(struct Player *player,int tid);
int insertpq(struct Task *task);
int countplayers(struct Player *tree);
struct Task* rectree2list(struct Task *tree);
struct Task** mergelist(struct Task *list1,struct Task *list2,int list1size,int list2size);
int countnodes(struct Task *tree);
struct Task* array2tree(struct Task **array, int start, int end);
void print_dl_evidence_players(struct Player *tree);
void print_double_evidence_tree();
void inserttask2tree(struct Task *task,struct Task *tree);

int hashfunct(int key);


/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize() {
    aliencount=0;
    playercount=0;

    // initualize the players tree
    if(!(players_tree = (struct Player*)malloc(sizeof(struct Player)))){return 0;} 
    playersentinel=players_tree;
    players_tree->pid=0;
    players_tree->is_alien=-1;
    players_tree->parent=NULL;
    players_tree->lc=NULL;
    players_tree->rc=NULL;

    //initialize the hash function
    int i=0;
    while(primes_g[i]<=max_tid_g){i++;}
    p=primes_g[i];
    srand(time(NULL));
    a = rand() % (p-1);
    b = rand() % (p-1);
    printf("hash function = (((%d*x+%d) mod %d) mod %d)\n",a,b,p,max_tasks_g);
    
    //initialize the general tasks hash table
    if(!(general_tasks_ht = (struct General_Tasks_HT*)malloc(sizeof(struct General_Tasks_HT)))){return 0;}
    if(!(general_tasks_ht->tasks = (struct HT_Task**)malloc(max_tasks_g*sizeof(struct HT_Task*)))){return 0;}
    general_tasks_ht->count=0; 

    //initialize the completed tasks priority queue
    if(!(completed_tasks_pq = (struct Completed_Tasks_PQ*)malloc(sizeof(struct Completed_Tasks_PQ)))){return 0;}
    if(!(completed_tasks_pq->tasks = (struct HT_Task**)malloc(max_tasks_g*sizeof(struct HT_Task*)))){return 0;}
    for(int i=0;i<max_tasks_g;i++){
        if(!(completed_tasks_pq->tasks[i] = (struct HT_Task*)malloc(sizeof(struct HT_Task)))){return 0;}
    }
    completed_tasks_pq->size=0;

    return 1;
}

int hashfunct(int key){
    // return key % max_tasks_g;
    return ((((a*key)+b) % p) % max_tasks_g);
}

/**
 * @brief Register Player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien) {

    //create the new player node
    struct Player *newPlayer;
    if(!(newPlayer = (struct Player*)malloc(sizeof(struct Player)))){return 0;}
    if(is_alien){aliencount++;}
    playercount++;
    newPlayer->is_alien=is_alien;
    newPlayer->pid=pid;
    newPlayer->lc=playersentinel;
    newPlayer->rc=playersentinel;
    
    //add the new player to the players tree
    if(players_tree->is_alien==-1){
        players_tree=newPlayer;
    }else{
        struct Player *itter=players_tree;
        while(1)
        if(itter->pid>pid){
            if(itter->lc->is_alien==-1){
                newPlayer->parent=itter;
                itter->lc=newPlayer;
                break;
            }
            itter=itter->lc;
        }else{
            if(itter->rc->is_alien==-1){
                newPlayer->parent=itter;
                itter->rc=newPlayer;
                break;
            }
            itter=itter->rc;
        }
    }
    print_players();
    return 1;
}

/**
 * @brief Insert Task in the general task hash table
 *
 * @param tid The task id
 * 
 * @param difficulty The difficulty of the task
 *
 * @return 1 on success
 *         0 on failure
 */
int insert_task(int tid, int difficulty) {
    int pos = hashfunct(tid);//get the new task's hash code
    
    //create the new task node
    struct HT_Task *newtask;
    if(!(newtask = (struct HT_Task*)malloc(sizeof(struct HT_Task)))){return 0;}
    newtask->tid = tid;
    newtask->difficulty = difficulty;
    newtask->next=NULL;

    //if the hash table's list in the specific hash code is empty, just add it
    if(general_tasks_ht->tasks[pos]==NULL){
        general_tasks_ht->tasks[pos]=newtask;
    }else{//else set its next to the current first and set it as the first node
        newtask->next=general_tasks_ht->tasks[pos];
        general_tasks_ht->tasks[pos]=newtask;
    }
    general_tasks_ht->count++;
    print_tasks();
    return 1;
}

/**
 * @brief Distribute Tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks() {
    currchain=0;
    currnode=NULL;
    distributedtaskcount=0;
    //call the recursicve function as many times it needs so that all the tasks are distributed
    for(int i=0;i<ceil((double)general_tasks_ht->count/(playercount-aliencount));i++){
        distribute_rec(players_tree);
    }
    print_double_tree();
    return 1;
}


void distribute_rec(struct Player *node){
    //if the node is null or the node is the player sentinel or the distributed tasks are more or equal to the total tasks, return
    if(node==NULL ||node->is_alien==-1|| distributedtaskcount>=max_tasks_g){return;}

    distribute_rec(node->lc);
    if(distributedtaskcount>=max_tasks_g){return;}//if the distributed tasks are more or equal to the total tasks, return
    //ass a task to the player only if he is not an alien
    if(node->is_alien==0){
        distributedtaskcount++;
        //create the new task 
        struct HT_Task *taskitterret = retnexttask();
        struct Task *insertask;
        if(!(insertask = (struct Task*)malloc(sizeof(struct Task)))){return;}
        insertask->difficulty=taskitterret->difficulty;
        insertask->lcnt=0;
        insertask->tid=taskitterret->tid;

        if(node->tasks==NULL){//if the player has no tasks just set the new task as the tree head
            node->tasks=insertask;
        }else{//else insert it to the table
            inserttask2tree(insertask,node->tasks);
        }
    }

    distribute_rec(node->rc);
}

//a helping function for inserting a task into a players task tree
void inserttask2tree(struct Task *task,struct Task *tree){
    struct Task *itter=tree;
    while(itter){
        if(task->tid<itter->tid){
            if(itter->lc==NULL){
                itter->lc=task;
                itter->lcnt++;
                return;
            }
            itter->lcnt++;
            itter=itter->lc;
        }else if(task->tid>itter->tid){
            if(!itter->rc){
                itter->rc=task;
                return;
            }
            itter=itter->rc;
        }else{
            break;
        }
    }
}

//DEBUG INSERT
// void inserttask2tree(struct Task *task,struct Task *tree){
//     printf("HERE\n");
//     printf("%d \\/\n",task->tid);
//     struct Task *itter=tree;
//     while(itter){
//         printf("%d compared to %d (lc?%d,rc?%d)",task->tid,itter->tid,itter->lc!=NULL,itter->rc!=NULL);
//         if(task->tid<itter->tid){
//             printf("->lc\n");
//             if(itter->lc==NULL){
//                 itter->lc=task;
//                 itter->lcnt++;
//                 return;
//             }
//             itter->lcnt++;
//             itter=itter->lc;
//         }else if(task->tid>itter->tid){
//             printf("->rc\n");
//             if(!itter->rc){
//                 printf("\nHERE\n");
//                 itter->rc=task;
//                 return;
//             }
//             if(!itter->rc->tid){
//                 printf("sou kanei malakia auto bro\n");
//             }else{
//                 printf("ola kala edw\n");
//             }
//             printf("->rc(tid=%d)\n",itter->rc->tid);
//             itter=itter->rc;
//         }else{
//             break;
//         }
//     }
// }

//a helping funtion whits in every of its calls returns the next task from the tassk hash table
struct HT_Task* retnexttask(){
    //if the current node is not initialized set it as the first item of the first (non-empty) chain and return it
    if(!currnode){
        for(int i=0;i<max_tasks_g;i++){
            if(general_tasks_ht->tasks[i]!=NULL){
                currnode=general_tasks_ht->tasks[i];
                currchain=i;
                return currnode;
            }
        }
    }
    //if the current node has a next node, advance it to its next node and return it 
    if(currnode->next){currnode=currnode->next;return currnode;}
    //if it doesn have a next node, advance it to the next (not-empty) chain
    for(int i=currchain+1;i<max_tasks_g;i++){
        if(general_tasks_ht->tasks[i]!=NULL){
            currnode=general_tasks_ht->tasks[i];
            currchain=i;
            break;
        }
    }
    return currnode;
}

//a helpig fuction calculating if the task exist in a player's tree
struct Task* taskexists(struct Player *player,int tid){
    if(!player->tasks){return NULL;}
    struct Task *tasksitter=player->tasks;
    while(tasksitter->tid!=tid){
        if(tasksitter->tid>tid){
            tasksitter=tasksitter->lc;
            if(tasksitter==NULL){return NULL;}
        }else{
            tasksitter=tasksitter->rc;
            if(tasksitter==NULL){return NULL;}
        }
    }
    return tasksitter;
}

//a helping function for deleting a task from a players tree
int deletetask(int tid,struct Player *player){
    if(!player || !player->tasks){return 0;}
    struct Task *itterparrent=NULL;
    struct Task *tasksitter=player->tasks;
    //at first we find the task to delete
    while(tasksitter && tasksitter->tid!=tid){
        itterparrent=tasksitter;
        if(tasksitter->tid>tid){
            tasksitter->lcnt--;
            tasksitter=tasksitter->lc;
        }else if(tasksitter->tid<tid){
            tasksitter=tasksitter->rc;
        }
    }
    //if the task has 2 children
    if(tasksitter->lc && tasksitter->rc){
        struct Task *temp;
        struct Task *tempparrent = NULL;

        //create a temp pionter to find the inorder sucessor of the deleted node
        temp=tasksitter->rc;
        while(temp->lc){
            tempparrent=temp;
            tempparrent->lcnt--;
            temp=temp->lc;
        }

        //if temp had a left child(therefore the tempparrent has ben set)
        if(tempparrent){
            //set his left child to temp's right child
            tempparrent->lc = temp->rc;
        }else{
            //set the deleted nodes right child to its left child's right child
            tasksitter->rc = temp->rc;
        }

        //set the taskitter data and key to the temp's data
        tasksitter->tid=temp->tid;
        tasksitter->difficulty=temp->difficulty;
    }else if(!tasksitter->lc && !tasksitter->rc && player->tasks==tasksitter){//if the taskitter is the head and has no cildren, the tasks tree is emptyed 
        player->tasks=NULL;
    }else{//if the taskitter has at most 1 child
        struct Task *replacer=NULL;
        
        //if the left child exists set it to replace the node
        if(tasksitter->lc!=NULL){
            replacer = tasksitter->lc;
        }else{//els if the right child exists set it to replace the node
            replacer = tasksitter->rc;
        }
        //if the taskitter has no children, the replacer stays null


        //if the delete node is the tree head, set its child to the tree head
        if(itterparrent==NULL){
            player->tasks = replacer;
            return 1;
        }

        //set its parrent's child as the replacer
        if(itterparrent->rc==tasksitter){
            itterparrent->rc=replacer;
        }else{
            itterparrent->lc=replacer;
        }
    }
    return 1;

}

//insert to the priority queue as we were taught in section 7
int insertpq(struct Task *task){
    int m = completed_tasks_pq->size;
    while(m > 0 && task->difficulty > completed_tasks_pq->tasks[(m-1)/2]->difficulty) { 
        completed_tasks_pq->tasks[m]->difficulty = completed_tasks_pq->tasks[(m-1)/2]->difficulty; 
        completed_tasks_pq->tasks[m]->tid = completed_tasks_pq->tasks[(m-1)/2]->tid; 
        m = (m-1)/2; 
    }
    completed_tasks_pq->tasks[m]->difficulty = task->difficulty;
    completed_tasks_pq->tasks[m]->tid = task->tid;
    completed_tasks_pq->size++;
    return 1;
}

//heap fixing function after deletion
int heap_fixer(struct HT_Task **tasks,int size ,int start){
    struct HT_Task *temp;
    int max = size;
    int lc = (2*start)+1; 
    int rc = (2*start)+2; 


    if(lc<size && tasks[max]->difficulty < tasks[lc]->difficulty ){//if the left kid is violating the heap priority
        max = lc;
    }
    if(rc<size && tasks[max]->difficulty < tasks[rc]->difficulty ){//if the right kid is violating the heap priority
        max = rc;
    }//if the max changed in the above ifs
    if(max!=start){//change the max and the start items
        temp = tasks[start];
        tasks[start] = tasks[max];
        tasks[max] = temp;
        heap_fixer(tasks,size,max);//and call the heap fixer for the rest of the nodes
    }
    return 1;
}

//pop max from the priority queue as we were taught in section 7
struct HT_Task* poppq(){
    if(completed_tasks_pq->size == 0){return NULL;}

    //create the return item
    struct HT_Task *pop;
    if(!(pop= (struct HT_Task*)malloc(sizeof(struct HT_Task*)))){return NULL;}
    pop->tid = completed_tasks_pq->tasks[0]->tid;
    pop->difficulty = completed_tasks_pq->tasks[0]->difficulty;

    //bring the last item in the pq head
    completed_tasks_pq->tasks[0]->tid=completed_tasks_pq->tasks[completed_tasks_pq->size-1]->tid;
    completed_tasks_pq->tasks[0]->difficulty=completed_tasks_pq->tasks[completed_tasks_pq->size-1]->difficulty;

    completed_tasks_pq->size--;

    //cal the heap fixing function    
    heap_fixer(completed_tasks_pq->tasks,completed_tasks_pq->size,0);

    return pop;
}

/**
 * @brief Implement Task
 *
 * @param pid The player's id
 *
 * @param tid The task's tid
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int tid) {
    //find the target player
    struct Player *playersitter=players_tree;
    while(playersitter->pid!=pid){
        if(playersitter->is_alien==-1){return 0;} //if the playersitterator reaches the sentinel, the player was not found
        if(playersitter->pid>pid){
            playersitter=playersitter->lc;
        }else if(playersitter->pid<pid){
            playersitter=playersitter->rc;
        }
    }
    if(!taskexists(playersitter,tid)){return 0;}//if the task doesnt exist, return a fail
    insertpq(taskexists(playersitter,tid));//insert the task to the completed pq
    deletetask(tid, playersitter);//delete the task from the player
    print_double_tree();
    return 1;
}

//a helping function converting a given tree to a linked list (using lc as next)
struct Task* rectree2list(struct Task *tree){
    if(!tree){return NULL;}
    
    struct Task *ret=NULL;
    ret = rectree2list(tree->lc);//call the recursive function for the lc
    
    //if the lc function didnt return any nodes
    if(!ret){
        struct Task *newlistitem;//create a new node
        if(!(newlistitem = (struct Task*)malloc(sizeof(struct Task)))){return 0;}
        newlistitem->difficulty=tree->difficulty;//set its fields
        newlistitem->tid=tree->tid;
        newlistitem->lc=NULL;
    
        ret=newlistitem;//and set it as the return head node 
    }else{//else
        struct Task *newlistitem;//create the new node
        if(!(newlistitem = (struct Task*)malloc(sizeof(struct Task)))){return 0;}
        newlistitem->difficulty=tree->difficulty;//set its fields
        newlistitem->tid=tree->tid;
        newlistitem->lc=ret;//point its next to the old node head 
        ret=newlistitem;//and set it as the return nodes heads
    }

    struct Task *rcret=rectree2list(tree->rc);//then call the function for the rc
    if(rcret){//if it returns a node
        struct Task *itter=rcret;
        while(itter->lc){//advance an itterator to the last node of the returned nodes
            itter=itter->lc;
        }
        itter->lc=ret;//and set as next the old head to the last of the returned nodes
        ret=rcret;
    }
    
    return ret;
}

//a helping function for merging two lists into an array
struct Task** mergelist(struct Task *list1,struct Task *list2,int list1size,int list2size){
    struct Task **retarray, *mergedtask;
    if(!(retarray = (struct Task**)malloc((list1size+list2size)*sizeof(struct Task*)))){return NULL;}
    int i=0,j=0;
    while((i+j)<(list1size+list2size)){
        if(!(mergedtask = (struct Task*)malloc(sizeof(struct Task)))){return NULL;}
                
        if(list1 && list2){//if both lists have items
            if(!list2 || list2->tid<list1->tid || j==list2size){//if list1 has a bigger tid than list2
                mergedtask->tid=list1->tid;
                mergedtask->difficulty=list1->difficulty;
                retarray[i+j]=mergedtask;
                list1=list1->lc;
                i++;
            }else if(!list1 || list2->tid>list1->tid || i==list1size){//if list2 has a bigger tid than list1
                mergedtask->tid=list2->tid;
                mergedtask->difficulty=list2->difficulty;
                retarray[i+j]=mergedtask;
                list2=list2->lc;
                j++;
            }else{
                printf("TASKS WITH SAME TID\n");
                mergedtask->tid=list1->tid;
                mergedtask->difficulty=list1->difficulty;
                retarray[i+j]=mergedtask;
                i++;
                list1=list1->lc;
                list2=list2->lc;
                list2size--;
            }
        }else if(!list1){//if list1 is empty
            mergedtask->tid=list2->tid;
            mergedtask->difficulty=list2->difficulty;
            retarray[i+j]=mergedtask;
            list2=list2->lc;
            j++;
        }else{//if list 2 is empty
            mergedtask->tid=list1->tid;
            mergedtask->difficulty=list1->difficulty;
            retarray[i+j]=mergedtask;
            list1=list1->lc;
            i++;
        }
    }
    return retarray;
}

//a helping function recursively converting a array to tree
struct Task* array2tree(struct Task **array, int start, int end){ 
    struct Task *newnode;
    if (start > end){return NULL;}
    int m = ceil((start + end)/2); 

    //create the node to be inserted wich is the midlle of the array
    if(!( newnode = (struct Task*)malloc(sizeof(struct Task)))){return NULL;}
    newnode->tid=array[m]->tid;
    newnode->difficulty=array[m]->difficulty;

    //and set its kids to the left and right subarrays
    //they are reversed because the array is also reversed
    newnode->lc = array2tree(array, m+1, end); 
    newnode->lcnt=countnodes(newnode->lc);
    newnode->rc = array2tree(array, start, m-1); 

    return newnode;; 
}

//a helping function for removing a player from the players tree
int deleteplayer(struct Player *player){
    if(!player){return 0;}
    
    //if the player has 2 children
    if(player->lc->is_alien!=-1 && player->rc->is_alien!=-1){
        struct Player *temp;
        struct Player *temppar=NULL;

        //create a temp pionter to find the inorder sucessor of the deleted node
        temp=player->rc;
        while(temp->lc->is_alien!=-1){
            temppar=temp;
            temp=temp->lc;
        }

        //if temp had a left child
        if(temppar){
            //set his left child to temp's right child
            temppar->lc = temp->rc;
        }else{
            //set the deleted nodes right child to its left child's right child
            player->rc = temp->rc;
        }
        //set the players data and key to the temp's data
        player->pid=temp->pid;
        player->is_alien=temp->is_alien;
        player->evidence=temp->evidence;
        player->tasks=temp->tasks;
    }else if(player->lc->is_alien!=-1 && player->rc->is_alien!=-1 && players_tree==player){//if the player is the head and has no cildren, the players_tree is emptyed 
        players_tree=playersentinel;
    }else{//if the player has at most 1 child
        struct Player *replacer;
        
        //if the left child exists set it to replace the node
        if(player->lc->is_alien!=-1){
            player->lc->parent=player->parent;
            replacer = player->lc;
        }else if(player->rc->is_alien!=-1){//else if the right child exists set it to replace the node
            player->rc->parent=player->parent;
            replacer = player->rc;
        }else{
            replacer=playersentinel;
        }
        //if the taskitter has no children, the replacer stays null

        //if the delete node is the tree head, set its child to the tree head
        if(!player->parent){
            player=replacer;
            return 1;
        }

        //set its parrent's child as the replacer
        if(player->parent->rc==player){
            player->parent->rc=replacer;
        }else{
            player->parent->lc=replacer;
        }
    }
    return 1;
}

/**
 * @brief Eject Player
 * 
 * @param pid_1 The ejected player's id
 *
 * @param pid_2 The crewmates id
 *
 * @return 1 on success
 *         0 on failure
 */
int eject_player(int pid_1, int pid_2) {
    struct Task *list1=NULL, *list2=NULL, **mergedarray=NULL;
    int list1size=0,list2size=0;
    struct Player *player1=players_tree, *player2=players_tree;
    while(player1->pid!=pid_1){
        if(player1->is_alien==-1){return 0;} //if the player1 reaches the sentinel, the player was not found
        if(player1->pid>pid_1){
            player1=player1->lc;
        }else if(player1->pid<pid_1){
            player1=player1->rc;
        }
    }
    while(player2->pid!=pid_2){
        if(player2->is_alien==-1){return 0;} //if the player2 reaches the sentinel, the player was not found
        if(player2->pid>pid_2){
            player2=player2->lc;
        }else if(player2->pid<pid_2){
            player2=player2->rc;
        }
    }

    if(player1->tasks && player2->tasks){//if both players have tasks
        list1=rectree2list(player1->tasks);//turn them into lists

        list2=rectree2list(player2->tasks);

        list1size=countnodes(player1->tasks);
        list2size=countnodes(player2->tasks);
        mergedarray=mergelist(list1,list2,list1size,list2size);//merge them

        player2->tasks= array2tree(mergedarray,0,(list1size+list2size)-1);//and turn them into a tree
    }else if(!player2->tasks){//else if only p1 has tasks
        player2->tasks=player1->tasks;//set p2's tasks to p1's
    }

    deleteplayer(player1);//remove p1

    print_double_tree();
    return 1;
}

/**
 * @brief Witness Eject Player
 *
 * @param pid_1 The ejected player's id
 * 
 * @param pid_2 The crewmate's pid
 *
 * @param pid_a The alien's pid
 * 
 * @param number_of_witnesses The number of witnesses
 *
 * @return 1 on success
 *         0 on failure
 */
int witness_eject(int pid_1, int pid_2, int pid_a, int number_of_witnesses){
    struct Player *alien=players_tree;
    while(alien->pid!=pid_a){
        if(alien->is_alien==-1){return 0;} //if the alien reaches the sentinel, the player was not found
        if(alien->pid>pid_a){
            alien=alien->lc;
        }else if(alien->pid<pid_a){
            alien=alien->rc;
        }
    }
    alien->evidence+=number_of_witnesses;
    if(!eject_player(pid_1,pid_2)){return 0;}

    printf("\n\n\n");
    print_double_evidence_tree();

    return 1;
}

//a helping function for calculating the inorder predecessor
struct Player* findInorderPredecessor(struct Player *player){
    if(!player){return NULL;}
    //if the target player has a left child
    if(player->lc->is_alien!=-1){
        struct Player *itter=player->lc;
        //find it's right-most child 
        while(itter->rc->is_alien!=-1){
            itter=itter->rc;
        }
        //and return it
        return itter;
    }else{//else if the target player does not have a left child
        struct Player *itter=player;
        //find his parent who is the parent's parent left child
        while(itter && itter->parent && itter==itter->parent->lc){
            itter=itter->parent;
        }
        if(!itter->parent){//if this parent is NULL (aka if the target player is the first inorder node)
            while(itter->rc->is_alien!=-1){
                itter=itter->rc;//find the last inorder node
            }
            return itter;//and return it
        }
        return itter->parent;//else return the parrent
    }
}

//a helping function for calculating the inorder successor (same as the predecessor except rc becomes lc and the opposite)
struct Player* findInorderSuccessor(struct Player *player){
    if(!player){return NULL;}
    //if the target player has a right child
    if(player->rc->is_alien!=-1){
        struct Player *itter=player->rc;
        //find it's left-most child 
        while(itter->lc->is_alien!=-1){
            itter=itter->lc;
        }
        //and return it
        return itter;
    }else{//else if the target player does not have a right child
        struct Player *itter=player;
        //find his parent who is the parent's parent right child
        while(itter && itter->parent && itter==itter->parent->rc){
            itter=itter->parent;
        }
        if(!itter->parent){//if this parent is NULL (aka if the target player is the last inorder node)
            while(itter->lc->is_alien!=-1){
                itter=itter->lc;//find the first inorder node
            }
            return itter;//and return it
        }
        return itter->parent;//else return the parrent
    }
}

//a helping function for inserting a task into a player's tree
int tasktreeinsert(struct Player *player, struct Task *node){
    if(!player->tasks){player->tasks=node;return 1;}
    struct Task *itter=player->tasks;
    while(itter){
        if(itter->tid>node->tid){
            itter->lcnt++;
            if(!itter->lc){
                itter->lc=node;
                return 1;
            }
            itter=itter->lc;
        }else if(itter->tid<node->tid){
            if(!itter->rc){
                itter->rc=node;
                return 1;
            }
            itter=itter->rc;
        }
    }
    return 0;
}

/**
 * @brief Sabotage
 *
 * @param number_of_tasks The number of tasks to be sabotaged
 *
 * @param pid The player's id
 * 
 * @return 1 on success
 *         0 on failure
 */
int sabotage(int number_of_tasks, int pid) {
    if(number_of_tasks>completed_tasks_pq->size){number_of_tasks=completed_tasks_pq->size;}

    //find the target player
    struct Player *player=players_tree;
    while(player->pid!=pid){
        if(player->is_alien==-1){return 0;} //if the playersitterator reaches the sentinel, the player was not found
        if(player->pid>pid){
            player=player->lc;
        }else if(player->pid<pid){
            player=player->rc;
        }
    }

    //calculate the |_number_of_tasks/2_| predecessor 
    for(int i=0;i<=number_of_tasks/2;i++){
        player=findInorderPredecessor(player);
    }

    //for number_of_tasks times,
    for(int i=0;i<number_of_tasks;i++){
        player=findInorderSuccessor(player);//find the next successor,
        if(player->is_alien){//(if it is an alien, skip the loop)
            i--;
            continue;
        }
        struct Task *insertask;//create a new task (with the according fields)
        struct HT_Task *popedtask=poppq();
        if(!(insertask = (struct Task*)malloc(sizeof(struct Task)))){return 0;}
        insertask->difficulty=popedtask->difficulty;
        insertask->tid=popedtask->tid;
        insertask->lcnt=0;
        tasktreeinsert(player,insertask);//and insert it to the players tree
    }
    
    print_double_tree();
    print_pq();
    
    
    return 1;
}

void getmaxevidence(struct Player *tree){
    if(!tree){return;}
    getmaxevidence(tree->lc);

    if(tree->evidence>maxevidence->evidence){maxevidence=tree;}

    getmaxevidence(tree->rc);
}

/**
 * @brief Vote
 *
 * @param pid_1 The suspicious player's id
 *
 * @param pid_2 The crewmate's pid
 * 
 * @param vote_evidence The vote's evidence
 *
 * @return 1 on success
 *         0 on failure
 */
int vote(int pid_1, int pid_2, int vote_evidence) {
    struct Player *itter=players_tree;
    while(itter->pid!=pid_1){
        if(itter->is_alien==-1){return 0;} //if the playersitterator reaches the sentinel, the player was not found
        if(itter->pid>pid_1){
            itter=itter->lc;
        }else if(itter->pid<pid_1){
            itter=itter->rc;
        }
    }
    itter->evidence+=vote_evidence;
    
    maxevidence=players_tree;
    getmaxevidence(players_tree);

    if(!eject_player(maxevidence->pid,pid_2)){return 0;}

    printf("\n\n\n");
    print_double_evidence_tree();

    return 1;
}

//a helping function for counting a tasktree's nodes
int countnodes(struct Task *tree){
    int cnt=0;
    struct Task *itter=tree;
    while(itter){
        cnt++;
        cnt+=itter->lcnt;
        itter=itter->rc;
    }
    return cnt;
}

/**
 * @brief Give Away Work
 *
 * @param pid_1 The existing crewmate's id
 *
 * @param pid_2 The new crewmate's pid
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work(int pid_1, int pid_2) {
    struct Player *p1=players_tree, *p2=players_tree;
    int p2exists=0;
    //Search for the first player (pis_1)
    while(p1->pid!=pid_1){
        if(p1->is_alien==-1){return 0;} //if the playersitterator reaches the sentinel, the p1 was not found
        if(p1->pid>pid_1){
            p1=p1->lc;
        }else if(p1->pid<pid_1){
            p1=p1->rc;
        }
    }
    //Search if the second player exists (pid_2)
    while(p2->pid!=pid_2 && p2->is_alien!=-1){
        if(p2->pid>pid_2){
            p2=p2->lc;
        }else if(p2->pid<pid_2){
            p2=p2->rc;
        }
    }
    //if pid_2 does not exists, create a new player with the according fields
    if(p2->pid!=pid_2){
        if(!(p2 = (struct Player*)malloc(sizeof(struct Player)))){return 0;}
        p2->pid=pid_2;
        p2->is_alien=0;
        p2->evidence=0;
        p2->lc=playersentinel;
        p2->rc=playersentinel;
    }else{p2exists=1;}//else update the p2exists flag

    //TREE SPLITTING PART
    //this part is based on the assign#3 answer
    int k=countnodes(p1->tasks)/2;
    struct Task *p=p1->tasks, *temp=NULL;
    p1->tasks=NULL;
    p2->tasks=NULL;
    while(p){//start itterating the tree
        if(p->lcnt==k){//if the currnode's left tree has the nodes needed, take it
            tasktreeinsert(p1, p->lc);
            p->lc=NULL;
            p->lcnt=0;
            tasktreeinsert(p2, p);
            break;
        }else if(p->lcnt+1==k){//if the currnode's left tree has one node less than the nodes needed, take its tree and the current node
            tasktreeinsert(p2, p->rc);
            p->rc=NULL;
            tasktreeinsert(p1, p);
            break;
        }else if(p->lcnt>k){//if the current node as more than the nodes needed, lower its lcnt and go left
            temp=p->lc;
            p->lc=NULL;
            p->lcnt=0;
            tasktreeinsert(p2,p);
            p=temp;
        }else{//if the current node has less than the needed nodes, add the left tree, lower the lcnt and go right
            k-=(p->lcnt)+1;
            temp=p->rc;
            p->rc=NULL;
            tasktreeinsert(p1,p);
            p=temp;        
        }    
    }

    //if p2 exists, dont add him to the tree and return
    if(p2exists){
        print_double_tree();
        return 1;
    }

    //if he doesnt exist add him to the tree
    if(players_tree->is_alien==-1){
        players_tree=p2;
    }else{
        struct Player *itter=players_tree;
        while(itter){
            if(itter->pid>p2->pid){
                if(itter->lc->is_alien==-1){
                    p2->parent=itter;
                    itter->lc=p2;
                    break;
                }
                itter=itter->lc;
            }else{
                if(itter->rc->is_alien==-1){
                    p2->parent=itter;
                    itter->rc=p2;
                    break;
                }
                itter=itter->rc;
            }
        }
    }
    print_double_tree();
    return 1;
}

//a helping funcction for calculating the remaining team players
int countplayers(struct Player *tree){
    if(!tree || tree->is_alien==-1){return 0;}
    countplayers(tree->lc);
    if(tree->is_alien==1){curralien++;}
    else if(tree->is_alien==0){currcrew++;}
    countplayers(tree->rc);
    return 1;
}

/**
 * @brief Terminate
 *
 * @return 1 on success
 *         0 on failure
 */
int terminate() {
    currcrew=0;
    curralien=0;
    if(!countplayers(players_tree)){return 0;}
    
    printf("aliens=%d, crew=%d\n",curralien,currcrew);

    if(curralien>currcrew){
        printf("Aliens win.\n");
        return 1;
    }else if(curralien==0 || completed_tasks_pq->size==max_tasks_g){
        printf("Crewmates win\n");
        return 1;
    }


    return 0;
}

/**
 * @brief Print Players
 *
 * @return 1 on success
 *         0 on failure
 */
int print_players() {
    printf("Players = ");
    print_players_rec(players_tree);
    printf("\n");
    return 1;
}

//a helping function printing the player tree inorder
void print_players_rec(struct Player *tree){
    if(tree->is_alien==-1){return;}
    print_players_rec(tree->lc);
    // printf("<%d:%d> (lc:%d,rc=%d)",tree->pid, tree->is_alien,tree->lc->pid,tree->rc->pid);
    printf("<%d:%d>",tree->pid, tree->is_alien);
    print_players_rec(tree->rc);
}

/**
 * @brief Print Tasks
 *
 * @return 1 on success
 *         0 on failure
 */
int print_tasks() {
    struct HT_Task *itter;
    for(int i=0;i<max_tasks_g;i++){
        printf("Chain %d: ",i);
        itter=general_tasks_ht->tasks[i];
        while(itter!=NULL){
            printf("<%d,%d>",itter->tid,itter->difficulty);
            itter=itter->next;
        }
        printf("\n");
    }
    return 1;
}

/**
 * @brief Print Priority Queue
 *
 * @return 1 on success
 *         0 on failure
 */
int print_pq() {
    printf("Completed Tasks= ");
    for(int i=0;i<completed_tasks_pq->size;i++){
        printf("<%d,%d>",completed_tasks_pq->tasks[i]->tid,completed_tasks_pq->tasks[i]->difficulty);
    }
    printf("\n");
    return 1;
}

/**
 * @brief Print Players & Task tree
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_tree() {
    print_dl_players(players_tree);
    return 1;
}

void print_double_evidence_tree(){
    print_dl_evidence_players(players_tree);
}

//a helping function for print_double_evidence_tree() reading the player tree inorder
void print_dl_evidence_players(struct Player *tree){
    if(tree->is_alien==-1){return;}
    print_dl_evidence_players(tree->lc);
    printf("<Player %d, %d>=",tree->pid,tree->evidence);
    print_dl_tasks(tree->tasks);
    printf("\n");
    print_dl_evidence_players(tree->rc);
}

//a helping function for print_double_tree() reading the player tree inorder
void print_dl_players(struct Player *tree){
    if(tree->is_alien==-1){return;}
    print_dl_players(tree->lc);
    printf("Player %d=",tree->pid);
    print_dl_tasks(tree->tasks);
    printf("\n");
    print_dl_players(tree->rc);
}

//a helping function for print_dl_players() reading the tasks tree of each player inorder
void print_dl_tasks(struct Task *tree){
    if(tree==NULL){return;}
    print_dl_tasks(tree->lc);
    printf("<%d,%d>",tree->tid, tree->difficulty);
    print_dl_tasks(tree->rc);
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */

int free_all(void) {
    return 1;
}