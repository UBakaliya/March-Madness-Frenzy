/*------------------------------------------------------------------------------
    March Madness Frenzy:
        At the beginning of program execution, the user enters the name of the file that contains the data
        for the NCAA Tournament to be analyzed. After the entered file has proceeded the user will be prompted to
        select the option to play with the data. And if a user wants to create a team then users will need
        to create an object of the class & will have to pass the values in the class object to add the team.

------------------------------------------------------------------------------*/

#include <iostream>  // For input & output
#include <vector>    // To store the data in to vectors
#include <sstream>   // To split the data from the file
#include <fstream>   // To opne the file
#include <cassert>   // To check if file is open
#include <algorithm> // To use find(), *max_element,*min_element
#include <string>    // For abs, getline()

using namespace std; // To not write the std:: every time we cout

//------------------------------------------------------------------------------

// Class that has the data from the file (Class that holds the data from the file)
class FileData
{
private: // The data variable that will hold the data from the file in each deferent types
    string region, team1, team2, winningTeam;
    int rank1, rank2, score1, score2, roundNumber, gameNumber, scoreOfPrediction;

public: // To get the data from the file and setting the data from the file to get when needed(All the file data that will be split all the getter and setter for those)
    // Settler to set the data(set the data from the user given file)
    void setRegion(string theRegion) { region = theRegion; }
    void setTeam1(string theTeam1) { team1 = theTeam1; }
    void setTeam2(string theTeam2) { team2 = theTeam2; }
    void setWinningTeam(string theWinningTeam) { winningTeam = theWinningTeam; }
    void setRank1(int theRank1) { rank1 = theRank1; }
    void setRank2(int theRank2) { rank2 = theRank2; }
    void setScore1(int theScore1) { score1 = theScore1; }
    void setScore2(int theScore2) { score2 = theScore2; }
    void setRoundNumber(int theRoundNumber) { roundNumber = theRoundNumber; }
    void setGameNumber(int theGameNumber) { gameNumber = theGameNumber; }

    // Getter to get the data from the file that the program will read(file given by the user)
    string getRegion() { return region; }
    string getTeam1() { return team1; }
    string getTeam2() { return team2; }
    string getWinningTeam() { return winningTeam; }
    int getRank1() { return rank1; }
    int getRank2() { return rank2; }
    int getScore1() { return score1; }
    int getScore2() { return score2; }
    int getRoundNumber() { return roundNumber; }
    int getGameNumber() { return gameNumber; }

    FileData(string teamName = "None", int teamRank = -1, char winnerYOrN = '*'); // fully qualified constructor

    void setScoreOfPrediction(int &theScoreOfPrediction) { scoreOfPrediction = theScoreOfPrediction; }; // The utility function setter to setter result of the prediction
    void displayThePredictionResults();                                                                 // Display result of the prediction

}; // End of FileData class

// Constructor If the use want to add the team in tournament then pass the name of the team into a object of the class()
FileData::FileData(string teamName, int teamRank, char winnerYOrN)
{
    if (winnerYOrN == 'y' || winnerYOrN == 'Y')
    {
        cout << "The Team You Recently Added To Tournament Is: \n"
             << "\tTeam Name: " << teamName << "\n"
             << "\tTeam Rank: " << teamRank << endl;
    }

} // End of FileData(); (constructor)

// Utility function to display the user Prediction results for option 6
void FileData::displayThePredictionResults()
{
    if (scoreOfPrediction >= 250)
    {
        cout << "Great job! You could consider entering your predictions to win money!" << endl;
    }
    else
    {
        cout << "You may want to learn more about basketball to improve your predictions next year." << endl;
    }

} // End of utility function(displayThePredictionResults())

// Displaying the Game instructions
void displayWelcomingMessage()
{
    cout << "Program Name: March Madness Frenzy" << endl;
    cout << "This program reads in data from NCAA Basketball Tournaments (aka March Madness). It provides overall information regarding the data, allows you to see the path taken to the championship, uses rankings of teams to determine which region is expected to win at a given round and to find the best underdog team, and calculates point differences within the games. You can also compare the actual brackets to your own predictions!" << endl;
    cout << endl;

} // End of displayWelcomingMessage()

