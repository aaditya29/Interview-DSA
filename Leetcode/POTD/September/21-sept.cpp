// Leetcode 1912. Design Movie Rental System
#include <iostream>
#include <deque>

using namespace std;
class MovieRentingSystem
{
public:
    map<int, set<pair<int, int>>> unrented_movies;
    set<tuple<int, int, int>> rented_movies;
    map<pair<int, int>, int> movie_prices;

    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (const auto &entry : entries)
        {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            movie_prices[{shop, movie}] = price;
            unrented_movies[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie)
    {
        vector<int> result;
        if (unrented_movies.find(movie) == unrented_movies.end())
        {
            return result;
        }
        auto &shops = unrented_movies.at(movie);
        int count = 0;
        for (const auto &[price, shop] : shops)
        {
            if (count >= 5)
                break;
            result.push_back(shop);
            count++;
        }
        return result;
    }

    void rent(int shop, int movie)
    {
        int price = movie_prices.at({shop, movie});
        unrented_movies[movie].erase({price, shop});
        rented_movies.insert({price, shop, movie});
    }

    void drop(int shop, int movie)
    {
        int price = movie_prices.at({shop, movie});
        rented_movies.erase({price, shop, movie});
        unrented_movies[movie].insert({price, shop});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> result;
        int count = 0;
        for (const auto &[price, shop, movie] : rented_movies)
        {
            if (count >= 5)
                break;
            result.push_back({shop, movie});
            count++;
        }
        return result;
    }
};

int main()
{
    MovieRentingSystem movieRentingSystem(3, {{0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}}); // Initializes the system with n = 3 shops and the entries shown.
    movieRentingSystem.search(1);                                                                                 // Returns [1,0,2]. Shops 1, 0 and 2 have an unrented movie 1 at prices 4, 5 and 5 respectively.
    movieRentingSystem.rent(0, 1);                                                                                // Shop 0 rents movie 1.
    movieRentingSystem.rent(1, 2);                                                                                // Shop 1 rents movie 2.
    movieRentingSystem.report();                                                                                  // Returns [[0,1],[1,2]]. The rented movies are (0,1) at price 5 and (1,2) at price 7.
    movieRentingSystem.drop(1, 2);                                                                                // Shop 1 drops movie 2.
    movieRentingSystem.search(2);                                                                                 // Returns [0]. Shop 0 has an unrented movie 2 at price 6.
    movieRentingSystem.rent(0, 2);                                                                                // Shop 0 rents movie 2.
    movieRentingSystem.report();                                                                                  // Returns [[0,1],[0,2]]. The rented movies are (0,1) at price 5 and (0,2) at price 6.
    return 0;
}