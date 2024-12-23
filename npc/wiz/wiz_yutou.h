NPC_BEGIN(CNwiz_yutou);

virtual void create()
{
	set_name("������ͷ","yu tou");

	set("icon", young_man6);
	set("gender", "����" );
	set("age", 19);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 21);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	
	set("max_hp", 1200);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 30000+random(10000));
	set("score", 10000);
	carry_object("male8_cloth")->wear();
	carry_object("menghan_yao")->wear();
	set("chat_chance", 20);

	set("no_kill",1);//����������ٹȵ�������
	add_money(10);

};

/*
virtual void init(CChar * me)
{	
	CNpc::init(me);
	char msg[255],msg1[255];

	if(me->query("add_skill/count"))
	{
		for(int i=0;i<7;i++)
		{
			snprintf(msg, 255, "add_skill/name%d",i);
			snprintf(msg1, 255, "add_skill/level%d",i);
			if(me->query(msg1))
			{
				me->set_skill(me->querystr(msg),me->query_skill(me->querystr(msg), 1)-me->query(msg1));	
				if(me->query_skill(me->querystr(msg), 1)<1)
					me->delete_skill(me->querystr(msg));
			}
			me->del(msg);
			me->del(msg1);
		}
		me->FlushMySkill(me);
	}
}
*/
int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n��$Nб�ۿ��˿���������ü������һ�䡰�������㡱��ת����ȥ��", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

char * chat_msg()
{
	if(EQUALSTR((this->environment())->querystr("base_name"), "����ǳ�ʥ����" ))
	{
		CContainer * env = environment();
		DTItemList * list = env->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * env1 = list->GetNext(p);
			if(! env1->is_character()) continue; 
			CChar * me = (CChar *)env1;  
			if(!userp(me))	continue;
			if(me->query("mj/zuolao"))
			{
				time_t t;	
				time(&t);
				if(t > me->query("mj/endtime"))	
				{
					message_vision("$n���˿�$N��˵����������ֲ�������ǰ������ɣ���ȥ����Ų�Ҫ��ȥħ����ûǰ;�������ˡ�", me, this);
					message_vision("$nһ�Ž�$N���������˳�ȥ��$Nˤ��Ľ������ŷ����Ե��ر���ҡ�", me, this);
					CRoom * r = load_room(START_ROOM);
					me->del("mj/zuolao");
					me->del("mj/endtime");
					me->move(r);
					me->set("start_city", START_ROOM);
				}
			}
		}
	}
	return "";
}
NPC_END;




