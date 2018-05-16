//
// Created by andreea on 07.05.2018.
//

#include "UndoAction.h"


void UndoRemove::executeUndo() {
    repo.add(this ->dog);
}

void UndoAdd::executeUndo() {
    repo.removeElem(this -> dog);
}
