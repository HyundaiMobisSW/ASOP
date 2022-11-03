struct compare {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        return (a.first == b.first) ? (a.second>b.second) : (a.first<b.first);
    }
};
class FoodRatings {
    unordered_map<string, int> cuisineIndex;
    unordered_map<string, int> foodsRating;
    unordered_map<string, string> foodsCuisine;
    unordered_map<int, priority_queue<pair<int, string>, vector<pair<int,string>>, compare>> cuisineRatings;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i < foods.size(); i++)
        {
            foodsRating[foods[i]] = ratings[i];
            foodsCuisine[foods[i]] = cuisines[i];
            if (cuisineIndex.count(cuisines[i]) == 0)
            {
                int tmpSize = cuisineRatings.size() + 1;
                cuisineRatings[tmpSize] = priority_queue<pair<int, string>, vector<pair<int,string>>, compare> ();
                cuisineIndex[cuisines[i]] = tmpSize;
            }
            
            int tmpIndex = cuisineIndex.find(cuisines[i])->second;
            cuisineRatings[tmpIndex].push({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        foodsRating[food] = newRating;
        string tmpCuisine = foodsCuisine[food];
        int tmpIndex = cuisineIndex.find(tmpCuisine)->second;
        cuisineRatings[tmpIndex].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        int tmpIndex = cuisineIndex.find(cuisine)->second;
        pair<int, string> tmpPair = cuisineRatings[tmpIndex].top();
        int tmpRate = tmpPair.first;
        string tmpFood = tmpPair.second;
        while (tmpRate != foodsRating[tmpFood])
        {
            cuisineRatings[tmpIndex].pop();
            tmpPair = cuisineRatings[tmpIndex].top();
            tmpRate = tmpPair.first;
            tmpFood = tmpPair.second;
        }
        
        return tmpFood;
    }
};

