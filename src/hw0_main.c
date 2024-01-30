#include <stdio.h>
#include <stdbool.h>
#define N 5

//print the board
void displayGame(const int* ruma) {
    for(int i=0; i<N;i++){ 
        printf("%d ", ruma[i]);
        if(i==3){
            printf("| %d",ruma[i+1]);
            break;
        }
    }

}

int promptUser(int *ruma){
    int index;
    printf("\nChoose a section (1-4): "); //starting game
    scanf("%d",&index);
    
    while (1>index || index > 4 || ruma[index-1] == 0) { //if input is invalid
        printf("Invalid choice. Choose a section (1-4): ");
        scanf("%d", &index);
    } 
    return index;
}

int updateBoard(int *ruma, int index, int *startSeedIndex) {
    int save = ruma[index - 1];
    ruma[index - 1] = 0;
    // printf("save%d",save);
    // printf("index%d ",index);
   
    int i=0;
    for ( i = index; i < N && save>1; i++) {
        ruma[i] += 1; 
        save -= 1;
    }
    // printf("save%d",save);
    //printf("index%d ",i);

    if (i > 4) {
        i = 0;
        while (save > 1) {
            ruma[i] += 1;
            save -= 1;
            // printf("p%d", ruma[i] += 1);
            // printf("save%d ", save -= 1);
            i += 1;
            //index = (index % 5) + 1;  // Fixed cyclic indexing
            if(save==1){
                break;
            }

        }
    }

    // // printf("save%d",save);
    // printf("!%d ",ruma[0]);
    // printf("%d ",ruma[1]);
    // printf("%d ",ruma[2]);
    // printf("%d! ",ruma[3]);
    // //displayGame(ruma);
    // printf("index%d ",i);
    
    
    // if (i == 4 && ruma[i]==7) {
    //     ruma[i] += 1;
    //     return 0;
    // } else 
    if(i == 4) {
        ruma[i] += 1;
        return 1;
    }else if (i<4 && ruma[i]!=0) {
        *startSeedIndex = i+1;
        ruma[i] += 1;
        return 2;  // Return 2 to indicate sowing seeds
        
    } else if (i<4 && ruma[i]==0) {
        *startSeedIndex = i+1;
        ruma[i] += 1;
        return 3;
    }
    
    
    return 0;
}



int main() {
    
    int ruma[N]= {2,2,2,2,0}; //starting board
    int startSeedIndex;
    displayGame(ruma);
    int choice = promptUser(ruma);

   

    /*
    update the ruma board
    if last marble is at ruma return 1 check if ruma[4] is full
    if not ask again but if it is player wins
    if last marble falls in non ruma and has atleast one marble 
    return 2 and sow seeds
    if last marble lands on empty 0-3 then return 3 which is a lost
    */
 //bool flag= true;
 int result = updateBoard(ruma, choice, &startSeedIndex);
   while (result) {


        if (result == 1) {
            if (ruma[4]==8){
                printf("You won!\n");
                break;
            }
            displayGame(ruma);
            choice = promptUser(ruma);
            result = updateBoard(ruma, choice, &startSeedIndex);
            
        } else if (result == 2) {
           // flag = 1;
            displayGame(ruma);
            printf("\nLast piece landed in section %d. Continue sowing seeds!\n", startSeedIndex);
            result = updateBoard(ruma, startSeedIndex, &startSeedIndex);
           
            
        } else if (result == 3) {
           // flag = 0;
            displayGame(ruma);
            printf("\nYou lost because the last counter fell into section %d.\n",startSeedIndex);
            break;
            
        }
        
        

        
    }

    return 0;
    
}
