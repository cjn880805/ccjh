//xiaoyao_xiaoxibian.h 小溪边
//秦波 2002、12、5

XiaoYao_BEGIN(CRXiaoYao_xiaoxibian);

virtual void create()
{
	set_name( "小溪边");

	set("no_get",1);
	set("no_fight",1);
	set("no_cast",1);

	add_door("逍遥谷镜月湖", "逍遥谷镜月湖", "逍遥谷小溪边");
	add_door("逍遥谷小径", "逍遥谷小径", "逍遥谷小溪边");
	
};

int valid_leave(CChar * me, const char * dir)
{
	if(me->query_temp("xy/renwu2_1"))
	{
		if(me->query("hp")<100)//防止玩家一进战斗就死
			me->set("hp",100);
		me->set("mp",0l);
		tell_object(me,"\n$HIC你试着动了一下，竟然周身刺痛，几入心扉，真气却一口都提不起来，看来受伤着实不轻，于是更不敢再动分毫。");
		tell_object(me,"$HIC真是祸不单行，一只巨大的蜘蛛，浑身五彩斑斓,在三尺之外凝视着你，忽然间八足一蹬向你扑来。");
		tell_object(me,"$HIC身未到一股猛烈的毒雾已笼罩你周身，你只觉一阵晕眩，暗道：我命休矣！\n");
		
		me->apply_condition("scorpion_poison", 2000);
		me->delete_temp("xy/renwu2_1");

		//进入与毒蜘蛛的战斗
		CFightRoom * obj;
		CContainer * env = me->environment();
		obj = (CFightRoom *)load_item("fight_room");		
		
		obj->set("room_locked", FIGHT_LOCKED);
		obj->set_name( "毒蜘蛛的战斗", "fight_room");		
		obj->move(env);
		
		me->move(obj);
		obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);

		CChar * robber = load_npc("animal_duzhizhu");
		robber->set("owner",atoi(me->id(1)));
		robber->set("no_kill",1);
		robber->move(obj);
		obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);				
		obj->Begin_Fight(0);
		
		me->call_out(do_tielao, 10);
	
		return 0;
	}
	return CRoom::valid_leave(me, dir);
}

static void do_tielao(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(me->query_temp("fight/is_fighting") )
	{
		int team;
		CFightRoom * obj=(CFightRoom *)me->environment();
		if(me->query_temp("fight/fight_team"))		//加入A队
			team = 1;
		else
			team = 0;
		CChar * tielao = load_npc("tmp_tielao");
		tielao->set_name("天山铁姥", "tong lao");
		tielao->set("gender", "女性");
		tielao->set("icon", 23);
		tielao->set("long","她看上去像是一位八九岁的小姑娘，但神色之间的成熟感却又与年龄不太相符。");
		tielao->set("age",8);
		tielao->set("str",1000);
		tielao->set("con",1000);
		tielao->set_temp("apply/damage",1000);
		tielao->set_temp("apply/dodge",1000);
		tielao->set("combat_exp",10000000);
		tielao->set("level",200);
		tielao->set_skill("force", 200);
		tielao->set_skill("unarmed", 200);
		tielao->set_skill("dodge", 200);
		tielao->set_skill("parry", 200);
		tielao->set_skill("hand",200);
		tielao->set_skill("strike", 200);
		tielao->set_skill("zhemei_shou",200);
		tielao->set_skill("liuyang_zhang",200);
		tielao->set_skill("yueying_wubu",200);
		tielao->set_skill("bahuang_gong", 200);
		tielao->map_skill("force", "bahuang_gong");
		tielao->map_skill("strike","liuyang_zhang");
		tielao->map_skill("dodge", "yueying_wubu");
		tielao->map_skill("unarmed", "liuyang_zhang");
		tielao->map_skill("strike","liuyang_zhang");
		tielao->map_skill("hand", "zhemei_shou");
		tielao->map_skill("parry", "liuyang_zhang");
		tielao->prepare_skill("strike","liuyang_zhang");
		tielao->prepare_skill("hand","zhemei_shou");
		tielao->set("max_mp",8000);
		tielao->set("mp",8000);
		tielao->set("mp_factor", 50);
		tielao->set("no_kill",1);

		tielao->move(obj);
		tielao->call_out(do_tielaodie, 60);
		tell_object(me,"\n$HIC眼见毒蜘蛛越逼越近，正惊恐间，一个娇小的身影飘然挡在了你面前。\n");
		
		obj->Join_Team(tielao, team);
	}
}

static void do_tielaodie(CContainer * ob, LONG param1, LONG param2)
{
	CChar * tielao = (CChar *)ob;
	if(!tielao->query_temp("fight/is_fighting") )
		destruct(tielao);
	else
		tielao->call_out(do_tielaodie, 60);
}
XiaoYao_END;
