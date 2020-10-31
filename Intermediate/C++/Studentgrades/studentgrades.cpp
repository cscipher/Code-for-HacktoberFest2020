#include "studentgrades.h"
#include <iostream>
#include <vector>
using namespace std;

vector<vector<double>> studentScores ={
        {90,85,75,85,95},
        {85,60,65,95,65},
        {75,70,80,85,90},
        {95,70,75,80,100},
        {75,45,80,60,70}
};

vector<string> studentNames = {
        "Jakob Baloski",
        "Lucinda Pavlov",
        "Daniele Hanston",
        "Yusef Goldstein",
        "Leona Rhee"
};

double sum(vector<double> scores) {
    double result = 0;
    for (int i = 0; i < scores.size(); i++) {
        result += scores[i];
    }
    return result;
}

double max(vector<double> scores) {
    double result = scores[0];
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i] > result) {
            result = scores[i];
        }
    }
    return result;
}

double min(vector<double> scores) {
    double result = scores[0];
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i] < result) {
            result = scores[i];
        }
    }
    return result;
}

double mean(vector<double> scores) {
    return sum(scores) / scores.size();
}

double meanLowestDropped(vector<double> scores) {
    return (sum(scores) - min(scores)) / (scores.size() - 1);
}

vector<vector<double>> transpose(vector<vector<double>> grid) {
    vector<vector<double>> rows;
    for (int row = 0; row < grid.size(); row++) {
        vector<double> temp;
        for (int col = 0; col < grid.size(); col++) {
            temp.push_back(grid[col][row]);
        }
        rows.push_back(temp);
    }
    return rows;
}

char gradeLetter(double meanGrade) {
    if (meanGrade >= 90) {
        return 'A';
    } else if (meanGrade >= 80) {
        return 'B';
    } else if (meanGrade >= 70) {
        return 'C';
    } else if (meanGrade >= 65) {
        return 'D';
    } else {
        return 'F';
    }
}

void printStudentSummary(vector<vector<double>> studentScores, vector<string> studentNames) {
    vector<vector<double>> assignmentScores = transpose(studentScores);

    // PRINT STUDENT RESULTS
    for (int i = 0; i < studentScores.size(); i++) {
        cout << studentNames[i] << endl;
        cout << "Highest score = " << max(studentScores[i]) << endl;
        cout << "Lowest score = " << min(studentScores[i]) << endl;
        double grade = mean(studentScores[i]);
        cout << "Mean = " << grade << " Grade:" << gradeLetter(grade) << endl;  // finish gradeletter function.
        cout << "Mean (lowest dropped) = " << meanLowestDropped(studentScores[i]) << endl;
        cout << "-------------------------------------" << endl;
    }

    // PRINT BLANK LINES
    cout << endl;
    cout << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;
    cout << endl;

    // PRINT ASSIGNMENT RESULTS
    for (int i = 0; i < assignmentScores.size(); i++) {
        cout << "Assignment: " << i + 1 << endl;
        cout << "Highest score = " << max(assignmentScores[i]) << endl;
        cout << "Lowest score = " << min(assignmentScores[i]) << endl;
        double grade = mean(assignmentScores[i]);
        cout << "Mean = " << grade << " Grade:" << gradeLetter(grade) <<  endl;  // finish gradeletter function.
        cout << "Mean (lowest dropped) = " << meanLowestDropped(assignmentScores[i]) << endl;
        cout << "-------------------------------------" << endl;
    }
}

void student_grades() {
    printStudentSummary(studentScores, studentNames);
}