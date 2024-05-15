#include "PININIT.H"
#include "MKL25Z4.h"
int Columna[4] = {0,1,2,3};
int Salida[4] = {4,5,6,7};
char SC[4][4] = { 
                {'1','2','3','A'},
                {'4','5','6','B'},
                {'7','8','9','C'},
                {'*','0','#','D'},
                };
void INIT(char puerto){
    char P = toupper(puerto);
    switch (P){
        case 'A':
        SIM -> SCGC5|=SIM_SCGC5_PORTA_MASK;
        for(int i = 0; i < 4;i++){
            PORTA -> PCR[Columna[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;           
            PORTA -> PCR[Salida[i]]|=PORT_PCR_MUX(1);
            PTA -> PSOR|=(1u << i);
        }
        break;
        case 'B':
        SIM -> SCGC5|=SIM_SCGC5_PORTB_MASK;
         for(int i = 0; i < 4;i++){
            PORTB -> PCR[Columna[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;           
            PORTB -> PCR[Salida[i]]|=PORT_PCR_MUX(1);
            PTB -> PSOR|=(1u << i);
        }
        break;
        case 'C':
        SIM -> SCGC5|=SIM_SCGC5_PORTC_MASK;
         for(int i = 0; i < 4;i++){
            PORTC -> PCR[Columna[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;           
            PORTC -> PCR[Salida[i]]|=PORT_PCR_MUX(1);
            PTC -> PSOR|=(1u << i);
        }
        break;
        case 'D':
        SIM -> SCGC5|=SIM_SCGC5_PORTD_MASK;
        for(int i = 0; i < 4;i++){
            PORTD -> PCR[Columna[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;           
            PORTD -> PCR[Salida[i]]|=PORT_PCR_MUX(1);
            PTD -> PSOR|=(1u << i);
        }
        break;
        case 'E':
        SIM -> SCGC5|=SIM_SCGC5_PORTE_MASK;
        for(int i = 0; i < 4;i++){
            PORTE -> PCR[Columna[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;           
            PORTE -> PCR[Salida[i]]|=PORT_PCR_MUX(1);
            PTE -> PSOR|=(1u << i);
        }
        break;
    }
}
void KEYBOARD(char puerto){
    char P = toupper(puerto);
    switch (P){
        case'A':
        for(int i = 0;i < 4;i++){
        PTA -> PSOR|=(0u << Salida[i]);
        for(int j = 0;i < 4;i++){
            int estado = PTA -> PDIR&(1 << Columna[j]);
            if(estado == 0){
                return SC[i][j];
                } 
            }
            PTA -> PSOR|=(1u << Salida[i]);
        }
    break;
    case'B':
        for(int i = 0;i < 4;i++){
        PTB -> PSOR|=(0u << Salida[i]);
        for(int j = 0;i < 4;i++){
            int estado = PTB -> PDIR&(1 << Columna[j]);
            if(estado == 0){
                return SC[i][j];
                } 
            }
            PTB -> PSOR|=(1u << Salida[i]);
        }
    break;
    case'C':
        for(int i = 0;i < 4;i++){
        PTC -> PSOR|=(0u << Salida[i]);
        for(int j = 0;i < 4;i++){
            int estado = PTC -> PDIR&(1 << Columna[j]);
            if(estado == 0){
                return SC[i][j];
                } 
            }
            PTC -> PSOR|=(1u << Salida[i]);
        }
    break;
    case'D':
        for(int i = 0;i < 4;i++){
        PTD -> PSOR|=(0u << Salida[i]);
        for(int j = 0;i < 4;i++){
            int estado = PTD -> PDIR&(1 << Columna[j]);
            if(estado == 0){
                return SC[i][j];
                } 
            }
            PTD -> PSOR|=(1u << Salida[i]);
        }
    break;
    case'E':
        for(int i = 0;i < 4;i++){
        PTE -> PSOR|=(0u << Salida[i]);
        for(int j = 0;i < 4;i++){
            int estado = PTE -> PDIR&(1 << Columna[j]);
            if(estado == 0){
                return SC[i][j];
                } 
            }
            PTE -> PSOR|=(1u << Salida[i]);
        }
    break;
    }