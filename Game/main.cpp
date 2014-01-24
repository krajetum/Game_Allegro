#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
int main(int argc, char **argv){
    bool game = 1;
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_BITMAP  *image   = NULL;

   int imageWidth, imageHeight;


   if(!al_init()) return -2; //allegro failed initialization

   display = al_create_display(640, 480);
   if(!display) return -1; //failed create display

    if(!al_init_image_addon()) {
      al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

   event_queue = al_create_event_queue();
   if(!event_queue) {  //failed create event queue
        al_destroy_display(display);
      return -3;
   }

   ;

    image = al_load_bitmap("MobHit.jpg");
    if(!image) {
                al_destroy_display(display);
                return 1;
    }
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);

    al_register_event_source(event_queue, al_get_display_event_source(display));
   while(game == 1)
   {
      ALLEGRO_EVENT ev;
      ALLEGRO_TIMEOUT timeout;
      al_init_timeout(&timeout, 0.06);

      bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);



        al_draw_bitmap(image,0,0,0);
        al_flip_display();
      if(get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         game = 0;
      }

   }

   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
    al_destroy_bitmap(image);
   return 0;
}
