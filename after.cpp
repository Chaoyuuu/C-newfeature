#include<iostream>
#include<cstdio>
template<typename T>
void testFunc(T) = delete;
using namespace std;
void testFunc(int Val);

int main(){
        printf("Input: \n");
        int i;
        int input;
        float input_f;
        scanf("%d",&i);
        if( i == 1){
                scanf("%d",&input);
                testFunc(input);
        }
        else{
                scanf("%f",&input_f);
                testFunc(input_f);
        }
}
void testFunc(int Val){
        printf("Hello\n");
        printf("%d\n",Val);
}

