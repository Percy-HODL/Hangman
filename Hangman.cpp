#include <iostream>
#include <vector>
#include <cstdlib>

std::string getword(){
    std::vector<std::string> words = {"hangman","quip","games","have","pain","distain","dictionary"};
    std::srand(time(0));
    size_t word_i = words.size();
    word_i = std::rand() % word_i;
    std::string word = words[word_i];
    return word;

}
void print_guesses(std::vector<char> guess){
    for(size_t i = 0; i < guess.size(); ++i){
        std::cout << guess[i] << " ";
    }
    std::cout << "\n";

}
std::vector<int> findIndexesOfLetter(const std::string& word, char letter) {
    std::vector<int> indexes;

    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == letter) {
            indexes.push_back(i);
        }
    }

    return indexes;
}
int main(){

    u_int32_t strikes = 0;
    std::string player_guess;
    std::vector<char> guesses = {};
    std::vector<char> wrong_guesses = {};
    std::string word = getword();
    
    for(int i = 0; i < word.length(); i++){
        std::cout << "? ";
            guesses.emplace_back('?');
        }
    do{
        std::cout << " \nPlease guess a letter: \n";
        std::cin >> player_guess;
        if(player_guess == word){
            break;

        }

        
        for(int i = 0; i < word.length(); i++){
            bool check = false;
            char compare = word[i];
            
            if((i == word.length() - 1 ) && (check == false)){
                std::cout << "That letter is not in the word ";
                strikes++;
                wrong_guesses.emplace_back(player_guess[0]);
            }
            
            if(compare == player_guess[0]){
                std::cout << "Well done, that letter is in the word\n";
                std::vector<int> indexes = findIndexesOfLetter(word,player_guess[0]);
                if(indexes.size() > 1){
                    for(int i = 0; i < indexes.size(); i++){
                        int index = indexes[i];
                        guesses[index] = player_guess[0];
                    }
                }
                if(indexes.size() == 1){
                    guesses[i] = player_guess[0];
                }
                

                check = true;
                break;
            }
            
            


            
            


        }
        print_guesses(guesses);

    }while ((strikes <= 10) &&(player_guess != word));

    if(player_guess == word){
        std::cout << "Well done, you guessed the word with " << strikes << " strikes";
    }
    if(strikes == 10){
        std::cout << "Unlucky for you, you have ran out of letters to guess, the word was " << word;
    }
    return 0;
}
        
