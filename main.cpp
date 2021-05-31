#include<iostream>
#include<list>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct task
{
    string task_title, desc, start_date, ending_date, emp_name;
    bool task_done = 0;
    int prio,emp_id;
} tasks[1000];

vector <pair <int, int>>emp[200];

void input_task(int index)
{
    int id;
    cout << "enter your task title" << "\n";
    cin >> tasks[index].task_title;
    cout << "enter your task Description" << "\n";
    cin.ignore();
    getline(cin, tasks[index].desc);
    cout << "enter your task assigning date" << "\n";
    cin.ignore();
    getline(cin, tasks[index].start_date);
    cout << "enter your task deadline date" << "\n";
    cin.ignore();
    getline(cin, tasks[index].ending_date);
    cout << "enter the priority level(1:10) that validate the importance of your task" << "\n";
    if (tasks[index].prio >= 0 && tasks[index].prio <= 10)
        cin >> tasks[index].prio;
    while (tasks[index].prio > 10 || tasks[index].prio < 1)
    {
        cout << "invalid level " << "\n" << "please , enter the priority level again" << "\n";
        cin >> tasks[index].prio;
    }
    cout << " enter employee name : " << "\n";
    cin.ignore();
    getline(cin, tasks[index].emp_name);
    cout << " Enter employee ID : " << endl;
    cin >> id;
    tasks[index].emp_id = id;
    emp[id].push_back({ tasks[index].prio,index });
    sort(emp[id].begin(), emp[id].end());
    reverse(emp[id].begin(), emp[id].end());
}

void display_emp_list(int id)
{
    int temp;
    for (auto it:emp[id])
    {
        temp = it.second;
        cout << " Task Title: " << tasks[temp].task_title << endl;
        cout << " Employee name: " << tasks[temp].emp_name << endl;
        cout << " Task's Description: " << tasks[temp].desc << endl;
        cout << " start date: " << tasks[temp].start_date << endl;
        cout << " Ending date: " << tasks[temp].ending_date << endl;
        cout << " Level: " << tasks[temp].prio << endl;
        cout << " Done: " << tasks[temp].task_done << endl;

    }
}
/*
 void pop_task(int index)
{
    tasks[index].task_done = 1;
    emp[tasks[index].emp_id].erase({ tasks[index].prio,index }, { tasks[index].prio,index });
}*/


int main (){
    for (;;)
    {
        int number_of_tasks = 0, option, id,index;
        cout << "enter the number of option you will do  " << "\n";
        cout << "1- read information of new task" << "\n";
        cout << "2- display list of tasks of any employee" << "\n";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            input_task(number_of_tasks);
            number_of_tasks++;
            break;
        }
        case 2:
        {
            cout << "enter the id of employee who wants your information" << "\n";
            cin >> id;
            display_emp_list(id);
            break;
        }

        case 3:
        {
            cout << "enter the index of task which finished " << "\n";
            cin >> index;
           // pop_task(index);
            break;
        }


        }
    }
    return 0;
}
