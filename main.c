#include <stdio.h>
#include <string.h>

int main() {
    char str1[1000] = {};
    char word[16] = {};
    int words = 0;
    int num = 0;
    char c = 0;
    int count = 0;//������
    int numberRepetitions = 0;

    gets(str1);
    for (int i = 0;(c = str1[i]) != '\0';i++){
        if (c < 65 || (c > 90 && c < 97) || c > 122) words = 0;//�ж�Ҫ�Ż�,�����
        else if (words == 0){
            words = 1;
            num++;
        }
    }
    printf("����%d������\n����������ĵ��ʣ�",num);
    words = 0;
    scanf("%s",word);

    num = strlen(word);
    for (int i = 0;i < strlen(str1);){
        //�ж���ĸ�����Ƿ���ͬ
        for (int j = i;;j++){
            if ((str1[j] > 96 && str1[j] < 123) || (str1[j] > 64 && str1[j] < 91)){
                words++;
            }else if (words != num){
                i += ++words;
                words = 0;
                break;
            }else{//�ж��Ƿ���ͬ
                count = 0;
                for (int z = 0;z < num;z++){
                    if (word[z] != str1[i + z])break;
                    else count++;
                }
                i += ++words;
                words = 0;
                if (count != num) break;
                else numberRepetitions++;
        }
        }
        
    }
    printf("����\"%s\"�ظ�%d��",word,numberRepetitions);
    getchar();
    getchar();
    return 0;
}
