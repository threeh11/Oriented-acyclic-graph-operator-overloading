#include <iostream>
#include <string>

using namespace std;

class ElementGraph
{
protected:
    string typeAnimal;
    string race;
    string name;
    string mainColor;
    int weight;

public:
    class ElementGraph* pointers[10];

    ElementGraph()
    {
        this->typeAnimal = "";
        this->race = "";
        this->name = "";
        this->mainColor = "";
        this->weight = 0;
    };

    ElementGraph(string typeAnimal,
                 string race,
                 string name,
                 string mainColor,
                 int weight);

    string getTypeAnimal() { return this->typeAnimal; };
    string getRace() { return this->race; };
    string getName() { return this->name; };
    string getMainColor() { return this->mainColor; };
    int getWeight() { return this->weight; };

    void setTypeAnimal(string typeAnimal) { this->typeAnimal = typeAnimal; }
    void setRace(string race) { this->race = race; }
    void setName(string name) { this->name = name; }
    void setMainColor(string mainColor) { this->mainColor = mainColor; }
    void setWeight(int weight) { this->weight = weight; }

    int getCountChildGraph();

    //����������
    // ������������ ������ �������� ��������� ������ �������
    ElementGraph* operator = (ElementGraph& graph);
    // ��������� �� ��������� ��������� ���������
    bool operator == (ElementGraph& graph);
    bool operator != (ElementGraph& grpah);
    // ��������� ��������� ��������� ������
    bool operator < (ElementGraph& graph);
    bool operator <= (ElementGraph& graph);
    bool operator > (ElementGraph& graph);
    bool operator >= (ElementGraph& graph);
    // ���� �� ������ ��������� ��������� ������
    friend std::istream& operator >> (std::istream& in, ElementGraph* graph);
    // ����� � ����� ��������� ��������� ������
    friend std::ostream& operator << (std::ostream& out, ElementGraph* graph);
};

ElementGraph::ElementGraph(string typeAnimal,
                           string race,
                           string name,
                           string mainColor,
                           int weight)
{

    this->typeAnimal = typeAnimal;
    this->race = race;
    this->name = name;
    this->mainColor = mainColor;
    this->weight = weight;

    for (int i = 0; i < 10; i++)
    {
        this->pointers[i] = NULL;
    }
}

ElementGraph* ElementGraph::operator = (ElementGraph& graph)
{
    this->typeAnimal = graph.typeAnimal;
    this->race = graph.race;
    this->name = graph.name;
    this->mainColor = graph.mainColor;
    this->weight = graph.weight;
    
    return this;
}

