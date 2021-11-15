#include "phys/bodies.h"
#include "phys/phys.h"
#include "nlohmann/json.hpp"
#include <string.h>
#include <iostream>
#include <fstream>
#include <future>
#include <Windows.h>
#include "phys/world.h"
#include <filesystem>
#include <ctime>
#include <functional>
#include <chrono>
#include "Render/Renderer.h"
// MASTER SYSTEM
// controls the flow of the entire simulation, and is responsible for the main loop of the program.


class Master_sys
{

	tm sim_time; //time in the simulation starting 
	
	int simticks = 0; // ticks since simulation start.
	float time_mult = 60.0f; // used to slow down or speed up simulation.
	float time_step = 1.0f; //time in seconds that should pass per tick. The tick rate should preferrable be synced to this time.
	bool worldloaded = false; // Did the World load successfully?

public:
	Master_sys();
	World_subsys World;
	void Init(std::filesystem::path path, std::string file);
private:
	bool stop_signal = false;
	int Loop(std::shared_future<std::vector<Body>>& r_future, std::packaged_task<std::vector<Body>()>& r_task);
	int Load_World_Data(std::filesystem::path path, std::string file);



};