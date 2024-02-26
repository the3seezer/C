/*
    theBitRiddler
    2/19/2024
    1:23 PM
    8.36 (Cooking with Healthier Ingredients)
    "1 cup sour cream",         "1 cup yogurt",
    "1 cup milk",               "1/2 cup evaporated milk and 1/2 cup water",
    "1 teaspoon lemon juice",   "1/2 teaspoon vinegar",
    "1 cup sugar",              "1/2 cup honey, 1 cup molasses or 1/4 cup agave nectar",
    "1 cup butter",             "1 cup margarine or yogurt",
    "1 cup flour",              "1 cup rye or rice flour",
    "1 cup mayonnaise",         "1 cup cottage cheese or 1/8 cup mayonnaise and 7/8 cup yogurt",
    "1 egg",                    "2 tablespoons cornstarch, arrowroot flour or potato starch or 2 egg whites or 1/2 of a large banana (mashed)",
    "1 cup milk",               "1 cup soy milk",
    "1/4 cup oil",              "1/4 cup applesauce",
    "white bread"               "whole-grain bread"         
*/
#include <stdio.h>
int main( void ) {
    char * ingredients[11][2] = {
        { "cup", "sour cream" }, { "cup", "milk"}, { "teaspoon", "lemon juice" }, { "cup", "sugar" }, { "cup", "butter"},
        { "cup", "flour" }, { "cup", "mayonnaise" }, { "egg", "" }, { "cup", "milk" }, { "cup", "oil" }, { "white bread", "" }
    };
    char * substitutions[11][8] = {
        { "cup", " yogurt", "", "", "", "", "", "" },
        { "cup", " evaporated milk", " and ", "cup", " water", "", "", "" },
        { "teaspoon", " vinegar", "", "", "", "", "", "" }, 
        { "cup", " honey", "cup", " molasses", " or ", "cup", " agave nectar", "" }, 
        { "cup", " margarine or yogurt", "", "", "", "", "", "" },
        { "cup", " rye or rice flour", "", "", "", "", "", "" }, 
        { "cup", " cottage cheese", " or ", "cup", " mayonnaise", " and ", "cup", " yogurt" },
        { "tablespoon", " cornstarch, arrowroot flour or potato starch", " or ", " egg whites", " or ", " of a large banana (mashed)", "", "" }, 
        { "cup", " soy milk", "", "", "", "", "", "" }, 
        { "cup", " applesauce", "", "", "", "", "", "" }, 
        { " whole-grain bread", "", "", "", "", "", "", "" }
    };

    return 0; // indicate successful termination
}   /* end main */