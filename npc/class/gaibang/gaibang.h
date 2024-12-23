//gaibang.h
//升袋
//Lanwood 2000-01-06

#define NPCGAIBANG_BEGIN(npc_name) class npc_name : public CNgaibang	{	public:	npc_name(){};	virtual ~npc_name(){};
#define NPCGAIBANG_END		};	

NPC_BEGIN(CNgaibang);

int accept_object(CChar * me, CContainer * obj)
{
        if (DIFFERSTR(me->querystr("family/family_name"), "丐帮"))
		{
			say("你哪里来的青竹令？", me);
			SendMenu(me);
			return 0;
		}

        if ( me->query_temp("have_cloth") && me->present("po bu") )
        {
            say("你不是已经有破布么?", me);
			SendMenu(me);
            return 0;
        }

        if (
				( me->query("beggarlvl") == 0 && me->query_combat_exp() <= 500) 
			||  ( me->query("beggarlvl") == 1 && me->query_combat_exp() <= 1000)
			||  ( me->query("beggarlvl") == 2 && me->query_combat_exp() <= 3000)
			||	( me->query("beggarlvl") == 3 && me->query_combat_exp() <= 5000)
			||  ( me->query("beggarlvl") == 4 && me->query_combat_exp() <= 10000)
			||  ( me->query("beggarlvl") == 5 && me->query_combat_exp() <= 15000)
			||  ( me->query("beggarlvl") == 6 && me->query_combat_exp() <= 20000)
			||  ( me->query("beggarlvl") >= 7 && me->query_combat_exp() <= 30000))
        {
             say("就你那点脓水？我看就算了吧。", me);
			 SendMenu(me);
             return 1;
        }

        if ( 
				(me->query("beggarlvl") == 0 && EQUALSTR(querystr("title"), "丐帮一袋弟子"))
			||  (me->query("beggarlvl") == 1 && EQUALSTR(querystr("title"), "丐帮二袋弟子") )
			||  (me->query("beggarlvl") == 2 && EQUALSTR(querystr("title"), "丐帮三袋弟子"))
			||  (me->query("beggarlvl") == 3 && EQUALSTR(querystr("title"), "丐帮四袋弟子"))
			||  (me->query("beggarlvl") == 4 && EQUALSTR(querystr("title"), "丐帮五袋弟子") )
			||  (me->query("beggarlvl") == 5 && EQUALSTR(querystr("title"), "丐帮六袋弟子"))
			||  (me->query("beggarlvl") == 6 && EQUALSTR(querystr("title"), "丐帮七袋弟子"))
			||  (me->query("beggarlvl") == 7 && EQUALSTR(querystr("title"), "丐帮八袋弟子"))
			||  (me->query("beggarlvl") == 8 && EQUALSTR(querystr("title"), "丐帮九袋长老")))
        {
			if( EQUALSTR(obj->querystr("base_name"), "qingzhu_ling")
				&& ! me->query_temp("have_cloth"))
          {
				destruct(obj);

				me->set_temp("fight_ok", 1);
				say("好，既然已有青竹令，那就看你的运气了。", me);
				AddMenuItem("开始比试", "$0bishi $1", me);
				AddMenuItem("放弃比试", "", me);
				
				SendMenu(me);
				return 1;
          }
       }

       say(g_Channel.do_emote(this, 0, "smile", 1), me);
       say("升袋当然只升不降。跳升也是不行的。", me);
       say("这东西给你还是自己留着吧。", me);
	   SendMenu(me);
       return 0;
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "升袋比试会");
		return 1;
	}

	return CNpc::handle_action(comm, me, arg);
}

//比试结束
void is_defeated(CChar * winner, CChar * failer)
{
	if(failer == this)
	{
		if(! winner->query_temp("fight_ok")) return;

		say("大爷今天心情好，算你运气。拿这块破布找简长老去 !");
		winner->set("newtitle", this->querystr("title"));
        winner->set_temp("have_cloth", 1);
        load_item("po_bu")->move(winner);
		return;
	}
	
	say("想升袋？也不看看自家长了几根毛 !");
	return;	
}

void accept_student(CChar * who)
{
	char msg[80];

	if(EQUALSTR(who->querystr("family/family_name"), "丐帮") && 
		this->query("beggarlvl") > (who->query("beggarlvl") + 2))
	{
		say ("丐帮号称天下第一大帮，帮规森严不能越级拜师的，数一数你身上的布袋，够数了再来找我吧。");
		return;
	}
	if(EQUALSTR(who->querystr("family/family_name"), "丐帮") && 
		who->query("beggarlvl") >= this->query("beggarlvl"))//玩家袋数高于NPC
	{
		say ("前辈不要和小的开玩笑，我可担当不起啊。");
		return;
	}
	else
	{
		say ("好吧，希望你能好好学习本门武功，将来为丐帮争一口气！。");
		command(snprintf(msg, 80, "recruit %ld", who->object_id()));
		who->set("class", "beggar");
	}
	return;
}

NPC_END;
