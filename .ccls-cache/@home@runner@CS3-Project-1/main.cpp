//Han Nguyen, 09/01, Period 6

//imported files
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>


using namespace std;

//defining functions
  //prints out the menu and gets user input
    void outputMenu();
  //filters through options to do function
    void performanceFilter();
  //gets the text to be analyzed
    void getUserTextInput();
  //to loop agian
    string getUser();
  //gets the type of analyses
    void getUserOptionInput();
  //makes everything lowercase
    string toLower(string);
  //others are self explanatory 
    int wordCount(string);
    string charFrequency(string);
    string findandrep(string, string, string);
    bool isPalindrome(string);
    string subStringSearch(string, string);
    string wordCapitalization(string);
    void textStatistics(string);

//global variables
  string userMenuInput;
  string userTextInput;

//main method
int main() {
  outputMenu();
}

//prints out menu
  void outputMenu() {
    //variables
    string runAgain = "yes";
    bool runAgainBool = true;
    
    //menu print
      cout << "\nDifferent Types of Text Analyses" << "\n\n| 'Word Count'- \n|    counts the number of words \n|\n| 'Character Frequency'- \n|    frequency of each characters(lower & uppercase are diff. characters) \n|\n| 'Find and Replace'- \n|    replace all occurences of a word with another \n|\n| 'Palindrome Check'- \n|    check if word is a palindrome \n|\n| 'Substring Search'- \n|    display all indices of a substring in the text \n|\n| 'Word Capitalization'- \n|    capitalized the first letter of all words \n|\n| 'Text Statistics'- \n|    finds the average word length and the longest word(s) " << endl;
    //ask user to select option
      getUserOptionInput();
        //filters user input to find function
          performanceFilter();
        //if run program again
          runAgain = getUser();
            while(runAgain == "yes") {
              cout << "\n--------------------------------------\n";
                getUserOptionInput();
                performanceFilter();
              runAgain = getUser();
            }
          cout << "\n\n--------------------------------------\n\n" << "Thank you!!";
  }

string getUser() {
  string temp;
   cout << "\n\nWould you like to run another analysis? Please type |yes| or |no|: ";
            getline(cin, temp);
  if(userMenuInput == "find and replace") {
    getline(cin, temp);
  } else if (userMenuInput == "substring search") {
    getline(cin, temp);
  }
            
  return temp;  
}



//filters to find corresponding funcction
  void performanceFilter() {
    //if user wants word count
      if(userMenuInput == "word count") {
        getUserTextInput();
          cout << "\n\nThere are " << wordCount(userTextInput) << " words.\n";
    
    //if user wants character frequency
      } else if (userMenuInput == "character frequency") {
         getUserTextInput();
          cout << charFrequency(userTextInput);
    
    //if user wants find and replace
      } else if (userMenuInput == "find and replace") {
          getUserTextInput();
            //variables
              string replace;
              string word;
            //output to get replace and word that replaces
              cout << "\n\nWord to Replace: ";
                cin >> replace;
              cout << "Replace with what word?: ";
                cin >> word;
              cout << "\nNew text: " << findandrep(userTextInput, word, replace) << "\n";
    
    //if user wants palindrome check
      } else if (userMenuInput == "palindrome check") {
          getUserTextInput();
            if(isPalindrome(userTextInput)) {
              cout << "\n\nYes, it is a palindrome.\n";
            } else {
                cout << "\n\nNo, it is not a palindrome.\n";
            }
      
    //if user wants substring search
      } else if (userMenuInput == "substring search") {
          getUserTextInput();
            string pat;
            cout << "\n\nType text pattern you want to know the index(s) of: ";
              cin >> pat;
                cout << "\nIndex(s): \n" << subStringSearch(userTextInput, pat);
    
    //if user wants word capitalization
      } else if (userMenuInput == "word capitalization") {
          getUserTextInput();
          cout << "\n\nNew text: " << wordCapitalization(userTextInput) << "\n";
    
    //if user wants text statistics
      } else if (userMenuInput == "text statistics") {
          getUserTextInput();
            textStatistics(userTextInput);
        
    //if user inputs value not acceptable
      } else {
        cout << "\n--------------------------------------\n" << "\n -Invalid option, please try again. Make sure your spelling is correct.\n" << "\n--------------------------------------\n";
          getUserOptionInput();
          performanceFilter();
         
      }  
  }


