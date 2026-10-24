class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> noOfDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int aMonthAlice = stoi(arriveAlice.substr(0, 2));
        int aDateAlice = stoi(arriveAlice.substr(3, 2));
        int lMonthAlice = stoi(leaveAlice.substr(0, 2));
        int lDateAlice = stoi(leaveAlice.substr(3, 2));
        int aMonthBob = stoi(arriveBob.substr(0, 2));
        int aDateBob = stoi(arriveBob.substr(3, 2));
        int lMonthBob = stoi(leaveBob.substr(0, 2));
        int lDateBob = stoi(leaveBob.substr(3, 2));

        int stMonth = max(aMonthAlice, aMonthBob);
        int endMonth = min(lMonthAlice, lMonthBob);
        int stDate, endDate;

        if(stMonth == aMonthAlice && stMonth == aMonthBob) stDate = max(aDateAlice, aDateBob);
        else if(stMonth == aMonthAlice) stDate = aDateAlice;
        else stDate = aDateBob;

        if(endMonth == lMonthAlice && endMonth == lMonthBob) endDate = min(lDateAlice, lDateBob);
        else if(endMonth == lMonthAlice) endDate = lDateAlice;
        else endDate = lDateBob;

        if(stMonth > endMonth || (stMonth == endMonth && stDate > endDate)) return 0;

        if(stMonth == endMonth) return endDate - stDate + 1;
        int days = noOfDays[stMonth - 1] - stDate + 1;
        days += endDate;
        for(int i = stMonth + 1; i < endMonth; i++) {
            days += noOfDays[i - 1];
        }
        return days;
    }
};