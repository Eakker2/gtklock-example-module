// gtklock-example-module
// Copyright (c) 2022 Jovan Lanik

// Example module

#include "gtklock-module.h"

static void add_label(struct Window *ctx) {
	ctx->module_data = gtk_label_new("Hello world!");
	gtk_container_add(GTK_CONTAINER(ctx->window_box), ctx->module_data);
	gtk_widget_show(ctx->module_data);
}

static void remove_label(struct Window *ctx) {
	if(ctx->module_data != NULL) gtk_widget_destroy(ctx->module_data);
}

const gchar *g_module_check_init(GModule *m) {
	g_print("Hello module!\n");
	return NULL;
}

void g_module_unload(GModule *m) {
	g_print("Goodbye!\n");
}

void on_activation(struct GtkLock *gtklock) {
	g_print("Hello activation!\n");
}

void on_output_change(struct GtkLock *gtklock) {
	g_print("Hello output change!\n");
}

void on_focus_change(struct GtkLock *gtklock, struct Window *win, struct Window *old) {
	g_print("Hello focus change!\n");
	if(!gtklock->hidden) remove_label(win);
}

void on_window_empty(struct GtkLock *gtklock, struct Window *ctx) {
	g_print("Hello window empty!\n");
	ctx->module_data = NULL;
}

void on_body_empty(struct GtkLock *gtklock, struct Window *ctx) {
	g_print("Hello body empty!\n");
	add_label(ctx);
}

void on_idle_hide(struct GtkLock *gtklock) {
	g_print("Hello idle hide!\n");
}

void on_idle_show(struct GtkLock *gtklock) {
	g_print("Hello idle show!\n");
	if(gtklock->focused_window) remove_label(gtklock->focused_window);
}