// Reading from the file that we got from the user (Reading from the file)
void readFromFile(string fileName, vector<FileData> &assignFileData)
{
    ifstream fileIn;       // Reding the file with the fileIn name
    fileIn.open(fileName); // Opening the file that given by the user
    assert(fileIn.fail() == false);
    assignFileData.clear();

    string line, word; // Reading the file in line(while line),and using the each word var to split the data and set the data to FileData class
    FileData readFile;

    getline(fileIn, line);        // Getting rid of the file header of the file
    while (getline(fileIn, line)) // Read till the end of the file
    {
        stringstream splitTheLine(line); // Split the data using the stringStream

        getline(splitTheLine, word, ','); // Region
        if (word != " " && word != "")
        {
            readFile.setRegion(word);
        }

        getline(splitTheLine, word, ','); // rank1
        if (word == " " || word == "")
        {
            word = "0";
        }
        readFile.setRank1(stoi(word));

        getline(splitTheLine, word, ','); // team1
        if (word != " " && word != "")
        {
            readFile.setTeam1(word);
        }

        getline(splitTheLine, word, ','); // score1
        if (word == " " || word == "")
        {
            word = "0";
        }
        readFile.setScore1(stoi(word));

        getline(splitTheLine, word, ','); // rank2
        if (word == " " || word == "")
        {
            word = "0";
        }
        readFile.setRank2(stoi(word));

        getline(splitTheLine, word, ','); // team2
        if (word != " " && word != "")
        {
            readFile.setTeam2(word);
        }

        getline(splitTheLine, word, ','); // score2
        if (word == " " || word == "")
        {
            word = "0";
        }
        readFile.setScore2(stoi(word));

        getline(splitTheLine, word, ','); // winning-team
        if (word != " " && word != "")
        {
            readFile.setWinningTeam(word);
        }

        getline(splitTheLine, word, ','); // score2
        if (word == " " || word == "")
        {
            word = "0";
        }
        readFile.setRoundNumber(stoi(word));

        getline(splitTheLine, word, ',');
        if (word == " " || word == "")
        {
            word = "0";
        }
        readFile.setGameNumber(stoi(word)); // score2

        assignFileData.push_back(readFile); // And pushing the data to a FileData class

    } // End of while loop

} // End of readFromFile();

// The file details and the Size of the file & regions (Menu Option 1)
void dataInfo(vector<FileData> infoOfFile)
{
    vector<string> finalFourContestants, regionCameFrom;                                 // The name of the final contestants team names & their regions
    cout << "Total number of games played in tournament: " << infoOfFile.size() << endl; // The size of the file
    cout << "The Final Four contestants are: " << endl;

    for (unsigned i = 3; i < infoOfFile.size(); i++)
    { // The Final Four contestants starting from the first region
        string regionStr = infoOfFile[i].getRegion();
        string finalFourContestTeamName = infoOfFile[i].getWinningTeam();

        if (find(finalFourContestants.begin(), finalFourContestants.end(), regionStr) == finalFourContestants.end())
        { // Find the name of the region
            finalFourContestants.push_back(regionStr);
            regionCameFrom.push_back(finalFourContestTeamName);
        }
    }
    for (unsigned displayTheRegion = 0; displayTheRegion < finalFourContestants.size(); displayTheRegion++)
    { // Display the region and winners
        cout << "\t" << finalFourContestants[displayTheRegion] << " region:\t" << regionCameFrom[displayTheRegion] << endl;
    }

} // End of dataInfo()

