import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Task {
    String description, date, time;

    Task(String description, String date, String time) {
        this.description = description;
        this.date = date;
        this.time = time;
    }
}

public class TaskScheduler { // Class name must match file name
    private Queue<Task> taskQueue = new LinkedList<>();

    public void addTask(String description, String date, String time) {
        taskQueue.add(new Task(description, date, time));
        System.out.println("Task added successfully!");
    }

    public void viewTasks() {
        if (taskQueue.isEmpty()) {
            System.out.println("No tasks scheduled.");
            return;
        }
        int i = 1;
        for (Task task : taskQueue) {
            System.out.println(i++ + ". " + task.description + " on " + task.date + " at " + task.time);
        }
    }

    public void completeTask() {
        if (taskQueue.isEmpty()) {
            System.out.println("No tasks to complete.");
            return;
        }
        Task completedTask = taskQueue.poll();
        System.out.println("Completed task: " + completedTask.description);
    }

    public void checkNextTask() {
        if (taskQueue.isEmpty()) {
            System.out.println("No upcoming tasks.");
            return;
        }
        Task nextTask = taskQueue.peek();
        System.out.println("Upcoming Task: " + nextTask.description + " on " + nextTask.date + " at " + nextTask.time);
    }

    public static void main(String[] args) {
        TaskScheduler scheduler = new TaskScheduler();
        Scanner scanner = new Scanner(System.in);
        int choice;

        while (true) {
            System.out.println("\nTask Scheduler");
            System.out.println("1. Add Task");
            System.out.println("2. View Tasks");
            System.out.println("3. Complete Task (FIFO)");
            System.out.println("4. Check Next Task");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter task description: ");
                    String description = scanner.nextLine();
                    System.out.print("Enter task date (YYYY-MM-DD): ");
                    String date = scanner.nextLine();
                    System.out.print("Enter task time (HH:MM): ");
                    String time = scanner.nextLine();
                    scheduler.addTask(description, date, time);
                    break;
                case 2:
                    scheduler.viewTasks();
                    break;
                case 3:
                    scheduler.completeTask();
                    break;
                case 4:
                    scheduler.checkNextTask();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Try again.");
            }
        }
    }
}


    
   
    
            
                   
                    
