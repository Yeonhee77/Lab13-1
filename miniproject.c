#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"miniproject.h"

void readMenu(){
printf("1.식당추가\
\n2.식당조회\
\n3.식당업데이트\
\n4.식당삭제\
\n5.리스트 정렬(이름)\
\n6.리스트 정렬(가격)\
\n7.식당 추천\
\n8.Save\
\n9.Load\
\n10.검색\
\n0.종료!\n");
}


int addData(Restaurant **s){
*s = (Restaurant *)malloc(sizeof(Restaurant));
printf("식당의 이름을 입력해주세요!\n");
char enter;
enter = getchar();

scanf("%[^\n]s",(*s)->name);

do{
printf("식당 음식의 평균가격을 입력해주세요!\n");
scanf("%d",&(*s)->price);
if((*s)->price<=0) printf("잘못된 입력입니다! 다시 입력해주세요!\n");

}while((*s)->price<=0);

do{
printf("식당의 평점을 입력해주세요!(0~5까지! 소수점 입력가능!)\n");
scanf("%f",&(*s)->reputation);
if((*s)->reputation>5||(*s)->reputation<0) printf("다시 입력해주세요!\n");
}while((*s)->reputation>5||(*s)->reputation<0);

printf("식당이 목록에 추가가 되었습니다!\n\n");
return 1;

}

void listRes(Restaurant *s[], int count){
if (count == 0) {printf("데이터가 없습니다!!\n\n");return;}

printf("No.	이름	가격	평점\n");
for(int i = 0 ; i < count; i++){
printf("%d %15s   %d원	%5.1f점\n",i+1,s[i]->name,s[i]->price,s[i]->reputation);
}
printf("\n");
}

int updateData(Restaurant *s[], int count){
if(count == 0) {printf("데이터가 없습니다!\n\n");return 0;}

listRes(s,count);
int select;
printf("수정할 식당의 번호를 입력해주세요!\n");

do{
scanf("%d",&select);
if(select<1 || select > count) printf("잘못된 입력입니다!다시 입력해주세요!\n");
}while(select<1 || select> count);

int select_u;

do{
printf("어떤 것을 수정합니까?\n 1.이름 2.가격 3.평점 4.전부 5.메인메뉴로\n");
scanf("%d",&select_u);
if(select_u ==1){
char enter;
enter = getchar();
printf("가게의 새 이름을 입력해주세요!\n");
scanf("%[^\n]s",s[select-1]->name);
printf("수정완료!\n");
}


else if(select_u == 2){
printf("가게의 새 평균가격을 입력해주세요!\n");
do{
scanf("%d",&s[select-1]->price);
if(s[select-1]->price<0){
printf("잘못된 입력입니다! 다시 입력해주세요!\n");
}
}while(s[select-1]->price<0);
printf("수정완료!\n");
}

else if(select_u == 3){
printf("식당의 새 평점을 입력해주세요!\n");
do{
scanf("%f",&s[select-1]->reputation);
if(s[select-1]->reputation<0||s[select-1]->reputation>5){
printf("잘못된 입력입니다! 다시 입력해주세요!\n");
}
}while(s[select-1]->reputation<0||s[select-1]->reputation>5);
printf("수정완료!\n");
}

else if(select_u == 4){

char enter;
enter = getchar();
printf("가게의 새 이름을 입력해주세요!\n");
scanf("%[^\n]s",s[select-1]->name);

printf("가게의 새 평균가격을 입력해주세요!\n");
do{
scanf("%d",&s[select-1]->price);
if(s[select-1]->price<0){
printf("잘못된 입력입니다! 다시 입력해주세요!\n");
}
}while(s[select-1]->price<0);

printf("식당의 새 평점을 입력해주세요!\n");
do{
scanf("%f",&s[select-1]->reputation);
if(s[select-1]->reputation<0||s[select-1]->reputation>5){
printf("잘못된 입력입니다! 다시 입력해주세요!\n");
}
}while(s[select-1]->reputation<0||s[select-1]->reputation>5);

printf("수정완료!\n");

}


else if(select_u == 5)break;

else	printf("잘못된 번호입니다!\n");

}while(select_u!=5);
}