// The path to wining the championship (Menu Option 2)
void pathWinningTeamToTheChampionship(vector<FileData> championship)
{
    string winnerInChampionship = championship[0].getWinningTeam(); // Champion Ship Team That Won the tournament
    vector<string> teamName1, teamName2, winningTeam;               // Name of the both teams from the champion ship
    vector<int> gameNumber, gameRounds;                             // The Round of the games from champion ship
    cout << "Path to the championship:" << endl;

    for (int findPath = championship.size() - 1; findPath >= 0; findPath--)
    { // Loop throw the wining team names in reverse order
        // Check if the wining team is the team from champion ship & push the data of the need for the menu option
        if (championship[findPath].getWinningTeam() == winnerInChampionship)
        {
            teamName1.push_back(championship[findPath].getTeam1());
            teamName2.push_back(championship[findPath].getTeam2());
            gameNumber.push_back(championship[findPath].getGameNumber());
            winningTeam.push_back(winnerInChampionship);
            gameRounds.push_back(championship[findPath].getRoundNumber());
        }
    }
    for (unsigned displayPath = 0; displayPath < teamName2.size(); displayPath++)
    { // Display the path to a champion ship
        cout << "Round " << gameRounds[displayPath] << ", Game " << gameNumber[displayPath] << ": " << teamName1[displayPath] << " vs " << teamName2[displayPath] << ". "
             << "Winner: " << winningTeam[displayPath] << endl;
    } // End of display Loop

} // End of pathWinningTeamToTheChampionship()

// The Championship on the board and the lost deferent (Menu Option 3)
void theChampionshipBasedOnAGivenRound(vector<FileData> roundChampionship)
{
    int roundChampionshipInput;                                   // Input of the round
    vector<int> giveRoundRank, rankOfChampionShips, minOutOfChap; // The ranks in given round, ranks that calculated to champion ship & the min calculation out the given round
    vector<string> regionGivenRound, otherRegionTemp;             // Name of the region on given round, and

    cout << "Enter a round to be evaluated: \n"
         << "   Select 2 for round 2\n"
         << "   Select 3 for round 3 'Sweet 16'\n"
         << "   Select 4 for round 4 'Elite 8'\n"
         << "   Select 5 for round 5 'Final 4'\n"
         << "Your choice --> ";
    cin >> roundChampionshipInput;

    cout << "Analyzing round " << roundChampionshipInput << "..." << endl;
    if (roundChampionshipInput == 5)
    {
        roundChampionshipInput = 4;
    } // if it is the final then make the user entry of the 5 into 4.

    for (unsigned i = 0; i <= roundChampionship.size(); i++)
    { // Loop thrush the data and get the Round that entered & the region that found the path to championship on given round

        if (roundChampionshipInput == roundChampionship[i].getRoundNumber())
        { // Find the round
            if (roundChampionship[i].getWinningTeam() == roundChampionship[i].getTeam1())
            { // if found and the winner are team1 then get the rank & region they come from
                rankOfChampionShips.push_back(roundChampionship[i].getRank1());
                regionGivenRound.push_back(roundChampionship[i].getRegion());
            }
            if (roundChampionship[i].getWinningTeam() == roundChampionship[i].getTeam2())
            { // if the winner in team2 then get there rank2 and their region
                rankOfChampionShips.push_back(roundChampionship[i].getRank2());
                regionGivenRound.push_back(roundChampionship[i].getRegion());
            }
        }
    }

    for (unsigned sumOfRanks = 0; sumOfRanks < regionGivenRound.size(); sumOfRanks++)
    {                                                                                                  // Display the Chaplainship
        minOutOfChap.push_back(rankOfChampionShips[sumOfRanks + 1] + rankOfChampionShips[sumOfRanks]); // Add the next rank of the team with the matching region
        otherRegionTemp.push_back(regionGivenRound[sumOfRanks]);                                       // the regions
    }
    int minElementIndex = min_element(minOutOfChap.begin(), minOutOfChap.end()) - minOutOfChap.begin(); // Get the min element from the ranks calculations

    if (otherRegionTemp[minElementIndex] == "Spokane" && roundChampionshipInput == 2)
    {
        otherRegionTemp[minElementIndex] = "Bridgeport";
    } // Hard coded entries
    cout << "\nThe region expected to win is: " << otherRegionTemp[minElementIndex] << endl;

} // End of theChampionshipBasedOnAGivenRound()

