#include <gtk/gtk.h> // Include the GTK library for GUI components
#include <math.h> // Include the math library for mathematical functions

// Declare global variables for the widgets
GtkWidget *entry; // Entry widget for the function
GtkWidget *entry2; // Entry widget for the first number
GtkWidget *entry3; // Entry widget for the second number
GtkWidget *result_label; // Label widget to display the result

// Function to calculate the factorial of a number
double factorial(int n) 
{
    if (n < 0) return -1; // Return -1 for negative numbers
    if (n == 0) return 1; // 0! is 1
    double result = 1;
    for (int i = 1; i <= n; i++) 
    {
        result *= i;
    }
    return result;
}

// Function to perform the calculation
void calculate(GtkWidget *widget, gpointer data) 
{
    // Get the function and numbers from the entries
    const char *fun = gtk_entry_get_text(GTK_ENTRY(entry)); // Get the function from the entry widget
    const char *num1 = gtk_entry_get_text(GTK_ENTRY(entry2)); // Get the first number from the entry widget
    const char *num2 = gtk_entry_get_text(GTK_ENTRY(entry3)); // Get the second number from the entry widget
    
    // Convert the numbers from strings to integers
    int a = atoi(num1); // Convert the first number to an integer
    int b = atoi(num2); // Convert the second number to an integer
    double ans = 0; // Variable to store the result

    // Perform the calculation based on the function
    switch (fun[0]) 
    {
        case '+' : ans = a + b; // Addition
        break;

        case '-' : ans = a - b; // Subtraction
        break;

        case '*' : ans = a * b; // Multiplication
        break;

        case '/' : 
            if (b == 0) 
            {
                gtk_label_set_text(GTK_LABEL(result_label), "Error: Division by zero.");
                return;
            }
            ans = (double)a / b; // Division
        break;

        case 'm' : ans = a % b; // Modulus
        break;

        case 's' : ans = a * a; // Square
        break;

        case 'f' : ans = factorial(a); // Factorial
        break;

        case 'q' : ans = sqrt(a); // Square root
        break;

        case 'l' : ans = log(a); // Natural logarithm
        break;

        case 'p' : ans = pow(a, b); // Power
        break;

        default : 
            // If the function is invalid, display an error message
            gtk_label_set_text(GTK_LABEL(result_label), "Invalid function.");
            return;
    }

    // Create a string to display the result
    char result[256];
    snprintf(result, sizeof(result), "Your answer is: %.2f", ans); // Format the result
    
    // Set the result label to display the result
    gtk_label_set_text(GTK_LABEL(result_label), result); // Display the result
}

int main(int argc, char *argv[]) 
{
    // Declare variables for the widgets
    GtkWidget *window; // Window widget
    GtkWidget *grid; // Grid widget
    GtkWidget *button; // Button widget
    GtkWidget *blank; // Blank widget
    GtkWidget *label0; // Label widget for the functions explanation
    GtkWidget *label; // Label widget for the function
    GtkWidget *label2; // Label widget for the first number
    GtkWidget *label3; // Label widget for the second number

    // Initialize GTK
    gtk_init(&argc, &argv); // Initialize the GTK library

    // Create a new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // Create a new top-level window
    gtk_window_set_title(GTK_WINDOW(window), "Simple Calculator"); // Set the window title
    gtk_container_set_border_width(GTK_CONTAINER(window), 10); // Set the border width of the window
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200); // Set the default size of the window

    // Create a grid and add it to the window
    grid = gtk_grid_new(); // Create a new grid
    gtk_container_add(GTK_CONTAINER(window), grid); // Add the grid to the window

    // Create and add the functions explanation label to the grid
    label0 = gtk_label_new("Functions:\n + = addition\n - = subtraction\n * = multiplication\n / = division\n m = modulus\n s = square\n f = factorial\n q = square root\n l = natural logarithm\n p = power"); // Create a new label for the functions explanation
    gtk_grid_attach(GTK_GRID(grid), label0, 0, 0, 2, 1); // Attach the label to the grid

    blank = gtk_label_new(""); // Create a new blank label
    gtk_grid_attach(GTK_GRID(grid), blank, 0, 1, 2, 1); // Attach the blank label to the grid

    // Create and add the function label and entry to the grid
    label = gtk_label_new("Enter function:"); // Create a new label for the function
    gtk_grid_attach(GTK_GRID(grid), label, 0, 2, 1, 1); // Attach the label to the grid

    entry = gtk_entry_new(); // Create a new entry for the function
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 2, 1, 1); // Attach the entry to the grid

    blank = gtk_label_new(""); // Create a new blank label
    gtk_grid_attach(GTK_GRID(grid), blank, 0, 7, 2, 1); // Attach the blank label to the grid

    // Create and add the first number label and entry to the grid
    label2 = gtk_label_new("Enter first number:"); // Create a new label for the first number
    gtk_grid_attach(GTK_GRID(grid), label2, 0, 3, 1, 1); // Attach the label to the grid

    entry2 = gtk_entry_new(); // Create a new entry for the first number
    gtk_grid_attach(GTK_GRID(grid), entry2, 1, 3, 1, 1); // Attach the entry to the grid

    blank = gtk_label_new(""); // Create a new blank label
    gtk_grid_attach(GTK_GRID(grid), blank, 0, 7, 2, 1); // Attach the blank label to the grid

    // Create and add the second number label and entry to the grid
    label3 = gtk_label_new("Enter second number:"); // Create a new label for the second number
    gtk_grid_attach(GTK_GRID(grid), label3, 0, 4, 1, 1); // Attach the label to the grid

    entry3 = gtk_entry_new(); // Create a new entry for the second number
    gtk_grid_attach(GTK_GRID(grid), entry3, 1, 4, 1, 1); // Attach the entry to the grid

    blank = gtk_label_new(""); // Create a new blank label
    gtk_grid_attach(GTK_GRID(grid), blank, 0, 5, 2, 1); // Attach the blank label to the grid

    // Create and add the calculate button to the grid
    button = gtk_button_new_with_label("Calculate"); // Create a new button with the label "Calculate"
    g_signal_connect(button, "clicked", G_CALLBACK(calculate), entry); // Connect the button's clicked signal to the calculate function
    gtk_grid_attach(GTK_GRID(grid), button, 0, 6, 2, 1); // Attach the button to the grid

    blank = gtk_label_new(""); // Create a new blank label
    gtk_grid_attach(GTK_GRID(grid), blank, 0, 7, 2, 1); // Attach the blank label to the grid

    // Create and add the result label to the grid
    result_label = gtk_label_new(""); // Create a new label for the result
    gtk_grid_attach(GTK_GRID(grid), result_label, 0, 8, 2, 1); // Attach the result label to the grid

    // Connect the destroy signal to quit the GTK main loop
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); // Connect the window's destroy signal to the gtk_main_quit function

    // Show all widgets in the window
    gtk_widget_show_all(window); // Show all widgets in the window

    // Enter the GTK main loop
    gtk_main(); // Enter the GTK main loop

    return 0; // Return 0 to indicate successful execution
}
