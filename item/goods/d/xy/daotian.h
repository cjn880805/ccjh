//daotian.h ��ң�����������
ITEM_BEGIN(CIdaotian)

virtual void create(int nFlag = 0)		
{
	set_name("����", "dao tian");
	set("long",	"���������ֵ��̣���ů����������ҫ����Ƭ���ֵ����أ�ϣ�����и����ճɰɡ�");
	set("unit", "֧");
	set_weight(1000);
	set("value", 1);
	set("no_get", "��Ҳ̫�����쿪�˰ɡ�");
};

virtual int do_look(CChar * me)
{
	say("���������ֵ��̣���ů����������ҫ����Ƭ���ֵ����أ�ϣ�����и����ճɰɡ�",me);
	if (me->PresentName("liandao",IS_ITEM))
	{
		AddMenuItem("���","$0ge $1 0",me);
		AddMenuItem("�Ȼ��ٸ�","",me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	
	if (strcmp(comm,"ge") == 0)
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
		
		if (!me->PresentName("liandao",IS_ITEM))	//����������û�д���
			return notify_fail("��û��������ô������أ��ò������ñ������������ɣ�");
		
		me->add("hp",-50);
		message_vision("\n$HIC$N����������������ǰ�ĵ�����ͷ����������", me);
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
			load_item("daohe")->move(me->environment());
			message_vision("$HIC������ܿ�Ͷ�����һ�ص��̣��������ͣ��������",me);
			destruct(this);
		}
		else
		{
			message_vision("$HIC���۵���ͷ�󺹣����е��������ҵ�ͣ��������",me);
		}
		me->start_busy(3);
		return 1;

	}
	return CItem::handle_action(comm, me, arg);
}

ITEM_END;