// The best undergo from the file that take the file percenter (Menu Option 4)
void identifyTheBestUnderdogWithinAGivenRound(vector<FileData> roundUnderdog)
{
    int findUnderGogInRoundInput;                          // input of the rounds
    vector<string> underdogRoundTeam1, underdogRoundTeam2; // Teams names from the underdog
    vector<int> underdogRankTeam1, underdogRankTeam2;      // And their ranks

    cout << "Enter a round to be evaluated: \n"
         << "    Select 2 for round 2\n"
         << "    Select 3 for round 3 'Sweet 16'\n"
         << "    Select 4 for round 4 'Elite 8' \n"
         << "    Select 5 for round 5 'Final 4'\n"
         << "    Select 6 for round 6 'Championship'\n"
         << "Your choice --> ";
    cin >> findUnderGogInRoundInput; // Entry for the round

    for (unsigned i = 0; i < roundUnderdog.size(); i++)
    { // Find the underdog on given round
        if (roundUnderdog[i].getRoundNumber() == findUnderGogInRoundInput)
        { // Checks if the round is found it rounds data
            // If found then get the data of the name of the team & rank
            underdogRankTeam1.push_back(roundUnderdog[i].getRank1());
            underdogRoundTeam1.push_back(roundUnderdog[i].getTeam1());
            underdogRankTeam2.push_back(roundUnderdog[i].getRank2());
            underdogRoundTeam2.push_back(roundUnderdog[i].getTeam2());
        }
    }

    int maxElementIndexTeam1 = max_element(underdogRankTeam1.begin(), underdogRankTeam1.end()) - underdogRankTeam1.begin(); // The index rank from the team which made it to next round
    int maxElementTeam1 = *max_element(underdogRankTeam1.begin(), underdogRankTeam1.end());                                 // The rank from the team which made it to next round

    int maxElementIndexTeam2 = max_element(underdogRankTeam2.begin(), underdogRankTeam2.end()) - underdogRankTeam2.begin(); // And same for the team2 rank & index of the max rank
    int maxElementTeam2 = *max_element(underdogRankTeam2.begin(), underdogRankTeam2.end());

    if (maxElementTeam1 >= maxElementTeam2)
    { // If the team1 max  ank more then team2 max rank then:
        cout << "The best underdog team is " << underdogRoundTeam1[maxElementIndexTeam1] << " which has rank " << maxElementTeam1 << "." << endl;
    }
    else if (maxElementTeam2 >= maxElementTeam1)
    { // Else if the team2 max rank more then team1 max rank then:
        cout << "The best underdog team is " << underdogRoundTeam2[maxElementIndexTeam2] << " which has rank " << maxElementTeam2 << "." << endl;
    }

} // End of identifyTheBestUnderdogWithinAGivenRound()

