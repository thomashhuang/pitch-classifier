import requests
import regex
import pandas as pd

pitcher_id = 543294

r = requests.get("http://www.brooksbaseball.net/tabs.php?player={}&p_hand=-1&ppos=-1&cn=200&compType=none&gFilt=&time=month&minmax=ci&var=gl&s_type=2&startDate=03/30/2008&endDate=10/17/2019&balls=-1&strikes=-1&b_hand=-1".format(pitcher_id))


fx_url_base = "http://www.brooksbaseball.net/pfxVB/tabdel_expanded.php?pitchSel={}&game={}/&s_type=3&h_size=700&v_size=500"

game_ids = []

for line in r.text.splitlines():
    if "gid" in line and len(line) < 500:
        game_id_begin = line.index("game=") + len("game=")
        game_id_end = line.index("/", game_id_begin)
        game_ids.append(line[game_id_begin:game_id_end])

# r = requests.get(fx_url_base.format(pitcher_id, game_ids[0]))
print("Found {} games.".format(len(game_ids)))

game_dfs = []

games_processed = 0
for game in game_ids:
    df = pd.read_html(fx_url_base.format(pitcher_id, game))
    game_dfs.append(df[0])
    games_processed += 1
    print("Processed game {}/{}".format(games_processed, len(game_ids)))

full_pitch_history = pd.concat(game_dfs, ignore_index=True)
full_pitch_history = full_pitch_history[full_pitch_history.des != "Intent Walk"]

print("Loaded {} pitches".format(full_pitch_history.count()))

full_pitch_history = full_pitch_history[["mlbam_pitch_name", "spin", "ftime", "pfx_x", "pfx_z", "start_speed"]]

data_path = "../data/{}.csv".format(pitcher_id)

full_pitch_history.to_csv(data_path)

