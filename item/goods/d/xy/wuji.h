//wuji.h ��ң�����������
NPC_BEGIN(CNwuji)

virtual void create()
{
	set_name("�ڼ�", "wu ji");
	set("long",	"����һֻȫ���ë���ڼ�������ʳ��ҩ�ġ�");
	
	set("icon", tiger);
	
	set("race", "Ұ��");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", -1);
	
	CVector v;
	
	v.append("bite");
	v.append("claw");
	v.append("knock");
	set("verbs", v);
	
	set("max_hp",15000);
	
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 250);
	set_temp("apply/armor", 200);
	set_temp("apply/damage", 400);
	set_temp("apply/dodge", 200);
	set_temp("apply/parry", 200);

	set("no_get","�ڼ������ĳ��ɵ���һ�ߣ���ս�Ƶĳ����������������������....������");

	call_out(do_xiadan, 900);
};

virtual int do_look(CChar * me)
{
	say("����һֻȫ���ë���ڼ�������ʳ��ҩ�ġ�", me);
	if (me->PresentName("shen",IS_ITEM))
		AddMenuItem("��׽","$0bu $1 0",me);
	SendMenu(me);
	
	return 1;
}

static void do_xiadan(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	if(EQUALSTR(env->querystr("area"),"house"))
	{
		message_vision("\n$HIR�ڼ���Ȼ������ſ�ڵ���һ������������Щ��ʱ�䣬����������....�����ļ�����������Ķ��ߡ�\n�㶨��һ��������һ�֣�ԭ���ڼ�����һ����������",me); 
		load_item("jidan")->move(env);
	}
	me->call_out(do_xiadan, 900);
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if (strcmp(comm,"bu") == 0)
	{
		if (me->is_busy())
		{
			switch(random(5))
			{
			case 0:
			case 1:
				return notify_fail("����æ���أ����ٸ����ҷ�ָ�����");
				break;
			case 3:
				return notify_fail("�Ҷ��������ˣ�������û�ꣿ");
				break;
			default:
				return notify_fail("̫���ˣ�������Ъ��ɡ���");
				break;
			}
		}

		if (me->query("hp") < 60)
			return notify_fail("�������̫���ˣ�������˯һ���ɡ�");
		
		if (!me->PresentName("shen",IS_ITEM))	//����������û�д�����
			return notify_fail("�������ڵ����֣�����ȥ�Ҹ��������ɣ�");
		
		me->add("hp",-50);
		message_vision("\n$HIC$N���ĵ��ó�һ�����ӽ��һ����Ȧ��������ŵ��ߵ��ڼ����棬�͵�һ�ӣ������׿ɹ�ȥ��", me);
		int lvl=me->query_skill("dodge",1);
		int jump;
		if(lvl>=300)
			jump=1;
		else if(lvl>=200 )
		{
			if(random(100)>20)	jump=1;
		}
		else if(lvl>=100 )
		{
			if(random(100)>30)	jump=1;
		}
		else if(lvl>=50 )
		{
			if(random(100)>50)	jump=1;
		}
		if(jump==1)
		{
			message_vision("\n$HIR$N�ɹ�����ס���ڼ���",me); 
			disable_player("����");
			del("no_get");
			CContainer * shen=me->present("shen");
			if(shen)
				destruct(shen);
		}
		else
		{
			message_vision("\n$HIR�ڼ������ĳ��ɵ���һ�ߣ���ս�Ƶĳ�$N��������������������....������",me); 
			message_vision("$HIR$N��к��գ�\n",me); 
		}
		return 1;
	}
	else if (strcmp(comm,"kill") == 0 || strcmp(comm,"fight") == 0 
		||strcmp(comm,"cast") == 0 ||strcmp(comm,"get") == 0 )
	{
		message_vision("\n$HIR�ڼ������ĳ��ɵ���һ�ߣ���ս�Ƶĳ�$N��������������������....������",me); 
		message_vision("$HIR$N��к��գ�\n",me); 
		return 1;
	}
	return CNpc::handle_action(comm, me, arg);
}
NPC_END;