bool ElementGraph::operator == (ElementGraph &graph) 
{
    if (this->typeAnimal == graph.typeAnimal &&
        this->race == graph.race &&
        this->name == graph.name &&
        this->mainColor == graph.mainColor &&
        this->weight == graph.weight)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ElementGraph::operator != (ElementGraph& graph) 
{
    if (this->typeAnimal != graph.typeAnimal ||
        this->race != graph.race ||
        this->name != graph.name ||
        this->mainColor != graph.mainColor ||
        this->weight != graph.weight)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ElementGraph::operator < (ElementGraph& graph)
{
    if ((graph.getTypeAnimal() == "������" || graph.getTypeAnimal() == "���") &&
        (this->typeAnimal == "���" || this->typeAnimal == "�����"))
    {
        return true;
    }
    else if (this->weight < graph.getWeight())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ElementGraph::operator <= (ElementGraph& graph)
{
    if ((graph.getTypeAnimal() == "������" || graph.getTypeAnimal() == "���") &&
        (this->typeAnimal == "���" || this->typeAnimal == "�����"))
    {
        return true;
    }
    else if (this->weight <= graph.getWeight())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ElementGraph::operator > (ElementGraph& graph)
{
    if ((graph.getTypeAnimal() == "������" || graph.getTypeAnimal() == "���") &&
        (this->typeAnimal == "���" || this->typeAnimal == "�����"))
    {
        return false;
    }
    else if (this->weight > graph.getWeight())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ElementGraph::operator >= (ElementGraph& graph)
{
    if ((graph.getTypeAnimal() == "������" || graph.getTypeAnimal() == "���") &&
        (this->typeAnimal == "���" || this->typeAnimal == "�����"))
    {
        return false;
    }
    else if (this->weight >= graph.getWeight())
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::istream& operator >> (std::istream& in, ElementGraph* graph)
{
    cout << "���, ������, ���, ������������� ����, ���" << endl;
    string typeAnimal, race, name, mainColor;
    int weight;

    in >> typeAnimal;
    in >> race;
    in >> name;
    in >> mainColor;
    in >> weight;

    graph->setTypeAnimal(typeAnimal);
    graph->setRace(race);
    graph->setName(name);
    graph->setMainColor(mainColor);
    graph->setWeight(weight);

    return in;
}

std::ostream& operator << (std::ostream& out, ElementGraph* graph)
{
    out << "��� ��������� ���������: " << graph->getTypeAnimal() << endl;
    out << "������ ��������� ���������: " << graph->getRace() << endl;
    out << "���: " << graph->getName() << endl;
    out << "������������ ����: " << graph->getMainColor() << endl;
    out << "���: " << graph->getWeight() << endl;

    return out;
}

int ElementGraph::getCountChildGraph()
{
    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        if (this->pointers[i] != NULL)
        {
            count++;
        }
    }

    return count;
}

class Graphs
{
protected:
    class ElementGraph* start;
    class ElementGraph* now;
    class ElementGraph* before;

public:
    Graphs();
    ~Graphs();

    void create();
    int amountGraphs(class ElementGraph* graph);
    int amountWeight(class ElementGraph* graph);
    void addGraphTo(int to);
    void removeGraph(class ElementGraph* graph);
    void clearPointers(class ElementGraph* deletedNow);
    void updateNow() { this->now = this->before; };
    void updateBefore() { this->before = this->now; };
    void goToStart() { this->now = this->start; };
    void changePosition();
    void getValue();
    void refrehStart(class ElementGraph* start) { this->start = start; };

    class ElementGraph* getStart() { return this->start; }
    class ElementGraph* getNow() { return this->now; }
    class ElementGraph* getBefore() { return this->before; }

    //����������
    //������������ ����� ��������� ������ ������
    Graphs* operator = (Graphs* structGraph);
    //��������� ��������� ��������� ������
    bool operator < (Graphs& structGraph);
    bool operator <= (Graphs& structGraph);
    bool operator > (Graphs& structGraph);
    bool operator >= (Graphs& structGraph);
    //��������� �� ��������� �������� ������
    bool operator == (Graphs& structGraph);
    bool operator != (Graphs& structGraph);
};

Graphs::~Graphs()
{
    this->removeGraph(this->start);
}

Graphs::Graphs()
{
    this->start = NULL;
    this->now = NULL;
    this->before = NULL;
}

Graphs* Graphs::operator = (Graphs* structGraph)
{
    this->start = structGraph->getStart();
    return this;
}

bool Graphs::operator < (Graphs& structGraph)
{
    int countChildFirstStruct = 0;
    int countChildSecondStruct = 0;
    if (this->start->getCountChildGraph() < structGraph.getStart()->getCountChildGraph())
    {
        return true;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            countChildFirstStruct += this->start->pointers[i]->getCountChildGraph();
            countChildSecondStruct += structGraph.getStart()->pointers[i]->getCountChildGraph();
        }
        if (countChildFirstStruct < countChildSecondStruct)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Graphs::operator <= (Graphs& structGraph)
{
    int countChildFirstStruct = 0;
    int countChildSecondStruct = 0;
    if (this->start->getCountChildGraph() <= structGraph.getStart()->getCountChildGraph())
    {
        return true;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            countChildFirstStruct += this->start->pointers[i]->getCountChildGraph();
            countChildSecondStruct += structGraph.getStart()->pointers[i]->getCountChildGraph();
        }
        if (countChildFirstStruct <= countChildSecondStruct)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Graphs::operator > (Graphs& structGraph)
{
    int countChildFirstStruct = 0;
    int countChildSecondStruct = 0;
    if (this->start->getCountChildGraph() > structGraph.getStart()->getCountChildGraph())
    {
        return true;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            countChildFirstStruct += this->start->pointers[i]->getCountChildGraph();
            countChildSecondStruct += structGraph.getStart()->pointers[i]->getCountChildGraph();
        }
        if (countChildFirstStruct > countChildSecondStruct)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Graphs::operator >= (Graphs& structGraph)
{
    int countChildFirstStruct = 0;
    int countChildSecondStruct = 0;
    if (this->start->getCountChildGraph() >= structGraph.getStart()->getCountChildGraph())
    {
        return true;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            countChildFirstStruct += this->start->pointers[i]->getCountChildGraph();
            countChildSecondStruct += structGraph.getStart()->pointers[i]->getCountChildGraph();
        }
        if (countChildFirstStruct >= countChildSecondStruct)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Graphs::operator == (Graphs& structGraph)
{
    if (this->amountWeight(this->start) == structGraph.amountWeight(structGraph.getStart()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Graphs::operator != (Graphs& structGraph)
{
    if (this->amountWeight(this->start) != structGraph.amountWeight(structGraph.getStart()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Graphs::create()
{
    string typeAnimal, race, name, mainColor;
    int weight;

    cout << "---------------------------------------------------------------" << endl;
    cout << "|                     ��������� ����...                       |" << endl;
    cout << "---------------------------------------------------------------" << endl;

    cout << "������� ��� ��������� ���������: ";
    cin >> typeAnimal;
    cout << "������� ������ ��������� ���������: ";
    cin >> race;
    cout << "������� ��� ��������� ���������: ";
    cin >> name;
    cout << "������� ������������� ���� ��������� ���������: ";
    cin >> mainColor;
    cout << "������� ��� ��������� ���������: ";
    cin >> weight;

    this->start = new ElementGraph(
        typeAnimal, race, name,
        mainColor, weight
    );

    this->now = this->start;
    this->before = this->start;
}

int Graphs::amountGraphs(class ElementGraph* graph)
{
    int count = 0;

    if (graph == NULL)
    {
        return 0;
    }
    else if (graph != NULL)
    {
        count++;
    }
    for (int i = 0; i < 10; i++)
    {
        count += amountGraphs(graph->pointers[i]);
    }
    return count;
}

int Graphs::amountWeight(class ElementGraph* graph)
{
    int weight = 0;

    if (graph == NULL)
    {
        return 0;
    }
    else if (graph != NULL)
    {
        weight += graph->getWeight();
    }
    for (int i = 0; i < 10; i++)
    {
        weight += amountWeight(graph->pointers[i]);
    }
    return weight;
}

void Graphs::addGraphTo(int to)
{
    // to - 1 � ������, to - 2 � �������� �����
    string typeAnimal, race, name, mainColor;
    int weight;

    cout << "---------------------------------------------------------------" << endl;
    cout << "|                     ��������� ����...                       |" << endl;
    cout << "---------------------------------------------------------------" << endl;

    cout << "������� ��� ��������� ���������: ";
    cin >> typeAnimal;
    cout << "������� ������ ��������� ���������: ";
    cin >> race;
    cout << "������� ��� ��������� ���������: ";
    cin >> name;
    cout << "������� ������������� ���� ��������� ���������: ";
    cin >> mainColor;
    cout << "������� ��� ��������� ���������: ";
    cin >> weight;

    class ElementGraph* freshGraph = new ElementGraph(
        typeAnimal, race, name,
        mainColor, weight
    );

    if (to == 1)
    {
        for (int i = 0; i < 10; i++)
        {
            if (this->start->pointers[i] == NULL)
            {
                this->start->pointers[i] = freshGraph;
                break;
            }
            if (i == 9)
            {
                cout << "���������� �� �������� ���������� ������������ ���������� �������� ������!" << endl;
            }
        }
    }
    else if (to == 2)
    {
        for (int i = 0; i < 10; i++)
        {
            if (this->now->pointers[i] == NULL)
            {
                this->now->pointers[i] = freshGraph;
                break;
            }
            if (i == 9)
            {
                cout << "���������� �� �������� ���������� ������������ ���������� �������� ������!" << endl;
            }
        }
    }

}

void Graphs::removeGraph(class ElementGraph* graph)
{
    if (graph != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            removeGraph(graph->pointers[i]);
        }
    }
    delete graph;
}

void Graphs::clearPointers(class ElementGraph* deletedNow)
{
    for (int i = 0; i < 10; i++)
    {
        if (this->before->pointers[i] == deletedNow)
        {
            this->before->pointers[i] = NULL;
        }
    }
}

void Graphs::changePosition()
{
    cout << "---------------------------------------------------------------" << endl;
    cout << "          �� ���������� � {{" << this->now << "}} �����." << endl;
    cout << "---------------------------------------------------------------" << endl;

    int countChildren = 0;

    while (this->now->pointers[countChildren] != NULL)
    {
        countChildren++;
    }

    if (countChildren == 0)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "       � ����� ��� �������� ��������� ������� �� ��������!" << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "�� ������ ��������� � ������ �����('y' - ��, 'n' - ���)?" << endl;
        string answer;
        cin >> answer;
        if (answer == "y")
        {
            this->goToStart();
            cout << "�� ������� ������������� � ������ �����!" << endl;
        }
        else if (answer == "n")
        {
            cout << "�� ���, ��� ���";
        }
        else
        {
            cout << "������� �� ���������� ��������!" << endl;
        }
    }
    else if (countChildren == 1)
    {
        cout << "� ����� 1 �������� �������, ������� � ����('y' - ��, 'n' - ���, '1' - ��������� � ������ �����):" << endl;
        string answer;
        cin >> answer;
        if (answer == "y")
        {
            this->now = this->now->pointers[0];
            cout << "---------------------------------------------------------------" << endl;
            cout << "                    �� ������� �������� ����!" << endl;
            cout << "---------------------------------------------------------------" << endl;
            countChildren = 0;
        }
        else if (answer == "n")
        {
            cout << "�� ���, ��� ���";
        }
        else if (answer == "1")
        {
            this->goToStart();
            cout << "�� ������� ������������� � ������ �����!" << endl;
        }
        else
        {
            cout << "������� �� ���������� ��������!" << endl;
        }
    }
    else
    {
        int answer = 0;
        int i1 = 0;
        cout << "---------------------------------------------------------------" << endl;
        cout << "�������� ���� � �������� ������ �������, ����� �������� ������ = " << countChildren << endl;
        cout << "---------------------------------------------------------------" << endl;

        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < countChildren; i++)
        {
            cout << i + 1 << ")" << this->now->pointers[i] << endl;
            if (i + 1 == countChildren)
            {
                i1 = i + 2;
            }
        }
        cout << i1 << ")" << "��������� � ������" << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "�������� ����: ";
        cin >> answer;

        if (answer > 0 && answer <= countChildren)
        {
            if (answer == i1)
            {
                this->goToStart();
                cout << "�� ������� ������������� � ������ �����!" << endl;
            }
            else {
                cout << "---------------------------------------------------------------" << endl;
                cout << "               �� ������� �������� ����!" << endl;
                cout << "---------------------------------------------------------------" << endl;
                this->now = this->now->pointers[answer - 1];
                countChildren = 0;
            }
        }
        else if (answer == i1)
        {
            this->goToStart();
            cout << "�� ������� ������������� � ������ �����!" << endl;
        }
        else
        {
            answer = 0;
            cout << "������� �� ���������� ��������" << endl;
            this->changePosition();
        }
    }
}

void Graphs::getValue()
{
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "                      {{" << this->now << "}}                  " << endl;
    cout << "��� ��������� ���������: " << this->now->getTypeAnimal() << endl;
    cout << "������ ��������� ���������: " << this->now->getRace() << endl;
    cout << "��� ��������� ���������: " << this->now->getName() << endl;
    cout << "������������� ���� ��������� ���������: " << this->now->getMainColor() << endl;
    cout << "��� ��������� ���������: " << this->now->getWeight() << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
}

void setRussian()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
}

void printTools()
{
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "|                         ����                                |" << endl;
    cout << "| 1)��������� ���������� ��������� � ��������� ������         |" << endl;
    cout << "| 2)���������� �������� � ��������� ������                    |" << endl;
    cout << "| 3)������� ��������� �������� ��� �������� ��������          |" << endl;
    cout << "| 4)�������� �������� �������� ��������� ������               |" << endl;
    cout << "| 5)������� ��������� ������                                  |" << endl;
    cout << "| 6)����������� �� ��������� ��������� ������                 |" << endl;
    cout << "| 7)������ ���������� �� �������� �������� ��������� ������   |" << endl;
    cout << "| 8)�����                                                     |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
}

int getTools()
{
    printTools();
    int numberTool = 0;
    cout << "������� �����: ";
    cin >> numberTool;
    return numberTool;
}