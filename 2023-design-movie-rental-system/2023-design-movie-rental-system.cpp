class MovieRentingSystem {
private:
    map<int, set<pair<int, int>>> available_movies;
    set<tuple<int, int, int>> rented_movies;
    map<pair<int, int>, int> prices;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            prices[{shop, movie}] = price;
            available_movies[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        if (available_movies.count(movie)) {
            auto& shops = available_movies.at(movie);
            int count = 0;
            for (const auto& p : shops) {
                if (count >= 5) break;
                result.push_back(p.second); 
                count++;
            }
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = prices.at({shop, movie});
        
        available_movies.at(movie).erase({price, shop});
        rented_movies.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = prices.at({shop, movie});

        rented_movies.erase({price, shop, movie});
        available_movies.at(movie).insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (const auto& t : rented_movies) {
            if (count >= 5) break;
            result.push_back({get<1>(t), get<2>(t)});
            count++;
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */