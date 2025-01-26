# 2024_2025_GAUCHÉ_JUMIN
Ce projet fait partie de la formation de l'année 5ISS à l'INSA Toulouse. Nous avons créé un capteur de gaz à nanoparticules à l'AIME, le laboratoire de l'INSA Toulouse.
Ensuite, nous avons réalisé le PCB et développé un code sur ESP32 pour pouvoir utiliser le capteur et afficher ses données sur un interface web.

## SOMMAIRE 
1. [Introduction](#introduction)
2. [Lora](#lora)
3. [LoraWAN](#lorawan)
4. [TTN](#ttn)
5. [LTspice](#ltspice)
6. [KiCad](#kicad) 
7. [Node-RED](#node-red)
8. [Datasheet](#datasheet)
9. [Possible improvements](#possible_improvements)
10. [Contacts](#contact)

## Introduction

Ce projet nous a permis d'aller plus loin dans le développement de notre capteur. 
En effet, nous pouvons maintenant l'utiliser avec un shield, le connecter à TTN et voir les données sur un tableau de bord Node-RED. Le code Arduino utilisé pour récupérer et traiter les données a été adapté à la fois pour le capteur de gaz AIME et pour le capteur industriel grove (MQ-3B) qui nous a été prété en début de projet pour pouvoir simuler le fonctionnement du capteur dévellopé à l'AIME. Le microcontrolleur utilisé est un ESP32, équipé d'un module LoRa intégré.


Dans ce README nous présentons le contenu de ce repository:

- [x] Le code source arduino permettant la collecte des données, leur affichage sur un écran et leur envoie sur le réseau TTN.
- [x] Le schéma de la shield PCB, sa modélisation sous KiCad, et la version finale montée.
- [x] Le flow Node-Red et le dashboard web.
- [x] La datasheet du capteur.

Voici une image du circuit final : <br>
<img src="/Documents/Pictures/ARDUINO.jpg" height="500"> <br>

## Lora
Dans un premier temps nous avons...
## LoraWan
## TTN
## KiCad
Ci-dessous vous trouverez...
## Node-RED
## Datasheet
## Possible improvements
## Contacts