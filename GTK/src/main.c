#include "stdio.h"
#include "gtk/gtk.h"

static gboolean
delete_event(GtkWidget* widget,
	     GdkEvent*  event,
	     gpointer   data)
{
	return FALSE;
}

static void
do_exit(GtkWidget* widget, gpointer data)
{
	gtk_main_quit();
}

int main(int argc, char** argv)
{
	GtkWidget* window;
	GtkWidget* button;

	gtk_init (&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	g_signal_connect(window, "delete-event", 
			 G_CALLBACK(delete_event), NULL);

	g_signal_connect(window, "destroy",
			 G_CALLBACK(do_exit), NULL);

	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	button = gtk_button_new_with_label("Hello, world!");

	gtk_container_add(GTK_CONTAINER(window), button);

	gtk_widget_show(button);
	gtk_widget_show(window);

	gtk_main();

	return 0;
}
