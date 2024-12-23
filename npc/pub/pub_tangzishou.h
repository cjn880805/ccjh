//pub_tangzishou.h
//code by zwb
//12-15

NPC_BEGIN(CNpub_tangzishou);

virtual void create()
{
	set_name("������","tangzi shou");

	set("icon", 40);
	set("gender", "����");
	set("age", 35 );
	set("title", "�����ھ�");

	set("combat_exp", 5000);
	set("no_kill",1);
	set("chat_chance", 70);

};

virtual void init(CChar * me)
{	
	int exp=me->query("combat_exp")-CChar::Level2Exp(me->query("level"))-me->query("sk_exp");
	int skexp=(me->query("combat_exp")-me->query("sk_exp")*3)/3;
	if((me->query("level")<30 && (me->query_skill("force", 1) < 30 || me->query_skill("dodge", 1) < 30 
		|| me->query_skill("parry", 1) < 30))||exp<0||skexp<-100000)
	{
		remove_call_out(do_saying);
		call_out(do_saying, 3, me->object_id());
	}
}

static void do_saying(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *) ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if (!who) return;
	
	message_vision("$n��$N��ȵ����������ھ��ڳ�·���˵أ���ȴ��׷��˻����Ͽ�رܣ���\n������̧���ҽţ�һ����$N�������ŵ�$N�����󺰡������ھ�Ҫɱ��������һ�����ܵ�ûӰ����", who, me);
	who->move(load_room("��ɽ������"));
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if((strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0) && me->query("level")<30)
	{
		message_vision("$n��$Nб�ۿ��˿���������ü�������˵�˾䣺��ɱ����ĺܶ��ҵķݡ���", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

char * chat_msg()
{
	CContainer * obj;
	obj=environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(userp(target))
		{
			int exp=target->query("combat_exp")-CChar::Level2Exp(target->query("level"))-target->query("sk_exp");
			int skexp=(target->query("combat_exp")-target->query("sk_exp")*3)/3;
			if((target->query("level")<30 && (target->query_skill("force", 1) < 30 || target->query_skill("dodge", 1) < 30 
				|| target->query_skill("parry", 1) < 30))||exp<0||skexp<-100000)
			{
				remove_call_out(do_saying);
				call_out(do_saying, 3, target->object_id());
			}
			continue;
		}
		if(EQUALSTR(target->querystr("name"), querystr("owner")))
		{
			set("here",1);
			break;
		}
		else
		{
			del("here");
			continue;
		}
	}
	if(!query("here"))
		destruct(this);
	return "";
}
NPC_END;




