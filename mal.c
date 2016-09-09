char memory[10];
 
void initMemory(){
     
    int i=0;
    for(i=0; i < 10; i++){
        memory[i] ='s';
    }
}
 
void* malloc_t(int size){
 
    int i=0;
    int crtSize = 0;
    for(i=0; i < 10; i++){
        if(memory[i] == '?'){
            if(crtSize == size){
                return &memory[i-size];
            }
            crtSize++;
             
        }else{
            crtSize = 0;
        }
    }
}
 
int main(void){
 
    initMemory();
    char *string = (char*)malloc_t(5 * sizeof(char));
    //strcpy(string,"test\0");
    string = "test";
    printf("string: %s\n", string);
     
    int i=0;
    for(; i < 10; ++i){
        printf("char: %c\n", memory[i]);
    }
    return 0;
}
