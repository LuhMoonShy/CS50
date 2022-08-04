import csv
import sys
import random
N = 1000
def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")
    teams = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            team = row["team"]
            rating = int(row["rating"])
            teams.append({"team" : team, "rating" : rating})
    counts = {}
    for i in range(N):
        champion = simulate_tournament(teams)
        if champion in counts:
            counts[champion] += 1
        else:
            counts[champion] = 1
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")
def simulate_game(team1, team2):
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability
def simulate_round(teams):
    winners = []
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners
def simulate_tournament(teams):
    while len(teams) > 1:
        teams = simulate_round(teams)
    winner = teams[0]["team"]
    return winner
if __name__ == "__main__":
    main()