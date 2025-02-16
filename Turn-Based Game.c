//Xander Jay C. Cagang
//1BSCS: CMSC 18(G)
//Laboratory Exercise 7 - Turn-Based Battle Game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main() {
    
//Coin Toss
srand(time(NULL));
int cointoss = rand() % (2 - 1 + 1) + 1;
int random_damage;

//Starting
char theme[3][10] = {"Android", "Alien", "Wizard"};
int fighter;
int maxHP;
int damage;

//Actions
int move, comp_move, actionStart;

//Rounds
int round = 1, maxRound = 50;


//Player HP
int P1_HP; //P1 is the player/user
int P2_HP; // P2 is the computer

//Store moves each round
int P1_moves[maxRound];
int P2_moves[maxRound];

//Store descriptions of the moves each round
char P1_moves_descriptions[maxRound][100];
char P2_moves_descriptions[maxRound][100];

//Starting info
printf("Welcome to the Turn-Based Battle Game!\n");
sleep(2);
printf("\n--GAME MECHANICS--\n");
printf("- A Player(you) and the Computer will play.\n");
printf("- Both takes turn in choosing moves.\n");
printf("- The game ends when the round limit is reached or a player reaches 0 HP.\n");
sleep(4);
printf("\nTime to play the Game! Have Fun!\n");
sleep(2);

//User chooses theme
do{
printf("Themes: (1) Androids, (2) Aliens, (3) Wizards \n");
    printf("Choose your fighter: ");
    scanf("%d", &fighter);
    
    if(fighter < 1 || fighter > 3)
    {
       printf("Please input only: 1, 2, or 3\n");
       while(getchar() != '\n');
    }
} while (fighter < 1 || fighter > 3);

//User chooses max HP
choose_HP:
printf("Choose Maximum HP (50-200): ");
    scanf("%d", &maxHP);

    if(maxHP < 50 || maxHP > 200) {
        printf("Please enter from 50 to 200 only.\n");
        goto choose_HP;
    } else

    P1_HP = maxHP;
    P2_HP = maxHP;

//User chooses max number of rounds
choose_maxRound:
printf("Choose maximum number of rounds (max = 50 rounds): ");
    scanf("%d", &maxRound);
    
    if(maxRound < 1 || maxRound > 50)
    {
        printf("Please enter from 1 to 50 only.\n");
        goto choose_maxRound;
    }

//Cointoss message
printf("\nCoin toss to determine who goes first...\n");
sleep(5);
if(cointoss == 1) {
    printf("\nCoin toss result: %d, PLAYER FIRST!!\n", cointoss);
    actionStart = 1;
} else {
    printf("\nCoin toss result: %d, COMPUTER FIRST!!\n", cointoss);
    actionStart = 2;
}
sleep(2);

//Game Conditions
printf("\n--GAME CONDITIONS--\n");
sleep(2);
//cointoss for which goes first
if(cointoss == 1) {
    printf("\n- PLAYER %s goes first!\n", theme[fighter - 1]);
    actionStart = 1;
} else {
    printf("\n- COMPUTER %s goes first!\n", theme[fighter - 1]);
    actionStart = 2;
}
printf("- Heroes chosen: %s\n", theme[fighter - 1]);
printf("- Maximum Health: %d hp\n", maxHP);
printf("- Maximum Rounds: %d rounds\n", maxRound);
sleep(5);

//Game Instructions
printf("\n--GAME INSTRUCTIONS--\n");
sleep(2);
printf("\nMove choices: (1) Attack (2) Defend (3)Heal (4) Ultimate\n");
sleep(2);
printf("- | Attack | deals a random damage points from 0 to 5.\n");
sleep(1);
printf("- | Defend | reduces the damage of an incoming attack by 2 points.\n");
sleep(1);
printf("- |  Heal  | Increases health points by 2.\n");
sleep(1);
printf("- |Ultimate| Special action based on the theme.\n");
sleep(1);
printf("     + (Android) Reactor Beam - Hits a critical damage of 5 - 10 points but reduces health by 2 points.\n");
sleep(1);
printf("     + (Alien) Life Grab - Grabs 5 HP for itself from the enemy.\n");
sleep(1);
printf("     + (Wizard) Supreme Spell - Has a 50%% chance of dealing double a normal attack damage, and a 50%% chance of it failing dealing 0 damage.\n");
sleep(6);