int deleteData(Restaurant *s[], int count){

if(count == 0){
printf("데이터가 없습니다!\n");
return 0;
}
listRes(s,count);
printf("삭제하고싶은 데이터를 선택해주세요!\n");

int select;
do{
scanf("%d",&select);
if(select<0||select>count){
printf("다시입력해주세요!\n");
}

}while(select<0||select>count);
int i;
for( i = select-1; i < count; i++){
if(i == count -1)break;
strcpy(s[i]->name,s[i+1]->name);
s[i]->price = s[i+1]->price;
s[i]->reputation = s[i+1]->reputation;
}
//free(s[count-1]->name);
free(s[count-1]);
return 1;
}

void sortName(Restaurant *s[], int count) {
Restaurant *temp;

for(int i=0;i<count;i++) {
	for(int j=i+1;j<count;j++) {
	if(strcmp(s[i]->name, s[j]->name)>0) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	}
}

printf("정렬이 완료되었습니다.\n\n");
}

void sortPrice(Restaurant *s[], int count) {
Restaurant *temp;

for(int i=0;i<count;i++) {
	for(int j=i+1;j<count;j++) {
	if((s[i]->price)>(s[j]->price)) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	}
}
printf("정렬이 완료되었습니다.\n\n");
}


void recommand(Restaurant *s[], int count) {

srand(time(NULL));

if(count>0) {
	int num = rand() % count ;
	printf("오늘은 %s 어때요???\n\n", s[num]->name);
	printf("이름 : %s, 가격 : %d, 평점: %.1f\n",s[num]->name,s[num]->price,s[num]->reputation);
}else{
printf("데이터가 없습니다!!\n\n");
}
}

void SaveData(Restaurant *s[],int count){
if(count == 0) {printf("데이터 없음!\n\n");return;}
FILE *fp = fopen("Restaurant_Data.txt","wt");
for(int i = 0 ; i < count; i++){
fprintf(fp,"%d %f %s\n",s[i]->price,s[i]->reputation,s[i]->name);
}
printf("저장완료!\n\n");
fclose(fp);
}



int loadData(Restaurant *s[]){
FILE *fp = fopen("Restaurant_Data.txt","rt");
if(fp == NULL){
printf("파일이 없습니다!\n\n");return 0;}
int i = 0;
while(1){
s[i] = (Restaurant *)malloc(sizeof(Restaurant));
fscanf(fp,"%d %f %[^\n]s",&s[i]->price,&s[i]->reputation,s[i]->name);
if(feof(fp)!=0) break;
i++;
}
printf("Load 성공!!\n\n");
return i;
}

void SearchData(Restaurant *s[], int count) {
int search;

while(1){
printf("무엇으로 검색하시겠습니까? (1.이름 2.가격 3.평점 0.취소)\n");
scanf("%d", &search);

if(search==0) {
	printf("취소되었습니다.\n");
	break;
}else if(search==1){
	SearchName(s, count);
}else if(search==2) {
	SearchPrice(s, count);
}else if(search==3) {
	SearchReputation(s, count);
}
}
}

void SearchName(Restaurant *s[], int count){
printf("찾고자 하는 식당의 이름을 입력해주세요!\n");
int y_n = 0;
char name[30];
int enter;
enter = getchar();
scanf("%[^\n]s",name);
printf("No.	이름	가격	평점\n");
for(int i = 0 ; i < count ; i++){
if(strstr(s[i]->name,name)){
printf("%d %15s %d원	%.1f점\n",i+1,s[i]->name,s[i]->price,s[i]->reputation);
y_n += 1;
}
}
if(y_n == 0) printf("%s의 검색결과가 없습니다!\n",name);
printf("\n");
}

void SearchPrice(Restaurant *s[], int count) {
printf("찾고자 하는 가격을 입력해주세요!\n");
int search;
scanf("%d", &search);

int y_n=0;

for(int i=0;i<count;i++) {
if(search == s[i]->price) {
printf("%d %15s %d원	%.1f점\n", i+1, s[i]->name, s[i]->price, s[i]->reputation);
y_n++;
}
}

if(y_n==0) printf("검색한 가격의 식당이 없습니다!\n\n");
}

void SearchReputation(Restaurant *s[], int count) {
printf("찾고자 하는 평점을 입력해주세요!\n");
float search;
scanf("%f", &search);

int y_n=0;

for(int i=0;i<count;i++) {
if(search == s[i]->reputation) {
printf("%d %15s %d원	%.1f점\n", i+1, s[i]->name, s[i]->price, s[i]->reputation);
y_n++;
}
}

if(y_n==0) printf("검색한 평점의 식당이 없습니다!\n\n");

}




