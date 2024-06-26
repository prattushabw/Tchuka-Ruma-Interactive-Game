#include <stdio.h>
#define N 5


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
   
    int i=0;
    for ( i = index; i < N && save>1; i++) {
        ruma[i] += 1; 
        save -= 1;
    }

    if (i > 4) {
        i = 0;
        while (save > 1) {
            ruma[i] += 1;
            save -= 1;
            i += 1;
            if(save==1){
                break;
            }

        }
    }

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
            displayGame(ruma);
            printf("\nLast piece landed in section %d. Continue sowing seeds!\n", startSeedIndex);
            result = updateBoard(ruma, startSeedIndex, &startSeedIndex);   
        } else if (result == 3) {
            displayGame(ruma);
            printf("\nYou lost because the last counter fell into section %d.\n",startSeedIndex);
            break;   
        }
 
    }

    return 0;    
}
