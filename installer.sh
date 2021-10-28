#!/bin/bash

# name:					deploy_ututor_SSJ.sh
# author:				Jin Jose Manuel Serrano Amaut
# description:          Script for deployment of uTutor.net
# Updates the project from upstream, builds it and serves it.  It is meant
# to be used in the production server.

##############################
# Colors
##############################

SPECIAL='\e[7;49;96m'
NORMAL='\e[0m'
BLUE='\e[36m'
BOLD='\e[1m'
TITULO='\e[7m'
BLINK='\e[5m'
##############################
# Global variables
##############################

readonly UPSTREAM_BRANCH=develop
readonly BUILD_DIR=build
readonly PM2_PROCESS_NAME=uTutor_net
readonly LOG_DIR=/home/ubuntu/uTutor_net/logs
readonly BACKEND_REPO=https://github.com/JinSSJ3/uTutor_backend.git

readonly FRONTEND_REPO_FFFF=https://github.com/Dlumior/ututor-front.git

##############################
# Modules
##############################

# Checks the if the last command failed.  If so, prints a message an exits.
function check_last_command_error() {
    if [ $? -ne 0 ]; then
        echo >&2 echo "error: " . $1
        exit 1
    fi
}
# Checks if both .env and .env.example have the same number of lines. If so, exits will error.
function check_env_diff() {
    local dotenv_lines=$(cat .env | wc -l)
    local dotenv_example_lines=$(cat .env.example | wc -l)

    if [ $dotenv_lines -ne $dotenv_example_lines ]; then
        echo >&2 echo "error: .env doesn't have all the variables in .env.example"
        exit 1
    fi
}
# Imprimir mesaje
function special_SSJ() {
    echo -e "${SPECIAL}" $1 "${NORMAL}"
    #exit 1
}
function tittle_SSJ() {
    echo -e "${TITULO}" $1 "${NORMAL}"
    #exit 1
}
function NORMAL() {
    echo -e "${NORMAL}" $1 "${NORMAL}"
    #exit 1
}
function await() {
    sleep 2s
}
function awaitMini() {
    sleep 1s
}
function finsection() {
    clear
}
function main() {
    clear
    #sudo -s
    # echo "Checking that .env file exists ..."

    # echo "Checking that .env file is updated ..."
    # check_env_diff

    echo "*********************************************************"
    echo "*********************************************************"
    echo "**                                                     **"
    echo "**        BIENVENIDO SR. JIN JOSE MANUEL SSJ3          **"
    echo "**                                                     **"
    echo "*********************************************************"
    echo "*********************************************************"

    await

   
    tittle_SSJ "Iniciando descarga automatica de dependencias para ${SPECIAL}Quantum asset"
    tittle_SSJ "Profavor espere..."

   
    # First FIRST FIRST
    special_SSJ "Instalando dependencias necesarias"
    await
    tittle_SSJ "..."
    finsection

    tittle_SSJ "Actualizando Linux"
    await
    sudo apt-get update -y
    finsection

    tittle_SSJ "Instalando"
    special_SSJ "=> node.js"
    await
    sudo apt install nodejs -y
    finsection

    tittle_SSJ "Instalando"
    special_SSJ "=> NPM"
    await
    sudo apt install npm -y
    npm -v or npm version

    curl -sL https://deb.nodesource.com/setup_14.x | sudo -E bash -
    sudo apt-get install -y nodejs
    finsection

    tittle_SSJ "Version Obtenida de NPM"
    node -v
    await
    finsection


    tittle_SSJ "INstalando C compiler"
    sudo apt install build-essential -y
    await
    finsection

    tittle_SSJ "Actualizando Linux denuevo"
    await
    sudo apt-get update -y
    sudo apt-get upgrade -y
    finsection

    tittle_SSJ "descargando repositorio"
    await
    cd ..
    sudo git clone https://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@github.com/quantum-asset/backend.git
    finsection

    tittle_SSJ "Instalando dependencias"
    await
    cd backend
    npm install
    finsection

    tittle_SSJ "Iniciando servidor"
    await
    cp ../deployer/saiyan-server .
    finsection

    tittle_SSJ "Actualizando Linux denuevo"
    await
    ./saiyan-server
    finsection

    special_SSJ "Descarga e instalación automatica de NPM y backend completada"
    tittle_SSJ "Un gusto haberlo ayudado Sr. Jin José Manuel"
    tittle_SSJ "Hasta la proxima :D"

    sudo reboot

    exit 0
}

main $@
