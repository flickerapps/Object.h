#include "../Object.h"

int main(int args, const char* argv[]){
    var parent = ObjectCreate("My Parent");


    var children1 = ObjectCreate("child1");
    children1->setNumber(children1, 55);

    var children2 = ObjectCreate("child2");
    children2->setNumber(children2, 65);

    var children3 = ObjectCreate("child3");
    children3->setNumber(children3, 75);

    parent->setChild(parent, children1);
    parent->appendChild(parent, children2);
    parent->appendChild(parent, children3);

    if(isObject(parent)){
        //parent->removeChild(parent, "child2");
        if(hasChild(parent,"child2")){
            var finded = parent->find(parent,"child2");
            finded->setNumber(finded,99);
            int should_be_65 = finded->getNumber(finded);
            printf("Should be: %d\n", should_be_65);
        }
        else{
            printf("Not found child2\n");
        }
    }
    else{
        printf("Undefined parent");
    }

    // do not forget free memory
    freeObject(parent);
    return 0;
}