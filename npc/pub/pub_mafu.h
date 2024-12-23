NPC_BEGIN(CNPub_mafu);

virtual void create()
{
	set_name( "马夫");

	set("icon", banditi);
	set("age", 32);
	set("gender", "男性");
	set("long","驯马和租马的小贩，给他租金就可以雇到马。");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 50000);
	set("shen_type", 1);
	call_out(do_die, 1800);
	set("no_kill",1);

 };

int handle_action(char *comm, CChar *me, char *arg)
{
	if(querystr("owner"))
	{
		if((strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0 )
			&& DIFFERSTR(querystr("owner"),me->querystr("id")))
		{
			message_vision("$n向$N耸了耸肩膀，转过头去。", me, this);
			me->start_busy(2);
			return 1;
		}
	}
	return CNpc::handle_action(comm, me, arg);
}

virtual void die()
{
	if(querystr("owner"))
	{
		CContainer * obj = environment();
		DTItemList * list = obj->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			CChar * target = (CChar *)obj;  
			if(!userp(target))	continue;
			if(query("corps_id"))
			{
				if(target->query_temp("fight/is_fighting") && EQUALSTR(target->querystr_temp("corps/quest/name"),querystr("name"))
					&& EQUALSTR(querystr("owner"),target->querystr("id")))
				{
					target->add_temp("corps/quest/finish",1);
					break;
				}
			}
			else if(target->query_temp("fight/is_fighting") && EQUALSTR(target->querystr_temp("zhang/name"),querystr("name"))
				&& EQUALSTR(querystr("owner"),target->querystr("id")))
			{
				target->add_temp("zhang/finish",1);
				break;
			}
		}
	}
	CNpc::die();
}
static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	destruct(me);
}
NPC_END;




