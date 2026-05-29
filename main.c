/* 
  파일이름: main.c
  작 성 자: 장대한
  하 는 일: 이용자의 정보를 받은 BMI 계산과 예상 기초대사량(BMR) 계산
*/

#include <stdio.h>

double bmicalculate(double weight, double height)
{
  double height_m;
  height_m = height / 100.0;
  return weight / (height_m * height_m);
}

double bmrcalculate(double weight,double height,int age)
{
  return 10 * weight + 6.25 * height - 5 * age;
}

void printfinal(char name[], char gender, int age)
{
  printf("\n--- %s님의 분석 결과입니다. ---\n\n", name);
  printf("성별: %c / 나이: %d\n", gender, age);
}

void printbmi(double bmi)
{
  printf("현재 BMI 지수: %.2f\n", bmi);
}

double genderbmr(char gender, double bmr)
{
  if(gender == 'M')
  {
    bmr = bmr + 5;
  }
  else if(gender =='W')
  {
    bmr = bmr - 161;
  }
  else
  {
    printf("잘못된 성별을 입력하셨습니다. BMR 값을 0으로 처리합니다.");
    bmr = 0;
  }

  return bmr;
}

void printbmr(double bmr)
{
  printf("현재 예상 BMR(기초대사량) 지수: %.2fkcal\n", bmr);
}

int main() {

  char name[20]; //이용자의 이름
  int age; //나이
  char gender; //성별
  double height, weight, bmi, bmr; //처음부터 키, 몸무게, BMI, BMR
  int choice;

  printf("--- 안녕하세요 BMI, BMR 계산기입니다. ---\n");
  printf("당신의 이름은 무엇입니까? : ");
  scanf("%s", name);
  printf("당신의 성별은 무엇인가요?(M/W로 입력해주세요) : ");
  scanf(" %c", &gender);
  printf("나이, 키(cm), 몸무게(kg)를 순서대로 입력해주세요. : ");
  scanf("%d %lf %lf", &age, &height, &weight);

  printf("무엇을 하고 싶으신가요? :\n");
  printf("1. BMI 계산\t2. BMR(기초대사량) 계산\t 3. BMI,BMR(기초대사량) 동시 계산\t 4.종료\n");
  scanf("%d", &choice);

  if(age <= 0 || height <= 0 || weight <= 0)
  {
    printf("비정상적인 수치가 감지되어 프로그램이 종료됩니다.");
    return 0;
  }


  switch(choice)
  {
    case 1:
      printf("BMI 계산을 선택하였습니다.");
      bmi = bmicalculate(weight, height);
      printfinal(name, gender, age);
      printbmi(bmi);
      if(bmi >= 25.0)
      {
        printf("\n표준 BMI지수보다 수치가 높습니다. 약간의 운동을 추천합니다. \n\n");
      }
      break;
    
    case 2:
      printf("BMR(기초대사량) 계산을 선택하였습니다.");
      bmr = bmrcalculate(weight, height, age);
      bmr = genderbmr(gender, bmr);
      printfinal(name, gender, age);
      printbmr(bmr);
      break;

    case 3:
      printf("BMI, BMR(기초대사량) 동시 계산을 선택하셨습니다.");
      bmi = bmicalculate(weight, height);
      bmr = bmrcalculate(weight, height, age);
      bmr = genderbmr(gender, bmr);
      printfinal(name, gender, age);
      printbmi(bmi);
      if(bmi >= 25.0)
      {
        printf("\n표준 BMI지수보다 수치가 높습니다. 약간의 운동을 추천합니다. \n\n");
      }
      printbmr(bmr);
      break;


    case 4:
      printf("프로그램을 종료합니다.");
      break;

    default:
      printf("올바르지 않은 번호입니다. 프로그램을 종료합니다.");
      break;


    
    
  }

  return 0;
}
