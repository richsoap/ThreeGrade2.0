WDTCN DATA 0FFH ;      
ORG 0000H ;    
AJMP START ;     
ORG 0100H ;    
START:
MOV WDTCN, #0DEH
MOV WDTCN, #0ADH ;         
MOV R0, #20H ;               
MOV DPTR, #CONST ;           
CLR A
MOVC A, @A+DPTR ;        
MOV R1, A ;      
CLR A
INC DPTR ; 1
MOVC A, @A+DPTR
MOV R2, A ;      
MOV DPTR, #0000H ;           1.3      5
MOVX A, @DPTR
ADD A, R1 ;    
DA A ;        
MOV @R0, A ;        (      @R0 @R1)
INC DPTR
INC R0 ;       1
MOVX A, @DPTR
ADDC A, R2 ;      
DA A ;        
MOV @R0, A ;    
INC R0
CLR A
MOV ACC.0, C ;          A    
MOV @R0, A ;       
SJMP $ ;    
CONST:
DW 1234H ;  
END