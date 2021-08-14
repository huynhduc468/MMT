﻿#include"Server.h"
#include</Study/Year 1/Semeter 3/Mạng máy tính/MMT-Duc/MMT-Duc/TestGUIServer/TestGUIServer/single_include/nlohmann/json.hpp>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
void TakeData() {
	CURL* curl;
	CURLcode res;
	std::string readBuffer;

	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();
	if (curl) {
		std::ofstream fout("Data.json", std::ios_base::out);
		curl_easy_setopt(curl, CURLOPT_URL, "https://coronavirus-19-api.herokuapp.com/countries");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		fout << readBuffer << std::endl;

		fout.close();
	}
}

void exportCovidInfo(SOCKET ClientSocket, string path) {
	string temp = "";

	ifstream file("Data.json");

	getline(file, temp);

	stringstream ss(temp);
	string jsonObject;
	getline(ss, jsonObject, '[');
	getline(ss, jsonObject, '}');
	jsonObject += '}';
	nlohmann::json value;
	stringstream(jsonObject) >> value;

	while (jsonObject != "") {
		getline(ss, jsonObject, ',');
		if (jsonObject == "]") break;
		getline(ss, jsonObject, '}');
		jsonObject += '}';
		stringstream(jsonObject) >> value;
		if (path == value["country"]) {
			send(ClientSocket, "1", 1, 0);

			string tmp = value["country"].dump();
			char* countr = (char*)tmp.c_str();
			send(ClientSocket, countr, (int)strlen(countr), 0);
			this_thread::sleep_for(0.1s);

			tmp = value["cases"].dump();
			char* cases = (char*)tmp.c_str();
			send(ClientSocket, cases, (int)strlen(cases), 0);
			this_thread::sleep_for(0.1s);

			tmp = value["todayCases"].dump();
			char* todayCases = (char*)tmp.c_str();
			send(ClientSocket, todayCases, (int)strlen(todayCases), 0);
			this_thread::sleep_for(0.1s);

			tmp = value["deaths"].dump();
			char* deaths = (char*)tmp.c_str();
			send(ClientSocket, deaths, (int)strlen(deaths), 0);
			this_thread::sleep_for(0.1s);

			tmp = value["todayDeaths"].dump();
			char* todayDeaths = (char*)tmp.c_str();
			send(ClientSocket, todayDeaths, (int)strlen(todayDeaths), 0);
			this_thread::sleep_for(0.1s);

			tmp = value["recovered"].dump();
			char* recovered = (char*)tmp.c_str();
			send(ClientSocket, recovered, (int)strlen(recovered), 0);
			this_thread::sleep_for(0.1s);

			tmp = value["active"].dump();
			char* active = (char*)tmp.c_str();
			send(ClientSocket, active, (int)strlen(active), 0);
			this_thread::sleep_for(0.1s);

			tmp = value["critical"].dump();
			char* critical = (char*)tmp.c_str();
			send(ClientSocket, critical, (int)strlen(critical), 0);
			this_thread::sleep_for(0.1s);

			tmp = value["casesPerOneMillion"].dump();
			char* casesPerOneMillion = (char*)tmp.c_str();
			send(ClientSocket, casesPerOneMillion, (int)strlen(casesPerOneMillion), 0);
			this_thread::sleep_for(0.1s);

			tmp = value["deathsPerOneMillion"].dump();
			char* DeathsPerOneMillion = (char*)tmp.c_str();
			send(ClientSocket, DeathsPerOneMillion, (int)strlen(DeathsPerOneMillion), 0);
			this_thread::sleep_for(0.1s);

			tmp = value["totalTests"].dump();
			char* totalTests = (char*)tmp.c_str();
			send(ClientSocket, totalTests, (int)strlen(totalTests), 0);
			this_thread::sleep_for(0.1s);

			tmp = value["testsPerOneMillion"].dump();
			char* testPerOneMillion = (char*)tmp.c_str();
			send(ClientSocket, testPerOneMillion, (int)strlen(testPerOneMillion), 0);

			file.close();
			return;
		}
	}
	send(ClientSocket, "0", 1, 0);
	file.close();
	return;
}