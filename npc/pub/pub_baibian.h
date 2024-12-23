// pub_baibian.c
//code by Fisho
//date : 2000-12-13

NPC_BEGIN(CNpub_baibian);

virtual void create()
{
	set_name("张三", "zhang san" );

	set("icon", taoist_with_sword);
	set("title",  "百变道人" );
	set("gender", "男性" );
	set("age", 50);
	set("long", "一位邋邋遢遢的道士。");
	set("attitude", "heroism");
	set("class", "taoist");
	
	set("str", 21);
	set("con", 30);
	set("int", 27);
	set("dex", 23);
	
	set("max_hp", 1800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 30);
	set("shen_type", -1);
	set("env/wimpy", 60);
	set("combat_exp", 25000);
	
	set_temp("apply/attack",  10);
	set_temp("apply/defense", 20);
	
	set_skill("force", 43); 
	set_skill("unarmed", 51);
	set_skill("sword", 37);
	set_skill("dodge", 59);
	set_skill("parry", 40);
	set_skill("taiji_quan", 42); 
	set_skill("taiji_jian", 41); 
	set_skill("taiji_shengong", 40); 
	set_skill("tiyunzong", 53);
	
	map_skill("force", "taiji_shengong");
	map_skill("unarmed","taiji_quan");
	map_skill("parry", "taiji_quan");
	map_skill("sword", "taiji_jian");
	map_skill("dodge", "tiyunzong");
	
	create_family("武当派", 3, "弟子");
	
	set("chat_chance", 5);

	carry_object("force_book");
	 carry_object("changjian")->wear();
	add_money(300);
	
}

virtual void init(CChar *me)
{	
	CMapping *skill_status, *map_status;

	CNpc::init(me);	
	if (is_fighting() || wizardp(me)) return ;
	
	skill_status = me->query_skills();
			
	CVector v;
	int i;

	skill_status->keys(v);

	for(i=0; i<v.count(); i++)
	{
		set_skill(v[i], (* skill_status)[v[i]]);
	}
	
	command("enable 0 unarmed none");	
	command("enable 0 dodge none");	
	command("enable 0 parry none");	
	
	if ( !(map_status = me->query_skill_map()) ) return ;

	v.clear();
	map_status->keys(v);

	for(i=0; i<v.count(); i++)
	{
		map_skill(v[i], map_status->querystr(v[i]));
	}
	
	set("mp", 600);
	set("mp_factor", 30);
	
}
/*
void pretending(CChar * ob)
{
	CChar * me;// = this_object();
	char msg[255];
	CContainer * mask = PresentName("mask", IS_ITEM);
	switch( random(3) ) 
	{
	case 0:
		command(snprintf(msg, 255, "grin %ld", ob->object_id()));
		if(mask)
			command(snprintf(msg, 255, "pretend %ld %s", mask->object_id(), ob->querystr("id").c_str()) );
		command("exert recover");
		break;
	case 1:
		command(snprintf(msg,255,"hi %s" , ob->querystr("id").c_str() ));
		command("exert heal");
		command("exert recover");
		break; 
	case 2:
		command(snprintf(msg,255,"stare %s" , ob->querystr("id").c_str() ));
		me->fight_ob(ob);
		ob->fight_ob(me);
		break;
	}
}
*/
NPC_END;