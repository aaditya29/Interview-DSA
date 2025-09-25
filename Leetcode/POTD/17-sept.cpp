// Leetcode 2353
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <string>
using namespace std;
class FoodRatings
{
public:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;

    unordered_map<string, set<pair<int, string>>> cuisineToFoods;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        int n = foods.size();

        for (int i = 0; i < n; i++)
        {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;

            cuisineToFoods[cuisine].insert({-rating, food});
        }
    }

    void changeRating(string food, int newRating)
    {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];

        cuisineToFoods[cuisine].erase({-oldRating, food});

        foodToRating[food] = newRating;

        cuisineToFoods[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine)
    {
        return cuisineToFoods[cuisine].begin()->second;
    }
};

int main()
{
    vector<string> foods = {"kimchi", "miso", "sushi", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 7};

    FoodRatings foodRatings(foods, cuisines, ratings);

    cout << foodRatings.highestRated("korean") << endl;   // Output: "kimchi"
    cout << foodRatings.highestRated("japanese") << endl; // Output: "ramen"

    foodRatings.changeRating("sushi", 16);

    cout << foodRatings.highestRated("japanese") << endl; // Output: "sushi"

    return 0;
}