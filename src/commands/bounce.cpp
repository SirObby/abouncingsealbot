#include "bounce.h"

#include <dpp/dpp.h>

void bounce_command(const dpp::slashcommand_t &event, dpp::cluster *bot) {
	dpp::message m;
	
	m.set_content("https://cdn.discordapp.com/attachments/878681451384668170/880399400533368882/BouncingSeals.mp4");
	
	event.reply(m);
};
