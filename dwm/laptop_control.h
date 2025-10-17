#include <X11/XF86keysym.h>
#include <X11/keysym.h>

/* ==================== AUDIO TOOL SELECTION ==================== */
/* Uncomment the tool you want to use */
// #define USE_WPCTL
// #define USE_PACTL
#define USE_AMIXER

/* ==================== BRIGHTNESS TOOL SELECTION ==================== */
// #define USE_LIGHT
#define USE_BRIGHNESSCTL

/* ==================== COMMAND DEFINITIONS ==================== */

#ifdef USE_WPCTL
static const char *upvol[]    = { "sh", "-c", "/usr/bin/wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+ && pkill -RTMIN+17 dwmblocks", NULL };
static const char *downvol[]  = { "sh", "-c", "/usr/bin/wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%- && pkill -RTMIN+17 dwmblocks", NULL };
static const char *mutevol[]  = { "sh", "-c", "/usr/bin/wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle && pkill -RTMIN+17 dwmblocks", NULL };
static const char *mutemic[]  = { "sh", "-c", "/usr/bin/wpctl set-mute @DEFAULT_AUDIO_SOURCE@ toggle && pkill -RTMIN+17 dwmblocks", NULL };
#elif defined(USE_PACTL)
static const char *upvol[]    = { "sh", "-c", "/usr/bin/pactl set-sink-volume @DEFAULT_SINK@ +5% && pkill -RTMIN+17 dwmblocks", NULL };
static const char *downvol[]  = { "sh", "-c", "/usr/bin/pactl set-sink-volume @DEFAULT_SINK@ -5% && pkill -RTMIN+17 dwmblocks", NULL };
static const char *mutevol[]  = { "sh", "-c", "/usr/bin/pactl set-sink-mute @DEFAULT_SINK@ toggle && pkill -RTMIN+17 dwmblocks", NULL };
static const char *mutemic[]  = { "sh", "-c", "/usr/bin/pactl set-source-mute @DEFAULT_SOURCE@ toggle && pkill -RTMIN+17 dwmblocks", NULL };
#elif defined(USE_AMIXER)
static const char *upvol[]    = { "sh", "-c", "/usr/bin/amixer set Master 1%+ && pkill -RTMIN+17 dwmblocks", NULL };
static const char *downvol[]  = { "sh", "-c", "/usr/bin/amixer set Master 1%- && pkill -RTMIN+17 dwmblocks", NULL };
static const char *mutevol[]  = { "sh", "-c", "/usr/bin/amixer set Master toggle && pkill -RTMIN+17 dwmblocks", NULL };
static const char *mutemic[]  = { "sh", "-c", "/usr/bin/amixer set Capture toggle", NULL };
#else
#error "No audio tool selected. Define USE_WPCTL, USE_PACTL, or USE_AMIXER."
#endif

/* ==================== BRIGHTNESS ==================== */

#ifdef USE_LIGHT
static const char *light_up[]   = { "sh", "-c", "/usr/bin/light -A 1 && pkill -RTMIN+16 dwmblocks", NULL };
static const char *light_down[] = { "sh", "-c", "/usr/bin/light -U 1 && pkill -RTMIN+16 dwmblocks", NULL };
#elif defined(USE_BRIGHNESSCTL)
static const char *light_up[]   = { "sh", "-c", "/usr/bin/brightnessctl set +1% && pkill -RTMIN+16 dwmblocks", NULL };
static const char *light_down[] = { "sh", "-c", "/usr/bin/brightnessctl set 1%- && pkill -RTMIN+16 dwmblocks", NULL };
#endif

