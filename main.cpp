#include <iostream>
#include <string>
#include "logic.hpp"

using namespace std;

int main() 
{
	setRussian();
	cout << "ЭЛЕМЕНТЫ СТРУКТУРЫ" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "1)Присваивание одного элемента структуры данных другому" << endl;
	cout << "----------------------------------------------------------------" << endl;

	ElementGraph* Graph1 = new ElementGraph("Кот", "Вислоухий", "Феликс", "Серо-черный", 8);
	ElementGraph* Graph2 = new ElementGraph("Собака", "Овчарка", "Рик", "Черный", 12);

	cout << "До:" << endl;
	cout << "{{firstGraph}}" << endl;
	cout << Graph1;
	cout << "{{secondGraph}}" << endl;
	cout << Graph2;

	Graph1 = Graph2;

	cout << "-----------------------------------------------------" << endl;
	cout << "После:" << endl;
	cout << "{{firstGraph}}" << endl;
	cout << Graph1;
	cout << "{{secondGraph}}" << endl;
	cout << Graph2;

	cout << "----------------------------------------------------------------" << endl;
	cout << "2)Сравнение на равенство структур данных" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "{{ == }}" << endl;

	ElementGraph* Graph3 = new ElementGraph("Кот", "Вислоухий", "Феликс", "Серо-черный", 8);
	ElementGraph* Graph4 = new ElementGraph("Кот", "Вислоухий", "Феликс", "Серо-черный", 8);

	cout << "{{ firstGraph }}" << endl;
	cout << Graph3 << endl;
	cout << "{{ secondGraph }}" << endl;
	cout << Graph4 << endl;

	if (*Graph3 == *Graph4)
	{
		cout << "Графы равны" << endl;
	}
	else
	{
		cout << "Графы не равны" << endl;
	}

	cout << "-----------------------------------------------------" << endl;
	cout << "{{ != }}" << endl;

	ElementGraph* Graph5 = new ElementGraph("Кот", "Вислоухий", "Феликс", "Серо-черный", 8);
	ElementGraph* Graph6 = new ElementGraph("Собака", "Овчарка", "Рик", "Черный", 12);

	cout << "{{ firstGraph }}" << endl;
	cout << Graph5 << endl;
	cout << "{{ secondGraph }}" << endl;
	cout << Graph6 << endl;

	if (*Graph5 != *Graph6)
	{
		cout << "Графы не равны" << endl;
	}
	else
	{
		cout << "Графы равны" << endl;
	}

	cout << "----------------------------------------------------------------" << endl;
	cout << "3)Cравнение элементов структуры данных" << endl;
	cout << "----------------------------------------------------------------" << endl;

	cout << "{{ < }}" << endl;

	ElementGraph* Graph7 = new ElementGraph("Кот", "Вислоухий", "Феликс", "Серо-черный", 8);
	ElementGraph* Graph8 = new ElementGraph("Собака", "Овчарка", "Рик", "Черный", 12);

	if (*Graph7 < *Graph8)
	{
		cout << "Граф с " << Graph7->getTypeAnimal() << " с весом " << Graph7->getWeight() << " меньше чем " <<
			"граф c " << Graph8->getTypeAnimal() << " с весом " << Graph8->getWeight() << endl;
	}

	cout << "-----------------------------------------------------" << endl;
	cout << "{{ <= }}" << endl;

	ElementGraph* Graph9 = new ElementGraph("Кот", "Вислоухий", "Феликс", "Серо-черный", 8);
	ElementGraph* Graph10 = new ElementGraph("Собака", "Овчарка", "Рик", "Черный", 12);

	if (*Graph9 <= *Graph10)
	{
		cout << "Граф с " << Graph9->getTypeAnimal() << " с весом " << Graph9->getWeight() << " меньше или равен чем " <<
			"граф c " << Graph10->getTypeAnimal() << " с весом " << Graph10->getWeight() << endl;
	}

	cout << "-----------------------------------------------------" << endl;
	cout << "{{ > }}" << endl;

	ElementGraph* Graph11 = new ElementGraph("Собака", "Вислоухий", "Феликс", "Серо-черный", 13);
	ElementGraph* Graph12 = new ElementGraph("Кот", "Овчарка", "Рик", "Черный", 10);

	if (*Graph11 > *Graph12)
	{
		cout << "Граф с " << Graph11->getTypeAnimal() << " с весом " << Graph11->getWeight() << " больше " <<
			"граф c " << Graph12->getTypeAnimal() << " с весом " << Graph12->getWeight() << endl;
	}

	cout << "-----------------------------------------------------" << endl;
	cout << "{{ >= }}" << endl;

	ElementGraph* Graph13 = new ElementGraph("Собака", "Вислоухий", "Феликс", "Серо-черный", 13);
	ElementGraph* Graph14 = new ElementGraph("Кот", "Овчарка", "Рик", "Черный", 10);

	if (*Graph13 >= *Graph14)
	{
		cout << "Граф с " << Graph13->getTypeAnimal() << " с весом " << Graph13->getWeight() << " больше или равен " <<
			"граф c " << Graph14->getTypeAnimal() << " с весом " << Graph14->getWeight() << endl;
	}

	cout << "----------------------------------------------------------------" << endl;
	cout << "4)Вывод в поток элементов структуры данных" << endl;
	cout << "----------------------------------------------------------------" << endl;

	ElementGraph* Graph15 = new ElementGraph("Кот", "Овчарка", "Рик", "Черный", 12);

	cout << Graph15 << endl;

	cout << "----------------------------------------------------------------" << endl;
	cout << "5)Ввод из потока элементов структуры данных" << endl;
	cout << "----------------------------------------------------------------" << endl;

	ElementGraph* Graph16 = new ElementGraph;

	cin >> Graph16;
	cout << Graph16 << endl;

	cout << "СТРУКТУРЫ ДАННЫХ" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "6)Присваивание одной структуры данных другой" << endl;
	cout << "----------------------------------------------------------------" << endl;

	Graphs* struct1 = new Graphs();
	Graphs* struct2 = new Graphs();

	struct2->create();
	struct2->addGraphTo(1);
	struct2->addGraphTo(1);
	struct2->addGraphTo(1);

	cout << "----------------------------------------------------------------" << endl;
	cout << "Количество элементов до присваивания 1 структуры: " << struct1->amountGraphs(struct1->getStart()) << endl;
	cout << "Количество элементов до присваивания 2 структуры: " << struct2->amountGraphs(struct2->getStart()) << endl;
	cout << "----------------------------------------------------------------" << endl;

	struct1 = struct2;

	cout << "Количество элементов после присваивания 1 структуры: " << struct1->amountGraphs(struct1->getStart()) << endl;
	cout << "Количество элементов после присваивания 2 структуры: " << struct2->amountGraphs(struct2->getStart()) << endl;

	cout << "----------------------------------------------------------------" << endl;
	cout << "7)Сравнение структур данных" << endl;
	cout << "----------------------------------------------------------------" << endl;

	Graphs* struct3 = new Graphs();
	Graphs* struct4 = new Graphs();

	//	 1
	//2	 3	4

	cout << "Создаем первый граф" << endl;

	struct3->create();
	struct3->addGraphTo(1);
	struct3->addGraphTo(1);
	struct3->addGraphTo(1);

	//	 1
	//2	 3  4
	//     5  6

	cout << "Создаем второй граф" << endl;
	struct4->create();
	struct4->addGraphTo(1);
	struct4->addGraphTo(1);
	struct4->addGraphTo(1);
	struct4->changePosition();
	struct4->addGraphTo(1);
	struct4->addGraphTo(1);

	if (*struct3 < *struct4)
	{
		cout << "Структура " << "{{ " << struct3 << " }}" << " меньше чем {{" << struct4 << "}}" << endl;
	}
	else if (*struct3 <= *struct4)
	{
		cout << "Структура " << "{{ " << struct3 << " }}" << " меньше или равна {{" << struct4 << "}}" << endl;
	}
	else if (*struct3 > *struct4)
	{
		cout << "Структура " << "{{ " << struct3 << " }}" << " больше чем {{" << struct4 << "}}" << endl;
	}
	else if (*struct3 >= *struct4)
	{
		cout << "Структура " << "{{ " << struct3 << " }}" << " больше или равна {{" << struct4 << "}}" << endl;
	}

	cout << "----------------------------------------------------------------" << endl;
	cout << "7)Cравнение на равенство структур данных" << endl;
	cout << "----------------------------------------------------------------" << endl;

	Graphs* struct5 = new Graphs();
	Graphs* struct6 = new Graphs();

	cout << "Создаем первый граф" << endl;
	struct5->create();
	struct5->addGraphTo(1);
	struct5->addGraphTo(1);

	cout << "Создаем второй граф" << endl;
	struct6->create();
	struct6->addGraphTo(1);

	if (*struct5 == *struct6)
	{
		cout << "Графы равны по весу между собой" << endl;
	}
	else if (*struct5 != *struct6)
	{
		cout << "Графы не равны между собой по весу" << endl;
	}
}
