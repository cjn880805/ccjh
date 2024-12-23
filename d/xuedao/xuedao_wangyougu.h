//wangyougu.h

//Sample for room:  Ѫ�������ǹ�
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_wangyougu);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ѫ�������ǹ�");

	add_npc("pub_yangzong");
	
	add_door("Ѫ���Ŵ�ѩɽɽ��9", "Ѫ���Ŵ�ѩɽɽ��9", "Ѫ�������ǹ�");
	add_door("Ѫ���Ŵ�ѩɽɽ��8", "Ѫ���Ŵ�ѩɽɽ��8", "Ѫ�������ǹ�");

};


virtual int do_look(CChar * me)
{
	char msg[255];
	CContainer * weapon;
	weapon = me->query_weapon();

	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if (me->query("xy/renwu8_2") && EQUALSTR(weapon->querystr("base_name"),"yao chu"))
	{
		AddMenuItem("��", "$0wa $1", me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	CContainer * weapon;
	weapon = me->query_weapon();

	if(!strcmp(comm, "wa") && me->query("xy/renwu8_2") && EQUALSTR(weapon->querystr("base_name"),"yao chu"))
		return do_wa(me, arg);
	return 0;
}

int do_wa(CChar *me, char * arg)
{
	CContainer * weapon;
	weapon = me->query_weapon();
	char msg[255];
	if (! weapon)
	{
		tell_object(me,"\n$HIR���޴������Ӻ�˵��");
	}
	else
	{
		if(EQUALSTR(weapon->querystr("base_name"),"yao chu"))
		{
			if (me->is_busy())
			{
				switch(random(0))
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
					return notify_fail("��ѽ���ȵȵȣ��ҵĳ�ͷ�Ѿ��Ӳ����ˡ���");
					break;
				}
			}
			if (me->query("hp") < 60)
				return notify_fail("�������̫���ˣ�������˯һ���ɡ�");
			
			if (!me->PresentName("yao chu",IS_ITEM))	//����������û�д���ͷ
				return notify_fail("��û�г�ͷ��ô���أ��ò������ñ�����������ɣ�");
			
			me->add("hp",-5);
			message_vision("\n$HIC$N���˿���ǰ����Ƭ������Ȼ�Ĳݵأ������Ļ����ͷ����������", me);
			if(!random(10))
			{
				load_item("baihe")->move(me);
				tell_object(me,"$HICֻ��һ�ꡰ$HIR�ٺ�$HIC����¶������ǰ����һ����ϲ��С��������ɿ���ͷ����������Ľ��������뻳��");
			}
			me->start_busy(3);
			return 1;
		}
		else
		{
			tell_object(me,snprintf(msg, 255,"\n$HIR���%s�ƺ������ʺ������ھ�",weapon->name(1)));
		}
	}
	return 1;
}

ROOM_END;
