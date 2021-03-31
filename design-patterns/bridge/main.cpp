#include "shape.h"
#include "square.h"
#include "circle.h"
#include "color.h"
#include "red_color.h"
#include "blue_color.h"

int main() {
    RedColor rc;
    Square sq(&rc);

    BlueColor bc;
    Circle cr(&bc);

    Shape *shape = &sq;
    shape->present();

    sq.setColor(&bc);
    shape->present();

    shape = &cr;
    shape->present(); 
}