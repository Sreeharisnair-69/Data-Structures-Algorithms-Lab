                +-------------------+
                |     <<abstract>>  |
                |        Task       |
                |-------------------|
                | - taskId : int    |
                | - title : String  |
                | - dueDate : Date  |
                | - priority: String|
                | - status : String |
                |-------------------|
                | + markComplete()  |
                | + displayTask()   |
                +-------------------+
                   ^           ^
                   |           |
     --------------+           +--------------
     |                                      |
+-------------------+             +-------------------+
|     StudyTask     |             |     ExamTask      |
|-------------------|             |-------------------|
| - subject : String|             | - subject : String|
|-------------------|             | - examDate : Date |
| + displayTask()   |             |-------------------|
+-------------------+             | + displayTask()   |
                                  +-------------------+


+-------------------+                  +-------------------+
|       User        |                  |      Planner      |
|-------------------|                  |-------------------|
| - userId : int    |                  | - tasks: List<Task>|
| - name : String   |                  |-------------------|
| - email : String  |                  | + addTask(Task)   |
|-------------------|                  | + removeTask(int) |
| + getDetails()    |                  | + updateTask(Task)|
+-------------------+                  | + getTasks()      |
         |                             | + searchTask()    |
         |                             +-------------------+
         |                                     |
         |  Association                        |  Composition (owns tasks)
         v                                     v
       [Task] ------------------------------- [Task]


+-------------------+         +-------------------+
|  DatabaseManager  |         |    FileManager    |
|-------------------|         |-------------------|
| - connection      |         | + exportTasks()   |
|-------------------|         | + importTasks()   |
| + connect()       |         +-------------------+
| + insertTask()    |
| + updateTask()    |
| + deleteTask()    |
| + fetchTasks()    |
+-------------------+


+-------------------+
|    PlannerGUI     |
|-------------------|
| - frame : JFrame  |
| - buttons:JButton[]|
| - taskTable:JTable|
|-------------------|
| + initUI()        |
| + showTasks()     |
| + getUserInput()  |
+-------------------+


Arrows:
--------
StudyTask ------|> Task           (Inheritance)
ExamTask  ------|> Task           (Inheritance)
User -----------> Task            (Association)
Planner --------> Task            (Association/Composition)
Planner .......> DatabaseManager  (Dependency)
Planner .......> FileManager      (Dependency)
PlannerGUI ....> Planner          (Dependency)
PlannerGUI ....> DatabaseManager  (Dependency)
