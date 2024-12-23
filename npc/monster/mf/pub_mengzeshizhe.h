//pub_mengzeshizhe.h
//����ɽ��

NPC_BEGIN(CNpub_mengzeshizhe);

void create()
{
	set_name("����ɽ��", "shan ren");
    set("gender", "����");
	set("icon", young_monk);
    set("age", 60);
	set("per", 18 + random(15));
    set("combat_exp", 20000);
	set("str", 40);
	set("no_kill", 1);

	set("hp",990000);
	set("max_hp",990000);
	set("mp",990000);
	set("max_mp",990000);
	set("mp_factor", 3000);

	set("combat_exp", 99900000);
	set("score", 400000);
	 
	set_skill("force", 500);             
	set_skill("taixuan_gong", 500);    
	set_skill("unarmed", 500);           
	set_skill("dodge", 500);      	     
	set_skill("parry", 500);             
	
	map_skill("force", "taixuan_gong");
	map_skill("unarmed", "taixuan_gong");
	map_skill("dodge", "taixuan_gong");
	map_skill("parry", "taixuan_gong");

	set_inquiry("Ѱ��", ask_for_back);

}

static char * ask_for_back(CNpc * npc, CChar * who)
{
	message_vision("$n��ǰŲ��Ų��$N��ʱ��ǰ����һ��ҫ�۵İ׹⣬���ɵ�������ס��˫�ۡ�", who, npc);
	who->delete_temp("mf/pass");
	who->move(load_room("���ݿ͵�"));
	return 0;
}

void init(CChar * me)
{
	CNpc::init(me);
	char msg[255];
	if(! is_fighting() && userp(me))
	{
		if(me->query_temp("mf/pass"))
		{
			if(me->query_temp("mf/pass")==2)
			{
				CContainer * env = load_room("pk");
				if(!env->query("free_mf"))
				{
					message_vision(snprintf(msg, 255, "$HIR����ɽ���俢���۹�ɨ����%s,�ߵ��������������󱦵أ����Ѿ����˸��뿪��ʱ���ˡ���\n", me->name()), this);
					me->move(load_room("��ɽ�ձ�������"));
				}
			}
			else
			{
				DTItemList * list = me->Get_ItemList();
				POSITION p = list->GetHeadPosition();
				CContainer * obj;
				while(p)
				{
					obj = list->GetNext(p);
					if(userp(obj))
					{
						message_vision(snprintf(msg, 255, "$HIR����ɽ���俢���۹�ɨ����%s,�ߵ��������������󱦵أ�������Ե�߲������ڡ���\n", me->name()), this);
						obj->move(load_room("���ݿ͵�"));
						me->move(load_room("��ɽ�ձ�������"));
					}
				}
				if(!random(10))
				{
					if(me->query("hp")<me->query("max_hp"))me->set("hp",me->query("max_hp"));
					me->set("eff_hp",me->query("max_hp"));
					if(me->query("mp")<me->query("max_mp"))me->set("mp",me->query("max_mp"));
				}
			}
		}	
		else 
		{
			message_vision(snprintf(msg, 255, "$HIR����ɽ���俢���۹�ɨ����%s,�ߵ��������������󱦵أ�������Ե�߲������ڡ���\n", me->name()), this);
			me->move(load_room("���ݿ͵�"));
		}
	}
}

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

NPC_END;