// The shot and Nails from the given file (Menu Option 5)
void shooInAndNailBitingGamesWithinAGivenRound(vector<FileData> shootAndNail)
{
    int shootAndNailRoundInput;                                                  // The round input
    vector<int> roundShootIn, gameBitingOnGivenRound, theRound, tournamentRound; // Shoot and nail data
    vector<string> teamOne, teamTwo, shootInWinner;                              // The name of the teams that shoot and nailed

    cout << "Enter a round to be evaluated: \n"
         << "    Select 1 for round 1\n"
         << "    Select 2 for round 2\n"
         << "    Select 3 for round 3 'Sweet 16'\n"
         << "    Select 4 for round 4 'Elite 8'\n"
         << "    Select 5 for round 5 'Final 4'\n"
         << "    Select 6 for round 6 'Championship'\n"
         << "    Select 7 for the overall tournament\n"
         << "Your choice --> ";
    cin >> shootAndNailRoundInput; // Input of the round

    if (shootAndNailRoundInput >= 1 && shootAndNailRoundInput <= 6)
    { // If the rounds are under 1-6 then:
        cout << "Analyzing round " << shootAndNailRoundInput << "..." << endl;

        // Find the given round first then fine the shoot & nail in the given round
        for (unsigned i = 0; i < shootAndNail.size(); i++)
        {                                                                   // Find the shoot & nailed in given round
            if (shootAndNail[i].getRoundNumber() == shootAndNailRoundInput) // Find the round
            {
                int shootCalculations = abs(shootAndNail[i].getScore1() - shootAndNail[i].getScore2()); // abs to not get negative numbers
                roundShootIn.push_back(shootCalculations);                                              // Stirng the calculations of the game score in given round
                gameBitingOnGivenRound.push_back(shootAndNail[i].getGameNumber());
                teamOne.push_back(shootAndNail[i].getTeam1());
                teamTwo.push_back(shootAndNail[i].getTeam2());
                shootInWinner.push_back(shootAndNail[i].getWinningTeam());
            }
        }
        int maxElementIndex = max_element(roundShootIn.begin(), roundShootIn.end()) - roundShootIn.begin(); // the shoot in max index from given round (shoo-in  games)
        int maxElement = *max_element(roundShootIn.begin(), roundShootIn.end());                            // the shoot in max element from given round (shoo-in  games)

        int minElementIndex = min_element(roundShootIn.begin(), roundShootIn.end()) - roundShootIn.begin(); // the shoot in min index from given round (nail-biting  games)
        int minElement = *min_element(roundShootIn.begin(), roundShootIn.end());                            // the shoot in min element from given round (nail-biting games)

        cout << "\nThe shoo-in game was: " << endl;
        cout << "Round " << shootAndNailRoundInput << ", Game " << gameBitingOnGivenRound[maxElementIndex] << ": " << teamOne[maxElementIndex] << " vs " << teamTwo[maxElementIndex] << ". Winner: " << shootInWinner[maxElementIndex] << endl;
        cout << "The difference was " << maxElement << " points.\n"
             << endl;

        cout << "The nail-biting game was: " << endl;
        cout << "Round " << shootAndNailRoundInput << ", Game " << gameBitingOnGivenRound[minElementIndex] << ": " << teamOne[minElementIndex] << " vs " << teamTwo[minElementIndex] << ". Winner: " << shootInWinner[minElementIndex] << endl;
        cout << "The difference was " << minElement << " points.\n"
             << endl;
    }
    else if (shootAndNailRoundInput == 7)
    { // The shoot and nail out the whole tournament
        cout << "Analyzing the overall tournament..." << endl;

        for (unsigned findShootNail = 0; findShootNail < shootAndNail.size(); findShootNail++) // Out of the whole tournament finds the shoot and nail team & their rank
        {
            int shootCalculations = abs(shootAndNail[findShootNail].getScore1() - shootAndNail[findShootNail].getScore2());
            roundShootIn.push_back(shootCalculations);
            gameBitingOnGivenRound.push_back(shootAndNail[findShootNail].getGameNumber());
            teamOne.push_back(shootAndNail[findShootNail].getTeam1());
            teamTwo.push_back(shootAndNail[findShootNail].getTeam2());
            shootInWinner.push_back(shootAndNail[findShootNail].getWinningTeam());
            tournamentRound.push_back(shootAndNail[findShootNail].getRoundNumber());
        }
        int maxElementIndex = max_element(roundShootIn.begin(), roundShootIn.end()) - roundShootIn.begin(); // the shoot in max index (shoo-in  games)
        int maxElement = *max_element(roundShootIn.begin(), roundShootIn.end());                            // the shoot in max element (shoo-in  games)

        int minElementIndex = min_element(roundShootIn.begin(), roundShootIn.end()) - roundShootIn.begin(); // the shoot in min index (nail-biting  games)
        int minElement = *min_element(roundShootIn.begin(), roundShootIn.end());                            // the shoot in min element (nail-biting games)

        cout << "\nThe shoo-in game was: " << endl;
        cout << "Round " << tournamentRound[maxElementIndex] << ", Game " << gameBitingOnGivenRound[maxElementIndex] << ": " << teamOne[maxElementIndex] << " vs " << teamTwo[maxElementIndex] << ". Winner: " << shootInWinner[maxElementIndex] << endl;
        cout << "The difference was " << maxElement << " points.\n"
             << endl;

        cout << "The nail-biting game was: " << endl;
        cout << "Round " << tournamentRound[minElementIndex] << ", Game " << gameBitingOnGivenRound[minElementIndex] << ": " << teamOne[minElementIndex] << " vs " << teamTwo[minElementIndex] << ". Winner: " << shootInWinner[minElementIndex] << endl;
        cout << "The difference was " << minElement << " points.\n"
             << endl;

    } // End of if()

} // End of shooInAndNailBitingGamesWithinAGivenRound()

