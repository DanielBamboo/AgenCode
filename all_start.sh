#!/bin/bash

rcssserver server::auto_mode=on &  # automatically start the game

cd ~/college/football/agent2d-3.1.1/src
./start.sh # ou ./start.sh -n x  where x is the number of players you want to load

#cd ~/下载/helios2018-bin/
#cd ~/college/football/learned-agent2d/src
#cd ~/college/football/Agent2D/YuShan-Base/YuShan-EXE
cd ~/college/football/Agent2D-NNChain/src
./start.sh # ou ./start.sh -n x  onde x é o número de jogadores que você deseja carregar

soccerwindow2 --hide-view-area --hide-stamina # or rcssmonitor

set -e
function stop_server {   
    pkill rcssserver
}

trap stop_server EXIT
