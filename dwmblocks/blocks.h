//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{" ", 		"",			0,			0			},
	{" ",		"sb_cpu_temp",		1,			11			},
	{" ",		"sb_memory",		5,			12			},
	{" ",		"sb_storage",		10,			13			},
	{"󰏔 ",		"sb_packages",		3600,			14			},
	{"",		"sb_internet",		1,			15			},
	{"󰞏 ",		"sb_brightness",	0,			16			},
	{"",		"sb_volume",		0,			17			},
	{"",		"sb_battery",		1,			18			},
	{"",		"sb_datetime",		1,			19			},
	{"  ",		"",			0,			0			},
};

// 󰏔 

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;

