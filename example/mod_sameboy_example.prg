import "mod_gfx";
import "mod_input";
import "mod_sound";
import "mod_misc";
import "mod_sameboy";

Global
	int graph_sameboy;
End

Process main();
Begin
	set_mode(1280,720);
	window_set_title("My GB Game");
	set_fps(60,0);
	
	background.graph = map_load("background.png");
	
	x = 640; y = 360; size = 300;
	
	write(0,0,0,0,"Controls: Arrows, Z, X, Right Shift, Enter");
	write(0,0,20,0,"Press keys from Q to T for stuff.");
	
	graph = graph_sameboy = sameboy_start_emulator("game.gb");
	// sameboy_load_sram("game.sav");
	sameboy_load_state("game.savestate");

	while(!key(_esc) and !wm_info.exit_status)
		sameboy_update_keys(
			key(_left),
			key(_right),
			key(_up),
			key(_down),
			key(_z),
			key(_x),
			key(_r_shift),
			key(_enter));

		if(key(_q)) angle -= 1000; end
		if(key(_w)) angle -= 1000; end
		if(key(_e)) size -= 10; end
		if(key(_r)) size += 10; end
		if(key(_t)) falling_thingy(); end

		sameboy_tick();
		
		frame;
	end
	// sameboy_save_sram("game.sav");
	sameboy_save_state("game.savestate");
	exit();
End

Process falling_thingy();
Public
	int x_inc;
Private
	int y_inc, angle_inc;
	falling_thingy pid_collision;
Begin
	graph = father.graph;
	x = rand(0, 1280);
	y = -100; 
	x_inc = rand(-3, 3);
	y_inc = rand(1, 3);
	angle_inc = rand(-3,3) * 1000;
	size = rand(30, 100);
	while(y < 820)
		y += y_inc;
		x += x_inc;
		angle += angle_inc;
		if(x > 1200) x_inc = -abs(x_inc); end
		if(x < 80) x_inc = abs(x_inc); end
		if(x_inc > 0) flags = 0; else flags = 1; end
		if(pid_collision = collision(type falling_thingy))
			if(x < pid_collision)
				pid_collision.x_inc = abs(x_inc);
				x_inc = -abs(x_inc);
			end
		end
		frame;
	end
End