//get text userInput
  void getUserTextInput() {
    cout << "Insert the text to be analyzed: ";
        getline(cin, userTextInput);
    cout << "\n--------------------------------------";
    return;
  }

//get option userInput
  void getUserOptionInput() {
     cout << "\nPlease select one of the options from the menu: ";
        getline(cin, userMenuInput);
        //so its not capsensitive
          userMenuInput = toLower(userMenuInput);
  }

//changes input to lowercase
  string toLower(string str) {
      for(int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
      }
    return str;
  }


//word count
  int wordCount(string str) {
    int wordCountVar = 1;
    //iterate to add number when find space
    for(int i = 0; i < str.length(); i++) {
      if(str[i] == ' ') {
        wordCountVar++;
      }
    }
    return wordCountVar;
  }


//character frequency
  string charFrequency(string str) {
    str = toLower(str);
    //varaiables
      list<string> existingCharacters;
        list<string>::iterator iterate;
      list<string> strAsList;
      list<int> existingFreq;
        list<int>::iterator iterateInt;
      list<double> percentage;
        list<double>::iterator iterateDouble;
      string currChar;
   
    
    //puts characters into list
      for(int i = 0; i < str.length(); i++) {
          if(str[i] != ' ') {
            if(str[i] != ',') {
              if(str[i] != '.') {
                if(str[i] != '!') {
                  if(str[i] != '?') {
                    if(str[i] != '\'') {
                      existingCharacters.push_back(str.substr(i,1));
                      strAsList.push_back(str.substr(i,1));
                    }
                  }
                }
              }
            }
          }
      }    
    //sets iterate to beginning of existingCharacters list
      iterate = existingCharacters.begin();
    
    //sorts existing characters in "ascending order" 
      existingCharacters.sort();
    //unique removes the letters after the first letter(to each letter)
    existingCharacters.erase(unique(existingCharacters.begin(), existingCharacters.end()), existingCharacters.end());
    
    //iterates through existing characters list
      for(int i = 0; i < existingCharacters.size(); i++) {
        //count each character
          int count = 0;
          iterate = existingCharacters.begin();
          advance(iterate, i);
          currChar = *iterate;

          //iterate through string
            for(int o = 0; o < str.length(); o++) {
              //if beginning letter matches
              if(currChar.compare(str.substr(o,1)) == 0) {
                count++;
              }
            }
        double count1 = count;
        double size = strAsList.size();
        double freq = count1/size;
          freq *= 100;
        //adds the count to the existingFreq list
          existingFreq.push_back(count);
          percentage.push_back(freq);
      }
    
  //prints the frequency of each letter
      cout << "\n\n";
    for(int i = 0; i < existingCharacters.size(); i++) {
      iterate = existingCharacters.begin();
      iterateInt = existingFreq.begin();
      iterateDouble = percentage.begin();
        advance(iterateInt,i);
        advance(iterate, i);
        advance(iterateDouble, i);
          cout << *iterate + " : " << *iterateInt << " : " << *iterateDouble << "%\n";
    }
    return "";
  }


//find and replace pt 
  string findandrep(string str, string replacew, string wtreplace) {
    //finds the index of the first word to replace
      int occurence = str.find(wtreplace);
    
    //while there is still another word to replace
    while(occurence != -1) {
      str.replace(occurence, wtreplace.length() , replacew);
      occurence = str.find(wtreplace);
    }
    return str;
  }


