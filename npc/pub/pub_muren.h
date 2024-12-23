// pub_muren.c 木人
//修改被lanwood 2001-03-28

NPC_BEGIN(CNpub_muren);

void create()
{
	set_name("木人", "mu ren" );

	set("icon", waiter);
	set("gender", "男性" );
	set("age", 30);
	set("long", "一个练功用的比武木人，制作精巧，如同真人一般。");
	set("attitude", "heroism");
	
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	
	set("no_get", 1);
	set("max_hp", 900);
	set("eff_hp", 300);
	set("hp", 300);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 10);
	
	
	set("combat_exp", 50000);
	
	set_skill("force", 30);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	
	set("monster_lvl", 1);
	set("muren", 1);

	call_out(selfdest, 3600);		//1小时后毁灭
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "fight") == 0)
		return do_fight(me);
/*
	if(strcmp(comm, "cast") == 0)
	{
		if (DIFFERSTR(querystr("owner"), me->querystr("id") ))
		{	
			set("eff_hp", -1);	//设置马上死亡。不能直接销毁物件。
			return 1;
		}
	}
*/
	return CNpc::handle_action(comm, me, arg);
}

const char * invalid_fight(CChar * me)
{
	CContainer * env = environment();

	if( env->query("no_fight") )
		return "这里禁止战斗。";
		
	if(env->Query(IS_FIGHTROOM)) return "已经在战斗中了。";		//已经在战斗了。

	if( !living(this) )
		return "木人已经无法战斗了。"; 
	
	if (DIFFERSTR(querystr("owner"), me->querystr("id")) )
	{
		return "木人嘎吱嘎吱的叫了两声，不睬你。";		
	}	

	return 0;
}

int do_fight(CChar * me)
{
	char msg[80];
	CContainer * env = me->environment();
	
	const char * tmp = invalid_fight(me);
	if(tmp)
	{
		tell_object(me, tmp);
		return 1;
	}

	snprintf(msg, 80, "%s与木人的战斗", me->name());
	CFightRoom * room = (CFightRoom *)load_item("fight_room");			//载入战斗精灵
		
	room->set_name( msg);
	room->move(env);

	me->move(room);
	room->Join_Team(me, CFightRoom::FIGHT_TEAM_A);		//加入战队

	do_copyme(me);
	move(room);
	room->Join_Team(this, CFightRoom::FIGHT_TEAM_B);

	//检查在场所有之木人
	DTItemList list;
	CContainer * obj;

	CopyList(&list, env->Get_ItemList());
	POSITION p = list.GetHeadPosition();

	while(p)
	{
		obj = list.GetNext(p);

		if(obj == this) continue;
		if(EQUALSTR(obj->querystr("base_name"), "pub_muren" )
			&& obj->is_character())
		{
			CNpub_muren * who = (CNpub_muren *)obj;
			
			if(! who->invalid_fight(me))
			{
				who->do_copyme(me);
				who->move(room);
				room->Join_Team(who, CFightRoom::FIGHT_TEAM_B);
			}
		}
	}

	room->Begin_Fight(1, 1);	//比试
	return 1;
}

//复制主人
void do_copyme(CChar * ob)
{
	CMapping * hp_status, * skill_status, * map_status, * prepare_status;
	int i;
		
	skill_status = query_skills();
	skill_status->clear();

	skill_status = ob->query_skills();

	CVector v;

	skill_status->keys(v);

	for(i=0; i<v.count(); i++)
	{
		set_skill(v[i], (* skill_status)[v[i]]);
	}
		
	/// delete and copy skill maps ///
	
	map_status = query_skill_map();
	map_status->clear();

	map_status = ob->query_skill_map();

	v.clear();
	map_status->keys(v);
	
	for(i=0; i<v.count(); i++)
	{		
		map_skill(v[i], map_status->querystr(v[i]));
	}
	
	/// delete and copy skill prepares ///

	prepare_status = query_skill_prepare();
	prepare_status->clear();

	prepare_status = ob->query_skill_prepare();

	v.clear();
	prepare_status->keys(v);

	for(i=0; i<v.count(); i++)
	{
		prepare_skill(v[i], prepare_status->querystr(v[i]));
	}
	
	hp_status = ob->query_entire_dbase();
	
	set("str", hp_status->query("str"));
	set("int", hp_status->query("int"));
	set("con", hp_status->query("con"));
	set("dex", hp_status->query("dex"));
	
	set("max_hp",    hp_status->query("max_hp"));
	set("eff_hp",    hp_status->query("eff_hp"));
	set("hp",        hp_status->query("hp"));
	set("max_mp", hp_status->query("max_mp"));
	set("mp",     hp_status->query("mp"));
	set("mp_factor",     hp_status->query("mp_factor"));
	set("combat_exp", hp_status->query("combat_exp"));
	set("level",hp_status->query("level"));
}

static void selfdest(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * me = ob->environment();

	if(ob->query("ok")) return;

	if(userp(me))
		tell_object((CChar *)me, "木人嘎吱嘎吱的叫了两声，砰一声炸成了碎片。");
	else
		tell_room(me, "木人嘎吱嘎吱的叫了两声，砰一声炸成了碎片。");

	destruct(ob);
	return;
}

void die()
{
	message_vision("木人嘎吱嘎吱的叫了两声，砰一声炸成了碎片。", this);
	destruct(this);
}

void attack(CChar *me)
{
	if (DIFFERSTR(querystr("owner"), me->querystr("id") ))
	{	
		set("eff_hp", -1);	//设置马上死亡。不能直接销毁物件。
		return;
	}

	CChar::attack(me);
}

NPC_END;