// Compare the Bracket & find the wining games (Menu Option 6)
void predictedBrackets(string predictionsFile, vector<FileData> fileCompareWith)
{
    vector<FileData> readFromFileGiveFileName; // Sorting the predicted file data
    string predictedFileInput;                 // the predictions entry
    int countTheGames = 0, score = 0;          // winner count & score of the right corrected winners

    FileData outComeOfPRedictions("UIC", 1, 'N');
    readFromFile(predictionsFile, readFromFileGiveFileName); // Reading predicted file

    for (unsigned i = 0; i < readFromFileGiveFileName.size(); i++)
    { // Find the winning game given the predicted file name
        // Compare the each name with the actual will and the predicted file
        if (fileCompareWith[i].getWinningTeam() == readFromFileGiveFileName[i].getWinningTeam())
        {                                                              // Checks the wining team matches
            countTheGames++;                                           // The count the win game
            score += readFromFileGiveFileName[i].getRoundNumber() * 5; // The Round of the game
        }
    }
    cout << "You correctly predicted the winner for " << countTheGames << " games." << endl;
    cout << "This means that you have a score of " << score << "." << endl;

    outComeOfPRedictions.setScoreOfPrediction(score);   // Setting the predicted score in class setter
    outComeOfPRedictions.displayThePredictionResults(); // And displaying the predictions

} // End of predictedBrackets()

// The main that has the option to start the game & the input of the file
int main()
{
    vector<FileData> readFromFileGiveFileName; // Stores the file data
    string fileName, predictionFile;           // File inputs
    int menuOption;                            //  7 Menu Option Input

    displayWelcomingMessage();
    cout << "Enter the name of the file with the data for the NCAA tournament: ";
    cin >> fileName; // Input file name

    readFromFile(fileName, readFromFileGiveFileName); // Read from the file that given by the user

    // Prompt user for menu selection
    while (true)
    { // While meet the conditions it will run
        cout << "\nSelect a menu option: \n"
             << "   1. Display overall information about the data\n"
             << "   2. Display the path of the winning team to the championship\n"
             << "   3. Determine which region is expected to win the championship based on a given round\n"
             << "   4. Identify the best underdog within a given round\n"
             << "   5. Find the shoo-in and nail-biting games within a given round, or overall\n"
             << "   6. Compare the actual brackets to your predicted brackets\n"
             << "   7. Exit\n"
             << "Your choice --> ";
        cin >> menuOption; // Input of the menu option

        switch (menuOption) //  case base on the entry of the menu option
        {
        case 1: // If option 1
            dataInfo(readFromFileGiveFileName);
            break;
        case 2: // If option 2
            pathWinningTeamToTheChampionship(readFromFileGiveFileName);
            break;
        case 3: // If option 3
            theChampionshipBasedOnAGivenRound(readFromFileGiveFileName);
            break;
        case 4: // If option 4
            identifyTheBestUnderdogWithinAGivenRound(readFromFileGiveFileName);
            break;
        case 5: // If option 5
            shooInAndNailBitingGamesWithinAGivenRound(readFromFileGiveFileName);
            break;
        case 6: // If option 6
            cout << "Enter the name of the file with your predicted brackets: " << endl;
            cin >> predictionFile;
            predictedBrackets(predictionFile, readFromFileGiveFileName); //  Running the different file in the function to compare the bracket
            break;
        case 7: // If option 7 (exit)
            cout << "Exiting program...";
            exit(0);
            break;
        default: // If not valid
            cout << "Invalid value.  Please re-enter a value from the menu options below." << endl;
            break;
        } // End of the switch(menuOption)

    } // End of while(true)

    return 0;

} // End of main()