//palindrome
  bool isPalindrome(string str) {
    //variable
      string reversed = "";
      bool isPalindrome = false;
    
    //reverse str
      for(int i = 0; i < str.length(); i++) {
        reversed = str[i] + reversed;
      }
    
    //checks to see if reverse and str are the same
      if(reversed.compare(str) == 0) {
        return true;
      } else {
        return false;
      }
  }


//substring search
  string subStringSearch(string str, string pattern) {
    //variables
      string finalResult;
      int lengthOfPattern = pattern.length();
      char firstLetterPattern = pattern.at(0);
    
    //iterate through string
      for(int i = 0; str[i] != '\0'; i++) {
        //if the first letters match
          if(firstLetterPattern == str[i]) {
            //if rest of word matches
              if(str.substr(i,lengthOfPattern) == pattern) {
                //finds last index and adds to finalResult
                  int lastIndex = lengthOfPattern + i;
                  finalResult += to_string(i) + "-" + to_string(lastIndex) + "\n";
              }
          
          }
      }
    return finalResult;
  }


//word capitalization
  string wordCapitalization(string str) {
    //varaibles
      list<string> wordList;
      list<string>::iterator iterate;
      string eachWord;
      string finalResult;
      str += " ";
    
    //add words to list
      for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ') {
          eachWord += str[i];
        } else {
          wordList.push_back(eachWord);
          wordList.push_back(" ");
          eachWord = "";
        }
      }
    
    //capitalizes first letter
      for(int i = 0; i < wordList.size(); i++) {
        iterate = wordList.begin();
        advance(iterate, i);
          string temp = *iterate;
          char first = temp[0];
          first = toupper(first);
          temp = temp.substr(1);
          finalResult += first + temp;
      }
  return finalResult;
}


//text statistics
  void textStatistics(string str) {
    //variables
      list<string> wordList;
      list<string> multipleAnswersString;
        list<string>::iterator iterate = wordList.begin();
        list<string>::iterator iterateMAS;
          int longestLength = 0;
          double averageLength = 0;
          int indexLongestLength;
            string eachWord;
    //add words to list
      str += " ";
        for(int i = 0; str[i] != '\0'; i++) {
          if(str[i] != ' ') {
            if(str[i] != ',') {
              if(str[i] != '.') {
                if(str[i] != '!') {
                  if(str[i] != '?') {
                    if(str[i] != '\'') {
                      eachWord += str[i];
                    }
                  }
                }
              }
            }
          } else {
            wordList.push_back(eachWord);
            eachWord = "";
          }
        }
    
    //iterates through wordList to find longest word and average word length
      for(int i = 0; i < wordList.size(); i++) {
          iterate = wordList.begin();
          advance(iterate, i);
          string temp = *iterate;
        if(temp.length() > longestLength) {
          multipleAnswersString.clear();
            multipleAnswersString.push_back(temp);
              longestLength = temp.length();
              indexLongestLength = i;
        } else if (temp.length() == longestLength) {
            multipleAnswersString.push_back(temp);
        }
          averageLength += temp.length();
      }
    
    //print 
      iterate = wordList.begin();
        //no multiple answers for longest
          if(multipleAnswersString.size() == 1) {
                advance(iterate, indexLongestLength);
                  cout << "\n\nThe longest word is " + *iterate + " with a length of " << longestLength;
            
        //multiple answers for longest
          } else {
              cout << "\n\nThere longest words are ";
                for(int i = 0; i < multipleAnswersString.size(); i++) {
                  iterateMAS = multipleAnswersString.begin();
                    advance(iterateMAS, i);
                    cout << *iterateMAS;
                  //to print, or not to print comma
                    if(i != multipleAnswersString.size()-1) {
                        cout << " and ";
                    }
                }
            cout<< " with a length of " << longestLength;
          }
    double size = wordList.size();
    double avg = averageLength / size;
    cout << "\nThe average length of your input is: " << avg << "\n";
        
  }


