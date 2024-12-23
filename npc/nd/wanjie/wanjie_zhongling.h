// zhongling.c

//code by sound
//date:2001-07-12

NPC_BEGIN(CNwanjie_zhongling);

virtual void create()
{
        set_name("中灵", "zhong ling");
        set("gender", "女性" );
        set("age", 15);
        set("str", 16);
        set("con", 24);
        set("dex", 11);
        set("per", 27);
        set("int", 24);
        set("icon",young_woman2);

        set("chat_chance", 1);

	set_inquiry("誉儿"," 段哥哥呢？他在哪儿？ ");
	set_inquiry("中灵"," 我就是钟灵啊。 ");
	set_inquiry("甘贝贝"," 甘宝宝是我妈。 ");
	set_inquiry("中千恨"," 钟万仇是我爹。 ");
	set_inquiry("这里"," 这里是万劫谷。 ");
	set_inquiry("木婉青"," 木婉清被关在后面的石屋里，快去救她！ ");

        set("attitude", "friendly");

        set("max_mp", 200);
        set("mp", 200);
        set("mp_factor", 10);

        set("combat_exp", 3500);

        set_skill("finger", 60);
        set_skill("parry", 40);
        set_skill("dodge", 50);
        set_skill("sword", 30);
        set_skill("force", 50);
        set_skill("sun_finger",40);

        map_skill("finger", "sun_finger");
        map_skill("parry", "sun_finger");

//	carry_object("moon-dress")->wear();
//	carry_object("shoes")->wear();
//	carry_object("xiu-scarf")->wear();
}

virtual char *chat_msg(CChar * player)
{
	return "中灵自言自语道：“要是我的闪电貂在这儿就好了。”";
}

/*
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
        message_vision("钟灵对$N说道：快去救木姐姐，木姐姐被关在后面的石屋里！\n",ob);
        }
}

int accept_object(object who, object ob)
{
        object *inv, sh;
        int i;

        inv = all_inventory(this_object());

        if (ob->name() == "闪电貂") {
            tell_object(who,"钟灵说道：谢谢你帮我找回了闪电貂！\n");
            tell_object(who,"钟灵说道：下次你见到段誉时，告诉他我已经回家了。\n");
            if(!sizeof(inv) )
                for ( i=0; i< sizeof(inv); i++ )
                    if ( inv[i]->name() == "绣花鞋" ) {
                        destruct(inv[i]);
                        tell_object("who, 钟灵脱下一双绣花鞋。\n");
                        sh = new("/t/wanjiegu/npc/obj/shoes2");
                        tell_object(who, "钟灵说道：这是我的一双绣花鞋，请你带给段誉。\n");
                        sh->move(who);
                        return 1;
                    }
            return 1;
        }
        return 0;
}

void die()
{
        int i;
        object killer;

        if(objectp(killer = query_temp("last_damage_from")))
            killer->set("marks/murder_zhongling", 1);
        message_vision("钟灵无力地说道：原来你和他们是一伙的！\n", killer);

        ::die();
}
*/
NPC_END;