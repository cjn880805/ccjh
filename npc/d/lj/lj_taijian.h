//taijian.h
//�ز� 2002-08-01

NPC_BEGIN(CNlj_taijian);

virtual void create()
{
	set_name("̫��", "tai jian");
	set("gender", "����");
	set("icon", young_man4);
	
	set("title", "���Ļʹ�");
	set("age", 35);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 45);
	set("dex", 40);
	set("per",32);
	
	set("max_hp", 46000);
	set("mp", 15000);
	set("max_mp", 15000);
	set("mp_factor", 200);
	set("combat_exp", 6000000);
	set("score", 300000);

	set("no_kill",1);
	
};

void init(CChar * me)
{
	CNpc::init(me);
	CContainer * r = load_room("���ݻʹ�����");
	if(r->query("start") && r->query("start")==atoi(me->id(1)) && !me->query_temp("lj/renwu113"))
	{
		me->disable_player("�۲���");
		me->set_temp("lj/renwu113",1);
		call_out(do_gangsi, 6);	
	}
}


static void do_gangsi(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env=(CChar *)(ob->environment());
	DTItemList * list = env->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(userp(target))
		{
			target->enable_player();
			continue;
		}
		if(DIFFERSTR(target->querystr("name"), "̫��") )
		{
			message_vision("\n$N����һԾ����ǿ���ϸ�˿�����λ��˼��Ρ�", target);
			if(EQUALSTR(target->querystr("name"), "�߶�����")|| EQUALSTR(target->querystr("name"), "¹����"))
			{
				message_vision("ͻȻ$N���һ���Ը�˿�ϵ��£��ڸ�˿�µ����ˤ�˸�����ʺ���Ա���̫��׷���Ц���ѡ�", target);
				message_vision("$HIR$Nʧȥ�˱������׵��ʸ�����ͨ����˵��˻ʹ�������", target);
				//target->move(load_room("���ݻʹ�����"));
				destruct(target);
			}
			else
			{
				message_vision("$N���������ֻ���������˼�������Ծ���˶԰���", target);
				target->move(load_room("���ݻʹ����鷿"));
			}
		}
	}
}
	
NPC_END;

