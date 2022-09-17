#include "info.h"

#include <dpp/dpp.h>

void info_command(const dpp::slashcommand_t &event, dpp::cluster *bot) {
	dpp::message m;
	
	dpp::embed e;
	e.set_title("A Bouncing Seal");
	e.add_field("Version", "0.0.1", true);
	e.add_field("DPP::Version", DPP_VERSION_TEXT, true);
	e.set_description("A Bouncing Seal is a discord bot about very funny bouncing seals.");

	m.set_flags(dpp::m_ephemeral);
	m.add_embed(e);
	
	event.reply(m);
};
