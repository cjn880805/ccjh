//xueduei.h ��ң�����������
ITEM_BEGIN(CIguanmulin)

virtual void create(int nFlag = 0)		
{
	set_name("��ľ��", "guan mu lin");
	set("long",	"��ǰ��һƬ�деĹ�ľ�֣�ֻ��һ�������������������ϡ�ɼ���С����ǰ���ӡ�");
	set("unit", "Ƭ");
	set_weight(1000);
	set("value", 1);
	set("no_get"," ");
};


virtual int do_look(CChar * me)
{
	say("��ǰ��һƬ�деĹ�ľ�֣�ֻ��һ�������������������ϡ�ɼ���С����ǰ���ӡ�",me);
	say("������в񵶣����Կ��ǿ���һЩ�����ջ���¯�Ĳ�̡�",me);
	AddMenuItem("����ľ","$0kancai $1 0",me);
	AddMenuItem("�Ȼ��ٿ�","",me);
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	
	if (strcmp(comm,"kancai") == 0)
	{
		if (me->is_busy())
		{
			switch(random(10))
			{
			case 0:
			case 1:
				return notify_fail("����æ���أ����ٸ����ҷ�ָ�����");
				break;

			case 3:
				return notify_fail("�Ҷ��������ˣ�������û�ꣿ");
				break;

			case 7:
			case 8:
				return notify_fail("̫���ˣ�������Ъ��ɡ���");
				break;

			default:
				return notify_fail("��ѽ���ȵȵȣ��ҵĵ��β������ˡ���");
				break;
			}
		}

		if (me->query("hp") < 60)
			return notify_fail("�������̫���ˣ�������˯һ���ɡ�");
		
		if (!me->PresentName("chaidao",IS_ITEM))	//����������û�д���
			return notify_fail("��û�в���ô����ľ�أ��ò������ñ������������ɣ�");
		
		me->add("hp",-50);
		message_vision("\n$HIC$N����񵶣�������ǰ�Ĺ�ľ����ͷ����������", me);
		int lvl=me->query_skill("parry",1);
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
			load_item("chaihe")->move(me->environment());
			message_vision("$HIC������ܿ�Ͷ�����һ�ز�̣��������ͣ��������",me);
			destruct(this);
		}
		else
		{
			message_vision("$HIC���۵���ͷ�󺹣����еĲ񵶲��ҵ�ͣ��������",me);
		}
		me->start_busy(3);
	
		return 1;

	}
	return CItem::handle_action(comm, me, arg);
}

ITEM_END;




