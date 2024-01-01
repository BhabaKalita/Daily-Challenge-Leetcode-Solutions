#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class FoodRatings {
public:
  // Map to store food ratings
  unordered_map<string, int> food_rating;

  // Map to store food cuisines
  unordered_map<string, string> food_cuisine;

  // Map to store cuisine-wise food ratings with a set of pairs
  // (rating, food) sorted by rating in descending order
  unordered_map<string, set<pair<int, string>>> cuisine_rating_food;

  // Constructor to initialize the FoodRatings object with data
  FoodRatings(vector<string> &foods, vector<string> &cuisines,
              vector<int> &ratings) {
    for (int i = 0; i < foods.size(); i++) {
      // Populate food_rating map
      food_rating[foods[i]] = ratings[i];

      // Populate food_cuisine map
      food_cuisine[foods[i]] = cuisines[i];

      // Populate cuisine_rating_food map
      cuisine_rating_food[cuisines[i]].insert({-ratings[i], foods[i]});
    }
  }

  // Method to change the rating of a food item
  void changeRating(string food, int newRating) {
    // Retrieve cuisine associated with the food
    auto cuisineIt = food_cuisine.find(food);

    auto &cuisine = cuisineIt->second;

    // Erase the existing rating for the food from the set
    cuisine_rating_food[cuisine].erase({-food_rating[food], food});

    // Insert the new rating for the food into the set
    cuisine_rating_food[cuisine].insert({-newRating, food});

    // Update the rating in the food_rating map
    food_rating[food] = newRating;
  }

  // Method to get the highest-rated food for a given cuisine
  string highestRated(string cuisine) {
    // Check if there are any foods in the set for the given cuisine
    if (!cuisine_rating_food[cuisine].empty()) {
      // Return the food with the highest rating
      return begin(cuisine_rating_food[cuisine])->second;
    } else {
      // Return an empty string if no foods are found
      return "";
    }
  }
};

/*
Time Complexity: O(N * log M)
Space Complexity: O(N * (1 + M)) + O(N) ≈ O(N * (1 + M))
*/
