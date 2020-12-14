// Backtester.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include<Windows.h>
#include<string>
#define CURL_STATICLIB
#include <curl\curl.h>
#include "General_ToolBox.h"
#include <chrono>
#include <thread>








int main()
{
    General_ToolBox gt;

    int day_of_year = gt.get_day_of_year();

    std::string hh = "http://vps468116.ovh.net/analysis/";
    for (int day_in = 0; day_in < 10; day_in++) {
        std::string he = "data_to_save_fxx" + std::to_string(day_of_year- day_in)+".csv";
        std::string tmp_s = hh + he;
        gt.downloadFile(tmp_s.c_str(), he.c_str());
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
