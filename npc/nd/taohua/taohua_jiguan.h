// jiguan.c ������
//sound 2001-07-18

NPC_BEGIN(CNtaohua_jiguan);

virtual void create()
{
	set_name("������", "jiguan ren");
	set("gender", "����" );
	set("age", 30);
	set("long", "һ���һ��������õı�������ˣ��������ɣ���ͬ����һ�㡣");
	set("attitude", "heroism");
	
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("icon",young_man3);			//������������
	
//	set("no_get", "1");
	set("hp", 300);
	set("max_hp", 300);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 10);
	set("shen_type", 0l);
	
	set("combat_exp", 50000);
	
	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	
//	set("fight_times", 0);	       
}
/*
int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;
	
	me = this_object();
	
	if (is_fighting()) return 0;
	
	if (me->query("damaged"))
		return notify_fail("����������Ѿ������ˣ�");	
	
	if (random(me->query("fight_times")) >= 10) 
	{
		me->set("damaged", 1);
		return notify_fail("����������Ѿ������ˣ�");	
	}
	
	if (me->query("last_fighter") == ob->query("id"))
		return notify_fail("��ո������������������");		
		  
	me->set("last_fighter", ob->query("id"));
	me->add("fight_times", 1);
		  
	remove_call_out("renewing");	
	call_out("renewing", 300 + random(300), me);	
		  
//	delete and copy skills
		  
	if ( mapp(skill_status = me->query_skills()) ) 
	{
		skill_status = me->query_skills();
		sname  = keys(skill_status);
		
		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) 
		{
			me->delete_skill(sname[i]);
		}
	}
		  
	if ( mapp(skill_status = ob->query_skills()) ) 
	{
		skill_status = ob->query_skills();
		sname  = keys(skill_status);
		
		for(i=0; i<sizeof(skill_status); i++) 
		{
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
		  
//	delete and copy skill maps
		  
	if ( mapp(map_status = me->query_skill_map()) ) 
	{
		mname  = keys(map_status);
		
		temp = sizeof(map_status);
		for(i=0; i<temp; i++) 
		{
			me->map_skill(mname[i]);
		}
	}
		  
	if ( mapp(map_status = ob->query_skill_map()) ) 
	{
		mname  = keys(map_status);
		
		for(i=0; i<sizeof(map_status); i++) 
		{
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
//	delete and copy skill prepares
		  
	if ( mapp(prepare_status = me->query_skill_prepare()) ) 
	{
		pname  = keys(prepare_status);
		
		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) 
		{
			me->prepare_skill(pname[i]);
		}
	}
	
	if ( mapp(prepare_status = ob->query_skill_prepare()) ) 
	{
		pname  = keys(prepare_status);
		
		for(i=0; i<sizeof(prepare_status); i++) 
		{
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
		  
	hp_status = ob->query_entire_dbase();
		  
	me->set("str", hp_status["str"]);
	me->set("int", hp_status["int"]);
	me->set("con", hp_status["con"]);
	me->set("dex", hp_status["dex"]);
		  
	me->set("max_hp",    hp_status["max_hp"]);
	me->set("eff_qi",    hp_status["eff_qi"]);
	me->set("qi",        hp_status["qi"]);
	me->set("hp",  hp_status["hp"]);
	me->set("eff_jing",  hp_status["eff_jing"]);
	me->set("jing",      hp_status["jing"]);
	me->set("max_mp", hp_status["max_mp"]);
	me->set("mp",     hp_status["mp"]);
	me->set("mp_factor",     hp_status["mp_factor"]);
	me->set("combat_exp",hp_status["combat_exp"]);
		  
	return 1;
}

void renewing(object me)
{
	me->delete("last_fighter");
}
*/
NPC_END;