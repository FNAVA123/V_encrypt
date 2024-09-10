  #include "front.h"
  
  double ShapesD::centerX (){
        return  ((width - sizewidth) / 2.0);
    }
    double ShapesD::centery(){
        return ((height - sizeheight) / 2.0);
    }

    double ShapesD::centeryoffset(float offset){
        return centerX() + (offset);
    }