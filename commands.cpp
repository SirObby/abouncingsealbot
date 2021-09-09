/*
    Already implemented commandss.. please ignore.

dpp::slashcommand bouncecmd;
            bouncecmd.set_name("bounce")
            .set_description("Do you want to see Seals Bouncing?")
            .set_application_id(bot.me.id);
        bot.global_command_create(bouncecmd);

        dpp::slashcommand infocmd;
        infocmd.set_name("info")
            .set_description("Information about this bot.")
            .set_application_id(bot.me.id);
        bot.global_command_create(infocmd);
        
        dpp::slashcommand evalcmd;
        evalcmd.set_name("eval")
            .set_description("Evaluate code from within the bot.")
            .set_application_id(bot.me.id)
            //.add_permission(dpp::command_permission(dpp::command_permission_type::cpt_user))
            .add_option(dpp::command_option(dpp::co_string, "code", "The code to evaluate.", true)
                );
        bot.global_command_create(evalcmd);

        dpp::slashcommand goptcmd;
        goptcmd.set_name("guild-opt")
            .set_description("Choose whether to opt-in/out your guild for leveling.")
            .set_application_id(bot.me.id)
            //.add_permission(dpp::command_permission(dpp::command_permission_type::cpt_user))
            //.add_option(dpp::command_option(dpp::co_boolean, "value", "Value to set to.", true)))
                ;
        bot.global_command_create(goptcmd);

        dpp::slashcommand uoptcmd;
        uoptcmd.set_name("user-opt")
            .set_description("Choose whether to opt-in/out for leveling.")
            .set_application_id(bot.me.id)
            //.add_permission(dpp::command_permission(dpp::command_permission_type::cpt_user))
            //.add_option(dpp::command_option(dpp::co_boolean, "value", "Value to set to.", true)
                ;
        bot.global_command_create(uoptcmd);

        dpp::slashcommand pingcmd;
            pingcmd.set_name("ping")
            .set_description("Check the bot's latency.")
            .set_application_id(bot.me.id);
        bot.global_command_create(pingcmd);

                dpp::slashcommand guildconfcmd;
        guildconfcmd.set_name("guild-config")
            .set_description("Change the guild config.")
            .set_application_id(bot.me.id)
            .add_option(
                dpp::command_option(dpp::co_string, "setting", "The setting to change.", true).
                    add_choice(dpp::command_option_choice("leveling", std::string("leveling")))
            )
            .add_option(dpp::command_option(dpp::co_boolean, "value", "Value to set to.", true))
        ;
        bot.global_command_create(guildconfcmd);

        dpp::slashcommand userconfcmd;
        userconfcmd.set_name("user-config")
            .set_description("Change the user config.")
            .set_application_id(bot.me.id)
            .add_option(
                dpp::command_option(dpp::co_string, "setting", "The setting to change.", true).
                    add_choice(dpp::command_option_choice("leveling", std::string("leveling")))
            )
            .add_option(dpp::command_option(dpp::co_boolean, "value", "Value to set to.", true));
        bot.global_command_create(userconfcmd);

        dpp::slashcommand levelingcmd;

        levelingcmd.set_name("leveling")
            .set_description("Commands related to A Bouncing Seal's leveling.")
            .set_application_id(bot.me.id)
            .add_option(
                dpp::command_option(dpp::co_string, "action", "What do you want to do leveling-wise?", true)
                    .add_choice(dpp::command_option_choice("rank", std::string("rank")))
                    .add_choice(dpp::command_option_choice("leaderboard", std::string("leaderboard")))
            )
            ;

        bot.global_command_create(levelingcmd);
        */