//Game proper starts
printf("\n+++++++++++++++++++++ Game Start! +++++++++++++++++++++\n");
sleep(3);
    while(round <= maxRound)
    {
        
        printf("\n<----------> Round %d! <---------->\n", round);
        sleep(2);
    
        //User starts first
            
            if (actionStart == 1) 
            {
                //User's move
                printf("\n<> PLAYER %s's Move <>\n", theme[fighter - 1]);
                printf("Choose a move: ");
                scanf("%d", &move);
                sleep(1);
                P1_moves[round - 1] = move;
                
                    switch(move)
                    {
                        case 1: 
                            //Random damage
                            random_damage = rand() % (5 - 0 + 1) + 0;
                            damage = random_damage;
                            snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]), "PLAYER %s attacked with %d damage points!\n", theme[fighter - 1], damage);
                            printf("%s", P1_moves_descriptions[round - 1]);
                            sleep(1);
                            if(comp_move == 2)
                            {
                                printf("COMPUTER %s defended, -3 attack damage.\n", theme[fighter - 1]);
                                sleep(1);
                                damage -= 3;
                                if(damage <= 0)
                                {
                                    damage = 0;
                                }
                            }
                                P2_HP -= damage;
                                printf("COMPUTER %s's health is now %d.\n", theme[fighter - 1], P2_HP);
                                sleep(1);
                                if(P2_HP < 0) P2_HP = 0;
                            break;
                        case 2:
                            snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]), "PLAYER %s defends!\n", theme[fighter - 1]);
                            printf("%s", P1_moves_descriptions[round - 1]);
                            sleep(1);
                            break;
                        case 3:
                            P1_HP += 2;
                            if(P1_HP > maxHP) P1_HP = maxHP;
                            snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]), "PLAYER %s healed itself!\n", theme[fighter - 1]);
                            printf("%s\n", P1_moves_descriptions[round - 1]);
                            sleep(1);
                            printf("PLAYER %s's health is now %d.\n", theme[fighter - 1], P1_HP);
                            sleep(1);
                            break;
                        case 4:
                            switch(fighter)
                            {
                                case 1: //for android
                                    random_damage = rand() % (10 - 5 + 1) + 5;
                                    damage = random_damage;
                                    P1_HP -= 2; 
                                    snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]), "PLAYER %s used REACTOR BEAM with %d damage points, but lost 2 HP.\n", theme[fighter - 1], damage);
                                    printf("%s", P1_moves_descriptions[round - 1]);
                                    sleep(1);
                                    P2_HP -= damage;
                                    printf("COMPUTER %s's health is now %d.\n", theme[fighter - 1], P2_HP);
                                    sleep(1);
                                if(P2_HP < 0) P2_HP = 0;
                                break;
                                case 2: //for alien
                                    damage = 5;
                                    P2_HP -= damage;
                                    P1_HP += damage;
                                    if (P1_HP > maxHP) P1_HP = maxHP;
                                    if (P2_HP < 0) P2_HP = 0;
                                    snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]), "PLAYER %s used LIFE GRAB! Grabbing %d HP from its enemy and harnessed it!\n", theme[fighter - 1], damage);
                                    printf("%s", P1_moves_descriptions[round - 1]);
                                    sleep(1);
                                    printf("PLAYER %s's health is now %d.\n", theme[fighter - 1], P1_HP);
                                    printf("COMPUTER %s's health is now %d.\n", theme[fighter - 1], P2_HP);
                                    sleep(1);
                                    break;
                                case 3: //for wizard
                                    if ((rand() % (2 - 1 + 1) + 1) == 1) 
                                    {  
                                    random_damage = rand() % (5 - 0 + 1) + 0;  
                                    damage = random_damage * 2;  
                                    snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]),
                                             "PLAYER %s casts SUPREME SPELL for a whopping %d points of damage!\n", theme[fighter - 1], damage);
                                    } else 
                                    {  
                                    damage = 0;
                                    snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]), "PLAYER %s's SUPREME SPELL failed, dealing no damage at all.\n", theme[fighter - 1]);
                                    }
                                    printf("%s", P1_moves_descriptions[round - 1]);
                                    sleep(1);
                                    P2_HP -= damage;
                                    if (P2_HP < 0) P2_HP = 0;
                                        printf("COMPUTER %s's health is now %d.\n", theme[fighter - 1], P2_HP);
                                        sleep(1);
                                break;
                                
                                default:
                                break;   
                            }
                            default:
                            break;
                    }
            
                //Computer's move
                printf("\n<> COMPUTER %s's Move <>\n", theme[fighter - 1]);
                sleep(1);
                comp_move = rand() % (4 - 1 + 1) + 1;
                P2_moves[round - 1] = comp_move;
                
                    switch(comp_move)
                    {
                        case 1: 
                            //Random damage
                            random_damage = rand() % (5 - 0 + 1) + 0;
                            damage = random_damage;
                            snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]), "COMPUTER %s attacked with %d damage points!\n", theme[fighter - 1], damage);
                            printf("%s", P2_moves_descriptions[round - 1]);
                            sleep(1);
                            if(move == 2)
                            {
                                printf("PLAYER %s defended, -3 attack damage.\n", theme[fighter - 1]);
                                sleep(1);
                                damage -= 3;
                                if(damage <= 0)
                                {
                                    damage = 0;
                                }
                            }
                            P1_HP -= damage;
                            printf("PLAYER %s's health is now %d.\n", theme[fighter - 1], P1_HP);
                            sleep(1);
                            if(P1_HP < 0) P1_HP = 0;
                            break;
                        case 2:
                            P1_HP = P1_HP;
                            snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]), "COMPUTER %s defends!\n", theme[fighter - 1]);
                            printf("%s", P2_moves_descriptions[round - 1]);
                            sleep(1);
                            break;
                        case 3:
                            P2_HP += 2;
                            if (P2_HP > maxHP) P2_HP = maxHP;
                            snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]), "COMPUTER %s healed itself!\n", theme[fighter - 1]);
                            printf("%s", P2_moves_descriptions[round - 1]);
                            sleep(1);
                            printf("COMPUTER %s's health is now %d.\n", theme[fighter - 1], P2_HP);
                            sleep(1);
                            break;
                        case 4: 
                            switch(fighter)
                            {
                                case 1: //for android
                                    random_damage = rand() % (10 - 5 + 1) + 5;
                                    damage = random_damage;
                                    P2_HP -= 2; 
                                    snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]), "COMPUTER %s used REACTOR BEAM with %d damage points, but lost 2 HP.\n", theme[fighter - 1], damage);
                                    printf("%s", P2_moves_descriptions[round - 1]);
                                    sleep(1);
                                    P1_HP -= damage;
                                    printf("PLAYER %s's health is now %d.\n", theme[fighter - 1], P1_HP);
                                    sleep(1);
                                    if(P1_HP < 0) P1_HP = 0;
                                    break;
                                case 2: //for alien
                                    damage = 5;
                                    P1_HP -= damage;
                                    P2_HP += damage;
                                    if (P2_HP > maxHP) P2_HP = maxHP;
                                    if (P1_HP < 0) P1_HP = 0;
                                    snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]), "COMPUTER %s used LIFE GRAB! Grabbing %d HP from its enemy and harnessed it!\n", theme[fighter - 1], damage);
                                    printf("%s", P2_moves_descriptions[round - 1]);
                                    sleep(1);
                                    printf("PLAYER %s's health is now %d.\n", theme[fighter - 1], P1_HP);
                                    printf("COMPUTER %s's health is now %d.\n", theme[fighter - 1], P2_HP);
                                    sleep(1);
                                    break;
                                case 3: //for wizard
                                    if ((rand() % (2 - 1 + 1) + 1) == 1) 
                                    { 
                                    random_damage = rand() % (5 - 0 + 1) + 0;  
                                    damage = random_damage * 2;  
                                    snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]),
                                             "COMPUTER %s casts SUPREME SPELL for a whopping %d points of damage!\n", theme[fighter - 1], damage);
                                    } else 
                                    {
                                        damage = 0;
                                        snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]), "COMPUTER %s's SUPREME SPELL failed, dealing no damage at all.\n", theme[fighter - 1]);
                                    }
                                        printf("%s", P2_moves_descriptions[round - 1]);
                                        sleep(1);
                                        P1_HP -= damage;
                                    if (P1_HP < 0) P1_HP = 0;
                                        printf("PLAYER %s's health is now %d.\n", theme[fighter - 1], P1_HP);
                                        sleep(1);
                                    break;
                                
                                    default:
                                    break;       
                            }
                            default:
                            break;
                    }
                sleep(1);    
                printf("\nPLAYER %s's current health: %d!\n", theme[fighter - 1], P1_HP);
                printf("COMPUTER %s's current health: %d!\n", theme[fighter - 1], P2_HP);
                sleep(1);
            }
    
        //Computer starts first
                
            else 
            {
                //Computer's move
                printf("<> COMPUTER %s's Move <>\n", theme[fighter - 1]);
                sleep(1);
                comp_move = rand() % (4 - 1 + 1) + 1;
                P2_moves[round - 1] = comp_move;
                
                    switch(comp_move)
                    {
                        case 1: 
                            //Random damage
                            random_damage = rand() % (5 - 0 + 1) + 0;
                            damage = random_damage;
                            snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]), "COMPUTER %s attacked with %d damage points!\n", theme[fighter - 1], damage);
                            printf("%s", P2_moves_descriptions[round - 1]);
                            sleep(1);
                            if(move == 2)
                            {
                                printf("PLAYER %s defended, -3 attack damage.\n", theme[fighter - 1]);
                                sleep(1);
                                damage -= 3;
                                if(damage <= 0)
                                {
                                    damage = 0;
                                }
                            }
                            P1_HP -= damage;
                            printf("PLAYER %s's health is now %d.\n", theme[fighter - 1], P1_HP);
                            sleep(1);
                            if (P1_HP < 0) P1_HP = 0;
                            break;
                        case 2:
                            snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]), "COMPUTER %s defends!\n", theme[fighter - 1]);
                            printf("%s", P2_moves_descriptions[round - 1]);
                            sleep(1);
                            break;
                        case 3:
                            P2_HP += 2;
                            if (P2_HP > maxHP) P2_HP = maxHP;
                            snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]), "COMPUTER %s healed itself!\n", theme[fighter - 1]);
                            printf("%s", P2_moves_descriptions[round - 1]);
                            sleep(1);
                            printf("COMPUTER %s's health is now %d.\n", theme[fighter - 1], P2_HP);
                            sleep(1);
                            break;
                        case 4: 
                            switch(fighter)
                            {
                                case 1: //for android
                                    random_damage = rand() % (10 - 5 + 1) + 5;
                                    damage = random_damage;
                                    P2_HP -= 2; 
                                    snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]), "COMPUTER %s used REACTOR BEAM with %d damage points, but lost 2 HP.\n", theme[fighter - 1], damage);
                                    printf("%s", P2_moves_descriptions[round - 1]);
                                    sleep(1);
                                    P1_HP -= damage;
                                    printf("PLAYER %s's health is now %d.\n", theme[fighter - 1], P1_HP);
                                    sleep(1);
                                    if(P1_HP < 0) P1_HP = 0;
                                    break;
                                case 2: //for alien
                                    damage = 5;
                                    P1_HP -= damage;
                                    P2_HP += damage;
                                    if (P2_HP > maxHP) P2_HP = maxHP;
                                    if (P1_HP < 0) P1_HP = 0;
                                    snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]), "COMPUTER %s used LIFE GRAB! Grabbing %d HP from its enemy and harnessed it!\n", theme[fighter - 1], damage);
                                    printf("%s", P2_moves_descriptions[round - 1]);
                                    sleep(1);
                                    printf("PLAYER %s's health is now %d.\n", theme[fighter - 1], P1_HP);
                                    printf("COMPUTER %s's health is now %d.\n", theme[fighter - 1], P2_HP);
                                    sleep(1);
                                    break;
                                case 3: //for wizard
                                    if ((rand() % (2 - 1 + 1) + 1) == 1) 
                                    { 
                                    random_damage = rand() % (5 - 0 + 1) + 0;  
                                    damage = random_damage * 2;  
                                    snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]),
                                             "COMPUTER %s casts SUPREME SPELL for a whopping %d points of damage!\n", theme[fighter - 1], damage);
                                    } else 
                                    {
                                        damage = 0;
                                        snprintf(P2_moves_descriptions[round - 1], sizeof(P2_moves_descriptions[round - 1]), "COMPUTER %s's SUPREME SPELL failed, dealing no damage at all.\n", theme[fighter - 1]);
                                    }
                                        printf("%s", P2_moves_descriptions[round - 1]);
                                        sleep(1);
                                        P1_HP -= damage;
                                    if (P1_HP < 0) P1_HP = 0;
                                        printf("PLAYER %s's health is now %d.\n", theme[fighter - 1], P1_HP);
                                        sleep(1);
                                    break;
                                
                                    default:
                                    break;       
                            }
                            default:
                            break;
                    }
            
                //User's move
                printf("\n<> PLAYER %s's Move <>\n", theme[fighter - 1]);
                printf("Choose a move: ");
                scanf("%d", &move);
                sleep(1);
                P1_moves[round - 1] = move;
                
                    switch(move)
                    {
                        case 1: 
                            //Random damage
                            random_damage = rand() % (5 - 0 + 1) + 0;
                            damage = random_damage;
                            snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]), "PLAYER %s attacked with %d damage points!\n", theme[fighter - 1], damage);
                            printf("%s", P1_moves_descriptions[round - 1]);
                            sleep(1);
                            if(comp_move == 2)
                            {
                                printf("COMPUTER %s defended, -3 attack damage.\n", theme[fighter - 1]);
                                sleep(1);
                                damage -= 3;
                                if(damage <= 0)
                                {
                                    damage = 0;
                                }
                            }    
                            P2_HP -= damage;
                            printf("COMPUTER %s's health is now %d.\n", theme[fighter - 1], P2_HP);
                            sleep(1);
                            if (P2_HP < 0) P2_HP = 0;
                            break;
                        case 2:
                            snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]), "PLAYER %s defends!\n", theme[fighter - 1]);
                            printf("%s", P1_moves_descriptions[round - 1]);
                            sleep(1);
                            break;
                        case 3:
                            P1_HP += 2;
                            if (P1_HP > maxHP) P1_HP = maxHP;
                            snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]), "PLAYER %s healed itself!\n", theme[fighter - 1]);
                            printf("%s", P1_moves_descriptions[round - 1]);
                            sleep(1);
                            printf("PLAYER %s's health is now %d.\n", theme[fighter - 1], P1_HP);
                            sleep(1);
                            break;
                        case 4:
                            switch(fighter)
                            {
                                case 1: //for android
                                    random_damage = rand() % (10 - 5 + 1) + 5;
                                    damage = random_damage;
                                    P1_HP -= 2; 
                                    snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]), "PLAYER %s used REACTOR BEAM with %d damage points, but lost 2 HP.\n", theme[fighter - 1], damage);
                                    printf("%s", P1_moves_descriptions[round - 1]);
                                    sleep(1);
                                    P2_HP -= damage;
                                    printf("COMPUTER %s's health is now %d.\n", theme[fighter - 1], P2_HP);
                                    sleep(1);
                                if(P2_HP < 0) P2_HP = 0;
                                break;
                                case 2: //for alien
                                    damage = 5;
                                    P2_HP -= damage;
                                    P1_HP += damage;
                                    if (P1_HP > maxHP) P1_HP = maxHP;
                                    if (P2_HP < 0) P2_HP = 0;
                                    snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]), "PLAYER %s used LIFE GRAB! Grabbing %d HP from its enemy and harnessed it!\n", theme[fighter - 1], damage);
                                    printf("%s", P1_moves_descriptions[round - 1]);
                                    sleep(1);
                                    printf("PLAYER %s's health is now %d.\n", theme[fighter - 1], P1_HP);
                                    printf("COMPUTER %s's health is now %d.\n", theme[fighter - 1], P2_HP);
                                    sleep(1);
                                    break;
                                case 3: //for wizard
                                    if ((rand() % (2 - 1 + 1) + 1) == 1) 
                                    {  
                                    random_damage = rand() % (5 - 0 + 1) + 0;  
                                    damage = random_damage * 2;  
                                    snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]),
                                             "PLAYER %s casts SUPREME SPELL for a whopping %d points of damage!\n", theme[fighter - 1], damage);
                                    } else 
                                    {  
                                    damage = 0;
                                    snprintf(P1_moves_descriptions[round - 1], sizeof(P1_moves_descriptions[round - 1]), "PLAYER %s's SUPREME SPELL failed, dealing no damage at all.\n", theme[fighter - 1]);
                                    }
                                    printf("%s", P1_moves_descriptions[round - 1]);
                                    sleep(1);
                                    P2_HP -= damage;
                                    if (P2_HP < 0) P2_HP = 0;
                                        printf("COMPUTER %s's health is now %d.\n", theme[fighter - 1], P2_HP);
                                        sleep(1);
                                break;
                                
                                default:
                                break;   
                            }
                            default:
                            break;
                    }
                sleep(1);    
                printf("\nPLAYER %s's current health: %d!\n", theme[fighter - 1], P1_HP);
                printf("COMPUTER %s's current health: %d!\n", theme[fighter - 1], P2_HP);
                sleep(2);
            }
            
            //check health
            if(P1_HP <= 0)
            {
                printf("\nGame Over! PLAYER %s with 0 HP left.\n", theme[fighter - 1]);
                sleep(1);
                printf("\nCOMPUTER %s wins! RAHHH!!!\n", theme[fighter - 1]);
                sleep(3);
                printf("\n+++++++++++++++++++++ Game End! +++++++++++++++++++++\n");
                sleep(5);
                break;
            }else if(P2_HP <= 0)
            {
                printf("\nGame Over! COMPUTER %s with 0 HP left.\n", theme[fighter - 1]);
                sleep(1);
                printf("\nPLAYER %s wins! RAHHH!!!!\n", theme[fighter - 1]);
                sleep(3);
                printf("\n+++++++++++++++++++++ Game End! +++++++++++++++++++++\n");
                sleep(5);
                break;
            }
        
            round++;
    }
    
    if(round > maxRound)
    {
        printf("\n ~~~~~ Round limit reached! ~~~~~");
        sleep(3);
        printf("\nPLAYER %s's FINAL health: %d!\n", theme[fighter - 1], P1_HP);
        printf("COMPUTER %s's FINAL health: %d!\n", theme[fighter - 1], P2_HP);
        sleep(3);
    if (P1_HP > P2_HP) {
            printf("\n===== PLAYER %s wins! RAHHH!!! =====\n", theme[fighter - 1]);
            sleep(1);
            printf("\n+++++++++++++++++++++ Game End! +++++++++++++++++++++\n");
            sleep(3);
        } else if (P2_HP > P1_HP) {
            printf("\n===== COMPUTER %s wins! RAHHHH!!! =====\n", theme[fighter - 1]);
            sleep(1);
            printf("\n+++++++++++++++++++++ Game End! +++++++++++++++++++++\n");
            sleep(3);
        } else {
            printf("===== It's a draw! =====\n");
            sleep(1);
            printf("\n+++++++++++++++++++++ Game End! +++++++++++++++++++++\n");
            sleep(3);
        }
    }
    
    printf("\n[] [] [] [] [] [] SUMMARY! [] [] [] [] [] []\n");
    sleep(3);
    int summaryRounds = (round > maxRound) ? maxRound : round;
    for(int i = 0; i < summaryRounds; i++)
    {
        printf("\n--Round #%d--\n", i + 1);
        sleep(1);
        printf("PLAYER %s chose %d!\n", theme[fighter - 1], P1_moves[i]);
        printf("PLAYER %s's move: %s", theme[fighter - 1], P1_moves_descriptions[i]);
        sleep(1);
        printf("COMPUTER %s chose %d!\n", theme[fighter - 1], P2_moves[i]);
        printf("COMPUTER %s's move: %s", theme[fighter - 1], P2_moves_descriptions[i]);
        sleep(3);
    }
    return 0;
}