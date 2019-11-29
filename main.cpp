#include <iostream>
#include <vector>
#include "figure.h"
#include "pentagon.h"
#include "trapeze.h"
#include "rhombus.h"
int main() {
    std::vector<figure*> figures;
    for(;;) {
        int command = 0;
        std::cin >> command;
        if (command == 0) {
            break;
        } else if(command == 1) {
            int figure_id;
            std::cin >> figure_id;
            figure* new_figure;
            if (figure_id == 0) {
                new_figure = new trapeze(std::cin);
            } else if (figure_id == 1) {
                new_figure = new rhombus(std::cin);
            } else if (figure_id == 2) {
                new_figure = new pentagon(std::cin);
            } else {
                std::cout << "no such a figure\n" << std::endl;
                exit(-1);
            }
            figures.push_back(new_figure);
        } else if(command == 2) {
            int function_id;
            std::cin >> function_id;
            if (function_id == 0) {
                for(figure* cur_figure: figures) {
                    cur_figure->print(std::cout);
                }
            } else if (function_id == 1){
                for(figure* cur_figure: figures) {
                    std::cout << cur_figure->area() << '\n' << '\n';
                }
            } else if (function_id == 2) {
                for(figure* cur_figure: figures) {
                    std::cout << cur_figure->center() << '\n';
                }
            }
        } else if (command == 3) {
            int id;
            std::cin >> id;
            if (id >= figures.size()) {
                std::cout << "no such an element" << '\n';
                exit(-1);
            }
            delete figures[id];
            figures.erase(figures.begin() + id);
        }
    }
    for (size_t i = 0; i < figures.size(); ++i) {
        delete figures[i];
    }
    return 0;
}