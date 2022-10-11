// Fill out your copyright notice in the Description page of Project Settings.


#include "Question.h"
#include "Math/UnrealMathUtility.h"

void UQuestion::SetupQuestion(int32 num)
{
	QuestionNum = num;

	//Setup multiple or simple choice
	if (QuestionNum <= 5)
	{
		bIsMultipleChoice = true;
	}
	else
	{
		bIsMultipleChoice = false;
	}

	//Setup question data
	int x = CalculateX();
	int y = CalculateY();
	FString wallType;
	//TODO: Change value per question.
	Value = 10;
	switch (QuestionNum)
	{
	case 1:
		QuestionTxt = "Si el muro del nivel 1 mide " + FString::FromInt(x) + " m y el del nivel 2 mide " + FString::FromInt(y) +
			" m, ¿Es correcto que sólo haya una dala?";
		PossibleAnswers = "";
		ReferenceTxt = "5.1.1 b) Además, existirán dalas en el interior del muro a una separación no mayor que 3 m.";
		if (x + y < 6)
		{
			Answer = QuestionAnswer::No;
		}
		else
		{
			Answer = QuestionAnswer::Yes;
		}
		break;
	case 2:
		QuestionTxt = "Si la abertura de la derecha tiene una dimensión de " + FString::FromInt(x) + " cm y su estructura es de Tipo I"
			", ¿Es correcto que requiere un refuerzo ? ";
		PossibleAnswers = "";
		ReferenceTxt = "5.1.3 Existirán elementos de refuerzo con las mismas características que las dalas y castillos en el perímetro "
			"de toda abertura cuyas dimensiones horizontal o vertical excedan de 400 mm en estructuras Tipo I o 600 mm en estructuras Tipo II.";
		if (x > 40)
		{
			Answer = QuestionAnswer::Yes;
		}
		else
		{
			Answer = QuestionAnswer::No;
		}
		break;
	case 3:
		QuestionTxt = "Si la altura del pretil es de " + FString::FromInt(x) + " cm, ¿Es correcto que lleve una dala?";
		PossibleAnswers = "";
		ReferenceTxt = "5.1.1 b) Además, existirán dalas en la parte superior de pretiles o parapetos cuya altura sea superior a 500 mm.";
		if (x > 50)
		{
			Answer = QuestionAnswer::Yes;
		}
		else
		{
			Answer = QuestionAnswer::No;
		}
		break;
	case 4:
		if (x == 1)
		{
			wallType = "I";
			Answer = QuestionAnswer::Yes;
		}
		else
		{
			wallType = "II";
			Answer = QuestionAnswer::No;
		}
		QuestionTxt = "Si la estructura es de tipo " + wallType + ", ¿Es correcto que el espesor de los muros sea >= 11 cm?";
		PossibleAnswers = "";
		ReferenceTxt = "5.1.4 Espesor y relación altura a espesor de los muros\n En estructuras Tipo I, el espesor de los muros de "
			"mampostería, t, no será menor que 100 mm, ni que 120 mm en estructuras Tipo II.";
		break;
	case 5:
		QuestionTxt = "¿Es correcto que los castillos sólo van en los extremos de los muros?";
		PossibleAnswers = "";
		ReferenceTxt = "5.1.1 a) Existirán castillos por lo menos en los extremos de los muros e intersecciones con otros muros y en "
			"puntos intermedios del muro.";
		Answer = QuestionAnswer::No;
		break;
	case 6:
		QuestionTxt = "Si el muro mide " + FString::FromInt(x) + " m de longitud y la altura entrepiso es de " + FString::FromInt(y) +
			", ¿Cuántos castillos deberían de colocarse en los pretiles?";
		PossibleAnswers = "a.\t1\nb.\t2\nc.\t3\nd.\t4";
		ReferenceTxt = "5.1.1 a) Existirán castillos a una separación no mayor que 1.5 H(altura de entrepiso) ni 4 m. Los pretiles o "
			"parapetos deberán tener castillos con una separación no mayor que 4 m.";
		//TODO: Calculate answer;
		break;
	case 7:
		QuestionTxt = "Si el espesor del muro reforzado interiormente es de " + FString::FromInt(x) + " cm, ¿Cuánto tiene que medir la "
			"separación del refuerzo vertical en su interior?";
		PossibleAnswers = "a.\t80cm\nb.\t100cm\nc.\t" + FString::FromInt(x * 6) + " cm\nd.\t" + FString::FromInt(x) + " cm";
		ReferenceTxt = "6.1.2.1 Refuerzo vertical\nEl refuerzo vertical en el interior del muro tendrá una separación no mayor que "
			"seis veces el espesor del mismo ni mayor que 800 mm.";
		if (x * 6 < 80)
		{
			Answer = QuestionAnswer::C;
		}
		else
		{
			Answer = QuestionAnswer::A;
		}
		break;
	case 8:
		QuestionTxt = "Si la distancia entre los 2 muros reforzados interiormente es de " + FString::FromInt(x) + " m, ¿Cuántas barras de "
			"refuerzo se deberán colocar?";
		PossibleAnswers = "a.\t1\nb.\t" + FString::FromInt(x) + "\nc.\t" + FString::FromInt(x / 3 + 1) + "\nd.\t" + FString::FromInt(x / 3 + 2);
		ReferenceTxt = "6.1.2.2 Refuerzo en los extremos de muros\na) Deberá colocarse, por lo menos, una barra vertical o refuerzo con "
			"resistencia a tensión equivalente, en cada una de dos celdas consecutivas, en todo extremo de muros, en las intersecciones "
			"entre muros o a cada 3 m.";
		if (x % 3 == 0)
		{
			Answer = QuestionAnswer::C;
		}
		else
		{
			Answer = QuestionAnswer::D;
		}
		break;
	case 9:
		QuestionTxt = "¿Cuál sería el mejor material para el muro no estructural (divisorio) de esta zona?";
		PossibleAnswers = "a.\tTablaroca\nb.\tMampostería de roca\nc.\tMampostería de bloc de concreto\nd.\t Mampostería de tabique";
		ReferenceTxt = "7.1 Pueden ser de mampostería confinada (Capítulo 5), reforzada interiormente (Capítulo 6), o de otros materiales "
			"ligeros y cuya contribución a la resistencia y rigidez laterales sea poco significativa.";
		Answer = QuestionAnswer::A;
		break;
	case 10:
		QuestionTxt = "Si la dala tiene una longitud de " + FString::FromInt(x) + " cm sobre un muro de espesor " + FString::FromInt(y) +
			" cm, la separación de los estribos deberá ser menor o igual a:";
		PossibleAnswers = "a.\t50 cm\nb.\t20 cm\nc.\t" + FString::FromInt(x) + " cm\nd.\t" + FString::FromInt(y * 1.5) + " cm";
		ReferenceTxt = "5.1.1 g) La separación de los estribos, s, no excederá de 1.5t ni de 200 mm.";
		if (y * 1.5 < 20)
		{
			Answer = QuestionAnswer::D;
		}
		else
		{
			Answer = QuestionAnswer::B;
		}
		break;
	}
}

int32 UQuestion::CalculateX()
{
	int x = 0;
	int option;
	switch (QuestionNum)
	{
	case 1:
		x = FMath::RandRange(3, 6);
		break;
	case 2:
		x = FMath::RandRange(30, 60);
		break;
	case 3:
		x = FMath::RandRange(40, 75);
		break;
	case 4:
		x = FMath::RandRange(1, 2);
		break;
	case 6:
		x = FMath::RandRange(3, 12);
		break;
	case 7:
		option = FMath::RandRange(1, 3);
		x = option == 1 ? 10 : option == 2 ? 12 : 15;
		break;
	case 8:
		//TODO: calcular valores de pregunta 8
		break;
	case 10:
		x = FMath::RandRange(100, 300);
		break;
	}

	return x;
}

int32 UQuestion::CalculateY()
{
	int y = 0;
	int option;
	switch (QuestionNum)
	{
	case 1:
		y = FMath::RandRange(1, 6);
		break;
	case 10:
		option = FMath::RandRange(1, 3);
		y = option == 1 ? 10 : option == 2 ? 12 : 15;
		break;
	}

	return y;
}

